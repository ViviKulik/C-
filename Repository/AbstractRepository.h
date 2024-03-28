#pragma once

#include <vector>

#include "../Domain/Movie.h"
#include "../Exceptii/Exceptii.h"

using std::vector;


class AbstractRepository {
public:
    /**
     * Destructor
     */
    virtual ~AbstractRepository() = default;


    /**
    * Returneaza o lista cu toate filmele
    */
    virtual vector<Movie> getAllMovies() = 0 ;


    /**
     * Returneaza numarul de filme din lista
     */
    virtual int size() = 0 ;


    /**
     * adauga un film in listaa
     * @param film: filmul pe care il adaugam  (Movie)
     * @return -
     *
     * @trows: RepoException daca exista deja in lista un film cu acelasi nume si acelasi an al aparitiei
     */
    virtual void add_repo(const Movie& film) = 0 ;


    /**
     * Cauta un film in lista
     *
     * Returneaza : - filmu(unic) cu titilul si anul aparitiei introdus daca exista in lista un astfel de film
     *              - RepoException daca nu exista
     *
     * @param titlu: titilul dupa care se  cauta
     * @param an_aparitie : anul dupa care se cauta
     */
    virtual const Movie& find_repo(const string& titlu, const int& an_aparitie) = 0 ;


    /**
     * Modificam un film din lista
     * Modificam genul si actorul principal al unui film
     *
     *@param film: filmul cu noile date
     *
     * Returneaza: -
     *
     * @throw: RepoException daca nu exista nici un fil cu titlul si anul aparitiei ca al filmului introdus
     */
    virtual void modify_repo(const Movie& film) = 0 ;

    /**
     * Sterge un film din lista
     * Sterge filmul dupa titlu si an al aparitiei
     *
     *@param titlu, an aparitie: caracteristicile unic identificabile ale filmul care trebuie sters
     *
     * @throw: RepoException daca nu exista nici un fil cu titlul si anul aparitiei ca al filmului introdus
     */
    virtual void delete_repo(const Movie& film_de_sters) = 0 ;

};
