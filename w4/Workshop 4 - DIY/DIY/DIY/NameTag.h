/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-18            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BOX_H_
#define SDDS_BOx_H_
//#pragma once
#include <iostream>

namespace sdds {
	class NameTag {
		char* m_tagName;
		int m_extension;

		void setTag(const char* Cstr);
		void setEmpty();
		bool hasExtension(int extension)const;

	public:
		NameTag();
		//NameTag(const char* tagName); // we don't need this constructor, We can add 
									   //  a default value for the extension parameter
		NameTag(const char* tagName, int extension = -1);
		~NameTag();

		bool yes();
		std::ostream& print()const;
		NameTag& read();
	};
}
#endif