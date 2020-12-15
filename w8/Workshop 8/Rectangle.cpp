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
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle() : LblShape(){
	}
	Rectangle::Rectangle(const char* Cstring, int width, int height) : LblShape(Cstring){
		int strLen = strlen(label());
		m_width = width;
		m_height = height;
		if (m_height < 3 || m_width < (strLen + 2)) {
			m_height = 0;
			m_width = 0;
		}
	}
	void Rectangle::getSpecs(std::istream& istr){
		LblShape::getSpecs(istr);
		istr >> m_width;
		//istr.ignore(',');
		istr.ignore();
		istr >> m_height;
		istr.ignore();
	}
	void Rectangle::draw(std::ostream& ostr) const{
		ostr << '+' << setw((streamsize)m_width - 1) << setfill('-') << '+' << endl;
		ostr << '|' << setw((streamsize)m_width - 2) << left << setfill(' ') << label() << '|' << endl;
		for (int i = 0; i < m_height - 3; i++) {
			ostr << '|' << setw((streamsize)m_width - 1) << setfill(' ') << right << '|' << endl;
		}
		ostr << '+' << setw((streamsize)m_width - 1) << setfill('-') << '+';
	}
}