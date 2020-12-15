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
#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;
  

   CovidPatient::CovidPatient() : Patient(nextCovidTicket) {
	   nextCovidTicket++;
   }

   char CovidPatient::type() const {
	   return 'C';
   }

   std::ostream& CovidPatient::csvWrite(std::ostream& ostr) const {
	   Patient::csvWrite(ostr);
	   return ostr;
   }

   std::istream& CovidPatient::csvRead(std::istream& istr) {
	   Patient::csvRead(istr);
	   nextCovidTicket = number() + 1;
	   return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr) const {
	   if (fileIO()) {
		   csvWrite(ostr);
	   }
	   else {
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr);
		   ostr << endl;
	   }
	   return ostr;
   }

   std::istream& CovidPatient::read(std::istream& istr) {
	   if (fileIO()) {
		   csvRead(istr);
	   }
	   else {
		   Patient::read(istr);
	   }
	   return istr;
   }

}