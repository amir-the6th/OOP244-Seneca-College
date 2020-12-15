// MS4 Tester
// file: ms4Tester.cpp
// Version: 0.8 
// Date: 11/21/2020
// Author: Fardad 
// Description:
// This file tests the CovidPatient and TriagePatient
// Modules of your project
/////////////////////////////////////////////
#include <iostream>
using namespace std;
#include "Patient.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
using namespace sdds;
void CPTest();
void TPTest();

int main() {
   cout << "Milestone 4 tester" << endl;
   CPTest();
   TPTest();
   return 0;
}

void CPTest() {
   sdds::debug = true;
   CovidPatient A, B;
   cout << "Testing CovidPatient:" << endl
      << "Enter the following:" << endl
      << "Enter current time: 12:34" << endl
      << "Name: aaa" << endl
      << "OHIP: 111111111" << endl;
   A.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   A.fileIO(false);
   cin >> A;
   cout << "Enter the following:" << endl
      << "Enter current time: 12:35" << endl
      << "Name: bbb" << endl
      << "OHIP: 222222222" << endl;
   B.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   B.fileIO(false);
   cin >> B;
   cout << endl << "Patients information entered:" << endl;
   cout << A << endl << B << endl;
   A.fileIO(true);
   B.fileIO(true);
   cout << "CSV output: " << endl;
   cout << A << endl << B << endl << endl;
   cout << "Testing CSV input:" << endl
      << "Enter the following:" << endl;
   cout << ">ccc,333333333,10,23:45" << endl << ">";
   cin >> A;
   cin.ignore(100, '\n');
   cout << endl << "Data entered:" << endl;
   A.fileIO(false);
   cout << A << endl;
   cout << "Testing global ticket number variable:" << endl
      << "Enter the following: " << endl
      << "Enter current time: 23:55" << endl
      << "Name: ddd" << endl
      << "OHIP: 444444444" << endl;
   CovidPatient C;
   C.setArrivalTime();
   C.fileIO(false);
   cin >> C;
   cout << "Patient information entered:" << endl;
   cout << C << endl;
}
void TPTest() {
   sdds::debug = true;
   TriagePatient A, B;
   cout << "Testing TriagePatient:" << endl
      << "Enter the following:" << endl
      << "Enter current time: 12:34" << endl
      << "Name: aaa" << endl
      << "OHIP: 111111111" << endl
      << "Symptoms: aaa aaa aaa" << endl;
   A.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   A.fileIO(false);
   cin >> A;
   cout << "Enter the following:" << endl
      << "Enter current time: 12:35" << endl
      << "Name: bbb" << endl
      << "OHIP: 222222222" << endl
      << "Symptoms: bbb bbb bbb" << endl;
   B.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   B.fileIO(false);
   cin >> B;
   cout << endl << "Patients information entered:" << endl;
   cout << A << endl << B << endl;
   A.fileIO(true);
   B.fileIO(true);
   cout << "CSV output: " << endl;
   cout << A << endl << B << endl << endl;
   cout << "Testing CSV input:" << endl
      << "Enter the following:" << endl;
   cout << ">ccc,333333333,10,23:45,ccc ccc ccc" << endl << ">";
   cin >> A;
   cin.ignore(100, '\n');
   cout << endl << "Data entered:" << endl;
   A.fileIO(false);
   cout << A << endl;
   cout << "Testing global ticket number variable:" << endl
      << "Enter the following: " << endl
      << "Enter current time: 23:55" << endl
      << "Name: ddd" << endl
      << "OHIP: 444444444" << endl
      << "Symptoms: ddd ddd ddd" << endl;
   TriagePatient C;
   C.setArrivalTime();
   C.fileIO(false);
   cin >> C;
   cout << "Patient information entered:" << endl;
   cout << C << endl;
}