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

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
    class Menu {
        char* m_text;
        int m_noOfSel;
    public:
        Menu(const char* text, int NoOfSelections);
        virtual ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        std::ostream& display(std::ostream& ostr = std::cout)const;
        int& operator>>(int& Selection);
    };
}
#endif // !SDDS_MENU_H_