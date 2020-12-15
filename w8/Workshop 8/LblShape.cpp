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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label() const {
		return m_label;
	}
	LblShape::LblShape() {
	}
	LblShape::LblShape(const char* Cstr) {
		delete[] m_label;
		m_label = new char[strlen(Cstr) + 1];
		strcpy(m_label, Cstr);
	}
	LblShape::~LblShape() {
		delete[] m_label;
	}
	void LblShape::getSpecs(std::istream& istr) {
		char label[21];
		istr.get(label, 21, ',');

		delete[] m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
		istr.ignore();
	}
}