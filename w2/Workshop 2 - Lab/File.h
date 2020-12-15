/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-30            ///
********************************************/


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#pragma once

namespace sdds {
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();

    // TODO: Declare read prototypes
    bool read(char* studentName);
    bool read(int& studentNo);
    bool read(double& studentGPA);
    //DONE

}
#endif // !SDDS_FILE_H_