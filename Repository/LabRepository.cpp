#include "LabRepository.h"


int LabRepository::size(){
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_real_distribution<> dist(0.0, 1.0);
    double random_prob = dist(mt);// numar aleator intre [0, 1]


    if (random_prob < prob) {
        return (int)AllMovies.size();
    }
    else {
        throw RepoException("Nu s-a putut efectua getAllMovies!\n");
    }
}


vector<Movie> LabRepository::getAllMovies() {
#include <random>
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_real_distribution<> dist(0.0, 1.0);
    double random_prob = dist(mt);// numar aleator intre [0, 1]


    if (random_prob < prob) {
        vector<Movie> movies;
        for (const auto& movie: AllMovies) {
            movies.push_back(movie.second);
        }
        return movies;
    }
    else {
        throw RepoException("Nu s-a putut efectua getAllMovies!\n");
    }
}


void LabRepository::add_repo(const Movie& film){
    string key = film.getTitlu() + to_string(film.getAnAparitie());

    std::mt19937 mt{ std::random_device{}() };
    std::uniform_real_distribution<> dist(0, 1);
    double random_prob = dist(mt);// numar aleator intre [0, 1]

    if (random_prob < prob) {
        if (AllMovies.find(key) != AllMovies.end()) {
            throw RepoException("Exista deja in lista un film cu titlul " + film.getTitlu() +
                                " aparut in anul " + to_string(film.getAnAparitie()) + " !\n");
        }
        AllMovies.insert({key, film});
    }
    else {
        throw RepoException("Nu s-a putut efectua add_repo!\n");
    }
}


const Movie& LabRepository::find_repo(const string& titlu, const int& an_aparitie) {
    string key = titlu + to_string(an_aparitie);

    std::mt19937 mt{ std::random_device{}() };
    std::uniform_real_distribution<> dist(0, 1);
    double random_prob = dist(mt);// numar aleator intre [0, 1]

    if (random_prob < prob) {

        if (AllMovies.find(key) != AllMovies.end()) {
            return AllMovies[key];
        } else {
            throw RepoException("Film inexistent");
        }

    }
    else {
        throw RepoException("Nu s-a putut efectua find_repo!\n");
    }
}

void LabRepository::modify_repo(const Movie& film){
    string key = film.getTitlu() + to_string(film.getAnAparitie());

    std::mt19937 mt{ std::random_device{}() };
    std::uniform_real_distribution<> dist(0, 1);
    double random_prob = dist(mt);// numar aleator intre [0, 1]

    if (random_prob < prob) {
        if ( AllMovies.find(key) != AllMovies.end()) {
            AllMovies[key] = film;
        }
        else {
            throw RepoException("Film inexistent");
        }
    }
    else {
        throw RepoException("Nu s-a putut efectua modify_repo!\n");
    }
}

void LabRepository::delete_repo(const Movie& film_de_sters){
    string key = film_de_sters.getTitlu() + to_string(film_de_sters.getAnAparitie());

    std::mt19937 mt{ std::random_device{}() };
    std::uniform_real_distribution<> dist(0, 1);
    double random_prob = dist(mt);// numar aleator intre [0, 1]

    if (random_prob < prob) {
        {
            auto i = AllMovies.find(key);
            AllMovies.erase(i);
        }
    }
    else {
        throw RepoException("Nu s-a putut efectua delete_repo!\n");
    }
}
