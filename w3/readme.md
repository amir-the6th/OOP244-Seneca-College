# Workshop #3: Member Functions and Privacy
* Version 1.1 (added a "note" to the init function of Transcript)

In this workshop, you will use member functions, privacy , safe empty state and formatting the output to complete your work.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- to define a class type
- to privatize data within the class type
- to instantiate an object of class type
- to access data within an object of class type through public member functions
- to use standard library facilities to format data inserted into the output stream
- to describe to your instructor what you have learned in completing this workshop

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

# LAB (50%) Student Transcript

Your task for this lab is to create a program that provides a class called **Transcript** that can be initiated using a student name and number of completed **Subject**s by the student.

Then the **Subject**s will be added one at the time to the Transcript by their name and the mark received for the subject out of 100.

The **Transcript** then can be displayed as a report. All the marks in the transcript should be converted to grades using the following table and the GPA should be calculated and displayed at the bottom of the page using the Scale 4 mark.

## Marks and their Grade and Scale 4 conversions

| Mark              | Grade | Scale 4 mark |
|-------------------|-------|--------------|
| 0 =< Mark < 50    | F     | 0.0          |
| 50 <= Mark < 60   | D     | 1.0          |
| 60 <= Mark < 70   | C     | 2.0          |
| 70 <= Mark < 80   | B     | 3.0          |
| 80 <= Mark <= 100 | A     | 4.0          |

## Sample main program and execution sample
```C++
#include "Transcript.h"
using namespace sdds;
int main() {
   Transcript T;
   T.init("Fred Soley", 5);
   T.add("EAC150", 65);
   T.add("DBS211", 85);
   T.add("DCF255", 75);
   T.add("OOP244", 95);
   // Premature call to display will result an error
   T.display();
   T.add("WEB222", 100);
   // Proper and timely call to display transcript
   T.display();
   T.deallocate();
   return 0;
}
```
```Text
Invalid Transcirpt!
Fred Soley
-----------------------------
EAC150          65         C
DBS211          85         A
DCF255          75         B
OOP244          95         A
WEB222         100         A
-----------------------------
                     GPA: 3.4
```


## Implementation

Implement this program in two modules (ie. classes):  
**Subject** and **Transcript** 

Files to submit:  
```Text
transcriptTester.cpp <--- contains the main function
Subjct.cpp
Subjct.h
Transcript.cpp
Transcript.h
```
### The Subject Class
Develop this class in files **Subject.h** and **Subject.cpp**

#### Private Member Variables (attributes)
The class subject should have the following member variables:

```C++
  char m_code[7]; // holds the subject code (exactly 6 characters)
  int m_mark;     // the mark out of 100
```
#### Private Member functions (Methods)
```C++
char grade()const;
```
This function returns the grade value of the mark held in the m_mark attribute and is incapable of modifying its owner (Subject)

See the [Marks and their Grades table](#Marks-and-their-Grade-and-Scale-4-conversions) to form your selection algorithm for the grade.

#### Public Member functions (Methods)
```C++
void setEmpty();
```
Sets the **Subject** to a recognizable safe Empty State. Do this by setting the mark to an impossible value like **-1** and setting the **m_code** to a blank string (first char set to null).

```C++
void set(const char* code, int mark);
```
Sets the Subjects code and mark to valid values. If the mark is an invalid mark (less than zero or greater than 100) the function will set the **Subject** object to the empty state. 

```C++
   float scale4()const;
```
Returns the Scale 4 (mark out of 4) values of the mark. This function can not modify its owner.

Same as the grade function; see the [Marks and their Grades table](#Marks-and-their-Grade-and-Scale-4-conversions) to form your selection algorithm to return the proper float value (0.0 -> 4.0)

```C++
bool isValid()const;
```
Returns true if the Subject is not in the empty state (ie. mark is greater or equal to zero) . This function can not modify its owner.

```C++
 void Subject::display()const;
```
If the subject is valid it will display the **Subject** in the following format:

- Subject code in 15 spaces, left justified.
- the mark in 3 spaces, right justified. 
- The grade in 10 spaces, right justified.

Otherwise this function will take no action.

### The Transcript Class

#### Private Member Variables (attributes)
The class **Transcript** should have the following member variables:

```C++
  char* m_studentName; // pointer to hold the student name dynamically 
  Subject* m_subjects; // pointer to hold the subjects in the Transcript dynamically
  int m_noOfSubjects;  // Number of subjects or number of elements in the array of m_subjects.
  int m_subjectsAdded; // Number of subjects in the m_subjects array that are set to thier values properly (they are not empty)
```

#### Private Member functions (Methods)
```C++
    void setEmpty();
```
Sets the **Transcript** object to an empty state by setting **m_studentName** and **m_subjects** to **nullptr**

```C++
    bool isValid()const;
```
Makes sure **m_studentName** and **m_subjects** are not null and then goes through all the **Subject** objects in the **m_subjects** array and makes sure they are all valid. If even one of the **Subject**s in the **m_subjects** array is invalid, this function will return false, otherwise it returns true.

```C++
    void Title()const;
```
First it will print the Student Name, then in the next line it prints a line using 29 dash('-') characters and then prints a new line:
```Text
Fred Soley
-----------------------------
```

```C++
    float gpa()const;
```

Calculates the GPA by finding the average of the **Subject** marks out of 4. 

Find the average by looping through **m_subjects** array and accumulating the return value of the **scale4()** functions of the **Subject** objects and dividing them by the number of the elements of the array.

```C++
    void footer()const;
```

Prints 29 dashes('-') and in the next line on position 22 it will print "GPA: " and then prints the return value of the **gpa()** function with one digit after the decimal point:

```Text
-----------------------------
                     GPA: 3.4
```
#### Public Member functions (Methods)

```C++
    void init(const char* studentName, int noOfSubjects);
```

If any of the arguments are invalid, it will set the Transcript to an empty state (ie. **studentName** is null or **noOfSubjects** is less than one)

Otherwise if the incoming arguments are valid:

- **init()** function will first set the **m_noOfSubjects** member variable to the incoming corresponding argument and sets **m_subjectsAdded** to zero.
- Next it will dynamically allocate memory for the student name in **m_studentName** and then copies the name into the allocated memory. 
- Then it will dynamically allocate an array of **Subject**s pointed by **m_subjects** member variable. The length of this array will be  **m_noOfSubjects**.
> Make sure all the dynamically allocated **Subject**s are set to empty


```C++
    bool add(const char* subject_code, int mark);
```

If number of added **Subject**s (**m_subjectsAdded**) is less than the length of the **m_subjects** array, this function will set the next available subject to the incoming argument values. Then it will add one to the **m_subjectsAdded** and return true;

Otherwise this function will do nothing, returning false;

```C++
    void display()const;
```

If the **Transcript** is in a valid state, this function will first print the **title()**, then it will loop through the **m_subjects** elements, printing every one of them, and finally prints the **footer()**. This function can not modify the Transcript. 

```Text
Fred Soley
-----------------------------
EAC150          65         C
DBS211          85         A
DCF255          75         B
OOP244          95         A
WEB222         100         A
-----------------------------
                     GPA: 3.4
```
If the **Transcript** is **NOT** in a valid state, the function only prints the following line and goes to new line.
```Text
Invalid Transcirpt!
```

```C++
    void deallocate();
```
Deallocates the **m_studentName** and the **m_subjects** arrays and sets the pointers to null.


## The tester program
Modify the [tester program](#Sample-main-program-and-execution-sample) provided to test all circumstances of execution.<br />
Note that when submitting, the professor's tester program will have more test data than the tester provided here.


## LAB Submission (part 1)

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w3/p1
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



# DIY (50%)
> Except from the mandatory sections of DIY, all the other parts can be changed by students if they find it necessary as long as the program produces an output that exactly matches the required output.

Write a **Bar Chart** program that receives several samples values and creates a bar chart based on the values received. 

A **BarChart** is a collection of valid **Bar**s that are drawn horizontally on the screen:  
  
```Text
Bar Chart Title
-----------------------------------------------------------------------
First sample title..|=====
Second Sample.......|=============================================
Third Sample........|====================
Fourth..............|=======
Fifth...............|=========================
And Six.............|===============
-----------------------------------------------------------------------
```

A sample consists of a title and an integer value between 0 and 100.

The **BarChart** is initialized by the title of the survey, the number of the samples (ie. Bars to be drawn) and the fill character to draw the bars.

> The **Title of the chart** and **the Bars** in the **BarChart** are to be held dynamically.

Each sample is **added** to the chart by the **title** and the **value** of the sample to be represented by a **Bar** in the **BarChart**. 

> Note: The length of the bar will be "the **value** divided by 2", which means, a value of 10 will be displayed by a bar that is 5 characters long or a value of 41 will be displayed by a bar that is 20 characters long and so on...

When displaying the **BarChart**, If the **number of added samples** is not the same as **the number of samples**, or if any of the **Bar**s in **BarChart** are invalid, then the Chart will be considered invalid and a proper error message will be displayed when attempted to draw the chart prematurely . (see main and execution sample below)

Here is a sample of the main program using the **BarChart** Class and its execution result:

```C++
#include <iostream>
#include "BarChart.h"
using namespace sdds;
using namespace std;
int main() {
   BarChart bc;
   bc.init("How much students like this lab.", 5, '=');
   bc.add("Best Lab Ever", 10);
   bc.add("Good Lab", 30);
   bc.add("Doable Lab", 40);
   cout << "Premature draw call:"<< endl; 
   bc.draw(); // will not draw; it will print an error instead
   bc.add("Bad Lab", 15);
   bc.add("Worst Lab Ever", 5);
   cout << "Proper draw call after all sampels are entered:" << endl;
   bc.draw();
   bc.deallocate();
   return 0;
}
```
Execution sample:
```Text
Premature draw call:
Invalid Chart!
Proper draw call after all sampels are entered:
How much students like this lab.
-----------------------------------------------------------------------
Best Lab Ever.......|=====
Good Lab............|===============
Doable Lab..........|====================
Bad Lab.............|=======
Worst Lab Ever......|==
-----------------------------------------------------------------------
```

Files to submit:  
```Text
chartMain.cpp <--- contains the main function
Bar.cpp
Bar.h
BarChart.cpp
BarChart.h
```
## Bar Module
### Suggested member variables
- a Cstring to hold maximum of 20 characters for title
- a char variable to hold the fill character
- an integer variable to hold the sample value of the Bar

### Suggested public member functions
- a function to set the Bar to the empty state
- a function to set the title, fill character and value of the bar and set the fuction to invalid state if the value is not acceptable (less than zero or more than 100)
- a function that returns "if the Bar is valid or not"

### Mandatory public member function
Write a member function called **draw** that does not accept any parameters and can not modify the bar.

This function should draw a bar with as follows.<br />
For example if the **title** of the bar is "**Number of cakes**", the **fill** character is asterisk (**'*'**) and the value is **51**; the Bar should be drawn exactly like this:  

```Text
Numberof cakes......|*************************<NEWLINE>
```
- Print the title in 20 characters and fill the spaces with dot character (**'.'**). 
- print a pipe character (**'|'**)
- print the fill character to **the value divided 2** (ie. 51/2 -> 25)

If the value of the Bar is invalid (less than zero or more than 100) this function takes no action.

### barTester program:  
```C++
#include "Bar.h"
using namespace sdds;
int main() {
   Bar b;
   for (int i = 1; i <= 5; i++) {
      b.set("the bar", '=', i*20);
      b.draw();
   }
   b.set("Bad Bar", '=', -200);
   b.draw();
   b.set("Bad Bar", '=', 200);
   b.draw();
   return 0;
}
```
### bar tester output
```Text
the bar.............|==========
the bar.............|====================
the bar.............|==============================
the bar.............|========================================
the bar.............|==================================================
```


## BarChart Module
### Mandatory member variables
- a **character pointer** to hold the dynamically allocated "title of the chart"
- a **Bar pointer** to hold the dynamically allocated array of **Bar**s.

### Suggested member variables
- a **character variable** to hold the fill character
- an **integer variable** to hold the size of the dynamically allocated array of **Bar**s
- an **integer variable** to keep track of number of added samples to set the **Bar**s.

### Suggested member function
- a function to return if all the **Bar**s are in a valid state or not.

### Mandatory member functions

```C++
    void init(const char* title, int noOfSampels, char fill);
```
Initializes the Chart as explained before.

```C++
    void add(const char* bar_title, int value);
```
Sets the next available **Bar**, or does nothing if they are all already set.
```C++
    void draw()const;
```
If The **BarChar** is valid and if all the **Bar**s in the Chart are valid it draws the bar exactly as follows:
- prints the title of the Chart and goes to new line
- prints 71 dashes ('-') and goes to new line
- prints all the Bars
- prints 71 dashes ('-') and goes to new line
Otherwise it will print:  
```Text
Invalid Chart!<NEWLINE>
```

```C++
    void deallocate();
```
Deallocates all the dynamically allocated memory.

> Modify the tester program to test are the different circumstanced of the application and note that the professor's tester may have many more samples than the tester program here.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w3/p2
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
