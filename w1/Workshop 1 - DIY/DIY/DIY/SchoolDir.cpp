/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-27            ///
********************************************/



#include <iostream>
#include "School.h"
#include "File.h"

using namespace std;
using namespace sch;

void flushkeys();
bool yes();


int main() {

    bool done = false;
    char schCode[6];
    loadSchool();
    cout << "Seneca School Extension search." << endl << endl;
    while (!done) {
        cout << "Enter the School code: ";
        cin >> schCode;
        flushkeys();
        displaySchoolsWithExt(schCode);
        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}


// flushes the keyboard
void flushkeys() {
    while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
    char ch = cin.get();
    flushkeys();
    return ch == 'y' || ch == 'Y';
}