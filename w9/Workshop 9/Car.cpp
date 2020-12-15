#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Car.h"
using namespace std;
namespace sdds {
   Car::Car(const char* plate , const char* makeModel ) {
      set(plate, makeModel);
   }
   void Car::set(const char* plate, const char* makeModel) {
      strncpy(_plate, plate, 8);
      _plate[8] = 0;
      strncpy(_makeModel, makeModel, 40);
      _makeModel[40] = 0;;
   }
   std::ostream& Car::display(std::ostream& os)const {
      return os << _plate << " " << _makeModel;
   }
   std::istream& Car::read(std::istream& is) {
      is >> _plate;
      is.getline(_makeModel, 40, '\n');
      return is;
   }
   bool Car::operator==(const char* mmSubstr)const {
      return strstr(_makeModel, mmSubstr) != nullptr;
   }
}