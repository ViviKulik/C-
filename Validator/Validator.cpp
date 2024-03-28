#include "Validator.h"
#include <vector>
#include <ctime>

using std::vector;
using std::time_t;

void FilmValidator::valideaza(const Movie &film) const {
    std::time_t timp = std::time(nullptr);
    std::tm* data_ora = std::localtime(&timp);

    // Obține anul curent
    int anul_curent = data_ora->tm_year + 1900;

    string errors ;
    if (film.getTitlu().length() <1)
        errors += "Titlul introdus este invalid!\n";
    if (film.getGen().length() < 3)
        errors += "Genul este invalid! \n";
    if (film.getAnAparitie() < 1888 || film.getAnAparitie()> (data_ora->tm_year + 1900))
        errors += "Anul aparitiei este invalid!\n";
    if (film.getActorPrincipal().length() < 2)
        errors += "Numele actorului introdus este invalid! \n";

    if (errors.length() > 0)
        throw ValidatorException( errors);
}