/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-11            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_BAR_H_
#define SDDS_BAR_H_
#pragma once

namespace sdds {
	class Bar {
		char b_title[21];
		char* b_fill;
		int b_sampleValue;

	public:
		void setEmpty();
		void set(const char* title, const char fill, int sampleValue);
		bool isValid()const;
		void draw()const;
	};



}
#endif