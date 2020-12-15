/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-15            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include "Box.h"
using namespace std;
namespace sdds {

	void Box::setName(const char* Cstr) {
		if (Cstr) {
			delete[] m_contentName;
			m_contentName = nullptr;

			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	}

	void Box::setUnusable() {
		delete[] m_contentName;
		m_contentName = nullptr;

		m_width = -1;
		m_height = -1;
		m_length = -1;
		m_contentVolume = -1;
	}

	bool Box::isUnusable()const {
		bool unusable = false;
		if (m_width == -1 || m_height == -1 || m_length == -1) {
			unusable = true;
		}
		
		return unusable;
	}

	bool Box::hasContent() const
	{
		bool hasContent = false;
		if (quantity() > 0) hasContent = true;

		return hasContent;
	}

	Box::Box() {
		m_width = 12;
		m_height = 12;
		m_length = 12;
		m_contentName = nullptr;
		m_contentVolume = 0;
	}
	
	Box::Box(int sideLength, const char* contentName) {
		m_contentName = nullptr;
		if (sideLength > 4 && sideLength < 37) {
			m_width = sideLength;
			m_height = sideLength;
			m_length = sideLength;
			m_contentVolume = 0;
			setName(contentName);
		}
		else {
			setUnusable();
		}
	}

	Box::Box(int width, int height, int length, const char* contentName) {
		m_contentName = nullptr;
		if (width > 4 && width < 37 &&
			height > 4 && height < 37 &&
			length > 4 && length < 37) 
		{
			m_width = width;
			m_height = height;
			m_length = length;
			m_contentVolume = 0;
			setName(contentName);
		}
		else {
			setUnusable();
		}
	}

	Box::~Box() {
		delete[] m_contentName;
	}

	int Box::capacity() const {
		return m_width * m_height * m_length;
	}

	int Box::quantity() const {
		return m_contentVolume;
	}

	Box& Box::setContent(const char* contentName) {
		if (m_contentName && hasContent()) {
			setUnusable();
		}
		else {
			setName(contentName);
		}
		return *this;
	}

	std::ostream& Box::display() const {
			if (m_contentName) {
				cout << setw(30) << left << setfill('.') << m_contentName << "  " <<
					setw(2) << right << setfill('0') << m_width << 'x' <<
					setw(2) << m_height << 'x' <<
					setw(2) << m_length <<
					setw(8) << setfill(' ') << quantity() << '/' << capacity() << " C.I.";
			}
			else if (!m_contentName && !isUnusable()) {
				cout << setw(30) << left << setfill('.') << "Empty box" << "  " <<
					setw(2) << right << setfill('0') << m_width << 'x' <<
					setw(2) << m_height << 'x' <<
					setw(2) << m_length <<
					setw(8) << setfill(' ') << quantity() << '/' << capacity() << " C.I.";
			}
			else {
				cout << "Unusable box, discard the content, and recycle.";
			}
			return cout;
	}

	

	Box& Box::add(int quantity)
	{
		if (quantity < capacity()) {
			m_contentVolume += quantity;
		}
		else {
			setUnusable();
		}
		return *this;
	}

	Box& Box::add(Box& B)
	{
		if (m_contentName == nullptr || quantity() == 0) {
			setContent(B.m_contentName);
		}
		if (strcmp(m_contentName, B.m_contentName) == 0) {
			if (quantity() + B.quantity() <= capacity()) {
				add(B.quantity());
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
				m_contentVolume = capacity();
			}
		}
		else {
			if (quantity() + B.quantity() <= capacity()) {
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
			}
			setUnusable();
		}
		return *this;
	}
}
