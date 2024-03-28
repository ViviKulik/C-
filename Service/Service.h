#pragma once

#include "../Repository/Repository.h"
#include "../Validator/Validator.h"
#include "../Exceptii/Exceptii.h"
#include "../Movies_Wishlist/Wishlist.h"
#include "../Undo/Undo.h"

#include <functional>
#include <map>

using std::function;
using std::map;

class Service {
private:
    //repo-ul filmelor(persisitent)
    AbstractRepository& repo;

    //validatorul filmelor
    FilmValidator& val;

    //whish list-ul curent (nepersistent)
    Wishlist currentWishlist;

    //lista cu pointeri de UndoAction
    vector<UndoAction*> undoActionList;

public:
    /**
    * Constructor
    * @param repo
    * @param val
    */
    Service(AbstractRepository& repo, FilmValidator& val) : repo{repo }, val {val } {}

    /**
    * Constructorul de copiere
    * @param ser
    */
    Service(const Service& ser) = delete;


    /**
    * returneaza numarul de filme din lista
    */
    int size();


    /**
    * Returneaza un vector cu toate filmele din lista
    */
    vector<Movie> getAllMovies() const ;


    /**
    * Adauga un film cu titilul titilu, cu genu gen, cu anul aparitie an_aparitie si cu personul principl
    * personaj_principla
    * @param titlu: string
    * @param gen: string
    * @param an_aparitie: int
    * @param persina_principal: string
    *
    * @throws:
    *      RepoExceprions daca exista deja un film cu titilul respectvi si cu acelasi an al aparitiei
    *      ValidationError daca filmul nu trece de validari
    */
    void adauga(const string& titlu, const string& gen, const int& an_aparitie, const string& personaj_principal);


    /**
    * Modifica un film cu noile atribute gen si personaj principal, titlul si anul aparitie fiind unic identificabile
    * @param titlu: string
    * @param gen: string
    * @param an_aparitie: int
    * @param persina_principal: string
    *
    * @throws:
    *      RepoException daca exista deja un film cu titilul respectvi si cu acelasi an al aparitiei
    *      ValidationException daca filmul nu trece de validari
    */
    const Movie& modifica(const string& titlu, const string& gen, const int& an_aparitie, const string& personaj_principal);


    /**
    * Returneaza filmul care are are anul egal cu an_aparitie si titlul egal cu titlu
    *
    * @throws:
    *      RepoException daca nu exista un film cu titlul si cu anul respectiv
    */
    const Movie& cauta(const string& titlu, const int& an_aparitie) const ;

    /**
    * Sterge filmul cu anul egal cu an_aparitie si titlul egal cu titlu
    *
    *@throws:
    *      RepoException daca nu exista un film cu titlul si cu anul respectiv
    */
    const Movie& sterge(const string& titlu, const int& an_aparitie);


    /**
    *Filtreaza lista de filme dupa filtrul introdus la apelare
    */
    vector<Movie> Filtrare(function<bool(const Movie&)> filtru) const;


    /**
    * Filtreaza lista de filme dupa titlu
    * Returneaza o lista cu toate filtrele care au titlu egal cu cel introdus de utilizator
    */
    vector<Movie> filtrareTitlu(const string& titlu) const;


    /**
    * Filtreaza lista de filme dupa anul aparitiei
    * Returneaza o lista cu toate filtrele care au anul aparitiei egal cu cel introdus de utilizator
    */
    vector<Movie> filtrareAnAparitie(const int& an) const;

    /**
    * Comparator in functie de Titlu
    * @param f1 Movie
    * @param f2 Movie
    * @param reverse bool
    * @return
    */
    static bool cmpTitlu(const Movie& f1, const Movie& f2, bool reverse) ;


    /**
    * Comparator in functie de Actorul Principal
    * @param f1 Movie
    * @param f2 Movie
    * @param reverse bool
    * @return
    */
    static bool cmpActor(const Movie& f1, const Movie& f2, bool reverse);


    /**
    * Comparator in functie de An si Gen
    * @param f1 Movie
    * @param f2 Movie
    * @param reverse bool
    * @return
    */
    static bool cmpAnGen(const Movie& f1, const Movie& f2, bool reverse);


    /**
    * Sortare generica cu functie de comparator data ca parametru
    * @return
    */
    vector<Movie> GenericSort(const function<bool(const Movie&, const Movie&, bool)>&, bool);


    /**
    * Adauga un film cu titlul titlu si anul aparitieti an_aparitie in Wishlist
    * @param an_aparitie: anul aparitiei filmului de adaugat
    * @param titlu: titlul filmului de adaugat
    */
    void addtoWishlist(const string& titlu, const int& an_aparitie);


    /**
    * Sterge toate filmele din Wishlist
    */
    void emptyWishlist() ;


    /**
    * Adauga un numar random de filme in Wishlist
    * @param howMany: cate filme trebuie adaugate(int)
    */
    int addRandomMoviesToWishlist(int howMany) ;


    /**
     * Returneaza un vector cu toate filmele din Wishlist
     */
    const vector<Movie>& getWishlist() const ;


    /**
    * Returneaza toate filmele din Wishlist
    */
    int sizeOfWishlist() const ;


    /**
    * Salveaza toate filmele din Wishlist in fisierul introdus de utilizator
    * @param fileName: numele fisierului(string)
    */
    void saveWishlistToFile(const string& fileName) const ;

    /**
     * Returneaza o statsistica in functie de anul filmelor
     */
    map<int, Movie_DTO> yearStatistic();

    /**
     * Da undo la ultima operatie efectuata care mofifica repo-ul
     */
    void undo();

    Wishlist& getCurrentWishlist() {
        return currentWishlist;
    }
};