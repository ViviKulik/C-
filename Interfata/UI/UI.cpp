#include "UI.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::ws;
using std::getline;
using std::endl;

void UI::prinMenu() {
    cout << "\n\n\n\n-------------------------------------------------APLICATIE INCHIRIERE FILME---------------------"
            "---------------------------\n";
    cout << "MENIU:" << endl;
    cout << "      1. Afiseaza toate filmele" << endl;
    cout << "      2. Adauga un film" << endl;
    cout << "      3. Modifica un film" << endl;
    cout << "      4. Cauta un film" << endl;
    cout << "      5. Sterge un film" << endl;
    cout << "      6. Filtrarea filmelor dupa: " << endl;
    cout << "               a) Titlu" << endl;
    cout << "               b) Anul aparitiei" << endl;
    cout << "      7. Sortarea filmelor: " << endl;
    cout << "             Modul:" << endl;
    cout << "               i.crescator" << endl;
    cout << "               ii.descrescator" << endl;
    cout << "             Criteriul:" << endl;
    cout << "               a) Titlu" << endl;
    cout << "               b) ActorPrincipal" << endl;
    cout << "               c) An al aparitiei + Gen" << endl;
    cout << "      8. Adauga un film in WishList " << endl;
    cout << "      9. Goleste WishList " << endl;
    cout << "     10. Adauga filme random in WishList " << endl;
    cout << "     11. Afiseaza toate filmele din WishList " << endl;
    cout << "     12. Salveaza Wishlist intr-un fisier " << endl;
    cout << "     13. Afiseaza raportul filmelor in functie de anul aparitiei " << endl;
    cout << "     14. Undo " << endl;
    cout << "     15. Exit" << endl;
}

void UI::addDefaultMovies() const {
    service.adauga("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman");
    service.adauga("The Godfather", "Actiune", 1972 , "Al Pacino");
    service.adauga("12 Angry Men", "Drama", 1957, "Henry Fonda");
    service.adauga("Schimdler's List", "Drama", 1994, "Liam Neeson");
    service.adauga("Forrest Gump", "Comedie", 1994, "Tom Hanks");
    service.adauga("The Matrix", "Actiune", 1999, "Keanu Reeves");
    service.adauga("Se7en", "Crima", 1995, "Brad Pitt");
    service.adauga("Interstellar", "Aventura", 2014 , "Matthew McConaughey");
    service.adauga("The Pianist", "Razboi", 2002, "Adrien Brody");
    service.adauga("Casablanca", "Romantic", 1942, "Ingrid Bergman");
}

int UI::cin_int() {
    int an;
    while(true){
        cin >> an;

        if (cin.fail()) {
            cout << "Input invalid! Va rugam introduceti un numar intreg: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }
    return an;
}


string UI::cin_string(){
    string s;
    getline(cin >> ws, s);
    return s;
}


void UI::printMovie(const Movie& film) {
    cout << "Titlu: " << film.getTitlu() << " | Gen: " << film.getGen() << " | Anul aparitiei: " <<
         film.getAnAparitie() << " | Actor Principal: " << film.getActorPrincipal() << endl;
}


void UI::printMovies(const vector<Movie>& Filme) {
    if (Filme.empty())
        cout << "Nu exista filme in lista ! \n";
    else {
        cout << "------------------------------------------------------------------------------------------------------"
                "----------------------" << endl;
        for (auto& film: Filme) {
            printMovie(film);
            cout << "---------------------------------------------------------------------------------------------------"
                    "----------------------" << endl;
        }
    }
}

void UI::printAllMoviesUI() const {
    printMovies(service.getAllMovies());
}

void UI::adaugaUI() const {
    string titlu, gen, actor_principal;
    int an_aparitie;

    cout << "Titilul filmului este: ";
    titlu = cin_string();

    cout << "Genul filmului este: ";
    gen = cin_string();

    cout << "Anul aparitiei filmului este: ";
    an_aparitie = cin_int();


    cout << "Actorul principal al filmului este: ";
    actor_principal = cin_string();

    service.adauga(titlu, gen, an_aparitie, actor_principal);

    cout << "Film adaugat cu succes! \n";
}

void UI::modificaUI() const {
    string titlu, gen, actor_principal;
    int an_aparitie;

    cout << "Titilul filmului pe care doriti sa-l modificati este: ";
    titlu = cin_string();

    cout << "Anul aparitiei filmului pe care doriti sa-l modificati este: ";
    an_aparitie = cin_int();

    cout << "Noul gen al filmului este: ";
    gen = cin_string();


    cout << "Noul actor principal al filmului este: ";
    actor_principal = cin_string();

    service.modifica(titlu, gen, an_aparitie, actor_principal);

    cout << "Film modificat cu succes! \n";
}

void UI::cautaUI() const {
    string titlu, gen, actor_principal;
    int an_aparitie;

    cout << "Titilul filmului pe care doriti sa-l modificati este: ";
    titlu = cin_string();

    cout << "Anul aparitiei filmului pe care doriti sa-l modificati este: ";
    an_aparitie = cin_int();

    Movie film_gasit = service.cauta(titlu, an_aparitie);
    printMovie(film_gasit);
}

void UI::stergeUI() const {
    string titlu, gen, actor_principal;
    int an_aparitie;

    cout << "Titilul filmului pe care doriti sa-l modificati este: ";
    titlu = cin_string();

    cout << "Anul aparitiei filmului pe care doriti sa-l modificati este: ";
    an_aparitie = cin_int();

    service.sterge(titlu, an_aparitie);

    cout << "Film sters cu succes!\n";
}

void UI::filtrareUI() const{
    string criteriu;
    cout << "Introduceti litera criteriului dupa care doriti sa fie filtrate filmele: ";
    criteriu = cin_string();
    if (criteriu == "a"){
        string titlu;
        cout << "Introduceti titlul dupa care doriti sa fie filtrate filmele: ";
        titlu = cin_string();
        printMovies(service.filtrareTitlu(titlu));
    }
    else if (criteriu == "b"){
        int an;
        cout << "Introduceti anul dupa care doriti sa fie filtrate filmele: ";
        an = cin_int();
        printMovies(service.filtrareAnAparitie(an));
    }
    else
        cout << "Criteriu invalid! \n";

}

void UI::sortareUI() const{
    string criteriu, rev;
    bool reverse;

    cout << "Introduceti modul in care doriti sa fie sortate filmele (i/ii): ";
    rev = cin_string();
    if (rev == "i")
        reverse = false;
    else
        reverse = true;

    cout << "Introduceti litera criteriului dupa care doriti sa fie sortate filmele: ";
    criteriu = cin_string();
    if (criteriu == "a"){
        printMovies(service.GenericSort(Service::cmpTitlu, reverse));
    }
    else if (criteriu == "b"){
        printMovies(service.GenericSort(Service::cmpActor, reverse));
    }
    else if (criteriu == "c"){
        printMovies(service.GenericSort(Service::cmpAnGen, reverse));
    }
    else
        cout << "Criteriu invalid! \n";
}


void UI::adaugaWishlistUI() const {
    string titlu;
    int an_aparitie;

    cout << "Introduceti titlul filmului pe care doriti sa-l adaugati in wishlist: ";
    titlu = cin_string();

    cout << "Introduceti anul aparititie filmului pe care doriti sa-l adaugati in wishlist: ";
    an_aparitie = cin_int();

    service.addtoWishlist(titlu, an_aparitie);
    cout << "Film adaugat in wishlist cu succes !" << endl;
    cout << "Numarul de filme din wishlist este: " << service.sizeOfWishlist();
}


void UI::golesteWishlistUI() const {
    service.emptyWishlist();
    cout << "Wishlist golit cu succes !";
}


void UI::adaugaRandomWishlistUI() const {
    int howMany;
    cout << "Introduceti numarul de filme adaugate random: ";
    howMany = cin_int();

    int howManyMoviesWasAdd = service.addRandomMoviesToWishlist(howMany);
    if (howMany == howManyMoviesWasAdd) {
        cout << "Cele " << howMany << " filme au fost adaugate cu succes in wishlist !"<< endl;
        cout << "Numarul de filme din wishlist este: " << service.sizeOfWishlist();
    }
    else {
        cout << "In wishlista au fost adaugate doar " << howManyMoviesWasAdd << " filme !"<< endl;
        cout << "Numarul de filme din wishlist este: " << service.sizeOfWishlist();
    }
}


void UI::afiseazaWishlistUI() const {
    printMovies(service.getWishlist());
}


void UI::saveWishlistToFileUI() const {
    string fileName;
    cout << "Introduceti numele fisierului in care doriti sa salvati wishlist-ul: ";
    fileName = cin_string();

    service.saveWishlistToFile(fileName);
    cout << "Wishlist salvat cu succes !";
}

void UI::yearStatisticUI() const {
    cout << 2;
    map<int, Movie_DTO> map = service.yearStatistic();
    for (const auto& pair : map ) {
        cout << "In anul "<< pair.first << " au aparut " <<  pair.second.get_count() << " filme" << endl;
    }
}

void UI::undoUI() const {
    service.undo();
    cout << "Undo realizat cu succes ! ";
}


void UI::runUI() const{
    int running = 1;
    int command;
    //addDefaultMovies();
    while (running){
        //system("clear");
        prinMenu();
        cout << "Introduceti numarul comenzii: ";
        command = cin_int();
        if (command > 15)
            cout << "Comanda invalida!\n";
        else
        if (command == 15)
            running = 0;
        else {
            try {
                (this->*commands.at(command))();
            }
            catch (RepoException &re) {
                cout << re.getMesajDeEroare();
            }
            catch (ValidatorException &ve) {
                cout << ve.getMesajDeEroare();
            }
            catch (UndoException &ve) {
                cout << ve.getMesajDeEroare();
            }
        }
    }


}