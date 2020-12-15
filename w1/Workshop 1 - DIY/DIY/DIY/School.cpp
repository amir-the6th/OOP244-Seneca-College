/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-27            ///
********************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include "School.h"
#include "File.h"
using namespace std;


namespace sch {

	School school[24];

	// loads all the school codes and extensions into the global array of structures.
	bool loadSchool() {
		
		School sch;
		int snum = 0; //number of schools read
		bool ok = true;

		if (openFile("schools.dat")) {
			while (ok && snum < 24) {
				ok = readCode(sch.s_code) &&
					readExt(&sch.s_ext);
				if (ok) school[snum++] = sch;
			}
			closeFile();
		}
		return snum == 24;
	}

	// returns true if the code entered is substring of any of the
	// codes in our file (School*)
	bool hasCode(const School* sch, const char schCode[]) {
		bool found = false;
			if (strstr(sch->s_code, schCode)) {
				found = true;
			}
		return found;
	}

	// displays the school extension
	void displayExt(const School* sch) {
		cout << "416 491 5050 x " << sch->s_ext << endl;
	}

	void displaySchoolsWithExt(const char schCode[]) {
		int i, j;
		for (i = 0, j = 1; i < 24; i++) {
			if (hasCode(&school[i], schCode)) {
				displayExt(&school[i]);
				j++;
			}
		}
		if (j == 1) {
			cout << schCode << " School code not found!" << endl;
		}
	}
}