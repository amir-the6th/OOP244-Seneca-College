/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-07            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Subject.h"
using namespace std;

namespace sdds {

	char Subject::grade()const {
		char grade = 'X';

		if (m_mark >= 0 && m_mark < 50) {
			grade = 'F';
		}
		else if (m_mark >= 50 && m_mark < 60) {
			grade = 'D';
		}
		else if (m_mark >= 60 && m_mark < 70) {
			grade = 'C';
		}
		else if (m_mark >= 70 && m_mark < 80) {
			grade = 'B';
		}
		else {
			grade = 'A';
		}
		return grade;
	}

	void Subject::setEmpty() {
		m_mark = -1;
		m_code[0] = { 0 };
	}

	void Subject::set(const char* code, int mark) {
		bool valid;

		valid = (mark < 0 || mark > 100);

		if (valid) {
			setEmpty();
		}
		else {
			strcpy(m_code, code);
			m_mark = mark;
		}
	}

	float Subject::scale4()const {
		float grade = 0.0;

		if (m_mark >= 0 && m_mark < 50) {
			grade = 0.0;
		}
		else if (m_mark >= 50 && m_mark < 60) {
			grade = 1.0;
		}
		else if (m_mark >= 60 && m_mark < 70) {
			grade = 2.0;
		}
		else if (m_mark >= 70 && m_mark < 80) {
			grade = 3.0;
		}
		else {
			grade = 4.0;
		}
		return grade;
	}


	bool Subject::isValid()const {
		bool valid = true;
		valid = (m_mark >= 0);
		return valid;
	}


	void Subject::display()const {
		if (isValid()) {
			std::cout.width(15);
			std::cout.setf(ios::left);
			std::cout << m_code;
			std::cout.unsetf(ios::left);

			std::cout.width(3);
			std::cout.setf(ios::right);
			std::cout << m_mark;

			std::cout.width(10);
			std::cout << grade();
			std::cout.unsetf(ios::right);
			cout << endl;
		}
	}
}