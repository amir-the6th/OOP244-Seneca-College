/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-18            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include "NameTag.h"
using namespace std;
namespace sdds {
	void NameTag::setTag(const char* Cstr) {
			delete[] m_tagName;
			m_tagName = nullptr;
			int length = strlen(Cstr) > 40 ? 40 : strlen(Cstr);
			m_tagName = new char[length + 1];
			strcpy(m_tagName, Cstr);
			m_tagName[40] = '\0';
	}
	void NameTag::setEmpty() {
		m_tagName = nullptr;
		m_extension = -1;
	}
	bool NameTag::hasExtension(int extension)const {
		return (extension < 100000 && extension > 9999);
	}
	NameTag::NameTag() {
		setEmpty();
	}
	/*NameTag::NameTag(const char* tagName) {
		m_tagName = nullptr;
		setTag(tagName);
	}*/
	NameTag::NameTag(const char* tagName, int extension) {
		m_tagName = nullptr;
		m_extension = -1;;
		if (tagName && (extension == -1 || hasExtension(extension))) {
			m_extension = extension;
			setTag(tagName);
		}
	}
	NameTag::~NameTag() {
		delete[] m_tagName;
	}
	bool NameTag::yes()	{
		char yn = 'x';

		cin >> yn;
		cin.ignore(1000, '\n');
		while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N') {
			cout << "Invalid answer, try again: ";
			cin >> yn;
		}
		return (yn == 'y' || yn == 'Y');
	}
	std::ostream& NameTag::print() const {
		if (m_tagName && hasExtension(m_extension)) {
			if (strlen(m_tagName) < 20) {
				cout << "************************" << '\n' <<
					'*' << setw(23) << setfill(' ') << '*' << '\n' <<
					"* " << m_tagName << setw(22 - strlen(m_tagName)) << '*' << '\n' <<
					'*' << setw(23) << setfill(' ') << '*' << '\n' <<
					"* Extension: " << m_extension << setw(6) << setfill(' ') << '*' << '\n' <<
					'*' << setw(23) << setfill(' ') << '*' << '\n' <<
					"************************" << endl;
			}
			else {
				cout << "********************************************" << '\n' <<
					'*' << setw(43) << setfill(' ') << '*' << '\n' <<
					"* " << m_tagName << setw(42 - strlen(m_tagName)) << '*' << '\n' <<
					'*' << setw(43) << setfill(' ') << '*' << '\n' <<
					"* Extension: " << m_extension << setw(26) << setfill(' ') << '*' << '\n' <<
					'*' << setw(43) << setfill(' ') << '*' << '\n' <<
					"********************************************" << endl;
			}
		}
		else if (m_tagName && m_extension < 0) {
			if (strlen(m_tagName) < 20) {
				cout << "************************" << '\n' <<
					'*' << setw(23) << setfill(' ') << '*' << '\n' <<
					"* " << m_tagName << setw(22 - strlen(m_tagName)) << '*' << '\n' <<
					'*' << setw(23) << setfill(' ') << '*' << '\n' <<
					"* Extension: " << "N/A" << setw(8) << setfill(' ') << '*' << '\n' <<
					'*' << setw(23) << setfill(' ') << '*' << '\n' <<
					"************************" << endl;
			}
			else {
				cout << "********************************************" << '\n' <<
					'*' << setw(43) << setfill(' ') << '*' << '\n' <<
					"* " << m_tagName << setw(42 - strlen(m_tagName)) << '*' << '\n' <<
					'*' << setw(43) << setfill(' ') << '*' << '\n' <<
					"* Extension: " << "N/A" << setw(28) << setfill(' ') << '*' << '\n' <<
					'*' << setw(43) << setfill(' ') << '*' << '\n' <<
					"********************************************" << endl;
			}
		}
		else {
			cout << "EMPTY NAMETAG!\n";
		}
		return cout;
	}
	NameTag& NameTag::read() {
		int extension = 0;
		char tagName[60];

		cout << "Please enter the name: ";
		cin.getline(tagName, 60);
		setTag(tagName);

		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		if (yes()) {
			cout << "Please enter a 5 digit phone extension: ";
			cin >> extension;
			while (!hasExtension(extension)) {
				cout << "Invalid value [10000<=value<=99999]: ";
				cin >> extension;
			}
			cin.ignore();
			m_extension = extension;
		}
		else m_extension = -1;

		return *this;
	}
}