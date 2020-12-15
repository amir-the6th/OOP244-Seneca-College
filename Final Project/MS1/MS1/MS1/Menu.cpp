/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-13            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds
{
    Menu::Menu(const char* text, int NoOfSelections) {
        m_text = nullptr;
        delete[] m_text;
        m_text = new char[strlen(text) + 1];
        strcpy(m_text, text);
        m_noOfSel = NoOfSelections;
    }
    Menu::~Menu() {
        delete[] m_text;
    }
    ostream& Menu::display(ostream& ostr)const {
        ostr << m_text << endl;
        ostr << "0- Exit\n" << "> ";
        return ostr;
    }
    int& Menu::operator>>(int& Selection) {
        int option;
        display();
        
        Selection = getInt("MENU", m_noOfSel);

        //while (!(Selection >= 0 && Selection <= m_noOfSel)) {
        //    cin.clear();
        //    //cin.ignore(1000, '\n');
        //    cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfSel << "]: ";
        //    Selection = getInt();
        //}

        return Selection;
    }
}