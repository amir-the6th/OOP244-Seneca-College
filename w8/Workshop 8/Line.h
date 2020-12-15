/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-11-20            ///
|*******************************************|
|*************   Workshop 8   **************|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
   class Line : public LblShape{
	   int m_length = 0;
   public:
	   Line();
	   Line(const char* Cstring, int len);
	   void getSpecs(std::istream& istr);
	   void draw(std::ostream& ostr)const;
   };
}
#endif // !SDDS_LINE_H

