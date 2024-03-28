#include "Movie.h"

string Movie::getTitlu() const{
    return titlu;
}

string Movie::getGen() const{
    return gen;
}

int Movie::getAnAparitie() const{
    return an_aparitie;
}

string Movie::getActorPrincipal() const{
    return actor_principal;
}


//---------------------------------------------------------------------------------------------------------------------

void Movie::setGen(const string& gen_nou){
    gen = gen_nou;
}

void Movie::setActorPrincipal(const string& actor_nou){
    actor_principal = actor_nou;
}

//---------------------------------------------------------------------------------------------------------------------

bool Movie::operator==(const Movie& f) const {
    return f.getAnAparitie() == an_aparitie && f.getTitlu() == titlu;
}