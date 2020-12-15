/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-23            ///
********************************************/



#include <iostream>
#include <cstring>
#include <cstdio>
#include "Movie.h"
#include "File.h"
using namespace std;


namespace sdds {

    Movie movies[50];


    // loads all the moves into the global array of structures.
    bool loadMovies() {
        Movie mv;
        int mnum = 0; // number of movies read
        bool ok = true;
        if (openFile("movies.dat")) {
            while (ok && mnum < 50) {
                ok = readTitle(mv.m_title) &&
                    readYear(&mv.m_year) &&
                    readMovieRating(mv.m_rating) &&
                    readDuration(&mv.m_duration) &&
                    readGenres(mv.m_genres) &&
                    readConsumerRating(&mv.m_consumerRating);
                if (ok) movies[mnum++] = mv;
            }
            closeFile();
        }
        return mnum == 50;
    }

    // returns true is the genre arg is substring of any of the
    // genres of the target of the mvp (Movie*) arg.
    bool hasGenre(const Movie* mvp, const char genre[]) {
        int i = 0;
        bool found = false;
        while (!found && mvp->m_genres[i][0]) {
            if (strstr(mvp->m_genres[i++], genre)) {
                found = true;
            }
        }
        return found;
    }

    // displays the movie info
    void displayMovie(const Movie* mvp) {
        int i = 1;
        cout << mvp->m_title << " [" << mvp->m_year << "], "
            << mvp->m_rating << ", duration: " << mvp->m_duration << " minutes, Rating: " << mvp->m_consumerRating << "/10" << endl << "    (" << mvp->m_genres[0];
        while (mvp->m_genres[i][0]) {
            cout << ", " << mvp->m_genres[i++];
        }
        cout << ")" << endl;
    }

    // displays all the movies containing the genre arg
    void displayMoviesWithGenre(const char genre[]) {
        int i, j;
        for (i = 0, j = 1; i < 50; i++) {
            if (hasGenre(&movies[i], genre)) {
                cout << j++ << "- ";
                displayMovie(&movies[i]);
            }
        }
        if (j == 1) {
            cout << "No match found for: " << genre << endl;
        }
    }
}