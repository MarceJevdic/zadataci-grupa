#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Film {
private:
    string title;
    string director;
    string genre;

public:
    Film(string t, string d, string g) {
        title = t;
        director = d;
        genre = g;
    }

    string getGenre() {
        return genre;
    }

    void ispisFilma() {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Genre: " << genre << endl;
    }
};

class MovieList {
private:
    vector<Film> filmovi;

public:
    void DodajFilm(Film f) {
        filmovi.push_back(f);
    }

    void IzdvojiPoZanru(string zanr) {
        cout << "Filmovi izdvojeni po specificnom zanru:\n";
        for (int i = 0; i < filmovi.size(); i++) {
            if (filmovi[i].getGenre() == zanr) {
                filmovi[i].ispisFilma();  // ispravak!
                cout << endl;
            }
        }
    }
};
int main() {
    MovieList lista;
    lista.DodajFilm(Film("Inception", "Christopher Nolan", "Sci-Fi"));
    lista.DodajFilm(Film("Interstellar", "Christopher Nolan", "Sci-Fi"));
    lista.DodajFilm(Film("The Godfather", "Francis Ford Coppola", "Crime"));
    lista.DodajFilm(Film("Gladiator", "Ridley Scott", "Historical"));
    lista.IzdvojiPoZanru("Sci-Fi");
    return 0;
}
