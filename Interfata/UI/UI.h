#pragma once

#include "../../Service/Service.h"
#include <unordered_map>

class UI;
typedef void(UI::* functieUI)() const;

using std::unordered_map;

class UI {
private:
    Service& service;

    unordered_map<int , functieUI> commands = {
            {1, &UI::printAllMoviesUI},
            {2, &UI::adaugaUI},
            {3, &UI::modificaUI},
            {4, &UI::cautaUI},
            {5, &UI::stergeUI},
            {6, &UI::filtrareUI},
            {7, &UI::sortareUI},
            {8, &UI::adaugaWishlistUI},
            {9, &UI::golesteWishlistUI},
            {10, &UI::adaugaRandomWishlistUI},
            {11, &UI::afiseazaWishlistUI},
            {12, &UI::saveWishlistToFileUI},
            {13, &UI::yearStatisticUI},
            {14, &UI::undoUI}
    };


public:
    /**
     * Constructor
     * @param service
     */
    explicit UI(Service& service) : service{ service }{};

    /**
     * Constructor de copiere
     */
    UI(UI& ot) = delete;


    /**
     * citeste un an int pana cat utilizatorul introduce corect datele
     */
    static int cin_int();


    /**
     * citeste un string
     */
    static string cin_string();


    /**
     * Printeaza meniul de tip consola pt utilizator
     */
    static void prinMenu();


    /**
     * Adauga 10 filme la decshiderea aplicatiei pt usurinta
     */
    void addDefaultMovies() const ;


    /**
     * Afiseaza atributele unui film
     */
    static void printMovie(const Movie& film);


    /**
     * Afiseaza toate filmele din lista
     */
    void printAllMoviesUI() const;


    /**
     * Afiseaza o lista de filme
     */
    static void printMovies(const vector<Movie>& filme);


    /**
     * Citeste datele de la utilizator pentru adaugarea unui film si returneaza mesajele de eroare daca acestea sunt
     * invlide
     */
    void adaugaUI() const;


    /**
     * Citeste datele de la utilizator pentru modificare unui obiesct si returneaza un mesaj de eroare daca acestea sunt
     * invalide
    */
    void modificaUI() const;


    /**
     * Citeste datele de la utilizator pentru cautarea unui obiesct si returneaza un mesaj de eroare daca acestea sunt
     * invalide
     */
    void cautaUI() const;

    /**
     * Citeste datele de la utilizator pentru stergerea unui obiesct si returneaza un mesaj de eroare daca acestea sunt
     * invalide
     */
    void stergeUI() const;


    /**
     * Citeste filtrul dupa care sa fie filtrate filmele, apeleaza functia de filtrare corespunzatoare si afiseaza
     * filmele care au trecut de filtru
     */
    void filtrareUI() const;

    /**
    * Citeste criteriul dupa care sa fie sortate filmele, apeleaza functia de filtrare corespunzatoare si afiseaza
    * filmele sortate
    */
    void sortareUI() const;


    /**
    * Citeste titlul si anul aparitiei al filmului de adaugat in Wishlist
    */
    void adaugaWishlistUI() const;


    /**
    * Goleste Wishlist-ul
    */
    void golesteWishlistUI() const;


    /**
    * Citeste numarul de filme de adauga random in Wishlist
    */
    void adaugaRandomWishlistUI() const;


    /**
    * Afiseaza filmele din Wishlist
    */
    void afiseazaWishlistUI() const;


    /**
     * Citeste numele fisierului in care va fi salvata lista de dorinte
     */
    void saveWishlistToFileUI() const;

    /**
     * Afiseaza un raport al filmelor dupa anul aparitiei
     */
    void yearStatisticUI() const;

    /**
     * Apeleaza functia de undo din service
     */
    void undoUI() const;

public:
    void runUI() const;
};