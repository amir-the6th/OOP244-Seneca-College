# Workshop #7: Virtual functions and Abstract base classes

In this workshop, you will create a hierarchy of classes to practice and understand the role of virtual functions in inheritance. 
The workshop consists of 4 classes:  
- Shape; encapsulates a shape that can be drawn on the screen<br />
(An interface, that is an abstract base class with only pure virtual functions)
- LblShape; encapsulates a shape that can be labeled<br />
(An abstract base class that represents a labeled shape) 
- Line; encapsulates a horizontal line on a screen with the label <br />
(this concrete class draws a labeled line)
- Rectangle; encapsulates a rectangle on the screen that can be labeled<br />
(this concrete class draws a rectangle with a label inside).


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define pure virtual functions
- create abstract base classes
- implement behavior using virtual functions
- explain the difference between an abstract base class and a concrete class
- describe what you have learned in completing this workshop


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


# lab (part 1) (100%)

Complete the code provided in workshop eight in the following four modules; **Shape, LblShape, Line** and **Rectangle**

![Classes](images/classes.png)


## 1- The `Shape` interface

### Create two pure virtual functions:
> a pure virtual function is a virtual function that has no implementation.  To indicate that the pure virtual function does not have implementation set its prototype to zero (```= 0;```) in the class declaration.

#### draw 
Returns void and receives as a reference to **ostream** as an argument.  This pure virtual function can not modify the current object.

#### getSpecs
Returns void and receives a reference to **istream** as an argument. 

### `destructor`
Create a virtual empty destructor for the shape interface. 
> this guarantees that any dynamically allocated derived class from the shape interface pointed by a base class pointer will be removed properly from memory when deleted.

### `Shape` helper functions
Overload the insertion and extraction operators so any shape object can be read or written using ostream and istream.


## 2- The `LblShape` abstract Class (the Labeled Shape class)
Inherit an abstract class from the interface `Shape` called `LblShape`.  This class adds a label to a `Shape`.

This class will implement the pure virtual function **getSpecs** but will not implement the draw function; therefore it remains abstract.

### Private Member variable
Add a character pointer member variable called **m_label** and initialize it to null.  This member variable will be used to hold the dynamically allocated label for the `Shape`.


### Protected members 
#### ```const char* label() const```
Add a query called **label** that returns m_label member variable. 

### public members
#### Default (no argument) constructor
Sets the label pointer to null. (You don't need to do this if the **m_label** is already initialized to null)
#### One argument constructor
Allocates memory large enough to hold the incoming Cstring argument pointed by the **m_label** member variable.  Then copies the Cstring argument to the newly allocated memory.
#### Destructor
Deletes the memory pointed by **m_label** member variable.
#### deleted actions
The copy constructor and assignment operator are deleted to prevent copying or assignment of instances of this class.
#### getSpecs
Reads a comma separated Cstring form istream: <br /> 
Override the **Shape::getSpecs** pure virtual function to receive a Cstring (a label) from **istream** up to 20 characters or **','** character, whichever comes first.  Afterward, follow the same logic as was done in the one argument constructor; allocate memory large enough to hold the Cstring and copy the Cstring into the newly allocated memory. 
Then ignore all the characters coming from the istream up to and including the **','** character.

- create a local character array of 21 characters.
- using the istream's **get** function read 21 characters up to the **','** character.
- do the DMA as mentioned above.
- using the "ignore" function of istream, ignore all the characters up to and including **','**


## 3- The `Line` concrete class
Line inherits the **LblShape** class to create a horizontal line with a label.

### Private Member variable
Create a member variable called **m_length** to hold the length of the **Line** in characters.

#### Default (no argument) constructor
Sets the **m_length** member variable to zero, and invokes the default constructor of the base class. 
#### Two argument constructor
Receives a Cstring and an integer from the argument list.  Passes the Cstring to the constructor of the base class and sets the **m_length** member variable to the value of the second argument.

#### Destructor
This class has no destructor implemented.

#### getSpecs
Reads comma-separated specs of the **Line** from istream.<br />
This function overrides the **getSpecs** function of the base class as follows.<br />
First, it will call the **getSpecs** function of the base class then it will read an integer from the istream argument, and then it will ignore The rest of the characters up to and including newline character **'\n'**.

#### draw
This function overrides the draw function of the base class.<br />
If the **m_length** member variable is greater than zero and the **label()** is not null, this function will first print the **label()** and then go to new line.  Afterwards it keeps printing the **'='** (assignment character) to the value of the **m_length** member variable.<br />
Otherwise, it will take no action.

For example, if the Cstring returned by the label query is "Separator" and the length is 40, the draw function should insert the following into ostream:

```Text
Separator
========================================
```
## 3- The `Rectangle` concrete class
The Rectangle class inherits the **LblShape** class to create a frame with a label inside.

### Private Member variable
Create two integer member variables called **m_width** and **m_height** to hold the width and the height of a rectangular frame.

#### Default (no argument) constructor
Sets the width and height, integer member variables to zero.  It will also invoke the default constructor of the base class.

#### Three argument constructor
Receives a Cstring for the label, and two integers for the width and height of the **Rectangle** from the argument list.  Passes the Cstring to the constructor of the base class and sets the **m_width** and **m_height** member variables to the corresponding values received from the argument list.
However if the **m_height** is less than 3 or **m_width** is less the length of the **label() + 2** it will set the Rectangle to an empty state.

#### Destructor
This class has no destructor implemented.

#### getSpecs
Reads comma-separated specs of the **Rectangle** from istream.<br />
This function overrides the **getSpecs** function of the base class as follows.<br />
First, it will call the **getSpecs** function of the base class, then it will read two comma-separated integers from istream and then ignores the rest of the characters up to and including newline character (**'\n'**).

- call LblShape::getSpecs
- read an integer from istream into **m_width**
- ignore a comma
- read an integer from istream into **m_length**
- ignore remaining characters up to and including the newline character

#### draw
This function overrides the draw function of the base class.<br />
If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows, otherwise, it will do nothing:

First line:<br />
prints '+', then prints the '-' character (m_width - 2) times and then prints '+' and goes to newline.

Second line:<br />
prints '|', then in (m_width-2) spaces it prints the **label()** left justified and then prints '|' and goes to new line.

In next (m_height - 3) lines:<br />
prints '|', (m_width-2) spaces then prints '|' and goes to new line.

Last line: <b />
exactly like first line.

For example, if the Cstring returned by the label query is "Container", the width is 30 and the height is 5, this function should insert the following into ostream:

```Text
+----------------------------+
|Container                   |
|                            |
|                            |
+----------------------------+
```



## `main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.

### Sample Output

```Text
Separator
==================================================
+----------------------------+
|Container                   |
|                            |
|                            |
+----------------------------+
Enter the following:
>Line two,40<ETNER>
>Line two,40
The following outputs should be the same
The correct output:
Line two
========================================
Your output:
Line two
========================================
Enter the following:
>A 50 by 4 frame,50,4<ETNER>
>A 50 by 4 frame,50,4
The following outputs should be the same
The correct output:
+------------------------------------------------+
| A 50 by 4 frame                                |
|                                                |
+------------------------------------------------+
Your output:
+------------------------------------------------+
|A 50 by 4 frame                                 |
|                                                |
+------------------------------------------------+
printing Line and Rectangle using Shape pointers:
Line two
========================================
+------------------------------------------------+
|A 50 by 4 frame                                 |
|                                                |
+------------------------------------------------+
Reading the data from a file
line one
==========
line two
==============================
line three
==================================================
line four
======================================================================
+-------------+
|Step four    |
|             |
+-------------+
+-----------------------+
|Step three             |
|                       |
+-----------------------+
+---------------------------------+
|Step two                         |
|                                 |
+---------------------------------+
+-------------------------------------------+
|Step one                                   |
|                                           |
+-------------------------------------------+

```


## Submission

To test and demonstrate the execution of your program use the same data as shown in the output example.

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w8/p1
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.





# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


## Submission

Run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w8/p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
