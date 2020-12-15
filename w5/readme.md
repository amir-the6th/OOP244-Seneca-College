# Workshop #5: Member Operators, Helper functions
* Version 0.91 (Removed the extra return cout statement from the display function)
* Version 0.9 (under review, Start working on the lab. If there are any corrections, the version number will change)

In this workshop, you will implement different types of operator overload on a partially developed class.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create  binary member operator
- define and create a type conversion operator
- define and a create unary member operator
- define and create helper binary operator between classes
- define and create helper operator between a primitive type and a class.

## Submission Policy

The workshop is divided into two coding parts; part 1, **LAB** and part 2, **DIY**  and one non-coding part:

- ***LAB*** (part 1): worth 50% of the workshop's total mark, is due on **Saturday at 23:59:59** of the week of your scheduled lab.
> Please note that the LAB (part 1) section is **not to be started in your lab session**. You should start it on your own before the day of your lab and and join the lab session to ask for help and correct your mistakes.
- ***DIY*** (part 2): worth 50% of the workshop's total mark, is due on **Thursday at 23:59:59** of the study week.  Submissions of *DIY* part that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

If at the deadline the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.

# LAB (50%) The Account module.

Your task for this lab is to complete the implementation of the **Account** module for holding a bank account number (an integer) and the balance of the account (a double value). 

# The Account class
The Account class has two attributes; one integer for account number (**m_number**) and a double for the balance of the account (**m_balance**)

The **Account** class can be in three different states: 

* Invalid Empty State<br />
An account is in an **invalid** state if invalid information is fed into the account. In these type of situations the account number is set to **-1** and the balance is set to **0**. The Account object in this case is rendered inactive an can not be used anymore.
* New <br />
An account is considered **New** or **not set** when it is just created and the account number is not assigned yet. This state of the **Account** class is flagged by setting the account number (**m_number**) to **0**.
* Valid<br />
An **Account** is considered **valid** if the account number is a 5 digit integer with a zero or positive account number.

## Already implemented parts:
## Constructors
The **Account** can be created in two different ways:
- default constructor *(implemented)* 
```C++
  Account();
```
The default constructor sets the account as **new** with balance of **0**. 
- Two argument constructor (and integer and a double) *(implemented)*
```C++
  Account(int number, double balance);
```
The two argument constructor sets the account number and balance to incoming arguments only if both values are valid. If an invalid account number or a negative balance is passed to the constructor, the object will be set into an invalid empty state.

## display function. 
*(implemented)*
```C++
   ostream& display() const
```
Displays the account on the screen.<br />
If the account is invalid, it is going to print:  **Invalid Account**. If the account is a new account, instead of the account number it will print **Not Set**. <br />
At the end **display** will return the **cout** object.

## To be implemented:
### type conversion operators
- **operator bool**<br />
returns **true** if the account is **valid** and otherwise **false**. This operator can not modify the **account** object.
- **operator int**<br />
returns the **account number**. This operator can not modify the **account** object.
- **operator double**<br />
returns the **balance value**. This operator can not modify the **account** object.

### Unary member operator
- **bool operator ~()**<br />
This operator returns **true** is the account is **new** or **not set** (i.e. if the **account number** is **zero**), otherwise it will return **false**.  This operator can not modify the **account** object.

### Binary member operators
> Note: All the binary member operators **will not take any action** if the **account** (i.e left operand) is in an **invalid** state.

#### assignment operators
- overload the **assignment operator** so the **account** can be set to an **integer**. Doing so should set the **account number** of the **account** to the **integer value**. <br />
If the **integer value** is an invalid account number, the object should be set to an **invalid empty state** instead. <br />
If the account is already in an invalid state, then this operator should not perform any action.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C++
Account A; 
   A = 55555;  // the account number of A will be set to 55555
   A = 555; // the account A will be set to invalid state
   A = 66666; // no action will be taken since the A is in an invalid state
```
- overload the **assignment operator** so the **account** can be set to another **Account** object. This action should **move** the balance from one account to another; therefore unlike the usual assignment operator that effects the left operand only, this operator will effect both operands; the balance of the left account will be set to the balance of the right account and then the balance of the right account will be set to zero.<br />
If any of the two accounts is already in an invalid state, then this operator should not perform any action.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C++
   Account A(55555, 0), B(66666, 400), Bad(555, -10);
   A = B;  // A will have balance of 400 and B will have balance of 0
   B = Bad; // Nothing will happen since Bad is invalid
   Bad = B; // Nothing will hapen since Bad is invalid
```
- overload the **+= operator** to add a double value to an account. This should act like depositing money into an account. (i.e. the value of the double should be added to the balance)<br />
if the account is in an invalid state or the double value is negative, no action should be taken.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C==
Account A(55555, 400.0), Bad(555, -10);
   A += 200.0;  // A will have a balance of 600 
   Bad += 300.0; // Nothing will happen since Bad is invalid
   A += -20.0; // Nothing will happen since double value is negative
```
- overload the **-= operator** to add a double value to an account. This should act like withdrawing money from an account. (i.e. the value of the balance should be reduced by the double value)<br />
if the account is in an invalid state, the double value is negative or there is not enough money in the account no action should be taken.<br />
In any case, a reference of the **current object** (**account**) should be returned. 
```C==
Account A(55555, 400.0), Bad(555, -10);
   A -= 150.0;  // A will have a balance of 250 
   A -= 300.0; // Nothing will happen since there not enough money in A
   A -= -20.0; // Nothing will happen since double value is negative
   Bad += 20.0 // Nothing will happen sinde Bad in invalid
```
### Binary helper operators

-- create a binary stand alone helper **+ operator** that accepts a **constant account reference** at left and another **constant account reference** at right and returns a **double** value. <br />
The **double** value should be the **sum** of the **balances** of the two accounts.<br />
If any of the two accounts is **invalid**, then **zero** is returned.<br />
```C++
   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum;
   sum = A + B; // sum should be 1000.0
   sum = A + Bad; // sum should be 0 since Bad is invalid
   sum = Bad + B; // sum should be 0 since Bad is invalid
```
-- create a binary stand alone helper **+= operator** that accepts a **double reference** at left and a **constant account reference** at right and returns a **double** value. <br />
The value of the balance of the right operand (account reference) should be added to the left operand (double reference) <br />
Then the value of the double reference is returned. 

```C++
   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum = 100, ret;
   ret = sum += A; // sum and ret should be 500.0
```

## The tester program.
The tester program tests all the operator overloads and the output should be as follows:
```Text
Using bool conversion overload and operator ~ to print the accounts:
1: Acc#:  11111 , Balance:       111.11
2: Acc#:  22222 , Balance:       222.22
3: Invalid Account
4: Acc#:  44444 , Balance:      4444.44
5: Acc#:  55555 , Balance:       555.55
6: Invalid Account
7: Acc#:  77777 , Balance:       777.77
8: Acc#: Not Set, Balance:         0.00
9: Acc#: Not Set, Balance:         0.00
Depositing $50.02 into account #1 using += operator:
Acc#:  11111 , Balance:       161.13
Withdrawing $100.01 from account #2 using -= operator:
Acc#:  22222 , Balance:       122.21
Attempting to withdraw too much from account #4 using -= operator:
Acc#:  44444 , Balance:      4444.44
Attempting to deposit and withdraw negative amounts on account #4:
Acc#:  44444 , Balance:      4444.44
Acc#:  44444 , Balance:      4444.44
Sum of the balance of accounts 5 and 7
   in three different ways: 1333.32, 1333.32, and 1333.32
Setting the account number of account#8 to 88888:
before: Acc#: Not Set, Balance:         0.00
After:  Acc#:  88888 , Balance:         0.00
Moving the balance from account# 7 to Account #8 using operator=:
Before:
1: Acc#:  77777 , Balance:       777.77
2: Acc#:  88888 , Balance:         0.00
After:
1: Acc#:  77777 , Balance:         0.00
2: Acc#:  88888 , Balance:       777.77
Setting the account number to a bad value, rendering the account#7 invalid:
Invalid Account
Attempting to move balance of a valid account to an invalid one: (8 to 7)
This attempt should have no effect on either accounts
Before:
1: Invalid Account
2: Acc#:  88888 , Balance:       777.77
After:
1: Invalid Account
2: Acc#:  88888 , Balance:       777.77
Display raw account numbers of all the accounts
 using int conversion operator
11111 22222 -1 44444 55555 -1 -1 88888 0
Display raw balances of the accounts:
 using double conversion operator
161.13 122.21 0.00 4444.44 555.55 0.00 0.00 777.77 0.00
Display valid accounts using bool conversion operator
Acc#:  11111 , Balance:       161.13
Acc#:  22222 , Balance:       122.21
Acc#:  44444 , Balance:      4444.44
Acc#:  55555 , Balance:       555.55
Acc#:  88888 , Balance:       777.77
Acc#: Not Set, Balance:         0.00

Display valid accounts that are not new
using bool conversion operator and operator~()
Acc#:  11111 , Balance:       161.13
Acc#:  22222 , Balance:       122.21
Acc#:  44444 , Balance:      4444.44
Acc#:  55555 , Balance:       555.55
Acc#:  88888 , Balance:       777.77

```


## LAB Submission (part 1)

Upload your source code and the tester program (**Account.cpp, Account.h and accountMain.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w5/p1
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



# DIY (50%)
> Please note that you can (and probably should) add more member functions to make the DIY part work.

Files to submit:  
```Text
Mark.cpp
Mark.h
```

Create a Module for a **Mark** to encapsulate a mark between **0** and **100**.

| Mark              | Grade | Scale 4 mark |
|-------------------|-------|--------------|
| 0 =< Mark < 50    | F     | 0.0          |
| 50 <= Mark < 60   | D     | 1.0          |
| 60 <= Mark < 70   | C     | 2.0          |
| 70 <= Mark < 80   | B     | 3.0          |
| 80 <= Mark <= 100 | A     | 4.0          |


The class name must be **Mark**.

> **:warning:Important:** No values are allowed to be kept in mark out of the range of 0 to 100. In any circumstance and during any function if the value goes below 0 or above 100, the mark is set to an invalid empty state. This condition will not be repeated in during the workshop and applies to all the functions and operators of class **Mark**

## Construction
Mark can be created using on integer value (one argument constructor)that sets the value of the mark. If this value is not provided (no argument constructor), the value of the mark will be zero.
```C++
   Mark m, n(25), k(200), p(-10);
   // value of m is 0
   // value of n is 25
   // k is invalid
   // p is invalid
```
## Operator and conversion overloads
- Mark can be casted to the an integer (int type). The result would be the value of the mark or zero if the mark is in an invalid state.
```C++
  Mark m, n(25), k(200), p(-10);
   cout << int(m) << endl;
   cout << int(n) << endl;
   cout << int(k) << endl;
   cout << int(p) << endl;
```
**Ouptut:** 
```Text
0
25
0
0
```
- An integer can be added to the value of the mark using += operator; if the mark is invalid, the action is omitted. Reference of the mark is returned after the operation.
```C++
  Mark m, n(25), k(200);
  cout << int(m += 20) << endl;
  cout << int(n += 20) << endl;
  cout << int(k += 20) << endl;
  cout << int(n += 60) << endl;
```
**Output:** 
```Text
20
45
0
0
```
- Mark can be set to an integer using the assignment operator. If the mark is in an invalid state, the invalid value can be corrected by the assignment.Reference of the mark is returned after the operation. 
```C++
  Mark m, n(25), k(200);
  cout << int(m = 80) << endl;
  cout << int(n = 120) << endl;
  cout << int(k = 70) << endl;
```
**Output:** 
```Text
80
0
70
```
- Mark can be casted to a double, the result would be the GPA equivalent of the integer value. See the table of mark values above. Casting an invalid mark will result a zero value.
```C++
   Mark m(50), n(80), k(120);
   cout << double(m) << endl;
   cout << double(n) << endl;
   cout << double(k) << endl;
```
**Output:** 
```Text
1
4
0
```
- Mark can be casted to a character (char type), the result would be the grade letter value of the mark. See the table of mark values above. Casting an invalid mark will result a 'X' value.
```C++
   Mark m(50), n(80), k(120);
   cout << char(m) << endl;
   cout << char(n) << endl;
   cout << char(k) << endl;
```
**Output:** 
```Text
D
A
X
```
- Mark can be added to an integer, returning the integer after the operation. Invalid marks will not add any value to the integer.
```C++
   Mark n(80), k(120);
   cout << (val += n) << endl;
   cout << (val += k) << endl;
```
**Output:** 
```Text
140
140
```

  
##Tester program:
```C++
// Workshop 5:
// Version: 1.0
// Date: 10/18/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
/////////////////////////////////////////////

#include <iostream>
#include "Mark.h"
using namespace std;
using namespace sdds;
int main() {
   Mark m, n(25), k(200), p(-10);
   cout << "int ............" << endl;
   cout << int(m) << endl;
   cout << int(n) << endl;
   cout << int(k) << endl;
   cout << int(p) << endl;
   cout << "+= ............." << endl;
   cout << int(m += 20) << endl;
   cout << int(n += 20) << endl;
   cout << int(k += 20) << endl;
   cout << int(n += 60) << endl;
   cout << "= .............." << endl;
   cout << int(m = 80) << endl;
   cout << int(n = 120) << endl;
   cout << int(k = 70) << endl;
   cout << "double ........." << endl;
   m = 50; n = 80; k = 120;
   cout << double(m) << endl;
   cout << double(n) << endl;
   cout << double(k) << endl;
   cout << "char ..........." << endl;
   cout << char(m) << endl;
   cout << char(n) << endl;
   cout << char(k) << endl;
   cout << "int += Mark ..." << endl;
   int val = 60;
   cout << (val += n) << endl;
   cout << (val += k) << endl;
   return 0;
}
```
Here is the execution sample for the tester program
```Text
int ............
0
25
0
0
+= .............
20
45
0
0
= ..............
80
0
70
double .........
1
4
0
char ...........
D
A
X
int += Mark ...
140
140
```

> Modify the tester program to test all the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w5/p2
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
