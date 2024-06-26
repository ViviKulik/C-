#pragma once
#include <vector>
#include <string>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>
#include <QSpinBox>
#include <qlistwidget.h>
#include <QList>


#include "../../Service/Service.h"
#include "../Observer/Observer-Observable.h"
#include "../Observer/WishlistGUI.h"


using std::vector;

class GUI : public QWidget, public Observer{
private:
    Service& service;


    QHBoxLayout* lyMain;
    QVBoxLayout* lyLeft;
    QVBoxLayout* lyRight;
    QVBoxLayout* lyStatistic;


    //butoare pt gestiune filme
    QGroupBox* GroupBoxOptions = new QGroupBox{tr("Movie management: ")};
    QPushButton* btnAddMovie;
    QPushButton* btnAdd;
    QPushButton* btnModifyMovie;
    QPushButton* btnModify;
    QPushButton* btnFindMovie;
    QPushButton* btnFind;
    QPushButton* btnDeleteMovie;


    //casutele de introdus date
    QLineEdit* editTitle;
    QLineEdit* editGenre;
    QLineEdit* editYear;
    QLineEdit* editActor;

    //tr - traduce textul afisat in dunctie de liba selectata
    //casuta pentru criteriile de sortare
    QGroupBox* GroupBoxSort = new QGroupBox{tr("Sort Movies")};
    QGroupBox* GroupBoxSortCriteria = new QGroupBox{tr("Sort by:")};
    QRadioButton* radioSortByTitle = new QRadioButton(QString::fromStdString("Title"));
    QRadioButton* radioSortByActor = new QRadioButton(QString::fromStdString("Actor"));
    QRadioButton* radioSortByYearGenre = new QRadioButton(QString::fromStdString("Year and Genre"));
    //casuta pentru ordinea sortarii
    QGroupBox* GroupBoxSortOrder = new QGroupBox{tr("Sort in:")};
    QRadioButton* radioSortAscending = new QRadioButton(QString::fromStdString("Ascending order"));
    QRadioButton* radioSortDescending = new QRadioButton(QString::fromStdString("Descending order"));
    QPushButton* btnSort;

    //Casuta pentru filtrare
    QGroupBox* GroupBoxFilter = new QGroupBox{tr("Filter movie")};
    QGroupBox* GroupBoxFilterCriteria = new QGroupBox{tr("Filter by")};
    QRadioButton* radioFilterTitle = new QRadioButton(QString::fromStdString("Title"));
    QRadioButton* radioFilterYear = new QRadioButton(QString::fromStdString("Year"));
    QPushButton* btnFilterWindow;
    QPushButton* btnFilter1;
    QPushButton* btnFilter2;

    QGroupBox* GroupBoxWishlist = new QGroupBox{tr("Wishlist:")};
    QPushButton* btnAddWishlist;
    QPushButton* btnEmptyWishlist;
    QPushButton* btnAddRandomWishlist;
    QWidget* AddRandomWindow;
    QPushButton* btnAddRandom;
    QSpinBox* spinBoxHowMany;
    QGroupBox* GroupBoxWindowsWishlist = new QGroupBox{"Wishlist Windows"};
    QHBoxLayout* ly_WindowsWishlist = new QHBoxLayout;
    QPushButton* btnCrudWishlist = new QPushButton{"CRUD Wishlist"};
    QPushButton* btnDrawWishlist = new QPushButton{"Draw Wishlist"};

    QPushButton* btnExportWishlist;
    QWidget* ExportWishlistWindow;
    QLineEdit* editFile;
    QPushButton* btnExport;



    QPushButton* btnReloadData;
    QPushButton* btnUndo;


    QTableWidget* tableMovies;
    QTableWidget* tableWishlist;
    QListWidget* listMovies;

    //ferestre pt functionaliotati
    QWidget *AddWindow;
    QWidget *ModifyWindow;
    QWidget *FindWindow;


    void initializeGuiComponents();

    void connectSignalsSlots();

    void reloadMoviesTabel(QTableWidget* tbl, const vector<Movie>& movies);
    void reloadMoviesList(QListWidget* list, const vector<Movie>& movies);

    void DynamicButtons();
    void ReloadDynamicButtons();


public:
    GUI(Service& service): service{ service } {
        service.getCurrentWishlist().addObserver(this);
        initializeGuiComponents();
        connectSignalsSlots();
        reloadMoviesTabel(tableMovies, service.getAllMovies());
    }

    void GuiAddMovieWindow();
    void GuiAddMovie();
    void GuiModifyMovieWindow();
    void GuiModifyMovie();
    void GuiFindMovieWindow();
    void GuiFindMovie();
    void GuiDeleteMovie();

    void GuiSort();
    void GuiFilter();

    void GuiAddWishlist();
    void GuiAddRandomWishlistWindow();
    void GuiExportWishlistWindow();

    void update() override {
        reloadMoviesTabel(tableWishlist, service.getWishlist());
    }
};