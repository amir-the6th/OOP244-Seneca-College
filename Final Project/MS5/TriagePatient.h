/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-12-05            ///
|*******************************************|
|**********  Final Project - MS5  **********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#ifndef SDDS_TRIAGE_H
#define SDDS_TIRAGE_H
#include <iostream>
#include "Patient.h"
namespace sdds {
	class TriagePatient : public Patient {
		char* m_symptoms;
	public:
		TriagePatient();
		virtual char type()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		~TriagePatient();
	};

}
#endif // !SDDS_