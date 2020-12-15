/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-15            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BOX_H_
#define SDDS_BOx_H_
//#pragma once
#include <iostream>

namespace sdds {
	class Box {
        char* m_contentName;   // the conent name pointer:
                           // this pointer holds the name of the material to be kept in the box
                           // dynamically
        int m_width;           // The dimensions of the box in Inches
        int m_height;
        int m_length;
        int m_contentVolume;   // the content volume:
                               // This variable holds the volume of the material currently in 
                               // the box in Cubic Inches

        void setName(const char* Cstr);
        void setUnusable();
        bool isUnusable()const;
        bool hasContent()const;
        

    public:
        Box();
        Box(int sideLength, const char* contentName = nullptr);
        Box(int width, int height, int length, const char* contentName = nullptr);
        ~Box();

        int capacity()const;
        int quantity()const;
        Box& setContent(const char* contentName);
        std::ostream& display()const;
        Box& add(int quantity);
        Box& add(Box& B);

	};
}
#endif

