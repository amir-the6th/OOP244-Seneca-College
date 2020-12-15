/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-11            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BARCHART_H_
#define SDDS_BARCHART_H_
#pragma once
#include "Bar.h"

namespace sdds {
	class BarChart {
		char bc_title;
		Bar* bc_bar;
		char* b_fill;
		int bc_noOfBars;
		int bc_barsAdded;

		bool isValid()const;

	public:
		void init(const char* title, int noOfSampels, char fill);
		void add(const char* bar_title, int value);
		void draw()const;
		void deallocate();
	};

}
#endif