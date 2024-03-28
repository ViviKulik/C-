#pragma once
#include <string>

using std::string;
/**
 * Clasa de exceptii generica pentru aplicatie
 */
class MovieException{
private:
    string mesaj_de_eroare;
public:
    /**
     * Constructorul
     * @param mesaj_de_eroarre
     */
    explicit MovieException(const string& mesaj_de_eroarre): mesaj_de_eroare{ mesaj_de_eroarre }{}

    /**
     * Returneaza mesajul de eroare
     */
    const string& getMesajDeEroare() const;
};

/**
 * Clasa de exceptii pentru Repository
 */
class RepoException : public MovieException{
public:
    explicit RepoException(const string& mesaj_de_eroarre): MovieException(mesaj_de_eroarre) {}

};


/**
 * Clasa de exceptii pentru Validator
 */
class ValidatorException : public MovieException {
public:
    explicit ValidatorException(const string& mesaj_de_eroaree): MovieException(mesaj_de_eroaree) {};

};


/**
 * Clasa de exceptii pentru Wishlist
 */
class WishlistException : public MovieException {
public:
    explicit WishlistException(const string& mesaj_de_eroarre): MovieException(mesaj_de_eroarre) {};
};


/**
 * Clasa de exceptii pentru Wishlist
 */
class UndoException : public MovieException {
public:
    explicit UndoException(const string& mesaj_de_eroarre) : MovieException(mesaj_de_eroarre) {};
};