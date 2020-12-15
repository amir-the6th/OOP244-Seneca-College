/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-07            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Transcript.h"
#include "Subject.h"
using namespace std;
namespace sdds {

	void Transcript::setEmpty() {
		m_studentName = nullptr;
		m_subjects = nullptr;
	}

	bool Transcript::isValid()const {
		bool valid = true;
		int i;

		if (m_studentName != nullptr && m_subjects != nullptr) {
			for (i = 0; i < m_noOfSubjects; i++) {
				valid = m_subjects[i].isValid();
			}
		}

		return valid;
	}

	void Transcript::Title()const {
		int i;

		cout << m_studentName << endl;
		for (i = 0; i < 29; i++) {
			cout << "-";
		}
		cout << endl;


	}

	float Transcript::gpa()const {
		float gpa = 0.0;
		int i = 0;

		for (i = 0; i < m_noOfSubjects; i++) {
			gpa += m_subjects[i].scale4();
		}
		gpa /= m_noOfSubjects;

		return gpa;
	}

	void Transcript::footer()const {
		int i;
		for (i = 0; i < 29; i++) {
			cout << "-";
		}
		cout << endl;

		cout.width(26);
		cout.setf(ios::right);
		cout << "GPA: ";
		cout.precision(2);
		cout << gpa() << endl;
	}

	void Transcript::init(const char* studentName, int noOfSubjects) {
		if (studentName == nullptr || noOfSubjects < 0) {
			setEmpty();
		}
		else {
			m_noOfSubjects = noOfSubjects;
			m_studentName = new char[strlen(studentName) + 1];
			strcpy(m_studentName, studentName);
			m_subjects = new Subject[m_noOfSubjects];
			m_subjectsAdded = 0;
		}
	}

	bool Transcript::add(const char* subject_code, int mark) {
		bool add = false;
		int check = (m_subjectsAdded < m_noOfSubjects) ? m_subjectsAdded : m_noOfSubjects;


		m_subjects[check].set(subject_code, mark);

		if (m_subjects[check].isValid()) {
			add = true;
			m_subjectsAdded++;
		}
		else {
			m_subjects[check].setEmpty();
		}

		return add;
	}

	void Transcript::display()const {
		int i;

		if (m_subjectsAdded == m_noOfSubjects)
		{
			Title();
			for (i = 0; i < m_noOfSubjects; i++) {
				if (m_subjects[i].isValid()) {
					m_subjects[i].display();
				}
			}
			footer();
		}
		else {
			cout << "Invalid Transcript!" << endl;
		}
	}

	void Transcript::deallocate() {
		delete[] m_studentName;
		delete[] m_subjects;
		m_studentName = nullptr;
		m_subjects = nullptr;
	}
}