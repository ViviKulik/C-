#pragma once

#include "../Repository/AbstractRepository.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>


using std::to_string;
using std::find_if;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

class MoviesFileRepository : public AbstractRepository {
private:
    vector<Movie> AllMovies;
    string FilePath;

public:
    /**
     * Constructorul defaul care este aoelat atunci cand nu avem parametrii
     */
    explicit MoviesFileRepository(const string& path) : FilePath{path} {};

    /**
     * Constructor de copiere
     */
    MoviesFileRepository(const MoviesFileRepository& repo_de_copiat) = delete;

    /**
     * Destructor
     */
    ~MoviesFileRepository() = default;


    /**
     * Returneaza o lista cu toate filmele
     */
    vector<Movie>getAllMovies() override ;


    /**
     * Returneaza numarul de filme din lista
     */
    int size() override ;

    /**
     * adauga un film in listaa
     * @param film: filmul pe care il adaugam  (Movie)
     * @return -
     *
     * @trows: RepoException daca exista deja in lista un film cu acelasi nume si acelasi an al aparitiei
     */
    void add_repo(const Movie& film) override ;

    /**
     * Returneaza true daca un film cu acelasi titlu si acelasi an al aparitiei se afla in lista
     */
    bool exists(const Movie& film);


    /**
     * Cauta un film in lista
     *
     * Returneaza : - filmu(unic) cu titilul si anul aparitiei introdus daca exista in lista un astfel de film
     *              - RepoException daca nu exista
     *
     * @param titlu: titilul dupa care se  cauta
     * @param an_aparitie : anul dupa care se cauta
     */
    const Movie& find_repo(const string& titlu, const int& an_aparitie) override ;


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
    void modify_repo(const Movie& film) override ;

    /**
     * Sterge un film din lista
     * Sterge filmul dupa titlu si an al aparitiei
     *
     *@param titlu, an aparitie: caracteristicile unic identificabile ale filmul care trebuie sters
     *
     * @throw: RepoException daca nu exista nici un fil cu titlul si anul aparitiei ca al filmului introdus
     */
    void delete_repo(const Movie& film_de_sters) override ;

    /**
     * Salveaza toate filme in fisier
     */
    void writeAllToFile() const ;

    /**
     * Adauga toate filmele din fisier in repo
    */
    void readAllFromFile();

    /**
     * Goleste un fiser (pt teste)
     */
    void emptyFile();

};