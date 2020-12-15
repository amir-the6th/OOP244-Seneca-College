/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-11            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
namespace sdds {
	class Vehicle {
		char m_plateNo[9];
		char m_address[64];
		int m_year;
	public:
		Vehicle(const char* plate, int year);
		//Vehicle(const char* address);
		virtual ~Vehicle();
		void moveTo(const char* address);
		
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Vehicle& V);
	std::istream& operator>>(std::istream& istr, Vehicle& V);
}
#endif