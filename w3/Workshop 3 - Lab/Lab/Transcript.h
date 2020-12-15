/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-07            ///
********************************************/


#ifndef SDDS_TRANSCRIPT_H_
#define SDDS_TRANSCRIPT_H_
#pragma once
#include "Subject.h"

namespace sdds {
	class Transcript {
		char* m_studentName; // pointer to hold the student name dynamically 
		Subject* m_subjects; // pointer to hold the subjects in the Transcript dynamically
		int m_noOfSubjects;  // Number of subjects or number of elements in the array of m_subjects.
		int m_subjectsAdded; // Number of subjects in the m_subjects array that are set to thier values properly (they are not empty)

		void setEmpty();
		bool isValid()const;
		void Title()const;
		float gpa()const;
		void footer()const;

	public:
		void init(const char* studentName, int noOfSubjects);
		bool add(const char* subject_code, int mark);
		void display()const;
		void deallocate();
	};
};

#endif