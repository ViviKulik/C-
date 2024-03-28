#include "Teste.h"
#include <cassert>
#include <iostream>

using namespace std;

//------------------------------------------------TESTE DOMAIN---------------------------------------------------------

void Teste::Ruleaza_teste_domain(){
    Movie film{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    assert(film.getTitlu() == "Harry Potter");
    assert(film.getGen() == "Fantastic");
    assert(film.getAnAparitie() == 1997);
    assert(film.getActorPrincipal() == "Daniel Radcliffe");

    film.setActorPrincipal("Daniel");
    film.setGen("Actiune");
    assert(film.getGen() == "Actiune");
    assert(film.getActorPrincipal() == "Daniel");
}


//--------------------------------------------------TESTE VALIDATOR------------------------------------------------------

void Teste::Ruleaza_teste_validator(){
    Movie f1{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    Movie f2{"", "Fantastic", 199, "Daniel Radcliffe"};
    Movie f3{"Harry Potter", "", 1997, "Daniel Radcliffe"};
    Movie f4{"", "", 197, ""};

    FilmValidator validator;
    validator.valideaza(f1);
    try{
        validator.valideaza(f2);
        assert(false);
    }
    catch (ValidatorException&){
        assert(true);
    }

    try{
        validator.valideaza(f3);
        assert(false);
    }
    catch (ValidatorException&){
        assert(true);
    }

    try{
        validator.valideaza(f4);
        assert(false);
    }
    catch (ValidatorException&){
        assert(true);
    }

}


//------------------------------------------------TESTE REPO---------------------------------------------------------

void Teste::Ruleaza_teste_repository(){
    Ruleaza_teste_adauga_repo();
    Ruleaza_teste_cauta_repo();
    Ruleaza_teste_modifica_repo();
    Ruleaza_teste_sterge_repo();
}

void Teste::Ruleaza_teste_adauga_repo(){
    MoviesFileRepository repo{"RepositoryTeste.txt"};
    repo.emptyFile();
    Movie f1{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    Movie f2{"Titanic", "Romantic", 1997, "LEonardo DiCaprio"};
    Movie f3{"Titanic", "Drama", 1997, "Leonardo DiCaprio"};
    Movie f4{"U", "drama", 2015, "John"};

    repo.getAllMovies();

    repo.add_repo(f1);
    repo.add_repo(f2);
    repo.add_repo(f4);
    assert(repo.size() == 3);

    try{
        repo.add_repo(f3);
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }
    assert(repo.size() == 3);
}

void Teste::Ruleaza_teste_cauta_repo(){
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    Movie f1{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    Movie f2{"Titanic", "Romantic", 1997, "LEonardo DiCaprio"};
    Movie f3{"Titanic", "Drama", 1997, "Leonardo DiCaprio"};
    Movie f4{"U", "drama", 2015, "John"};

    repo.add_repo(f4);
    repo.add_repo(f1);
    repo.add_repo(f2);
    assert(repo.size() == 3);

    assert(f1 == repo.find_repo(f1.getTitlu(), f1.getAnAparitie()));
    assert(repo.find_repo(f2.getTitlu(), f2.getAnAparitie()) == f2);

    try{
        repo.find_repo("aa", 12);
        assert(false);
    }
    catch (RepoException&){
        assert(true);
    }
}


void Teste::Ruleaza_teste_modifica_repo(){
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    Movie f1{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    Movie f2{"Titanic", "Romantic", 1997, "LEonardo DiCaprio"};
    Movie f1_modificat{"Harry Potter", "Aventura", 1997, "Daniel"};
    Movie f4{"U", "drama", 2015, "John"};

    repo.add_repo(f4);
    repo.add_repo(f1);
    repo.add_repo(f2);

    repo.modify_repo(f1_modificat);
    assert(repo.size() == 3);

    assert(f1_modificat == repo.find_repo(f1.getTitlu(), f1.getAnAparitie()));

}


void Teste::Ruleaza_teste_sterge_repo(){
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    Movie f1{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    Movie f2{"Titanic", "Romantic", 1997, "LEonardo DiCaprio"};
    Movie f4{"U", "drama", 2015, "John"};


    repo.add_repo(f1);
    repo.add_repo(f2);
    repo.add_repo(f4);
    assert(repo.size() == 3);

    repo.delete_repo(f2);
    assert(repo.size() == 2);

    repo.delete_repo(f1);
    assert(repo.size() == 1);

}



//------------------------------------------------TESTE LAB REPO--------------------------------------------------------

void Teste::Ruleaza_teste_Labrepository(){
    Ruleaza_teste_adauga_Labrepo();
    Ruleaza_teste_cauta_Labrepo();
    Ruleaza_teste_modifica_Labrepo();
    Ruleaza_teste_sterge_Labrepo();
}

void Teste::Ruleaza_teste_adauga_Labrepo(){
    LabRepository repo0{0};

    Movie f1{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    Movie f2{"Titanic", "Romantic", 1997, "LEonardo DiCaprio"};
    Movie f3{"Titanic", "Drama", 1997, "Leonardo DiCaprio"};
    Movie f4{"U", "drama", 2015, "John"};

    try {
        repo0.getAllMovies();
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }

    try {
        repo0.add_repo(f1);
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }
    try {
        repo0.add_repo(f2);
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }
    try {
        repo0.add_repo(f3);
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }
    try {
        repo0.size();
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }

    LabRepository repo1{1.1};

    repo1.getAllMovies();

    repo1.add_repo(f1);
    repo1.add_repo(f2);
    repo1.add_repo(f4);
    assert(repo1.size() == 3);

    try{
        repo1.add_repo(f3);
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }
    assert(repo1.size() == 3);

    assert(repo1.getAllMovies().size() == 3);

}

void Teste::Ruleaza_teste_cauta_Labrepo(){
    LabRepository repo0{0};
    Movie f1{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    Movie f2{"Titanic", "Romantic", 1997, "LEonardo DiCaprio"};
    Movie f3{"Titanic", "Drama", 1997, "Leonardo DiCaprio"};
    Movie f4{"U", "drama", 2015, "John"};

    try {
        repo0.find_repo(f1.getTitlu(), f1.getAnAparitie());
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }

    LabRepository repo1{1.1};
    repo1.add_repo(f4);
    repo1.add_repo(f1);
    repo1.add_repo(f2);
    assert(repo1.size() == 3);

    assert(f1 == repo1.find_repo(f1.getTitlu(), f1.getAnAparitie()));
    assert(repo1.find_repo(f2.getTitlu(), f2.getAnAparitie()) == f2);

    try{
        repo1.find_repo("aa", 12);
        assert(false);
    }
    catch (RepoException&){
        assert(true);
    }
}


void Teste::Ruleaza_teste_modifica_Labrepo(){
    LabRepository repo0{0};
    Movie f1{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    Movie f2{"Titanic", "Romantic", 1997, "LEonardo DiCaprio"};
    Movie f1_modificat{"Harry Potter", "Aventura", 1997, "Daniel"};
    Movie f4{"U", "drama", 2015, "John"};

    try {
        repo0.modify_repo(f1_modificat);
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }

    LabRepository repo1{1.1};
    repo1.add_repo(f1);
    repo1.add_repo(f2);

    repo1.modify_repo(f1_modificat);
    assert(repo1.size() == 2);

    try {
        repo1.modify_repo(f4);
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }

    assert(f1_modificat == repo1.find_repo(f1.getTitlu(), f1.getAnAparitie()));
}


void Teste::Ruleaza_teste_sterge_Labrepo(){
    LabRepository repo0{0};
    Movie f1{"Harry Potter", "Fantastic", 1997, "Daniel Radcliffe"};
    Movie f2{"Titanic", "Romantic", 1997, "LEonardo DiCaprio"};
    Movie f4{"U", "drama", 2015, "John"};

    try {
        repo0.delete_repo(f1);
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }

    LabRepository repo1{1.1};

    repo1.add_repo(f1);
    repo1.add_repo(f2);
    repo1.add_repo(f4);
    assert(repo1.size() == 3);

    repo1.delete_repo(f2);
    assert(repo1.size() == 2);

    repo1.delete_repo(f1);
    assert(repo1.size() == 1);
}


//------------------------------------------------TESTE SERVICE---------------------------------------------------------

void Teste::Ruleaza_teste_service() {
    Ruleaza_teste_adauga();
    Ruleaza_teste_cauta();
    Ruleaza_teste_modifica();
    Ruleaza_teste_sterge();
    Ruleaza_teste_filtrare_generica();
    Ruleaza_teste_sortare_generica();
    Ruleaza_teste_adauga_wishlist();
    Ruleaza_teste_goleste_wishlist();
    Ruleaza_teste_adauga__random_wishlist();
    Ruleaza_teste_salveaza_in_fisier_wishlist();
    Ruleaza_teste_yearStatitics();
}


void Teste::Ruleaza_teste_adauga(){
    string titlu1 = "Harry Potter", titlu2 = "Scarface", titlu3 = "No country for all men", titlu_invalid;
    string gen1 = "Fantastic", gen2 = "Actiune", gen3 = "Trailer", gen_invalid;
    int an1 = 1997, an2 = 1985, an3=2007, an_invalid = 200;
    string actor1 = "Daniel Radcliffe", actor2 = "Alpacino", actor3 = "Javiere Bardem", actor_invalid;

    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};

    assert(service.size() == 0);

    service.adauga(titlu1, gen1, an1, actor1);
    service.adauga(titlu2, gen2, an2, actor2);
    service.adauga(titlu3, gen3, an3, actor3);

    assert(service.size() == 3);

    try{
        service.adauga(titlu_invalid, gen_invalid, an_invalid, actor_invalid);
        assert(false);
    }
    catch (ValidatorException&){
        assert(true);
    }

    try{
        service.adauga(titlu3, gen3, an3, actor3);
        assert(false);
    }
    catch (RepoException&){
        assert(true);
    }
}


void Teste::Ruleaza_teste_cauta(){
    string titlu1 = "Harry Potter", titlu2 = "Scarface", titlu3 = "No country for all men", titlu_invalid;
    string gen1 = "Fantastic", gen2 = "Actiune", gen3 = "Trailer", gen_invalid;
    int an1 = 1997, an2 = 1985, an3=2007;
    string actor1 = "Daniel Radcliffe", actor2 = "Alpacino", actor3 = "Javiere Bardem", actor_invalid;

    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};

    assert(service.size() == 0);

    service.adauga(titlu1, gen1, an1, actor1);
    service.adauga(titlu2, gen2, an2, actor2);
    service.adauga(titlu3, gen3, an3, actor3);

    Movie film1{titlu1, gen1, an1, actor1};
    assert(film1 == service.cauta(titlu1, an1));

    try{
        service.cauta("a", 2000);
        assert(false);
    }
    catch (RepoException&){
        assert(true);
    }
}


void Teste::Ruleaza_teste_modifica(){
    string titlu1 = "Harry Potter", titlu2 = "Scarface", titlu3 = "No country for all men", titlu_invalid;
    string gen1 = "Fantastic", gen2 = "Actiune", gen3 = "Trailer", gen_invalid;
    int an1 = 1997, an2 = 1985, an3=2007;
    string actor1 = "Daniel Radcliffe", actor2 = "Alpacino", actor3 = "Javiere Bardem", actor_invalid;

    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};

    assert(service.size() == 0);

    service.adauga(titlu1, gen1, an1, actor1);
    service.adauga(titlu2, gen2, an2, actor2);
    service.adauga(titlu3, gen3, an3, actor3);

    service.modifica(titlu3, "Actiune", an3, "John");
    Movie film_modificat{titlu3, "Actiune", an3, "John"};
    assert(service.cauta(titlu3, an3) == film_modificat);

    try{
        service.modifica(titlu3, "", an3, "");
        assert(false);
    }
    catch (ValidatorException&){
        assert(true);
    }

    try{
        service.modifica("b", gen2, an3, actor1);
        assert(false);
    }
    catch (RepoException&){
        assert(true);
    }

    vector<Movie> toate_filmele = service.getAllMovies();
    assert(toate_filmele.size() == 3);
}


void Teste::Ruleaza_teste_sterge(){
    string titlu1 = "Harry Potter", titlu2 = "Scarface", titlu3 = "No country for all men", titlu_invalid;
    string gen1 = "Fantastic", gen2 = "Actiune", gen3 = "Trailer", gen_invalid;
    int an1 = 1997, an2 = 1985, an3=2007;
    string actor1 = "Daniel Radcliffe", actor2 = "Alpacino", actor3 = "Javiere Bardem", actor_invalid;

    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};

    assert(service.size() == 0);

    service.adauga(titlu1, gen1, an1, actor1);
    service.adauga(titlu2, gen2, an2, actor2);
    service.adauga(titlu3, gen3, an3, actor3);

    assert(service.size() == 3);
    service.sterge(titlu3, an3);
    assert(service.size() == 2);
    service.sterge(titlu2, an2);
    assert(service.size() == 1);
    service.sterge(titlu1, an1);
    assert(service.size() == 0);

    try{
        service.sterge(titlu1, an3);
        assert(false);
    }
    catch (RepoException&){
        assert(true);
    }
}

void Teste::Ruleaza_teste_filtrare_generica(){
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};
    service.adauga("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman");
    service.adauga("The Godfather", "Actiune", 1972 , "Al Pacino");
    service.adauga("12 Angry Men", "Drama", 1957, "Henry Fonda");
    service.adauga("Schimdler's List", "Drama", 1994, "Liam Neeson");
    service.adauga("Forrest Gump", "Comedie", 1994, "Tom Hanks");
    service.adauga("The Matrix", "Actiune", 1994, "Keanu Reeves");
    service.adauga("Se7en", "Crima", 1995, "Brad Pitt");
    service.adauga("Interstellar", "Aventura", 2014 , "Matthew McConaughey");
    service.adauga("The Pianist", "Razboi", 2002, "Adrien Brody");
    service.adauga("The Godfather", "Romantic", 1942, "Denirro");

    vector<Movie> lista_filtrata = service.filtrareTitlu("The Godfather");
    assert(lista_filtrata.size() == 2);
    Movie f1{"The Godfather", "Actiune", 1972 , "Al Pacino"};
    assert(lista_filtrata[0] == f1);
    Movie f2{"The Godfather", "Drama", 1942, "Denniro"};
    assert(lista_filtrata[1] == f2);

    lista_filtrata = service.filtrareTitlu("Se7en");
    assert(lista_filtrata.size() == 1);

    lista_filtrata = service.filtrareAnAparitie(1994);
    assert(lista_filtrata.size() == 3);
    assert(lista_filtrata[0] == Movie("Schimdler's List", "Drama", 1994, "Liam Neeson"));
    assert(lista_filtrata[1] == Movie("Forrest Gump", "Comedie", 1994, "Tom Hanks"));
    assert(lista_filtrata[2] == Movie("The Matrix", "Actiune", 1994, "Keanu Reeves"));
}


void Teste::Ruleaza_teste_sortare_generica(){
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};
    service.adauga("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman");
    service.adauga("The Godfather", "Actiune", 1972 , "Al Pacino");
    service.adauga("12 Angry Men", "Drama", 1957, "Henry Fonda");
    service.adauga("Schimdler's List", "Drama", 1994, "Liam Neeson");
    service.adauga("Forrest Gump", "Comedie", 1994, "Tom Hanks");
    service.adauga("The Matrix", "Actiune", 1994, "Keanu Reeves");
    service.adauga("Se7en", "Crima", 1995, "Brad Pitt");
    service.adauga("Interstellar", "Aventura", 2014 , "Matthew McConaughey");
    service.adauga("The Pianist", "Razboi", 2002, "Adrien Brody");
    service.adauga("The Godfather", "Romantic", 1942, "Denirro");

    vector<Movie> lista_sortata;
    lista_sortata = service.GenericSort(Service::cmpTitlu, false);
    assert(lista_sortata[0] == Movie("12 Angry Men", "Drama", 1957, "Henry Fonda"));
    assert(lista_sortata[1] == Movie("Forrest Gump", "Comedie", 1994, "Tom Hanks"));
    assert(lista_sortata[2] == Movie("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman"));

    lista_sortata = service.GenericSort(Service::cmpActor, true);
    assert(lista_sortata[3] == Movie("Schimdler's List", "Drama", 1994, "Liam Neeson"));
    assert(lista_sortata[0] == Movie("Forrest Gump", "Comedie", 1994, "Tom Hanks"));
    assert(lista_sortata[1] == Movie("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman"));
    assert(lista_sortata[2] == Movie("Interstellar", "Aventura", 2014 , "Matthew McConaughey"));


    lista_sortata = service.GenericSort(Service::cmpAnGen, true);
    assert(lista_sortata[3] == Movie("Schimdler's List", "Drama", 1994, "Liam Neeson"));
    assert(lista_sortata[4] == Movie("Forrest Gump", "Comedie", 1994, "Tom Hanks"));
    assert(lista_sortata[6] == Movie("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman"));
    assert(lista_sortata[0] == Movie("Interstellar", "Aventura", 2014 , "Matthew McConaughey"));


    lista_sortata = service.GenericSort(Service::cmpTitlu, true);
    assert(lista_sortata[9] == Movie("12 Angry Men", "Drama", 1957, "Henry Fonda"));
    assert(lista_sortata[8] == Movie("Forrest Gump", "Comedie", 1994, "Tom Hanks"));
    assert(lista_sortata[7] == Movie("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman"));
    assert(lista_sortata[6] == Movie("Interstellar", "Aventura", 2014 , "Matthew McConaughey"));

    lista_sortata = service.GenericSort(Service::cmpActor, false);
    assert(lista_sortata[6] == Movie("Schimdler's List", "Drama", 1994, "Liam Neeson"));
    assert(lista_sortata[9] == Movie("Forrest Gump", "Comedie", 1994, "Tom Hanks"));
    assert(lista_sortata[8] == Movie("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman"));
    assert(lista_sortata[7] == Movie("Interstellar", "Aventura", 2014 , "Matthew McConaughey"));

    lista_sortata = service.GenericSort(Service::cmpAnGen, false);
    assert(lista_sortata[6] == Movie("Schimdler's List", "Drama", 1994, "Liam Neeson"));
    assert(lista_sortata[5] == Movie("Forrest Gump", "Comedie", 1994, "Tom Hanks"));
    assert(lista_sortata[3] == Movie("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman"));
    assert(lista_sortata[9] == Movie("Interstellar", "Aventura", 2014 , "Matthew McConaughey"));


}

void Teste::Ruleaza_teste_adauga_wishlist() {
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};
    service.adauga("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman");
    service.adauga("The Godfather", "Actiune", 1972 , "Al Pacino");
    service.adauga("12 Angry Men", "Drama", 1957, "Henry Fonda");
    service.adauga("Schimdler's List", "Drama", 1994, "Liam Neeson");
    service.adauga("Forrest Gump", "Comedie", 1994, "Tom Hanks");
    service.adauga("The Matrix", "Actiune", 1994, "Keanu Reeves");
    service.adauga("Se7en", "Crima", 1995, "Brad Pitt");
    service.adauga("Interstellar", "Aventura", 2014 , "Matthew McConaughey");
    service.adauga("The Pianist", "Razboi", 2002, "Adrien Brody");
    service.adauga("The Godfather", "Romantic", 1942, "Denirro");

    assert(service.sizeOfWishlist() == 0);
    service.addtoWishlist("Inchisoarea ingerilor", 1982);
    assert(service.sizeOfWishlist() == 1);
    service.addtoWishlist("The Godfather", 1942);
    assert(service.sizeOfWishlist() == 2);

    vector<Movie> lista = service.getWishlist();
    assert(lista.size() == 2);

    try {
        service.addtoWishlist("Inchisoarea ingerilor", 1982);
        assert(false);
    }
    catch (WishlistException&) {
        assert(true);
    }

    try {
        service.addtoWishlist("Aa", 1999);
        assert(false);
    }
    catch (RepoException&) {
        assert(true);
    }
}


void Teste::Ruleaza_teste_goleste_wishlist() {
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};
    service.adauga("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman");
    service.adauga("The Godfather", "Actiune", 1972 , "Al Pacino");
    service.adauga("The Godfather", "Romantic", 1942, "Denirro");

    assert(service.sizeOfWishlist() == 0);
    service.addtoWishlist("Inchisoarea ingerilor", 1982);
    assert(service.sizeOfWishlist() == 1);
    service.addtoWishlist("The Godfather", 1942);
    assert(service.sizeOfWishlist() == 2);

    service.emptyWishlist();
    assert(service.sizeOfWishlist() == 0);
}


void Teste::Ruleaza_teste_adauga__random_wishlist() {
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};
    service.adauga("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman");
    service.adauga("The Godfather", "Actiune", 1972 , "Al Pacino");
    service.adauga("12 Angry Men", "Drama", 1957, "Henry Fonda");
    service.adauga("Schimdler's List", "Drama", 1994, "Liam Neeson");
    service.adauga("Forrest Gump", "Comedie", 1994, "Tom Hanks");
    service.adauga("The Matrix", "Actiune", 1994, "Keanu Reeves");
    service.adauga("Se7en", "Crima", 1995, "Brad Pitt");
    service.adauga("Interstellar", "Aventura", 2014 , "Matthew McConaughey");
    service.adauga("The Pianist", "Razboi", 2002, "Adrien Brody");
    service.adauga("The Godfather", "Romantic", 1942, "Denirro");

    assert(service.sizeOfWishlist() == 0);
    int nr = service.addRandomMoviesToWishlist(6);
    assert(nr == 6);
    assert(service.sizeOfWishlist() == 6);
    nr = service.addRandomMoviesToWishlist(7);
    assert(nr == 4);
    assert(service.sizeOfWishlist() == 10);
}


void Teste::Ruleaza_teste_salveaza_in_fisier_wishlist() {
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};
    service.adauga("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman");
    service.adauga("The Godfather", "Actiune", 1972 , "Al Pacino");
    service.adauga("12 Angry Men", "Drama", 1957, "Henry Fonda");
    service.adauga("Schimdler's List", "Drama", 1994, "Liam Neeson");
    service.adauga("Forrest Gump", "Comedie", 1994, "Tom Hanks");
    service.adauga("The Matrix", "Actiune", 1994, "Keanu Reeves");
    service.adauga("Se7en", "Crima", 1995, "Brad Pitt");
    service.adauga("Interstellar", "Aventura", 2014 , "Matthew McConaughey");
    service.adauga("The Pianist", "Razboi", 2002, "Adrien Brody");
    service.adauga("The Godfather", "Romantic", 1942, "Denirro");

    int nr = service.addRandomMoviesToWishlist(6);
    assert(service.sizeOfWishlist() == 6);
    service.saveWishlistToFile("/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/WishlistTeste.txt");
    assert(service.sizeOfWishlist() == 6);

    ifstream fin("/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/WishlistTeste.txt");
    string line;
    int numberOfLines = 0;
    while (getline(fin, line)) {
        numberOfLines++;
    }
    assert(numberOfLines == 6);
}


void Teste::Ruleaza_teste_yearStatitics() {
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};
    service.adauga("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman");
    service.adauga("The Godfather", "Actiune", 1957 , "Al Pacino");
    service.adauga("12 Angry Men", "Drama", 1957, "Henry Fonda");
    service.adauga("Schimdler's List", "Drama", 1994, "Liam Neeson");
    service.adauga("Forrest Gump", "Comedie", 1994, "Tom Hanks");
    service.adauga("The Matrix", "Actiune", 1994, "Keanu Reeves");
    service.adauga("Se7en", "Crima", 1995, "Brad Pitt");
    service.adauga("Interstellar", "Aventura", 2014 , "Matthew McConaughey");
    service.adauga("The Pianist", "Razboi", 2002, "Adrien Brody");
    service.adauga("The Godfather", "Romantic", 1942, "Denirro");

    map<int, Movie_DTO> map = service.yearStatistic();
    assert(map.size() == 7);
    assert(map[1957].get_count() == 2);
    assert(map[2014].get_count() == 1);
    assert(map[1994].get_count() == 3);
}


//------------------------------------------------TESTE UNDO---------------------------------------------------------

void Teste::Ruleaza_teste_undo() {
    MoviesFileRepository repo{"/Users/dianamoldovan/CLionProjects/OOP/LAB_08_OOP /Teste/RepositoryTeste.txt"};
    repo.emptyFile();
    FilmValidator val;
    Service service{repo, val};
    service.adauga("Inchisoarea ingerilor", "Emotionant", 1982, "Morgan Freeman");
    service.adauga("The Godfather", "Actiune", 1957 , "Al Pacino");
    assert(service.size() == 2);
    service.sterge("The Godfather", 1957 );
    assert(service.size() == 1);
    service.undo();
    assert(service.size() == 2);
    service.modifica("Inchisoarea ingerilor", "Lacrimogen", 1982, "Morgan Freeman");
    Movie mov = service.cauta("Inchisoarea ingerilor", 1982);
    assert(mov.getGen() == "Lacrimogen");
    service.undo();
    mov = service.cauta("Inchisoarea ingerilor", 1982);
    assert(mov.getGen() == "Emotionant");
    assert(service.size() == 2);
    service.undo();
    assert(service.size() == 1);
    service.undo();
    assert(service.size() == 0);
    try {
        service.undo();
        assert(false);
    }
    catch (UndoException&) {
        assert(true);
    }
}


//------------------------------------------------TESTE EXCEPTII---------------------------------------------------------

void Teste::Ruleaza_teste_execeptii(){
    RepoException exceptie1("mesaj de eroare pt test");
    ValidatorException exceptie2("Mesaj de eroare pt test");
    WishlistException exceptie3("Mesaj de eroare pt test");
    UndoException exceptie4("Mesaj de eroare pt test");
    assert(exceptie1.getMesajDeEroare() == "mesaj de eroare pt test");
    assert(exceptie2.getMesajDeEroare() == "Mesaj de eroare pt test");
    assert(exceptie3.getMesajDeEroare() == "Mesaj de eroare pt test");
    assert(exceptie4.getMesajDeEroare() == "Mesaj de eroare pt test");
}


//------------------------------------------------TESTE TOATE TESTELE}-------------------------------------------------

void Teste::Ruleaza_toate_testele() const {
    Ruleaza_teste_domain();
    cout << "Teste Domain trecute cu succes!\n";
    Ruleaza_teste_validator();
    cout << "Teste Validator trecute cu succes!\n";
    Ruleaza_teste_execeptii();
    cout << "Teste Exceptii trecute cu succes!\n";
    Ruleaza_teste_repository();
    cout << "Teste Repository trecute cu succes!\n";
    Ruleaza_teste_Labrepository();
    cout << "Teste LabRepository trecute cu succes!\n";
    Ruleaza_teste_service();
    cout << "Teste Service trecute cu succes!\n";
    Ruleaza_teste_undo();
    cout << "Teste Undo trecute cu succes!\n";
}