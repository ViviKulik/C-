#include "Repository.h"

int MoviesFileRepository::size(){
    return (int)AllMovies.size();
}


vector<Movie> MoviesFileRepository::getAllMovies() {
    readAllFromFile();
    return AllMovies;
}


void MoviesFileRepository::add_repo(const Movie& film){
    readAllFromFile();

    if (exists(film)){
        throw RepoException("Exista deja in lista un film cu titlul "+film.getTitlu()+
                            " aparut in anul "+to_string(film.getAnAparitie())+" !\n");
    }
    AllMovies.push_back(film);

    writeAllToFile();
}


bool MoviesFileRepository::exists(const Movie& film) {
    try{
        find_repo(film.getTitlu(), film.getAnAparitie());
        return true;
    }
    catch (RepoException&) {
        return false;
    }
}


const Movie& MoviesFileRepository::find_repo(const string& titlu, const int& an_aparitie) {
    readAllFromFile();

    /*for (const Movie& f: this->AllMovies){
        if (f.getTitlu() == titlu && f.getAnAparitie() == an_aparitie){
            return f;
        }
    }
    throw RepoException("Movie inexistent");*/

    auto MovieMatching = [=](const Movie& film) {
        return film.getTitlu() == titlu && film.getAnAparitie() == an_aparitie;
    };

    auto f = find_if(AllMovies.begin(), AllMovies.end(), MovieMatching);

    if ( f != AllMovies.end()) {
        return *f;
    }
    else {
        throw RepoException("Film inexistent");
    }
}

void MoviesFileRepository::modify_repo(const Movie& film){
    readAllFromFile();

    for (auto& f : AllMovies){
        if (f == film){
            f = film;
            break;
        }
    }

    writeAllToFile();
}

void MoviesFileRepository::delete_repo(const Movie& film_de_sters){
    readAllFromFile();

    for (int i=0; i < (int)AllMovies.size(); i++){
        if (AllMovies[i] == film_de_sters){
            AllMovies.erase(AllMovies.begin() + i);
            break;
        }
    }

    writeAllToFile();
}


void MoviesFileRepository::writeAllToFile() const {
    ofstream fout(FilePath);

    if (!fout.is_open())
        throw RepoException("Fisierul Repository.txt nu a putu fi deschis!!");

    for (const auto& movie: AllMovies) {
        fout << movie.getTitlu() << "," << movie.getGen() << "," << movie.getAnAparitie() << "," <<
             movie.getActorPrincipal() << endl;
    }

    fout.close();
}


void MoviesFileRepository::readAllFromFile() {
    ifstream fin (FilePath);

    if (fin.fail())
        throw RepoException("Fisierul Repository.txt nu a putu fi deschis!!");

    AllMovies.clear();

    string line;
    string atribut;
    vector<string> atribute;

    while (getline(fin, line)) {
        stringstream linestream(line);
        while (getline(linestream, atribut, ',')) {
            atribute.push_back(atribut);
            //atribute[0] = ttilu
            //atribute[1] = gen
            //atribute[2] = an_aparitie
            //atribute[3] = actor principal
        }
        Movie mov{atribute[0], atribute[1], std::stoi(atribute[2]),
                  atribute[3]};
        AllMovies.push_back(mov);
        atribute.clear();
    }

    fin.close();
}


void MoviesFileRepository::emptyFile() {
    ofstream fout(FilePath);
    fout.close();
}