/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-27            ///
********************************************/

#ifndef NAMESPACE_FILE_H
#define NAMESPACE_FILE_H

#pragma once

namespace sch {

	bool openFile(const char filename[]);
	void closeFile();
	bool readCode(char code[]);
	bool readExt(int* ext);
}


#endif