/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-11            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include <iostream>
#include "Vehicle.h"
namespace sdds {
	class Truck : public Vehicle {
		double m_capacity;
		double m_cargoLoad;
	public:
		Truck(const char* plate, int year, double capacity, const char* address);
		virtual ~Truck();
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& T);
	std::istream& operator>>(std::istream& istr, Truck& T);
}
#endif