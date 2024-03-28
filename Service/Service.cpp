#include "Service.h"

using std::copy_if;
using std::sort;

int Service::size(){
    return repo.size();
}


vector<Movie> Service::getAllMovies() const {
    return repo.getAllMovies();
}


void Service::adauga(const string& titlu, const string& gen, const int& an_aparitie, const string& personaj_principal){
    Movie film_de_adaugat{titlu, gen, an_aparitie, personaj_principal};
    val.valideaza(film_de_adaugat);
    repo.add_repo(film_de_adaugat);
    undoActionList.push_back(new AddUndo{repo, film_de_adaugat});
}



const Movie& Service::modifica(const string& titlu, const string& gen, const int& an_aparitie, const string& personaj_principal){
    const Movie& film_de_modificat = repo.find_repo(titlu, an_aparitie);

    Movie film_modificat{titlu, gen, an_aparitie, personaj_principal};
    val.valideaza(film_modificat);

    undoActionList.push_back(new ModifyUndo(repo, film_de_modificat));
    repo.modify_repo(film_modificat);

    return film_de_modificat;
}



const Movie& Service::cauta(const string& titlu, const int& an_aparitie) const {
    return repo.find_repo(titlu, an_aparitie);
}


const Movie& Service::sterge(const string& titlu, const int& an_aparitie){
    const Movie& film_de_sters = repo.find_repo(titlu, an_aparitie);

    undoActionList.push_back(new DeleteUndo(repo, film_de_sters));
    repo.delete_repo(film_de_sters);

    return film_de_sters;
}


vector<Movie> Service::Filtrare(function<bool(const Movie&)> filtru) const{
    vector<Movie> filme_filtrate;
    const vector<Movie>& AllMovies = repo.getAllMovies();

    copy_if(AllMovies.begin(), AllMovies.end(), back_inserter(filme_filtrate), std::move(filtru));

    return filme_filtrate;
}


vector<Movie> Service::filtrareTitlu(const string& titlu) const{
    return Filtrare([titlu](const Movie& film){return film.getTitlu() == titlu;});
}


vector<Movie> Service::filtrareAnAparitie(const int& an) const{
    function<bool(const Movie&)> filtruAnAparitie = [an](const Movie& film){return film.getAnAparitie() == an;};
    return Filtrare(filtruAnAparitie);
}


bool Service::cmpTitlu(const Movie& f1, const Movie& f2, bool reverse) {
    if (!reverse)
        return f1.getTitlu() <= f2.getTitlu();
    else
        return f1.getTitlu() >= f2.getTitlu();
}


bool Service::cmpActor(const Movie& f1, const Movie& f2, bool reverse) {
    if (!reverse)
        return f1.getActorPrincipal() < f2.getActorPrincipal();
    else
        return f1.getActorPrincipal() > f2.getActorPrincipal();
}


bool Service::cmpAnGen(const Movie& f1, const Movie& f2, bool reverse) {
    if (!reverse) {
        if (f1.getAnAparitie() == f2.getAnAparitie())
            return f1.getGen() < f2.getGen();
        else
            return f1.getAnAparitie() < f2.getAnAparitie();
    }
    else {
        if (f1.getAnAparitie() == f2.getAnAparitie())
            return f1.getGen() > f2.getGen();
        else
            return f1.getAnAparitie() > f2.getAnAparitie();
    }
}


vector<Movie> Service::GenericSort(const function<bool(const Movie&, const Movie&, bool)>& cmp , bool reverse) {
    vector<Movie> toate_filmele {repo.getAllMovies()};
    sort(toate_filmele.begin(), toate_filmele.end(), [=](const Movie& m1, const Movie& m2) {
        return cmp(m1, m2, reverse);
    });
    return toate_filmele;
}


//------------------------------------------------WISHLIST--------------------------------------------------------------


void Service::addtoWishlist(const string& titlu, const int& an_aparitie) {
    Movie mov = repo.find_repo(titlu, an_aparitie);
    currentWishlist.addMovieToWishlist(mov);
}


void Service::emptyWishlist() {
    currentWishlist.emptyWishlist();
}


int Service::addRandomMoviesToWishlist(int howMany) {
    return currentWishlist.addRandomMovies(repo.getAllMovies(), howMany);
}


const vector<Movie>& Service::getWishlist() const {
    return currentWishlist.getAllMoviesFromWishlist();
}


int Service::sizeOfWishlist() const {
    return currentWishlist.sizeOfWishlist();
}


void Service::saveWishlistToFile(const string& fileName) const {
    currentWishlist.saveWishlistToFile(fileName);
}


//------------------------------------------------STATISTICS------------------------------------------------------------
map<int, Movie_DTO> Service::yearStatistic() {
    vector<Movie> allMovies = repo.getAllMovies();
    map<int, Movie_DTO> m;

    for (const auto& movie: allMovies) {
        int year = movie.getAnAparitie();
        auto poz = m.find(year);
        if (poz != m.end()) {
            //exista cheia in map
            m[year].increment_count();
        }
        else
        {
            //nu exitsa cheia
            m.insert(std::make_pair(year, Movie_DTO{year, 1}));
        }
    }
    return m;
}


//------------------------------------------------UNDO------------------------------------------------------------------

void Service::undo() {
    if ( undoActionList.empty() ) {
        throw UndoException("Nu se mai poate realizat Undo !");
    }

    UndoAction* undo_action = undoActionList.back();
    undo_action->doUndo();

    undoActionList.pop_back();
    delete undo_action;
}