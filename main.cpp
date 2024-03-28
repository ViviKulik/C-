#include <QApplication>
#include
#include "Interfata/GUI/GUI.h"
#include "Interfata/Model/GUIModel.h"
#include "Interfata/UI/UI.h"
#include "Teste/Teste.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Teste teste;
    teste.Ruleaza_toate_testele();

    MoviesFileRepository repo{"/Users/viviankulik/Downloads/LAB_13-14_OOP/Repository/Repository.txt"};
    FilmValidator val;
    Service service{repo, val};

    UI ui{service};
    //ui.runUI();

    GUI gui{service};
    //gui.setWindowState(Qt::WindowMaximized);
    gui.resize(1200,600);
    //gui.show();

    GUIModel gui_model{service};
    gui_model.show();

    return a.exec();
}
