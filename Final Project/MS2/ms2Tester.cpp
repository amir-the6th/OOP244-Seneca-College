// IOAble Tester:
// Version: 1.0
// Date: 11/03/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the IOAble Module of your project
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "IOAble.h"
using namespace std;
using namespace sdds;
void displayFile(const char* filename) {
   ifstream file(filename);
   cout << filename << "---------------------" << endl;
   char ch;
   while (file.get(ch) && cout << ch);
   cout << "---------------------------------" << endl;
}
class Box :public IOAble {
   int m_hieght, m_width;
public:
   bool csv;
   Box() :m_hieght(0), m_width(0), csv(false) {
      cout << "defaulting Box" << endl;
   };
   ostream& csvWrite(std::ostream& ostr)const {
      return ostr << m_hieght << "," << m_width;
   }
   istream& csvRead(std::istream& istr) {
      istr >> m_hieght;
      istr.ignore();
      istr >> m_width;
      istr.ignore();
      return istr;
   }
   ostream& write(ostream& ostr)const {
      if (csv) {
         csvWrite(ostr);
      }
      else {
         int i;
         for (int j = 0; j < m_hieght; j++) {
            for (i = 0; i < m_width * 2; i++, ostr << "*");
            ostr << endl;
         }
      }
      return ostr;
   }
   istream& read(istream& istr) {
      if (csv) {
         csvRead(istr);
      }
      else {
         cout << "Height: ";
         istr >> m_hieght;
         cout << "Width: ";
         istr >> m_width;
      }
      return istr;
   }
   ~Box() {
      cout << "Box(" << m_hieght << "," << m_width  << ") is gone!" << endl;
   }
};
int main() {
   Box B;
   cout << "Getting information of an IOAble box from console: " << endl;
   cin >> B;
   cout << "Display the IOAble box on console: " << endl;
   cout << B << endl;
   B.csv = false;
   ifstream fboxes("boxes.txt");
   if (fboxes) {
      Box* Bp;
      ofstream bout("boxesOut.txt");
      B.csv = true;
      cout << "Saving " << B << " in the output file." << endl;
      bout << B << endl;
      cout << "Dynamically allocating a Box and holding it in an IOAble pointer..." << endl;
      IOAble* iop = Bp = new Box();
      cout << "Reading dimenstions from file using the IOAlbe pointer" << endl;;
      Bp->csv = true;
      fboxes >> *iop;
      cout << "Dimentions: " << endl;
      cout << *iop << endl;
      Bp->csv = false;
      cout << "What it looks like on screen:" << endl << *iop << endl;
      Bp->csv = true;
      cout << "Now save it in the fiel..." << endl;
      bout << *iop << endl;
      cout << "Reading the next dimenstions from file using the IOAble pointer" << endl;;
      fboxes >> *iop;
      cout << "Dimentions: " << endl;
      cout << *iop << endl;
      Bp->csv = false;
      cout << "What it looks like on screen:" << endl << *iop << endl;
      Bp->csv = true;
      cout << "Save this one too in the output file..." << endl;
      bout << *iop << endl;
      cout << "Close the file and display it..." << endl;
      bout.close();
      displayFile("boxesOut.txt");
      cout << "Removing the box from memroy uisng parents pointer..." << endl;
      delete Bp;
      bout.close();
   }
   else {
      cout << "Could not find the file \"boxes.txt\"." << endl;
   }
   cout << "Content of \"boxesOut.txt\" file" << endl;
   displayFile("boxesOut.txt");
   return 0;
}