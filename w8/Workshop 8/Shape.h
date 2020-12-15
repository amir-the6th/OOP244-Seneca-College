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

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
   class Shape {
   public:
	   virtual void draw(std::ostream& ostr)const = 0;
	   virtual void getSpecs(std::istream& istr) = 0;
	   virtual ~Shape() {};
   };
   std::ostream& operator<<(std::ostream& os, const Shape& ro);
   std::istream& operator>>(std::istream& is, Shape& ro);
}

#endif // !SDDS_SHAPE_H

