#include "WishlistGUI.h"

//===============================WishlistCRUD==============================
void WishlistCRUD::initializeComponents() {
    this->setLayout(lyMain);

    lyLeft->addWidget(btnAddWishlist);
    lyLeft->addWidget(btnAddRandomWishlist);
    lyLeft->addWidget(btnEmptyWishlist);
    lyLeft->addWidget(btnExportWishlist);

    tableWishlist->setHorizontalHeaderLabels(QStringList() <<"Title" << "Genre" << "Year" << "Main actor");
    lyRight->addWidget(tableWishlist);

    lyMain->addLayout(lyLeft);
    lyMain->addLayout(lyRight);
}


void WishlistCRUD::connectSignalSlot() {
    QObject::connect(btnAddWishlist, &QPushButton::clicked, this, &WishlistCRUD::WishlistGUI_add);
    QObject::connect(btnAddRandomWishlist, &QPushButton::clicked, this, &WishlistCRUD::WishlistGUI_addRandom);
    QObject::connect(btnEmptyWishlist, &QPushButton::clicked, this, [=]() {
        service.emptyWishlist();
        reloadTableWishlist(tableWishlist, service.getWishlist());
        QMessageBox::information(this, "Info", QString::fromStdString("Wishlist has been successfully emptied!"));
    });
    QObject::connect(btnExportWishlist, &QPushButton::clicked, this, &WishlistCRUD::WishlistGUI_export);

}


void WishlistCRUD::reloadTableWishlist(QTableWidget* tbl, const vector<Movie>& vec) {
    tbl->clearContents();
    tbl->setRowCount((int)vec.size());
    tbl->setColumnCount(4);

    tbl->clear();

    int lineNumber = 0;
    for (const auto& mov : vec) {
        tbl->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(mov.getTitlu())));
        tbl->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(mov.getGen())));
        tbl->setItem(lineNumber, 2, new QTableWidgetItem(QString::number(mov.getAnAparitie())));
        tbl->setItem(lineNumber, 3, new QTableWidgetItem(QString::fromStdString(mov.getActorPrincipal())));
        lineNumber++;
    }
}


void WishlistCRUD::WishlistGUI_add() {
    AddWindow->setWindowTitle("Add Movie to Wishlist");
    AddWindow->setStyleSheet("background-color: lightBlue;");
    AddWindow->setLayout(lyAddWishlist);

    lyAddWishlist->addRow(lblTitle, editTitle);
    lyAddWishlist->addRow(lblYear, editYear);
    lyAddWishlist->addWidget(btnAdd1);
    AddWindow->show();
    QObject::connect(btnAdd1, &QPushButton::clicked, this, [=]() {
        string title = editTitle->text().toStdString();
        int year = editYear->text().toInt();

        try {
            service.addtoWishlist(title, year);
            reloadTableWishlist(tableWishlist, service.getWishlist());
        }
        catch (WishlistException& we) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(we.getMesajDeEroare()));
        }
        AddWindow->close();
    });
}


void WishlistCRUD::WishlistGUI_addRandom() {
    AddRandomWindow->setWindowTitle("Add random Movies");
    AddRandomWindow->setStyleSheet("background-color: lightBlue;");
    AddRandomWindow->setLayout(lyAddRandomWindow);

    spinBoxHowMany->setMinimum(0);
    spinBoxHowMany->setMaximum(service.size() - service.sizeOfWishlist());
    lyAddRandomWindow->addRow(lblHowMany, spinBoxHowMany);
    lyAddRandomWindow->addWidget(btnAdd2);
    AddRandomWindow->show();

    QObject::connect(btnAdd2, &QPushButton::clicked, this, [=]() {
        int howMany = spinBoxHowMany->value();
        service.addRandomMoviesToWishlist(howMany);
        QMessageBox::information(this, "Info", QString::fromStdString(to_string(howMany) +
                                                                      " movies have been added to the wishlist"));
        reloadTableWishlist(tableWishlist, service.getWishlist());
        AddRandomWindow->close();
    });
}

void WishlistCRUD::WishlistGUI_export() {
    ExportWishlistWindow->setWindowTitle("Export Wishlist to file");
    ExportWishlistWindow->setStyleSheet("background-color: lightBlue;");
    ExportWishlistWindow->setLayout(lyExportWishlistWindow);

    lyExportWishlistWindow->addRow(lblFile, editFile);

    QObject::connect(btnExport, &QPushButton::clicked, this, [=]() {
        string filePath = editFile->text().toStdString();
        editFile->clear();
        service.saveWishlistToFile(filePath);
        QMessageBox::information(this, "Info", QString::fromStdString("Wishlist saved successfully!"));
        ExportWishlistWindow->close();
    });
    lyExportWishlistWindow->addWidget(btnExport);
    ExportWishlistWindow->show();
}


//===============================WishlistDRAW==============================

void WishlistDRAW::paintEvent(QPaintEvent* event) {
    QPainter p{ this };
    int x = rand() % 400 + 1;
    int y = rand() % 400 + 1;
    for (auto mov : wishlist.getAllMoviesFromWishlist()) {
        p.drawRect(x, y, 100, 100);
        QRectF target(x, y, 100, 100);
        QRectF source(0, 0, 1200, 1200);
        QImage image("../icon.jpg");

        p.drawImage(target,image, source);

        x += 40;

        x= rand() % 400 + 1;
        y = rand() % 400 + 1;

    }
}