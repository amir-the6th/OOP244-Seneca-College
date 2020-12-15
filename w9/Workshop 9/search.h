/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-27            ///
|*******************************************|
|*************   Workshop 9   **************|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
	template <typename T>
	bool search(const T array[], int arrSize, const char* key, Collection<T>& obj) {
		bool found = false;
		int i;
		for (i = 0; i < arrSize; i++) {
			if (array[i] == key) {
				found = true;
				obj.add(array[i]);
			}
		}
		return found;
	}
}
#endif