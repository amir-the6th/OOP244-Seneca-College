/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-28            ///
|*******************************************|
|**********  Final Project - MS4  **********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {
	ostream& operator<<(ostream& os, const IOAble& ro) {
		return	ro.write(os);
	}
	istream& operator>>(istream& is, IOAble& ro) {
		return ro.read(is);
	}
}