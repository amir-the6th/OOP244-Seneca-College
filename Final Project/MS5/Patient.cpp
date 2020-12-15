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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int tickNo, bool fromFile) : p_ticket(tickNo), p_fromFile(fromFile) {
	}
	Patient::~Patient() {
		delete[] p_name;
	}
	bool Patient::fileIO() const {
		return p_fromFile;
	}
	void Patient::fileIO(const bool fromF) {
		p_fromFile = fromF;
	}
	bool Patient::operator==(const char type) const {
		return this->type() == type;
	}
	bool Patient::operator==(const Patient& patient2) const {
		return this->type() == patient2.type();
	}
	void Patient::setArrivalTime() {
		p_ticket.resetTime();
	}
	Patient::operator Time() const {
		return (Time)p_ticket;
	}
	int Patient::number() const {
		return p_ticket.number();
	}
	std::ostream& Patient::csvWrite(std::ostream& ostr) const {
		ostr << type() << ',' << p_name << ',' << p_ohipNo << ',';
		return p_ticket.csvWrite(ostr);
	}
	std::istream& Patient::csvRead(std::istream& istr) {
		char patientName[51]{};
		istr.get(patientName, 51, ',');
		delete[] p_name;
		p_name = new char[strlen(patientName) + 1];
		strcpy(p_name, patientName);
		istr.ignore(2000, ',');
		istr >> p_ohipNo;
		istr.ignore();
		return p_ticket.csvRead(istr);
	}
	std::ostream& Patient::write(std::ostream& ostr) const {
		ostr << "Ticket No: " << p_ticket.number() << ", Issued at: " << Time(*this) << '\n' << p_name << ", OHIP: " << p_ohipNo;
		return ostr;
	}
	std::istream& Patient::read(std::istream& istr) {
		char patientName[51]{};
		cout << "Name: ";
		istr.get(patientName, 51, '\n');
		delete[] p_name;
		p_name = new char[strlen(patientName) + 1];
		strcpy(p_name, patientName);
		istr.ignore();
		cout << "OHIP: ";
		p_ohipNo = getInt("OHIP");
		//p_ohipNo = getInt();
		//while(!(p_ohipNo >= 100000000 && p_ohipNo <= 999999999)) {
		//	cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
		//	p_ohipNo = getInt();
		//}
		return istr;
	}
}