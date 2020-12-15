/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-12-05            ///
|*******************************************|
|**********  Final Project - MS5  **********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds {
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream& ostr)const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble() {};
	};
	std::ostream& operator<<(std::ostream& os, const IOAble& ro);
	std::istream& operator>>(std::istream& is, IOAble& ro);
}
#endif // !SDDS_IOABLE_H_