#pragma once

#include "../Domain/Movie.h"
#include "../Exceptii/Exceptii.h"

class FilmValidator {
public:
    /**
     * Valideaza un film
     * returneaza eroare daca:
     *      titlul, genul sau personajul principal sunt siruri vide
     *      int daca anul aparitiei eiste mai mic decat 1888
     */
    void valideaza(const Movie& film) const ;
};