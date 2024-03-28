#pragma once

#include "Observer-Observable.h"
#include "../../Movies_Wishlist/Wishlist.h"
#include "../../Service/Service.h"

#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QFormLayout>
#include <QTableWidget>
#include <QPainter>
#include <QLineEdit>
#include <QMessageBox>
#include <QListWidgetItem>
#include <algorithm>
#include <random>


class WishlistCRUD: public QWidget, public Observer {

private:
    Service& service;

    QHBoxLayout* lyMain = new QHBoxLayout;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    QVBoxLayout* lyRight = new QVBoxLayout;

    //============LEFT================
    QPushButton* btnAddWishlist = new QPushButton{" Add movie to Wishlist"};
    QWidget* AddWindow = new QWidget;
    QFormLayout* lyAddWishlist = new QFormLayout;
    QLabel* lblTitle = new QLabel{"Title: "};
    QLabel* lblYear = new QLabel{"Year: "};
    QLineEdit* editTitle = new QLineEdit;
    QLineEdit* editYear = new QLineEdit;
    QPushButton* btnAdd1 = new QPushButton{"Add Movie"};

    QPushButton* btnEmptyWishlist = new QPushButton{" Empty Wishlist"} ;

    QPushButton* btnAddRandomWishlist = new QPushButton{" Add random movies to Wishlist"};
    QWidget* AddRandomWindow = new QWidget;
    QFormLayout * lyAddRandomWindow = new QFormLayout;
    QPushButton* btnAddRandom = new QPushButton{" Add movies"};
    QLabel* lblHowMany = new QLabel{"Select the number of movies: "};
    QSpinBox* spinBoxHowMany =  new QSpinBox;
    QPushButton* btnAdd2 = new QPushButton{"Add Movie"};

    QPushButton* btnExportWishlist = new QPushButton{" Export Wishlist to file"} ;
    QWidget* ExportWishlistWindow = new QWidget;
    QFormLayout* lyExportWishlistWindow = new QFormLayout;
    QLabel* lblFile = new QLabel("the path of the file where you want to save the wishlist: ");
    QLineEdit* editFile= new QLineEdit;
    QPushButton* btnExport = new QPushButton("Save Wishlist");


    //============RIGHT================
    QTableWidget* tableWishlist = new QTableWidget{};

    void update() override {
        reloadTableWishlist(tableWishlist, service.getWishlist());
    }

    void initializeComponents();
    void connectSignalSlot();

    void reloadTableWishlist(QTableWidget* tbl, const vector<Movie>& movies);
    void WishlistGUI_add();
    void WishlistGUI_addRandom();
    void WishlistGUI_export();


public:
    WishlistCRUD(Service& service) : service {service} {
        this->setStyleSheet("background-color: lightBlue;");
        initializeComponents();
        connectSignalSlot();
    }
};



class WishlistDRAW: public QWidget, public Observer {
private:
    Wishlist& wishlist;


    void update() override {
        repaint();
    }

    void paintEvent(QPaintEvent* event) override;

    ~WishlistDRAW() {
        wishlist.removeObserver(this);
    }

public:
    WishlistDRAW(Wishlist& wishlist) : wishlist{wishlist}{
        wishlist.addObserver(this);
        this->setStyleSheet("background-color: lightBlue;");
    }
};
