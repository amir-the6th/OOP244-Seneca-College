/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-13            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{
    Time& Time::reset() {
        m_min = getTime();
        return *this;
    }

    Time::Time(unsigned int min) {
        m_min = min;
    }

    ostream& Time::write(ostream& ostr) const {
        int min = m_min % 60;
        int hour = m_min / 60;
        ostr << setfill('0') << setw(2)
            << hour << ':' << setw(2) << min;
        return ostr;
    }

    istream& Time::read(istream& istr) {
        char ch = '\0';
        int hour = 0, minute = 0;
        istr >> hour >> ch >> minute;
        if (ch != ':') {
            istr.setstate(ios::failbit);
        }
        m_min = (hour * 60) + minute;
        return istr;
    }

    Time::operator int()const {
        return m_min;
    }

    Time& Time::operator *= (int val) {
        this->m_min *= val;
        return *this;
    }

    Time& Time::operator-=(const Time& D) {
        if (this->m_min > D.m_min) {
            this->m_min -= D.m_min;
        }
        else {
            this->m_min += 1440;
            this->m_min -= D.m_min;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Time& T) {
        return T.write(os);
    }
    std::istream& operator>>(std::istream& is, Time& T) {
        return T.read(is);
    }
}