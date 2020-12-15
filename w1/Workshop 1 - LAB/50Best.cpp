/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-23            ///
********************************************/



#include <iostream>
#include "Movie.h"
#include "File.h"

using namespace std;
using namespace sdds;


void flushkeys();
bool yes();

    // flushes the keyboard
    void flushkeys() {
        while (cin.get() != '\n');
    }

    int main() {
        bool done = false;
        char genre[128];
        loadMovies();
        cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
        while (!done) {
            cout << "Enter the movie genre to start the search: ";
            cin >> genre;
            flushkeys();
            displayMoviesWithGenre(genre);
            cout << "Do another search? (Y)es: ";
            done = !yes();
            cout << endl;
        }
        cout << "Goodbye!" << endl;
        return 0;
    }

    // returns true if user enter y or Y
    bool yes() {
        char ch = cin.get();
        flushkeys();
        return ch == 'y' || ch == 'Y';
    }
