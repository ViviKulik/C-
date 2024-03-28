#include "Wishlist.h"

#include <random>
#include <fstream>

using std::shuffle;
using std::random_device;
using std::default_random_engine;
using std::ofstream;
using std::endl;


bool Wishlist::exist(const string& titlu, const int& an_aparitie) {
    auto MovieMatching = [=](const Movie &film) {
        return film.getTitlu() == titlu && film.getAnAparitie() == an_aparitie;
    };

    auto f = find_if(WishlistMovies.begin(), WishlistMovies.end(), MovieMatching);

    if (f != WishlistMovies.end()) {
        return true;
    } else {
        return false;
    }
}

void Wishlist::addMovieToWishlist(const Movie& mov) {
    if (!exist(mov.getTitlu(), mov.getAnAparitie())) {
        WishlistMovies.push_back(mov);
        notify();
    }
    else {
        throw WishlistException("Filmul este deja in Wishlist!");
    }
}


void Wishlist::emptyWishlist() {
    WishlistMovies.clear();
    notify();
}


int Wishlist::addRandomMovies(vector<Movie> theSourceofMovies, int howMany) {
    int howManyMoviesWasAdd = 0;
    shuffle(theSourceofMovies.begin(), theSourceofMovies.end(),
            default_random_engine(random_device{}()));
    while(howManyMoviesWasAdd < howMany && !theSourceofMovies.empty()) {
        if (!exist(theSourceofMovies.back().getTitlu(),theSourceofMovies.back().getAnAparitie())) {
            WishlistMovies.push_back(theSourceofMovies.back()); //take the last movie from the shuffle vector
            howManyMoviesWasAdd++;
        }
        theSourceofMovies.pop_back(); //erase the last movie
    }
    notify();
    return howManyMoviesWasAdd;
}


const vector<Movie>& Wishlist::getAllMoviesFromWishlist() const {
    return WishlistMovies;
}


int Wishlist::sizeOfWishlist() const {
    return (int)WishlistMovies.size();
}


void Wishlist::saveWishlistToFile(const string& fileName) const {
    ofstream fout (fileName);
    for ( const auto& movie: WishlistMovies) {
        fout << movie.getTitlu() << ", " << movie.getGen() << ", " << movie.getAnAparitie() << ", " <<
             movie.getActorPrincipal() << endl;
    }
    fout.close();
}