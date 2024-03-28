#include "GUIModel.h"

void GUIModel::initializeGuiComponents() {
    this->setWindowTitle("Movie App");
    this->setStyleSheet("background-color: lightBlue");
    /*
     * black (negru)
     * white (alb)
     * red (roșu)
     * green (verde)
     * blue (albastru)
     * cyan (cyan)
     * magenta (magenta)
     * yellow (galben)
     * gray (gri)
     * darkGray (gri închis)
     * lightGray (gri deschis)
     * transparent (transparent)
     */

    //main layout-------------------------------------------------------------------------------------------------------
    lyMain = new QHBoxLayout;
    this->setLayout(lyMain);


    //left part of the widow--------------------------------------------------------------------------------------------
    //Partea din stanga e inpartita in 5 subparti
    //left1 = optiunile de gestiune a filmelor
    //left2 = sortarea filmelor
    //left3 = filtrarea filmelor
    //left4 = gestiunea wishlistului
    //left5 = butonul de reload data
    lyLeft = new QVBoxLayout;

    //left1 = optiunile de gestiune a filmelor
    QHBoxLayout* lyLeft1 = new QHBoxLayout;
    QHBoxLayout* ly_options = new QHBoxLayout;
    GroupBoxOptions->setLayout(ly_options);
    btnAddMovie = new QPushButton("Add Movie");
    btnModifyMovie = new QPushButton("Modify Movie");
    btnFindMovie = new QPushButton("Search Movie");
    btnDeleteMovie = new QPushButton("Delete Movie");
    ly_options->addWidget(btnAddMovie);
    ly_options->addWidget(btnModifyMovie);
    ly_options->addWidget(btnFindMovie);
    ly_options->addWidget(btnDeleteMovie);
    lyLeft1->addWidget(GroupBoxOptions);
    lyLeft->addWidget(GroupBoxOptions);


    //left2 = sortarea filmelor
    //casuta de sortare trebuie impartita in inca doua casute (criteriu + ordine)
    QVBoxLayout* ly_sort = new QVBoxLayout;
    GroupBoxSort->setLayout(ly_sort);

    //
    QHBoxLayout* ly_sort1 = new QHBoxLayout;

    //criteriu
    QVBoxLayout* ly_sort_by = new QVBoxLayout;
    GroupBoxSortCriteria->setLayout(ly_sort_by);
    ly_sort_by->addWidget(radioSortByTitle);
    ly_sort_by->addWidget(radioSortByActor);
    ly_sort_by->addWidget(radioSortByYearGenre);
    //ordine
    QVBoxLayout* ly_sort_order = new QVBoxLayout;
    GroupBoxSortOrder->setLayout(ly_sort_order);
    ly_sort_order->addWidget(radioSortAscending);
    ly_sort_order->addWidget(radioSortDescending);
    //buton de sortare
    btnSort = new QPushButton("Sort the movies");

    ly_sort1->addWidget(GroupBoxSortCriteria);
    ly_sort1->addWidget(GroupBoxSortOrder);

    ly_sort->addLayout(ly_sort1);
    ly_sort->addWidget(btnSort);

    lyLeft->addWidget(GroupBoxSort);


    //left3 = filtrarea filmelor
    QVBoxLayout* lyFilter = new QVBoxLayout;
    GroupBoxFilter->setLayout(lyFilter);
    QVBoxLayout* ly_filter_criteria = new QVBoxLayout;
    //criterii
    GroupBoxFilterCriteria->setLayout(ly_filter_criteria);
    ly_filter_criteria->addWidget(radioFilterTitle);
    ly_filter_criteria->addWidget(radioFilterYear);
    //buton filtrare
    btnFilterWindow = new QPushButton("Filter the movies");

    lyFilter->addWidget(GroupBoxFilterCriteria);
    lyFilter->addWidget(btnFilterWindow);
    lyLeft->addWidget(GroupBoxFilter);


    //left4 = gestiunea wishlistului
    QHBoxLayout* ly_Wishlist = new QHBoxLayout;
    GroupBoxWishlist->setLayout(ly_Wishlist);
    btnAddWishlist = new QPushButton("Add Movie to Wishlist");
    btnEmptyWishlist = new QPushButton("Empty the Wishlist");
    btnAddRandomWishlist = new QPushButton("Add random movie");
    btnExportWishlist = new QPushButton("Export Wishlist to file");
    ly_Wishlist->addWidget(btnAddWishlist);
    ly_Wishlist->addWidget(btnEmptyWishlist);
    ly_Wishlist->addWidget(btnAddRandomWishlist);
    ly_Wishlist->addWidget(btnExportWishlist);
    GroupBoxWindowsWishlist->setLayout(ly_WindowsWishlist);
    ly_WindowsWishlist->addWidget(btnCrudWishlist);
    ly_WindowsWishlist->addWidget(btnDrawWishlist);

    lyLeft->addWidget(GroupBoxWishlist);
    lyLeft->addWidget(GroupBoxWindowsWishlist);


    //left5 = butonul de reload data si butonul de undo
    QWidget* left5_btns = new QWidget;
    QHBoxLayout* ly_buttons_reload_undo = new QHBoxLayout;
    left5_btns->setLayout(ly_buttons_reload_undo);
    btnReloadData = new QPushButton("Reload data");
    btnUndo = new QPushButton("Undo");
    ly_buttons_reload_undo->addWidget(btnReloadData);
    ly_buttons_reload_undo->addWidget(btnUndo);
    lyLeft->addWidget(left5_btns);


    //right part of the widow-------------------------------------------------------------------------------------------
    //partea drepata e imaprtita in doua pe verticala
    //right1 = tabel cu toate filmele
    //right2 = tabel cu filmele din wishlist
    lyRight = new QVBoxLayout;


    //right1 = tabel cu toate filmele
    //tableMovies = new QTableWidget{200, 4};
    //tableMovies->setObjectName("Movies Table");
    //tableMovies->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //tableMovies->setSelectionBehavior(QAbstractItemView::SelectRows);

    //right2 = listacu toate filmele
    listMovies = new QListWidget;


    //right3 = tabel cu toate filmele  din wishlist
    tableWishlist = new QTableWidget{100, 4};
    tableWishlist->setObjectName("Wishlist");
    tableWishlist->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    lyRight->addWidget(tableMovies, 5);
    lyRight->addWidget(listMovies, 2);
    lyRight->addWidget(tableWishlist, 2);


    //Statistic part of the widow-------------------------------------------------------------------------------------------
    lyStatistic = new QVBoxLayout;
    ReloadDynamicButtons();


    //add to the main layout the left and right part--------------------------------------------------------------------
    lyMain->addLayout(lyLeft, 3);
    lyMain->addLayout(lyRight, 2);
    lyMain->addLayout(lyStatistic, 1);

}


void GUIModel::connectSignalsSlots() {
    //butoanele care deschid fereastra de citit date pt adaugare, modificare, cautare si stergere
    QObject::connect(btnAddMovie, &QPushButton::clicked, this, &GUIModel::GuiAddMovieWindow);
    QObject::connect(btnModifyMovie, &QPushButton::clicked, this, &GUIModel::GuiModifyMovieWindow);
    QObject::connect(btnFindMovie, &QPushButton::clicked, this, &GUIModel::GuiFindMovieWindow);
    QObject::connect(btnDeleteMovie, &QPushButton::clicked, this, &GUIModel::GuiDeleteMovieWindow);

    //butonul de sortare
    QObject::connect(btnSort, &QPushButton::clicked, this, &GUIModel::GuiSort);

    //butonul de filtrare
    QObject::connect(btnFilterWindow, &QPushButton::clicked, this, &GUIModel::GuiFilter);

    //WISHLIST
    QObject::connect(btnAddWishlist, &QPushButton::clicked, this, &GUIModel::GuiAddWishlist);
    QObject::connect(btnAddRandomWishlist, &QPushButton::clicked, this, &GUIModel::GuiAddRandomWishlistWindow);
    QObject::connect(btnEmptyWishlist, &QPushButton::clicked, this, [=]() {
        service.emptyWishlist();
        reloadWislistTabel(tableWishlist, service.getWishlist());
        QMessageBox::information(this, "Info", QString::fromStdString("Wishlist has been successfully emptied!"));
    });
    QObject::connect(btnExportWishlist, &QPushButton::clicked, this, &GUIModel::GuiExportWishlistWindow);

    QObject::connect(btnCrudWishlist, &QPushButton::clicked, this, [=]() {
        WishlistCRUD* window = new WishlistCRUD{service};
        service.getCurrentWishlist().addObserver(window);
        window->show();
    });
    QObject::connect(btnDrawWishlist, &QPushButton::clicked, this, [=]() {
        WishlistDRAW* window = new WishlistDRAW{service.getCurrentWishlist()};
        window->show();
    });

    //butonul de reload data
    QObject::connect(btnReloadData, &QPushButton::clicked, this, [=]() {
        reloadMoviesTabel(tableMovies, service.getAllMovies());
        reloadMoviesList(listMovies, service.getAllMovies());
    });

    //butonul de undo
    QObject::connect(btnUndo, &QPushButton::clicked, this, [=]() {
        try {
            service.undo();
        }
        catch (UndoException& ue) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ue.getMesajDeEroare()));
        }
        reloadMoviesTabel(tableMovies, service.getAllMovies());
        reloadMoviesList(listMovies, service.getAllMovies());
    });

}


void GUIModel::reloadMoviesTabel(QTableView* tbl, const vector<Movie>& movies) {
    model->setMovies(movies);
}


void GUIModel::reloadWislistTabel(QTableWidget* tbl, const vector<Movie>& movies){
    tbl->clearContents();
    tbl->setRowCount((int)movies.size());


    int lineNumber = 0;
    for (const auto& mov : movies) {
        tbl->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(mov.getTitlu())));
        tbl->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(mov.getGen())));
        tbl->setItem(lineNumber, 2, new QTableWidgetItem(QString::number(mov.getAnAparitie())));
        tbl->setItem(lineNumber, 3, new QTableWidgetItem(QString::fromStdString(mov.getActorPrincipal())));
        lineNumber++;
    }
}

void GUIModel::reloadMoviesList(QListWidget* list, const vector<Movie>& movies) {
    list->clear();

    int lineNumber = 0;
    for (const auto& mov : movies) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(mov.getTitlu() + " " + mov.getGen() + " " +
                                                                           to_string(mov.getAnAparitie()) + " " + mov.getActorPrincipal()));
        list->addItem(item);
    }
}

void GUIModel::DynamicButtons() {
    map<int, Movie_DTO> yearStatistic = service.yearStatistic();
    for (const auto& pair: yearStatistic) {
        int year = pair.first;
        QPushButton* btn = new QPushButton{QString::fromStdString(to_string(year))};
        lyStatistic->addWidget(btn);
        QObject::connect(btn, &QPushButton::clicked, this, [=]() {
            QMessageBox::information(this, "Number of movies", QString::fromStdString(to_string(pair.second.get_count()) +
                                                                                      " movies"));
        });
    }
}

void GUIModel::ReloadDynamicButtons() {
    QLayoutItem *item;
    while((item = lyStatistic->takeAt(0))) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
    DynamicButtons();
    lyStatistic->addStretch();
}

void GUIModel::GuiAddMovieWindow() {
    AddWindow = new QWidget;
    AddWindow->setWindowTitle("Add Movie");
    AddWindow->setStyleSheet("background-color: lightBlue;");

    QFormLayout* lyAddWindow = new QFormLayout;
    AddWindow->setLayout(lyAddWindow);

    QLabel* lblTitle = new QLabel("Title: ");
    QLabel* lblGenre = new QLabel("Genre: ");
    QLabel* lblYear = new QLabel("Year: ");
    QLabel* lblActor = new QLabel("MainActor: ");
    editTitle = new QLineEdit;
    editGenre = new QLineEdit;
    editYear = new QLineEdit;
    editActor = new QLineEdit;
    lyAddWindow->addRow(lblTitle, editTitle);
    lyAddWindow->addRow(lblGenre, editGenre);
    lyAddWindow->addRow(lblYear, editYear);
    lyAddWindow->addRow(lblActor, editActor);
    btnAdd = new QPushButton("Add Movie");
    QObject::connect(btnAdd, &QPushButton::clicked, this, &GUIModel::GuiAddMovie);
    lyAddWindow->addWidget(btnAdd);
    AddWindow->show();
}

void GUIModel::GuiAddMovie() {
    string title = editTitle->text().toStdString();
    string genre = editGenre->text().toStdString();
    int year = editYear->text().toInt();
    string actor = editActor->text().toStdString();

    try {
        service.adauga(title, genre, year, actor);
        reloadMoviesTabel(tableMovies, service.getAllMovies());
        reloadMoviesList(listMovies, service.getAllMovies());
        ReloadDynamicButtons();

        //afisam un mesaj ca adaugarea s-a efectual cu succes
        QMessageBox::information(this, "Succes", QString::fromStdString("The movie has been successfully added"));
    }
    catch (RepoException& re) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(re.getMesajDeEroare()));
    }
    catch (ValidatorException& ve) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMesajDeEroare()));
    }
    AddWindow->close();
}


void GUIModel::GuiModifyMovieWindow() {
    ModifyWindow = new QWidget;
    ModifyWindow->setWindowTitle("Modify Movie");
    ModifyWindow->setStyleSheet("background-color: lightBlue;");

    QFormLayout* lyModifyWindow = new QFormLayout;
    ModifyWindow->setLayout(lyModifyWindow);

    QLabel* lblTitle = new QLabel("Title of the movie to modify : ");
    QLabel* lblGenre = new QLabel("New genre: ");
    QLabel* lblYear = new QLabel("Year of the movie to modify: ");
    QLabel* lblActor = new QLabel("New MainActor: ");
    editTitle = new QLineEdit;
    editGenre = new QLineEdit;
    editYear = new QLineEdit;
    editActor = new QLineEdit;
    lyModifyWindow->addRow(lblTitle, editTitle);
    lyModifyWindow->addRow(lblGenre, editGenre);
    lyModifyWindow->addRow(lblYear, editYear);
    lyModifyWindow->addRow(lblActor, editActor);
    btnModify= new QPushButton("Modify Movie");
    QObject::connect(btnModify, &QPushButton::clicked, this, &GUIModel::GuiModifyMovie);
    lyModifyWindow->addWidget(btnModify);
    ModifyWindow->show();
}


void GUIModel::GuiModifyMovie() {
    string title = editTitle->text().toStdString();
    string genre = editGenre->text().toStdString();
    int year = editYear->text().toInt();
    string actor = editActor->text().toStdString();

    editTitle->clear();
    editGenre->clear();
    editYear->clear();
    editActor->clear();

    try {
        service.modifica(title, genre, year, actor);
        reloadMoviesTabel(tableMovies, service.getAllMovies());
        reloadMoviesList(listMovies, service.getAllMovies());

        //afisam un mesaj ca adaugarea s-a efectual cu succes
        QMessageBox::information(this, "Succes", QString::fromStdString("The movie has been modified successfully"));
    }
    catch (RepoException& re) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(re.getMesajDeEroare()));
    }
    catch (ValidatorException& ve) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMesajDeEroare()));
    }
    ModifyWindow->close();
}


void GUIModel::GuiFindMovieWindow() {
    FindWindow = new QWidget;
    FindWindow->setWindowTitle("Find Movie");
    FindWindow->setStyleSheet("background-color: lightBlue;");

    QFormLayout* lyFindWindow = new QFormLayout;
    FindWindow->setLayout(lyFindWindow);

    QLabel* lblTitle = new QLabel("The title of the searched movie: ");
    QLabel* lblYear = new QLabel("the year of the searched movie: ");
    editTitle = new QLineEdit;
    editYear = new QLineEdit;
    lyFindWindow->addRow(lblTitle, editTitle);
    lyFindWindow->addRow(lblYear, editYear);
    btnFind = new QPushButton("Find Movie");
    QObject::connect(btnFind, &QPushButton::clicked, this, &GUIModel::GuiFindMovie);
    lyFindWindow->addWidget(btnFind);
    FindWindow->show();
}


void GUIModel::GuiFindMovie() {
    string title = editTitle->text().toStdString();
    int year = editYear->text().toInt();

    editTitle->clear();
    editYear->clear();

    try {
        Movie find_mov = service.cauta(title, year);
        reloadMoviesTabel(tableMovies, service.getAllMovies());
        reloadMoviesList(listMovies, service.getAllMovies());

        //afisam un mesaj ca adaugarea s-a efectual cu succes
        QMessageBox::information(this, "Succes", QString::fromStdString("The searched movie is:\n Title: "
                                                                        + find_mov.getTitlu() + "\n"
                                                                        + "Genre: " + find_mov.getGen() + "\n"
                                                                        + "Year: " + to_string(find_mov.getAnAparitie()) + "\n"
                                                                        + "Main actor:  " + find_mov.getActorPrincipal()));
    }
    catch (RepoException& re) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(re.getMesajDeEroare()));
    }
    catch (ValidatorException& ve) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMesajDeEroare()));
    }
    FindWindow->close();
}


void GUIModel::GuiDeleteMovieWindow() {
    QWidget *DeleteWindow = new QWidget;
    DeleteWindow->setWindowTitle("Delete Movie");
    DeleteWindow->setStyleSheet("background-color: lightBlue;");

    QFormLayout* lyDeleteWindow = new QFormLayout;
    DeleteWindow->setLayout(lyDeleteWindow);

    QLabel* lblTitle = new QLabel("The title of the movie to delete: ");
    QLabel* lblYear = new QLabel("the year of the movie to delete: ");
    editTitle = new QLineEdit;
    editYear = new QLineEdit;
    lyDeleteWindow->addRow(lblTitle, editTitle);
    lyDeleteWindow->addRow(lblYear, editYear);
    btnDelete = new QPushButton("Delete Movie");
    QObject::connect(btnDelete, &QPushButton::clicked, this, &GUIModel::GuiDeleteMovie);
    lyDeleteWindow->addWidget(btnDelete);
    DeleteWindow->show();
}


void GUIModel::GuiDeleteMovie() {
    string title = editTitle->text().toStdString();
    int year = editYear->text().toInt();

    editTitle->clear();
    editYear->clear();

    try {
        Movie delete_mov = service.sterge(title, year);
        reloadMoviesTabel(tableMovies, service.getAllMovies());
        ReloadDynamicButtons();

        //afisam un mesaj ca adaugarea s-a efectual cu succes
        QMessageBox::information(this, "Succes", QString::fromStdString("The movie has been deleted successfully"));
    }
    catch (RepoException& re) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(re.getMesajDeEroare()));
    }
    catch (ValidatorException& ve) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMesajDeEroare()));
    }
}


void GUIModel::GuiSort() {
    vector<Movie> MoviesSorted;
    //verificam sa avem optiuni alese
    if ((!radioSortByActor->isChecked() &&
         !radioSortByTitle->isChecked() &&
         !radioSortByYearGenre->isChecked()) ||
        (!radioSortAscending->isChecked() &&
         !radioSortDescending->isChecked())) {
        QMessageBox::warning(this, "Warning", "Select de sort options");

    }

    if (radioSortByTitle->isChecked()) {
        if (radioSortAscending->isChecked()) {
            MoviesSorted = service.GenericSort(service.cmpTitlu, false);
        }
        else {
            MoviesSorted = service.GenericSort(service.cmpTitlu, true);
        }
    }

    if (radioSortByActor->isChecked()) {
        if (radioSortAscending->isChecked()) {
            MoviesSorted = service.GenericSort(service.cmpActor, false);
        }
        else {
            MoviesSorted = service.GenericSort(service.cmpActor, true);
        }
    }

    if (radioSortByYearGenre->isChecked()) {
        if (radioSortAscending->isChecked()) {
            MoviesSorted = service.GenericSort(service.cmpAnGen, false);
        }
        else {
            MoviesSorted = service.GenericSort(service.cmpAnGen, true);
        }
    }

    radioSortByTitle->setChecked(false);
    radioSortByActor->setChecked(false);
    radioSortByYearGenre->setChecked(false);
    radioSortAscending->setChecked(false);
    radioSortDescending->setChecked(false);

    reloadMoviesTabel(tableMovies, MoviesSorted);
    reloadMoviesList(listMovies, MoviesSorted);
}

void GUIModel::GuiFilter() {
    if (!radioFilterYear->isChecked() && !radioFilterTitle->isChecked()) {
        QMessageBox::warning(this, "Warning", "Select de filter options");
    }

    if (radioFilterTitle->isChecked()) {
        QWidget* ReadTileWindow = new QWidget;
        ReadTileWindow->setWindowTitle("Filter by title");
        ReadTileWindow->setStyleSheet("background-color: lightBlue;");

        QFormLayout *ly_read_title = new QFormLayout;
        ReadTileWindow->setLayout(ly_read_title);

        QLabel *lblTitle = new QLabel("Title: ");
        editTitle = new QLineEdit;
        ly_read_title->addRow(lblTitle, editTitle);
        btnFilter1 = new QPushButton("Filter the movies");
        ly_read_title->addWidget(btnFilter1);
        QObject::connect(btnFilter1, &QPushButton::clicked, this, [=]() {
            string title = editTitle->text().toStdString();
            editTitle->clear();
            vector<Movie> MoviesFiltered = service.filtrareTitlu(title);
            if (MoviesFiltered.empty()) {
                QMessageBox::warning(this, "Warning", QString::fromStdString("There are no movies  with title "
                                                                             + title + " in the list"));
            }
            else {
                reloadMoviesTabel(tableMovies, MoviesFiltered);
                reloadMoviesList(listMovies, MoviesFiltered);
            }
        });
        radioFilterTitle->setChecked(false);
        ReadTileWindow->show();
    }

    if (radioFilterYear->isChecked()) {
        QWidget *ReadGenreWindow = new QWidget;
        ReadGenreWindow->setWindowTitle("Filter by year");
        ReadGenreWindow->setStyleSheet("background-color: lightBlue;");

        QFormLayout *ly_read_year = new QFormLayout;
        ReadGenreWindow->setLayout(ly_read_year);

        QLabel *lblYear = new QLabel("Year: ");
        editYear = new QLineEdit;
        ly_read_year->addRow(lblYear, editYear);
        btnFilter2 = new QPushButton("Filter the movies");
        ly_read_year->addWidget(btnFilter2);
        QObject::connect(btnFilter2, &QPushButton::clicked, this, [=]() {
            int year = editYear->text().toInt();
            editYear->clear();
            vector<Movie> MoviesFiltered = service.filtrareAnAparitie(year);
            if (MoviesFiltered.empty()) {
                QMessageBox::warning(this, "Warning", QString::fromStdString("There are no movies published in the year "
                                                                             + to_string(year) + " in the list"));
            }
            else {
                reloadMoviesTabel(tableMovies, MoviesFiltered);
                reloadMoviesList(listMovies, MoviesFiltered);
            }
        });
        radioFilterYear->setChecked(false);
        ReadGenreWindow->show();
    }
}




void GUIModel::GuiAddWishlist() {
    QList selectedMovies = model->selectedItems();
    if (selectedMovies.empty()) {
        QMessageBox::warning(this, "Warning", QString::fromStdString("Select the movies you want to"
                                                                     " add to the wishlist from the movie list"));
    }
    else {
        while (!selectedMovies.empty()) {
            string title = selectedMovies[0].getTitlu();
            int year = selectedMovies[0].getAnAparitie();
            try {
                service.addtoWishlist(title, year);
                QMessageBox::information(this, "Info",
                                         QString::fromStdString("The movie has been successfully added to Wishlist"));
                reloadWislistTabel(tableWishlist, service.getWishlist());
                ReloadDynamicButtons();
            }
            catch (RepoException &re) {
                QMessageBox::warning(this, "Warning", QString::fromStdString(re.getMesajDeEroare()));
            }
            for (int i = 0; i < 4; i++) {
                selectedMovies.pop_front();
            }
        }
    }
    reloadMoviesTabel(tableWishlist, service.getWishlist());
}


void GUIModel::GuiAddRandomWishlistWindow() {
    AddRandomWindow = new QWidget;
    AddRandomWindow->setWindowTitle("Add random Movies");
    AddRandomWindow->setStyleSheet("background-color: lightBlue;");

    QFormLayout* lyAddRandomWindow = new QFormLayout;
    AddRandomWindow->setLayout(lyAddRandomWindow);

    QLabel* lblHowMany = new QLabel ("Select the number of movies: ");
    spinBoxHowMany = new QSpinBox;
    spinBoxHowMany->setMinimum(0);
    spinBoxHowMany->setMaximum(service.size()-service.sizeOfWishlist());
    btnAddRandom = new QPushButton("Add movies to wishlits");
    lyAddRandomWindow->addRow(lblHowMany, spinBoxHowMany);

    QObject::connect(btnAddRandom, &QPushButton::clicked, this, [=]() {
        int howMany = spinBoxHowMany->value();
        service.addRandomMoviesToWishlist(howMany);
        QMessageBox::information(this, "Info", QString::fromStdString(to_string(howMany) +
                                                                      " movies have been added to the wishlist"));
        reloadWislistTabel(tableWishlist, service.getWishlist());
        AddRandomWindow->close();
    });
    lyAddRandomWindow->addWidget(btnAddRandom);
    AddRandomWindow->show();
}


void GUIModel::GuiExportWishlistWindow() {
    ExportWishlistWindow = new QWidget;
    ExportWishlistWindow->setWindowTitle("Export Wishlist to file");
    ExportWishlistWindow->setStyleSheet("background-color: lightBlue;");

    QFormLayout* lyExportWishlistWindow = new QFormLayout;
    ExportWishlistWindow->setLayout(lyExportWishlistWindow);

    QLabel* lblFile = new QLabel("the path of the file where you want to save the wishlist: ");
    editFile= new QLineEdit;
    lyExportWishlistWindow->addRow(lblFile, editFile);

    btnExport = new QPushButton("Save Wishlist");
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
