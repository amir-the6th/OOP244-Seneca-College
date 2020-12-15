/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-27            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Mark.h"
using namespace std;


namespace sdds {
	void Mark::setEmpty(){
		m_mark = -1;
	}
	Mark::Mark(int mark){
		setEmpty();
		m_mark = mark;
	}
	Mark::operator bool()const {
		return m_mark >= 0 && m_mark <= 100;
	}
	Mark::operator int()const{
		int convert;
		if (*this) {
			convert = int(m_mark);
		}
		else convert = 0;
		return convert;
	}
	Mark::operator double()const {
		int gpa = 0;
		if (m_mark >= 80 && m_mark < 100) {
			gpa = 4;
		}
		else if (m_mark >= 70 && m_mark < 80) {
			gpa = 3;
		}
		else if (m_mark >= 60 && m_mark < 70) {
			gpa = 2;
		}
		else if (m_mark >= 50 && m_mark < 60) {
			gpa = 1;
		}
		return gpa;
	}
	Mark::operator char() const {
		char gpa = 'X';

		if (m_mark > 0 && m_mark < 50) {
			gpa = 'F';
		}
		else if (m_mark >= 50 && m_mark < 60) {
			gpa = 'D';
		}
		else if (m_mark >= 60 && m_mark < 70) {
			gpa = 'C';
		}
		else if (m_mark >= 70 && m_mark < 80) {
			gpa = 'B';
		}
		else if (m_mark >= 80 && m_mark <= 100) {
			gpa = 'A';
		}
		return gpa;
	}
	Mark& Mark::operator+=(int mark){
		if (mark >= 0 && mark <= 100) {
			m_mark += mark;
			if (!*this) m_mark = 0;
		}
		return *this;
	}
	Mark& Mark::operator=(int mark){
		m_mark = mark;
		return *this;
	}
	int operator+=(int& value, const Mark& mark) {
		return value += int(mark);
	}
}