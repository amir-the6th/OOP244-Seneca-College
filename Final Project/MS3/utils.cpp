/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-22            ///
|*******************************************|
|**********  Final Project - MS3  **********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    int getInt() {
        int value;
        bool badEntry;
        char nextChar;
        do {
            badEntry = false;
            cin >> value;
            if (cin.fail()) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(3000, '\n');
                badEntry = true;
            }
            else {
                nextChar = cin.get();
                if (nextChar != '\n') {
                    cout << "Only enter an integer, try again: ";
                    cin.ignore(3000, '\n');
                    badEntry = true;
                }
            }
        } while (badEntry);
        return value;
    }
    int getInt(const char* type, int num) {
        int value;
        value = getInt();
        if (type == "OHIP") {
            while (!(value >= 100000000 && value <= 999999999)) {
                cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
                cin.clear();
                value = getInt("OHIP");
            }
        }
        else if (type == "MENU") {
            while (!(value >= 0 && value <= num)) {
                cin.clear();
                //cin.ignore(1000, '\n');
                cout << "Invalid value enterd, retry[0 <= value <= " << num << "]: ";
                value = getInt("MENU");
            }
        }
        return value;
    }
}