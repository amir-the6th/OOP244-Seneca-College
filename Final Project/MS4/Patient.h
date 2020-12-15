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

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds {
	class Patient :public IOAble {
		char* p_name = nullptr;
		int p_ohipNo = 0;
		Ticket p_ticket;
		bool p_fromFile;
	public:
		Patient(const int tickNo = 0, const bool fromFile = false);
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		virtual ~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(const bool fromF);
		bool operator==(const char type)const;
		bool operator==(const Patient& patient2)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_PATIENT_H_
