/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-24            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << "Acc#: ";
         if (~(*this)) 
            cout << "Not Set";
         else
            cout << " " << m_number << " ";
         cout << ", Balance: ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         // I (Fardad) removed the "return cout", this was a mistake
         // (copied and pasted by mistake)
         // and had no effect to the execution of the program.
         // As mentioned before we should have only
         // one return statement in a function.
      }
      else {
         cout << "Invalid Account";
      }
      return cout;
    }
   Account::operator bool() const {
       return m_number >= 0;
    }
   Account::operator int() const {
       return m_number;
   }
   Account::operator double() const {
       return m_balance;
   }
   bool Account::operator~() const {
       return m_number == 0;
   }
   Account& Account::operator=(int number) {
       if (*this && (number > 10000 && number < 99999)) {
           m_number = number;
       }
       else {
           setEmpty();
       }
       return *this;
   }
   Account& Account::operator=(Account& setA) {
       if (*this && (setA.m_number > 0)) {
           m_balance = setA.m_balance;
           setA.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator+=(double balance) {  
       if (*this && balance > 0) {
           m_balance += balance;
       }
       return *this;
   }
   Account& Account::operator-=(double balance) {
       if (*this && balance > 0 && (m_balance - balance > 0)) {
           m_balance -= balance;
       }
       return *this;
   }
   double operator+(const Account& lO, const Account& rO) {
       double sum = 0;
       if (lO && rO) {
           sum = double(lO) + double(rO);
       }
       return sum;
   }
   double operator+=(double& lO, const Account& rO) {
       return lO += double(rO);
   }
}