/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-20            ///
|*******************************************|
|*************   Workshop 8   **************|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#include <iostream>
#include "Shape.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Shape& ro) {
		ro.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Shape& ro) {
		ro.getSpecs(is);
		return is;
	}
}