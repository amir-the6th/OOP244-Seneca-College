/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-30            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   // TODO: read functions go here    
   bool read(char* studentName) {
       return fscanf(fptr, "%[^,],", studentName) == 1;
   }
   bool read(int& studentNo) {
       return fscanf(fptr, "%d,", &studentNo) == 1;
   }
   bool read(double& studentGPA) {
       return fscanf(fptr, "%lf\n", &studentGPA) == 1;
   }
   //DONE

}