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

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
   class Rectangle : public LblShape{
	   int m_width = 0;
	   int m_height = 0;
   public:
	   Rectangle();
	   Rectangle(const char* Cstring, int width, int height);
	   void getSpecs(std::istream& istr);
	   void draw(std::ostream& ostr)const;
   };
}
#endif