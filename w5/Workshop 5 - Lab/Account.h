/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-24            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator ~()const;
      Account& operator=(int setAccount);
      Account& operator=(Account& setAccount);
      Account& operator+=(double balance);
      Account& operator-=(double balance); 
   };
   double operator+(const Account& leftOperand, const Account& rightOperand);
   double operator+=(double& leftOperand, const Account& rightOperand);

}
#endif // SDDS_ACCOUNT_H_