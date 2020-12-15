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
#include <iomanip>
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line() : LblShape() {
	}
	Line::Line(const char* Cstring, int len) : LblShape(Cstring) {
		m_length = len;
	}
	void Line::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore();
	}
	void Line::draw(std::ostream& ostr) const {
		if (m_length > 0 && label() != nullptr) {
			ostr << label() << endl;
			ostr << setw(m_length) << setfill('=') << '=';
		}
	}
}
