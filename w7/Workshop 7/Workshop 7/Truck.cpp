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
#include "Truck.h"
using namespace std;

namespace sdds {
	Truck::Truck(const char* plate, int year, double capacity, const char* address) : Vehicle(plate, year) {
		m_cargoLoad = 0;
		m_capacity = capacity;
		Vehicle::moveTo(address);
	}
	Truck::~Truck() {
	}
	bool Truck::addCargo(double cargo) {
		bool result = false;
		double temp = m_cargoLoad;
		m_cargoLoad += cargo;
		if (m_cargoLoad > m_capacity) {
			m_cargoLoad = m_capacity;
		}
		if (m_cargoLoad != temp) {
			result = true;
		}
		return result;
		/*
		if ((m_cargoLoad + cargo) == m_capacity) {
			result = true;
		}
		if ((m_cargoLoad + cargo) < m_capacity) {
			m_cargoLoad += cargo;
			result = true;
		}
		else {
			m_cargoLoad = m_capacity;
		}
		return result;
		*/	
	}
	bool Truck::unloadCargo() {
		bool result = false;
		if (m_cargoLoad > 0) {
			m_cargoLoad = 0;
			result = true;
		}
		return result;
	}
	std::ostream& Truck::write(std::ostream& os)const {
		Vehicle::write(os);
		os << " | " << m_cargoLoad << '/' << m_capacity;
		return os;
	}
	std::istream& Truck::read(std::istream& in) {
		Vehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargoLoad;
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Truck& T) {
		return T.write(os);
	}
	std::istream& operator>>(std::istream& istr, Truck& T) {
		return T.read(istr);
	}
}