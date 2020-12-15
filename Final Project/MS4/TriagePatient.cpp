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
#include <cstring>
#include "TriagePatient.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;
 
   TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
	   m_symptoms = nullptr;
	   nextTriageTicket++;
   }

   char TriagePatient::type() const {
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const {
	   Patient::csvWrite(ostr);
	   ostr << ',' << m_symptoms;
	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr) {
	   char Cstring[511];
	   delete[] m_symptoms;
	   Patient::csvRead(istr);
	   istr.ignore(2000, ',');
	   istr.get(Cstring, 511, '\n');
	   m_symptoms = new char[strlen(Cstring) + 1];
	   strcpy(m_symptoms, Cstring);
	   nextTriageTicket = number() + 1;
	   return istr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr) const {
	   if (fileIO()) {
		   csvWrite(ostr);
	   }
	   else {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr);
		   ostr << endl << "Symptoms: " << m_symptoms << endl;
	   }
	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr) {
	   char Cstring[511];
	   if (fileIO()) {
		   csvRead(istr);
	   }
	   else {
		   delete[] m_symptoms;
		   Patient::read(istr);
		   cout << "Symptoms: ";
		   istr.get(Cstring, 511, '\n');
		   istr.ignore();
		   m_symptoms = new char[strlen(Cstring) + 1];
		   strcpy(m_symptoms, Cstring);
	   }
	   return istr;
   }

   TriagePatient::~TriagePatient() {
	   delete[] m_symptoms;
   }

}