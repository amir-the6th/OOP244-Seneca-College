/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-09-30            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds {
   int noOfStudents;
   Student* students;


   void sort() {
      int i, j;
      Student temp;
      for (i = noOfStudents - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (students[j].m_gpa > students[j + 1].m_gpa) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one student record from the file and loads it into the student reference
   // argument
   bool load(Student& students) {
      bool ok = false;
      char name[128];

      // if reading of name is successful
      if (read(name)) {

         // allocate memory to the size of the name + 1
         // and keep its address in the name of the Student Reference
          students.m_name = new char[strlen(name) + 1];

         // copy the name into the newly allocated memroy
          strcpy(students.m_name, name);

         // read student number and gpa from the file into the corresponding
         // variables in the Student Referenct
          read(students.m_studentNumber);   
          read(students.m_gpa);

         // make sure the "ok" flag is set to true, if all is good
          ok = true;
      }
      return ok;
   }
   //DONE


   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;

      if (openFile(DATAFILE)) {
         // set the noOfStudents to the number of records in the file.
          noOfStudents = noOfRecords();

         // dyanamically allocated an array of students into the global
         // Student pointer; "students" to the size of the noOfStudents.
          students = new Student[noOfStudents];

         // in a loop load the student records from the file into 
         // the dynamic array.
          for (i = 0; i < noOfStudents; i++) {
              load(students[i]);
          }

         // if the number of the records does not match the number of reads
         // print an error message
          if (i != noOfStudents) {
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
         }
         else {
            ok = true;
         }
         closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }
   //DONE


   // TODO: Implementation for the display functions go here
   void display(const Student& students) {
   
       cout << students.m_name << ", " << students.m_studentNumber << ": " << students.m_gpa;

   }

   void display() {
       int i = 0;
       int row = 1;
       sort();
   
       for (i = 0; i < noOfStudents; i++) {
           cout << row << ": ";
           display(students[i]);
           cout << endl;
           row++;
       }
   }
   //DONE



   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       int i = 0;
       for (i = 0; i < noOfStudents; i++) {
            
           delete[] students[i].m_name;
       }
       delete[] students;
   }
   //DONE
}