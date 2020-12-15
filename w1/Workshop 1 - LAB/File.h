/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-23            ///
********************************************/


#ifndef NAMESPACE_FILE_H
#define NAMESPACE_FILE_H

#pragma once

namespace sdds {
	
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);
}
#endif // !NAMESPACE_FILE_H