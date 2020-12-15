# Workshop #4: Constructors Destructors and Current object
* Version 1.2 (corrected workshop number from 5 to 4 (thanks Tim Lin for pointing it out))
* Version 1.1 (corrected the Box& add(Box&) function description and clarified DIY additional function creation)

In this workshop, you will use Constructors, a Destructor and reference of the current object to simulate a Box for holding bulk material. 

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define default constructor
- define custom constructor with different number of arguments
- define a Destructor to prevent memory leak.
- Use reference of the current object 
- describe to your instructor what you have learned in completing this workshop

## Submission Policy

The workshop is divided into two coding parts; part 1, **LAB** and part 2, **DIY**  and one non-coding part:

- ***LAB*** (part 1): worth 50% of the workshop's total mark, is due on **Wednesday at 23:59:59** of the week of your scheduled lab.
> Please note that the LAB (part 1) section is **not to be started in your lab session**. You should start it on your own before the day of your lab and and join the lab session to ask for help and correct your mistakes.
- ***DIY*** (part 2): worth 50% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *DIY* part that do not contain the *reflection* are not considered valid submissions and are ignored.
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
# LAB (50%) The Box Module

Your task for this lab is to create a **Box** module for holding bulk material. The **Box** can be created in different ways; 
- By default a **Box** is created as a cube with no content; 12x12x12 inches.  
- A Cubical Box is created with one value for all the three dimensions and an optional value for the name of the content of the box.
- A freestyle box is created with three different values for width, length, and height of the box with an optional value for the name of the box.

When constructed, the boxes are empty with or without a content name.

The content name of the box can be set later with a member function.

After the box is created the bulk material can be poured into the box by specifying the quantity of the material. If the quantity of the poured material causes an overflow, that is being more than the capacity of the box, The box becomes useless and unusable. These boxes are thrown away and the material inside is discarded. 

You can pour the material from one box into another box, only if the contents are the same. If the material is too much for the capacity of the box, the target box will become full and the source box will lose the exact amount of material poured into the target box.<br />
If the materials are not the same, however, the target box with mixed material will become useless and unusable. The source box however will just lose the material poured into the discarded box.

Note that a Box can not have a dimension value less than 5 inches or greater than 36 inches.

## Implementation

To implement the Box do the following:

Create a class called Box that has the following member variables: (Box Module)

```C++
    char* m_contentName;   // the conent name pointer:
                           // this pointer holds the name of the material to be kept in the box
                           // dynamically
    int m_width;           // The dimensions of the box in Inches
    int m_height;
    int m_length;
    int m_contentVolume;   // the content volume:
                           // This variable holds the volume of the material currently in 
                           // the box in Cubic Inches
```

Also create the following **private member functions** for the internal processes of the Box:

```C++
      void setName(const char* Cstr);
```
The function **setName** is used to set the name of the content of the Box dynamically to the incoming CString argument:
- Check the Cstr argument for being null; if it is null, then take no action and exit the function otherwise go to the next step.
- delete the Box's content name just in case it has previously allocated memory (*ie the name had been set before*)
- allocate memory for the content name to the size of the Cstr + 1 for the null byte
- copy the Cstr into the content name.


```C++
      void setUnusable();
```
This function sets the **Box** to an unusable and recognizable *empty state* as follows:
- deletes the content name and sets it to null
- sets all the other member variables to -1 

```C++
      bool isUnusable()const;
```
This function returns true if the Box is unusable. You can do this by checking any of the member variables that represent a dimension of the Box are equal to -1 which means it's unusable.

```C++
      bool hasContent()const;
```
This function return true if the content volume or **quantity()** is greater than zero.

## Constructors 

```C++
    Box();
```
The default constructor will set the member variables to the following default values;
- all the three dimensions are set to 12 inches
- the content name pointer is set to null
- the content volume is set to zero.

Note that the default constructor sets the box to an empty cubical 12-inch box that is empty and ready to be used. 

```C++
    Box(int sideLength, const char* contentName = nullptr);
```
This constructor will make a cubical box (all three sides the same size).<br />
The constructor will first set the content name pointer to **nullptr** and then:
- if any of the side lengths is not between 5 and 36, the box is set to be unusable and the function ends.
- if the side length is valid, then all three dimensions (width, height and length) are set to the sideLength value.
- the content volume is set to zero.
- Name is set to the content name value (using setName function)


```C++
    Box(int width, int height, int length, const char* contentName = nullptr);
```
This constructor will make a freestyle box.<br />
The constructor will first set the content name pointer to **nullptr** and then:
- if any of the width, height and length are not between 5 and 36, the box is set to be unusable and the function ends.
- if the dimensions are valid, then all three dimensions (m_width, m_height and m_length) are set to the corresponding arguments.
- the content volume is set to zero.
- The Box's content name is set to the respective argument (using the setName function)

## Destructor

Deallocate the allocated memory for the content name.

## Public Member Functions

```C++
  int capacity()const;
```
This function returns the product of m_width, m_height and m_length. (i.e. the volume of the box)

```C++
  int quantity()const;
```
This function return the content volume member variable.

```C++
  Box& setContent(const char* contentName);
```
setContent sets the content name to the parameter using the set name function and returns a reference of the current object.<br />
However if the box is already filled with material (use hasContent() function to validate) and has a non-empty content name, then the box is set to be unusable. This prevents mixing different material in a box.
In either case the reference of *the current object is always returned*.

```C++
  std::ostream& display()const;
```
This function displays the box information and returns the **cout** object.
Here is the format and sequence of the printed data:  
- In 30 spaces, left justified and spaces filled with the dot **'.'** the content name is printed. if the content name is null **"Empty box"** is printed instead
- one space
- in 2 spaces padded with zero, right justified **width** is printed
- the character **'x'**
- in 2 spaces padded with zero, right justified **height** is printed
- the character **'x'**
- in 2 spaces padded with zero, right justified **length** is printed
- one space
- in 6 spaces, right justified **quantity()** is printed
- the character **'/'**
- the **capacity()** is printed and then **" C.I."**

However if the object is unusable the following statement is printed: <br />
**"Unusable box, discard the content, and recycle."**<br />

In any case the object **cout** is returned.

```C++
  Box& add(int quantity);
```
If the parameter quantity is a positive value and the quantity value fits in the empty space in the box the quantity will be added to the content volume, otherwise the object will be set to unusable.
In any case the reference of the current object is returned.

> you can check this by comparing the sum of the qty argument and the **quantity()** of the box and the **capacity()** of the box. If the sum is less than the capacity, you are good to go, otherwise the box is unusable.

```C++
  Box& add(Box& B);
```
This function pours the content of one box into another. If the target box is full, the rest of the material remains in the source box **B**. If the target box has no name ~~and~~ or is empty, it will get the same name as the source box. If the material are not the same, the target box becomes unusable and the source box will lose the material poured in the target box.<br />
Here is the source code for this funciton:
```C++
  if (m_contentName == nullptr || quantity() == 0) {
     setContent(B.m_contentName);
  }
  if (strcmp(m_contentName, B.m_contentName) == 0) {
     if (quantity() + B.quantity() <= capacity()) {
        add(B.quantity());
        B.m_contentVolume = 0;
     }
     else {
        B.m_contentVolume -= (capacity() - quantity());
        m_contentVolume = capacity();
     }
  }
  else {
     if (quantity() + B.quantity() <= capacity()) {
        B.m_contentVolume = 0;
     }
     else {
        B.m_contentVolume -= (capacity() - quantity());
     }
     setUnusable();
  }
  return *this;
```


## LAB Submission (part 1)

Upload your source code and the tester program (**Box.cpp, Box.h and boxMain.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w4/p1
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



# DIY (50%)
> Please note that you can (and probably should) add more member functions to make the DIY part work.


Files to submit:  
```Text
NameTag.cpp
NameTag.h
```

Create a Module for a NameTag to create/read information for a name tag and print it.

The class name must be **NameTag**.

It should be able to hold two pieces of information; A name and a 5 digit extension number. The name should be kept dynamically; however if the name is longer than 40 characters, only 40 characters should be used. 
> After dynamically allocating the name, you can easily do this by setting the 40th character in the name to null if the length of the name is longer than 40.

Also if the name is shorter than 20 characters, it should be printed in 20 spaces. The extension number is optional and if not provided, it should be printed as **N/A**.

Print the name tag by drawing a box around it. The box must have five interior lines and the name should have exactly one space distance with the line of the box at left and minimum of one space with the line at right. The name and the extension are printed on lines 2 and 4 and the rest of the name tag is filled with spaces.

Here are couple of examples: <br />
(Name: "Fred Soley", extension 12345):
```Text
************************
*                      *
* Fred Soley           *
*                      *
* Extension: 12345     *
*                      *
************************

```
(Name: "David Wright Mason Gilmour Waters Rogers Nick", extension not available)
```Text
********************************************
*                                          *
* David Wright Mason Gilmour Waters Rogers *
*                                          *
* Extension: N/A                           *
*                                          *
********************************************
```

If the data provided are invalid, (name being null or extensions being more or less than 5 digits) the printout will be:
```Text
EMPTY NAMETAG!
```

## Public and mandatory functions, constructors and destructor
### constructors
- default constructor (for an empty tag)
- constructor with one argument to set the name without extension number
- constructor with two arguments to set the name and the extension

### destructor
- have a destructor to avoid memory leaks

## Functions:
### print
a function called **print** to print the name tag as shown above

### read
a function called **read** that receives the name and then the extension number and then returns the reference of the current object (NameTag&).

Read function should read the name up to the maximum of 40 characters and ignore the rest and then set the name of the **NameTag** to the entered name. <br />
(This may overwrite an already existing name in the **NameTag**)<br />
Then it should give an option to the user to enter the extension number or not. If the user chooses to enter the extension it should enforce the user to enter a 5 digit integer and if user does not comply, it should print the following message:<br />
```Text
Invalid value [10000<=value<=99999]: 
```
and get the new value and repeat until the user enters a correct value. 

A sample for execution is provided below; Note that the **read()** execution is demonstrated right before the name tag printouts.

```Text
Please enter the name: Fred Soley
Would you like to enter an extension? (Y)es/(N)o: n
************************
*                      *
* Fred Soley           *
*                      *
* Extension: N/A       *
*                      *
************************
Please enter the name: David Wright Mason Gilmour Waters Rogers Nick
Would you like to enter an extension? (Y)es/(N)o: y
Please enter a 5 digit phone extension: 9999
Invalid value [10000<=value<=99999]: 1000000
Invalid value [10000<=value<=99999]: 65432
********************************************
*                                          *
* David Wright Mason Gilmour Waters Rogers *
*                                          *
* Extension: 65432                         *
*                                          *
********************************************
```
  
##Tester program:
```C++
// Workshop 4:
// Version: 0.9
// Date: 10/09/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
/////////////////////////////////////////////
#include <iostream>
using namespace std;
#include "NameTag.h"
using namespace sdds;
int main() {
   NameTag nt[6] = {  
      "David Wright Mason Gilmour Waters Rogers Nick", // one argument constructor
      {"Fred Soley", 12345} ,       // two argument constructor with good data
      {nullptr, 23456},    // two argument constructor with bad name
      {"Bad number", 1234},  // two argument constructor with bad number
      {"Bad number", 123456}  // two argument constructor with bad number
                             // default constructor (sixth element)
   };
   int i;
   for (i = 0; i < 6; i++) {
      nt[i].print();
      cout << endl;
   }
   nt[1].read().print();
   nt[3].read().print();
   nt[5].read().print();
   return 0;
}

```
Here is the execution sample for the tester program
```Text
********************************************
*                                          *
* David Wright Mason Gilmour Waters Rogers *
*                                          *
* Extension: N/A                           *
*                                          *
********************************************

************************
*                      *
* Fred Soley           *
*                      *
* Extension: 12345     *
*                      *
************************

EMPTY NAMETAG!

EMPTY NAMETAG!

EMPTY NAMETAG!

EMPTY NAMETAG!

Please enter the name: John Doe<ENTER>
Would you like to enter an extension? (Y)es/(N)o: n
************************
*                      *
* John Doe             *
*                      *
* Extension: N/A       *
*                      *
************************
Please enter the name: A very very long name that is more than 40 characters<ENTER>
Would you like to enter an extension? (Y)es/(N)o: y<ENTER>
Please enter a 5 digit phone extension: 76543<ENTER>
********************************************
*                                          *
* A very very long name that is more than  *
*                                          *
* Extension: 76543                         *
*                                          *
********************************************
Please enter the name: Jane Doe<ENTER>
Would you like to enter an extension? (Y)es/(N)o: y<ENTER>
Please enter a 5 digit phone extension: 1234<ENTER>
Invalid value [10000<=value<=99999]: 123456<ENTER>
Invalid value [10000<=value<=99999]: 76543<ENTER>
************************
*                      *
* Jane Doe             *
*                      *
* Extension: 76543     *
*                      *
************************
```

> Modify the tester program to test are the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w4/p2
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
