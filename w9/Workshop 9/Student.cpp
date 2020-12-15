#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

using namespace std;
#include "Student.h"
namespace sdds {
   Student::Student() {
      set(0, "");
   }
   Student::Student(int stno, const char* name) {
      set(stno, name);
   }
   void Student::set(int stno, const char* name) {
      _stno = stno;
      strcpy(_name, name);
   }
   ostream& Student::display(ostream& os)const {
      return os << _stno << " " << _name;
   }
   istream& Student::read(istream& is) {
      is >> _stno;
      is.getline(_name, 40, '\n');
      return is;
   }
   bool Student::operator==(const char* nameSubstr)const {
      return strstr(_name, nameSubstr) != nullptr;
   }
}