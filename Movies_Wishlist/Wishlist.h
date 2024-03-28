#pragma once
#include "../Domain/Movie.h"
#include "../Exceptii/Exceptii.h"
#include "../Interfata/Observer/Observer-Observable.h"

#include <vector>

using std::vector;

class Wishlist: public Observable {
private:
    vector<Movie> WishlistMovies;

    /**
     * Return true if exist a movie in wishlist with the same title and year of aparition
     * @return
     */
    bool exist(const string&, const int&);

public:
    /**
     * Default constructor of the class Wishlist
     */
    Wishlist() = default;


    /**
     * Add a movie in Wishlist
     * @param mov: the movie to add (Movie)
     */
    void addMovieToWishlist(const Movie& mov);


    /**
     * Remove all the movies from the Wishlist
     */
    void emptyWishlist();


    /**
    * Add a number of random movies iin Wishlist
    * @param howMany : the number of the movies to add (int)
    * @param theSourceofMovies : the vector from where we take the random movies
    */
    int addRandomMovies(vector<Movie> theSourceofMovies, int howMany);


    /**
    * Returns a vector with all movies from Wishlist
    */
    const vector<Movie>& getAllMoviesFromWishlist() const;


    /**
    * Returns the numer of the movies from Wishlist
    */
    int sizeOfWishlist() const ;


    /**
    * Save all movies from Wishlist in a file
    * @param fileName: the name of the file where to save the movies (string)
    */
    void saveWishlistToFile(const string& fileName) const ;

};