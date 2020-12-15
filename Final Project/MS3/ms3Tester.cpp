// Patient Tester:
// Version: 1.1 (corrected matching outputs)
// Date: 11/16/2020
// Author: Fardad 
// Description:
// This file tests the Patient Module of your project
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;
#include "utils.h"
#include "Patient.h"
namespace sdds {
   class WalkinPatient : public Patient {
   public:
     WalkinPatient(int ticketNumber = 0, bool fileIO = false):
        Patient(ticketNumber,fileIO){ }
     char type()const {
        return 'W';
     }
     std::ostream& write(std::ostream& ostr)const {
        return fileIO() ? csvWrite(ostr) : Patient::write(ostr);
     }
     std::istream& read(std::istream& istr) {
        return fileIO() ? csvRead(istr).ignore(1000,'\n') : Patient::read(istr);
     }

   };
}
using namespace sdds;

void displayFile(const char* filename) {
   ifstream file(filename);
   cout << filename << "-----------------------" << endl;
   char ch;
   while (file.get(ch) && cout << ch);
   cout << "---------------------------------" << endl;
}
void testOperatorsCastAndNumber(const Patient& A, const Patient& B);
int main() {
   sdds::debug = true;
   ifstream csvfile("ms3.csv");
   ofstream csvoutfile("ms3out.csv");
   Patient* p = new WalkinPatient(24);
   WalkinPatient W;
   cout << "Enter The following:" << endl << 
      "-------------------\nJohn Doe\nabc\n"
      "100\n123123123\n12:34\n-------------------" << endl;
   cin >> *p;
   p->setArrivalTime();
   cout << "Sections 1 and 2 should match: " << endl << endl;
   cout << "1- Your output on screen:" << endl << *p << endl;
   cout << "2- The output should be :" << endl <<
      "Ticket No: 24, Issued at: 12:34\n"
      "John Doe, OHIP: 123123123" << endl << endl;
   p->fileIO(true);
   cout << "1- Your comma separated ouput: " << endl << *p << endl;
   cout << "2- comma separated ouput should be: " << endl <<
      "W,John Doe,123123123,24,12:34" << endl << endl;
   cout << "Enter the following: " << endl;
   cout << ">Jo Lee,234234234,200,12:50" << endl << ">";
   p->fileIO(true);
   cin >> *p;
   cout << "Sections 1 and 2 should match: " << endl << endl;
   p->fileIO(false);
   cout << "1- Your output on screen:" << endl;
   cout << *p << endl;
   cout << "2- The output should be:" << endl;
   // V1.1
   cout << "Ticket No: 200, Issued at: 12:50\n"
           "Jo Lee, OHIP: 234234234" << endl<<endl;

   cout << "Testing File IO: " << endl;
   int i = 0;
   W.fileIO(true);
   while (csvfile) {
      csvfile >> W;
      if (csvfile) {
         W.fileIO(false);
         cout << ++i << " -----------------------------------------------" << endl
            << W << endl << endl;
         W.fileIO(true);
         csvoutfile << W << endl;
      }
   }
   csvoutfile.close();
   displayFile("ms3out.csv");
   W.fileIO(false);
   p->fileIO(false);
   testOperatorsCastAndNumber(W, *p);
   delete p;
   return 0;
}
void testOperatorsCastAndNumber(const Patient& A, const Patient& B) {
   cout << "Testing operator== overloads: " << endl;
   cout << (A == 'W' ? "Success!" : "Failed!") << endl;
   cout << (A == B ? "Success!" : "Failed!") << endl;
   cout << "Testing Time cast and number: " << endl;
   cout << "W, Ticket Time: " << Time(A) << endl;
   cout << "W, Ticket number: " << A.number() << endl;
}
