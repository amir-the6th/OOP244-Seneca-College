/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-11            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Vehicle.h"
using namespace std;

namespace sdds {
	Vehicle::Vehicle(const char* plate , int year): m_year(year) {
		strcpy(m_plateNo, plate);
		strcpy(m_address, "Factory");
	}
	/*Vehicle::Vehicle(const char* address) {
		strcpy(m_address, address);
	}*/
	Vehicle::~Vehicle() {
	}
	void Vehicle::moveTo(const char* address) {
		if (m_address != address) {
			cout << '|' << setw(8) << right << m_plateNo << '|';
			cout << " |" << setw(20) << right << m_address;
			cout << " ---> ";
			cout << setw(20) << left << address << '|' << endl;
		}
		strcpy(m_address, address);
	}
	std::ostream& Vehicle::write(std::ostream& os)const {
		os << "| " << m_year << " | " << m_plateNo << " | " << m_address;
		return os;
	}
	std::istream& Vehicle::read(std::istream& in) {
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_plateNo;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Vehicle& V) {
		return V.write(os);
	}
	std::istream& operator>>(std::istream& istr, Vehicle& V) {
		return V.read(istr);
	}
}