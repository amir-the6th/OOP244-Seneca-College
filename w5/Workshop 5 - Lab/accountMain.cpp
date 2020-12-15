// Workshop 5:
// Version: 1.0
// Date: 10/18/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Account.h"
using namespace std;
using namespace sdds;
void displayAaccounts(const Account* acc, int num) {
   for (int i = 0; i < num; i++) {
      cout << (i + 1) << ": ";
      acc[i].display() << endl;
   }
}
void displayRawAccountNumber(const Account* acc, int num) {
   cout << "Display raw account numbers of all the accounts " << endl;
   cout << " using int conversion operator" << endl;
   for (int i = 0; i < num; i++) {
      cout << int(acc[i]) << " ";
   }
   cout << endl;
}
void displayRawBalances(const Account* acc, int num) {
   cout << "Display raw balances of the accounts: " << endl;
   cout << " using double conversion operator" << endl;
   for (int i = 0; i < num; i++) {
      cout << double(acc[i]) << " ";
   }
   cout << endl;
}
void displayValidAccounts(const Account* acc, int num) {
   cout << "Display valid accounts using bool conversion operator" << endl;
   for (int i = 0; i < num; i++) {
      if (acc[i]) acc[i].display() << endl;
   }
   cout << endl;
}
void displayValidNotNew(const Account* acc, int num) {
   cout << "Display valid accounts that are not new" << endl;
   cout << "using bool conversion operator and operator~()" << endl;
   for (int i = 0; i <num; i++) {
      if (acc[i] && !~acc[i]) acc[i].display() << endl;
   }
   cout << endl;
}
int main() {
   double value;
   Account mixed[9] = {
      {11111, 111.11},  
      {22222, 222.22},  
      {333, 333.333},   // invalid
      {44444, 4444.44},
      {55555, 555.55},
      {66666, -66.66},  // invalid
      {77777, 777.77}
   };
   cout << "Using bool conversion overload and operator ~ to print the accounts: " << endl;
   displayAaccounts(mixed, 9);
   cout << "Depositing $50.02 into account #1 using += operator:" << endl;
   (mixed[0] += 50.02).display() << endl;
   cout << "Withdrawing $100.01 from account #2 using -= operator:" << endl;
   (mixed[1] -= 100.01).display() << endl;
   cout << "Attempting to withdraw too much from account #4 using -= operator:" << endl;
   (mixed[3] -= 5555.55).display() << endl;
   cout << "Attempting to deposit and withdraw negative amounts on account #4:" << endl;
   (mixed[3] -= -5.55).display() << endl;
   (mixed[3] += -50.55).display() << endl;
   cout << "Sum of the balance of accounts 5 and 7"<< endl << "   in three different ways: ";
   cout << (value = mixed[4] + mixed[6]) << ", ";
   value = 0;
   value += mixed[4];
   value += mixed[6]; 
   cout << value << ", and ";
   value = double(mixed[4]);
   value += double(mixed[6]);
   cout << value << endl;
   cout << "Setting the account number of account#8 to 88888: "<< endl;
   cout << "before: ";
   mixed[7].display() << endl;
   cout << "After:  " ;
   (mixed[7] = 88888).display() << endl;
   cout << "Moving the balance from account# 7 to Account #8 using operator=:" << endl;
   cout << "Before: " << endl;
   displayAaccounts(&mixed[6], 2);
   mixed[7] = mixed[6];
   cout << "After: " << endl;
   displayAaccounts(&mixed[6], 2);
   cout << "Setting the account number to a bad value, rendering the account#7 invalid:" << endl;
   (mixed[6] = 444).display() << endl;
   cout << "Attempting to move balance of a valid account to an invalid one: (8 to 7)" << endl;
   cout << "This attempt should have no effect on either accounts" << endl;
   mixed[6] = mixed[7];
   cout << "Before: " << endl;
   displayAaccounts(&mixed[6], 2);
   mixed[7] = mixed[6];
   cout << "After: " << endl;
   displayAaccounts(&mixed[6], 2);


   displayRawAccountNumber(mixed, 9);
   displayRawBalances(mixed, 9);
   displayValidAccounts(mixed, 9);
   displayValidNotNew(mixed, 9);

   return 0;
}