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

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds {
   class LblShape: public Shape {
	   char* m_label = nullptr;
   protected:
	   const char* label() const;
   public:
	   LblShape();
	   LblShape(const char* Cstr);
	   ~LblShape();
	   LblShape(const LblShape&) = delete;
	   LblShape& operator=(const LblShape&) = delete;
	   void getSpecs(std::istream& istr);
   };
}
#endif // !SDDS_LBLSHAPE_H


