/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-27            ///
********************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "School.h"
#include "File.h"

using namespace std;

namespace sch {

    FILE* fptr;

    // opens the data file and returns true is successful
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // reads the school code from the global fptr File pointer
    // returns true if successful
    bool readCode(char code[]) {
        return fscanf(fptr, "%s ", code) == 1;
    }

    // reads the related extension from the global fptr File pointer
    // returns true if successful
    bool readExt(int* ext) {
        return fscanf(fptr, "%d", ext) == 1;
    }

}