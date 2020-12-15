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

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
    int getInt();
    int getInt(const char* type, int num = -1); // customized getInt
    int getTime(); // returns the time of day in minutes

    extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                       // all the files which include: "utils.h" 
                       //(you will learn this in detail in oop345)
}
#endif // !SDDS_UTILS_H_
