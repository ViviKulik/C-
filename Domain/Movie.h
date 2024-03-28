#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::string;

class Movie {

private:

    string titlu;
    string gen;
    int an_aparitie = 0;
    string actor_principal;


public:
    /**
     * Constructorul default care este apelat atunci cand nu avem parametrii
     */
    Movie() = default;

    /**
     * Constructorul de Movie cu atributele:
     *          titlu
     *          gen
     *          an_aparitie
     *          actor_principal
     */
    Movie(string titlu, string gen, int an_aparitie2, string actor_principal):
            titlu{ titlu }, gen{ gen }, an_aparitie { an_aparitie2 }, actor_principal { actor_principal }{};

    /**
     * Costructor de copiere
     */
    Movie(const Movie& ot) : titlu{ot.titlu }, gen{ot.gen }, an_aparitie {ot.an_aparitie },
                             actor_principal { ot.actor_principal }{
        //cout << "Called copy constructor!!! \n";
    }

//---------------------------------------------------------------------------------------------------------------------
    //GET-ERE
    /**
     * Returneaza titlul unui film
     */
    string getTitlu() const;

    /**
     * Returneaza genul unui film
     */
    string getGen() const;

    /**
     * Returneaza anul aparitiei unui film
     */
    int getAnAparitie() const;

    /**
     * Returneaza titlul actorul principal al unui film
     */
    string getActorPrincipal() const;


//---------------------------------------------------------------------------------------------------------------------
    /**
     * SET-ere pt toate atributele care nu sunt unic identificabile
     */

    /**
     * Seteaza noul gen la filmu
     */
    void setGen(const string& gen_nou);


    /**
     * Seteaza noul gen la filmu
     */
    void setActorPrincipal( const string& actor_nou);

//---------------------------------------------------------------------------------------------------------------------
    /**
    * Suprasriere operator
    *
    * returneaza true daca doua filme sunt egale
    * doua filme sunte geale daca au acelasi nume si acelasi an al apartitie
    */
    bool operator==(const Movie& f) const;
};


//---------------------------------------------------------DTO--------------------------------------------------------

class Movie_DTO {
private:
    int year;
    int count;
public:
    /**
     * Constructor for Movie_DTO class
     * @param year
     * @param count
     */
    Movie_DTO() = default;
    Movie_DTO(int year, int count) : year{year}, count{count} {};

    /**
     * Increment the count with 1
     */
    void increment_count() {
        count++;

    }

    /**
     * Return the count of the DTO object
     */
    int get_count() const{
        return count;
    }
};
