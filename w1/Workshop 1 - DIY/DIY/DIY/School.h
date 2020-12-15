/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-27            ///
********************************************/

#ifndef NAMESPACE_SCHOOL_H
#define NAMESPACE_SCHOOL_H

#pragma once

namespace sch {
	struct School
	{
		char s_code[6];
		int  s_ext;
	};

	bool loadSchool();
	bool hasCode(const School* sch, const char schCode[]);
	void displayExt(const School* sch);
	void displaySchoolsWithExt(const char schCode[]);

}




#endif
