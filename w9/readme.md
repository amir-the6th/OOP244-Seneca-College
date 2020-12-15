# Workshop #9: Function Templates
Version 1.0 

In this workshop, you are to code a function template to search through a compound type array and insert the matches found in the array, into a Collection of the same compound type.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

-	code a function template
-	implement a call to a function template
-	describe what you have learned in completing this workshop




## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- *Lab* (part 1): worth 100% of the workshop's total mark, is due on **Friday at 23:59:59** of the week of your scheduled lab.
- *reflection*: non-coding part, is due on **Sunday at 23:59:59** of the week of your scheduled lab. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

**The code that is submitted late receives 0%.**  On Sunday at midnight the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

If the file contains only your work or work provided to you by your professor, add the following message as a comment at the top of the file:


> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.


# Lab (Part 1, 100%)

Look at the code provided in the **Collection** template module, study it and understand it. The Collection class is a template that works like a dynamic array of objects and resizes itself as objects are added to it. The code snippet below demonstrates how Collection works:  
```C++
Collection<double> Cdbl;
Cdbl.add(1.23);
Cdbl.add(2.34);
Cdbl.add(3.45);
cout << "There are " << Cdbl.size() << " items in the Collection!" << endl;
for(int i=0; i< Cdbl.size();i++){
    cout << Cdbl[i] << endl;
}
```
Output:
```Text
There are 3 items in the Collection!
1.23
2.34
3.45
```
## Supplied Modules:
`ReadWrite` Module, `Collection` Module, `Employee` Module, `Student` Module and `Car` Module

**Do not modify these modules!**  Look at the code and make sure you understand them.


## `search` function template

Using the Collection template, Create a function template called **search** in a file called `search.h` that accepts four arguments:
- an array of objects (template)
- number of elements in the array
- a Cstring **key** value to search for
- A Collection reference of the same objects in the array (template)

The search function returns a bool that is true only if at least one match to the key is found in the array and false otherwise. 
The search function adds all the matches in the array to the Collection reference argument.


## the main module
Modify the main module and call the **search** function as the condition of the four **if** statements in the source code.

```C++
// Workshop 9:
// Version: 1.0
// Date: 11/22/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
// Modify the main function as stated in the workshop description
/////////////////////////////////////////////
#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#include "Collection.h"
#include "search.h"
using namespace std;
using namespace sdds;

int main() {
   Car C[8] = { Car("GVFGHI", "Tesla Model S"), Car("ABCDEF", "BMW 320"), Car("CDEFGH", "Ford Festiva"), 
                Car("BCDEFG", "Ford Festiva"),Car("GVDGHI", "Tesla Model 3"), Car("EFGHIJ", "Nissan Maxima"), 
                Car("GVDEFG", "Tesla Model X") };
   Student S[6] = { Student(23456, "Lisa Simpson"),Student(45678, "Ralph Wiggum"), Student(56789, "Milhouse Van Houten"), 
                Student(67890, "Todd Flanders"), Student(34567, "Nelson Muntz"),Student(12345, "Bart Simpson") };
   Employee E[6] = { Employee(213456, "Carl Carlson", 62344.56), Employee(122345, "Mindy Simmons", 65432.44), 
                Employee(435678, "Lenny Leonard", 43213.22), Employee(546789, "Waylon Smithers", 654321.55), 
                Employee(657890, "Frank Grimes", 34567.88), Employee(364567, "Homer Simpson", 55432.11) };
   Collection<Car> Cres;
   Collection<Student> Sres;
   Collection<Employee> Eres;
   cout << "Searching for Tesla cars: " << endl;

   // Call the search function passing "Tesla" as the key argument and "Cres" for Collection 
   if (Call the search here) {
      cout << Cres.size() << " match" << (Cres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Cres.size(); i++) {
         cout << (i + 1) << ": " << Cres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << "Searching for students with \"Simpson\" in their name" << endl;
   // Call the search function passing "Simpson" as the key argument and "Sres" for Collection 
   if ( Call the search here ) {
      cout << Sres.size() << " match" << (Sres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Sres.size(); i++) {
         cout << (i + 1) << ": " << Sres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << "Searching for employees with \"Sim\" in their name" << endl;
   // Call the search function passing "Sim" as the key argument and "Eres" for Collection 
   if ( Call the search here ) {
      cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Eres.size(); i++) {
         cout << (i + 1) << ": " << Eres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << "Searching for employees with \"Jack\" in their name" << endl;
   // Call the search function passing "Jack" as the key argument  and "Eres" for Collection 
   if ( call the search here) {
      cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Eres.size(); i++) {
         cout << (i + 1) << ": " << Eres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   return 0;
}
```
## output

```Text
Searching for Tesla cars:
3 matches found:
1: GVFGHI Tesla Model S
2: GVDGHI Tesla Model 3
3: GVDEFG Tesla Model X
Searching for students with "Simpson" in their name
2 matches found:
1: 23456 Lisa Simpson
2: 12345 Bart Simpson
Searching for employees with "Sim" in their name
2 matches found:
1: 122345 Mindy Simmons, 65432.44
2: 364567 Homer Simpson, 55432.11
Searching for employees with "Jack" in their name
No matches found!

```
## Submission

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w9/p1
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.


# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


## Submission

Run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w9/p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
