/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-07            ///
********************************************/

#ifndef SDDS_SUBJECT_H_
#define SDDS_SUBJECT_H_
#pragma once

namespace sdds {
	class Subject {
		char m_code[7]; // holds the subject code (exactly 6 characters)
		int m_mark;     // the mark out of 100
		char grade()const;

	public:
		void setEmpty();
		void set(const char* code, int mark);
		float scale4()const;
		bool isValid()const;
		void display()const;
	};
};

#endif