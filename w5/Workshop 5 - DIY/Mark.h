/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-27            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
//#pragma once

namespace sdds {
	class Mark {
		int m_mark;
		void setEmpty();
	public:
		Mark(int mark = 0);
		operator bool()const;
		operator int()const;
		operator double()const;
		operator char()const;
		Mark& operator+=(int mark);
		Mark& operator=(int mark);
	};
	int operator+=(int& value, const Mark& mark);
}
#endif