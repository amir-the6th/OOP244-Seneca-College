 # Workshop #6: Classes and resources, IO operators
* Version 1.0 (Submission is open now)

In this workshop, you will implement copy constructor and copy assignment to prevent memory leak and resize allocated memory.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create copy constructors
- define and create copy assignment 
- Resize dynamically allocated memory.
- Overload insertion operator so the class can be printed using ostream
- Overload extraction operator so the class can be read using istream

## Submission Policy

The workshop is divided into one coding part and one non-coding part:

- *Part 1*: worth 100% of the workshop's total mark, is due on **Friday at 23:59:59** of the week of your scheduled lab.
- *reflection*: non-coding part, is due on **Sunday at 23:59:59** of the week of your scheduled lab. The reflection doesn't have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

**The code that is submitted late receives 0%.**  On Sunday at midnight the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

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

# LAB (100%) The Numbers Module

Your task for this lab is to complete the implementation of the **Numbers** class. This class reads several double values from a file (one number per line) and holds them dynamically in memory. Then the caller application has the option of adding numbers to the collection. This Module can provide information about the numbers and display them on the screen:<br />
- The Module can display the values in ascending order (sort).
- The Module can find the largest value
- The Module can find the smallest value
- The Module can calculate the average of the values in the collection

Also The **Numbers** class has the following capabilities: 
- A **Numbers** object can safely be copied or assigned to another **Numbers** module
- A **Numbers** object can be displayed or streamed into an istream object.
- A **Numbers** object can be read from an istream object.

When the **Numbers** object goes out of the scope the values overwrite the old values in the file, ONLY IF the object is the original object and not a copy.
# The Numbers class
The Numbers class has four attributes:
```C++
    double* m_numbers; // holds the address of the dynamic array of doubles holding the number collection
    char* m_filename;  // holds the name of the file associated with the class (if it is the original object and not a copy)
    bool m_isOriginal; // flags if this object is the original (and not a copy)
    int m_numCount; // holds the number of values in the m_number dynamic array
```

## Constructors, Destructor and Copy Assignment

The **Numbers** class can be instantiated in three different ways:

### One argument constructor (implemented)
Creates an original instance of the Numbers class by receiving the data file name as a constant Cstring
- Sets the object to safe empty state (**setEmpty()**).
- Sets the m_isOriginal flag to true.
- Sets the filename of the class (**setFilename()**)
- Sets the number of the double values to be read from the file (sets m_numCount using **numberCount()**)

Now if the number of double values in file is greater than zero it tries to read the values from the file using the **load()** function as follows:

- If m_numCount is greater than zero and load() is successful, the values will be sorted.
- If not successful, it will free the memory pointed by m_numbers and m_filename
- sets the object back the safe empty state and sets the class NOT TO BE original anymore.

### Default constructor  (implemented)
```C++
  Account();
```
- Sets the object to safe empty state (**setEmpty()**).
- Sets the m_isOriginal flag to false.

### Destructor (implemented)
- Saves the values in the file
- deletes the memory pointed by m_numbers and m_filename

### Copy Constructor (to be implemented)
- Sets the object to safe empty state
- Sets the object NOT to be original
- Assigns the current object to the **Numbers** object that is being copied. (calls the Copy Assignment Operator)


### Copy Assignment Operator (to be implemented)
- deletes the current collection of the double values
- Allocates new memory pointed by m_numbers to the number of the values in the object that is being copied.
- Copies all the double values in the object that is being copied into the newly allocated memory.
- returns the reference of the current object.

## Member Functions and Member operator+= overload 

### isEmpty() (implemented)
returns true if **m_numbers** is null

### setEmpty() (implemented)
sets m_numbers and m_filename to nullptr.
sets m_numCount to zero.

### setFilename() (implemented)
- Receives a constant Cstring for the data file name.
- Frees the memory pointed by m_filename pointer
- Allocates memory to hold the data file name as a Cstring.
- Copies the data file name to the newly allocated memory.

### sort() (implemented)
Sorts the double values in ascending order

### max() (implemented)
Returns the largest double number in the list

### min() (implemented)
Returns the smallest double number in the list

### average()  (implemented)
Returns the average of the double numbers in the list.

### numberCount() (to be implemented)
This function (that is incapable of modifying the currect object), will return the number of lines in the data file (hence returning the number of double values in the file).
- Create an instance of **ifstream** to  open the data file name.
- While the **ifstream** object has not failed keep reading single characters from the file
- Count the number of **newline** characters in an integer variable
- Return the number of counted **newlines** when all characters in the file are scanned.

### load() (to be implemented)
This function returns true if all the double values are read from the data file and stored in a dynamically alocated memory pointed by **m_numbers**, othewise returns false.
- If number of double values in the file is greater than zero (m_numCount > 0)
- Allocate memory to hold the double values in an array pointed by m_numbers.
- Create an instance of ifstream for the data file
- While the ifstream object has not failed, keep reading double values from the file into the elements of m_numbers dynamic array (as you do with cin)<br />
> make sure to add to the index of the loop only if the istream object has not failed in its last reading
- return true if the number of read doubles, is equal to the m_numCount member variable.

### save() (to be implemented)
- If the current object is the original and it is not in safe empty state
- Create an instance of ofstream to overwrite the dat afile
- Write all the elements of the m_numbers array using the ofstream object.
- Write a newline after each double value.

### Operatro += (to be implemented)
Overload the += operator to add a single double value to the list of numbers in the array and then return the reference of the current object.

You need to increase the size of the allocated memory by one (add one double to the array), to be able to do this. 

Here is the sequence of the actions to be taken to resize memory:
- Create a temporary local double pointer and allocate memory with the increased size
- Copy all the current values to the newly allocated memory.
- Update the size of the data to the new size
- Now that all the values are copied to the new memory, delete the original allocated memory
- Set the original data pointer to point to newly allocated memory
- You are done!

[View the Slides](https://github.com/Seneca-244200/OOP244-NABD-Notes/blob/master/review/memoryResizing.pdf)

Using the above guidelines; in our case, do the following only if the object is not in an empty state:
- Create a temp double pointer and allocate memory to the size: **m_numCount + 1**
- In a loop, copy all the double **m_numbers** elements to the double **temp** number elements (up to m_numCount)
- Add one to m_numCount (to update the number of double values)
- copy the value of the double argument to the last element of the double **temp** array (and therefore add the double value to the list)
- delete m_numbers to get rid of the ariginal allocated memory
- Set **m_numbers** to **temp** pointer; by doing this m_numbers will point to the newly allocated memory.
- sort the numbers so the added number stands at the proper location in the array

Regardless of the object being empty or not return the reference of the current object.

### display function. (to be implemented)
```C++
   ostream& display(ostream& ostr) const
```
- if the object is empty, write: **"Empty list"**.
- if the object is not empty start by writing:  **"========================="** on **ostr** and then go to newline
- if the object is flagged as original, then write the file name otherwise write ```"*** COPY ***"``` and then go to new line
- write all the double numbers seperated by **", "** (A comma and a space) and then go to new line
- write **"-------------------------"** and go to new line
- Write **"Total of " << m_numCount << " number(s)"** and go to new line
- write **"Largest number:  "** and the largest number in the list and go to new line
- write **"Smallest number: "** and the smallest number in the list and go to new line
- write **"Average :        "** and the average of all the numbers inthe list and go to new line
- write **"========================="** and DO NOT GO TO NEWLINE

At the end return the ostr object.

#### Execution sample
A Numbers object that has the double values 34.1, 3, 6, 12.2 and 34.56 in a file called **numbers.txt**<br />
should be displayed as follows:  
```Text
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
```
If a Number object is empty, it will be displayed as follows:
```Text
Empty list
```

## Helper function overlaods (to be implemented)
```C++    
ostream& operator<<(ostream& os, const Numbers& N);
```
Overload the insertion operator to display the Numbers object using istream.
- call the display fucntion of N and return it

```C++
istream& operator>>(istream& istr, Numbers& N);
```
Overload the extraction operator to display the Numbers object using istream.
- read a double value using istr
- add the double value to N using += operator
- return istr;

## the tester program and the execution sample.
The tester program's execution should generate the following output:

```Text
Test 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
Add a number to the list: 1000
=========================
*** COPY ***
3, 6, 12.2, 34.1, 34.56, 1000
-------------------------
Total of 6 number(s)
Largest number:  1000
Smallest number: 3
Average :        181.643
=========================
End Test 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

Content of "numbers.txt"
*****************************************************************
3
6
12.2
34.1
34.56
*****************************************************************
Test 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
=========================
*** COPY ***
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
Empty list
Empty list
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56, 1000
-------------------------
Total of 6 number(s)
Largest number:  1000
Smallest number: 3
Average :        181.643
=========================
=========================
*** COPY ***
3, 6, 12.2, 34.1, 34.56, 1000
-------------------------
Total of 6 number(s)
Largest number:  1000
Smallest number: 3
Average :        181.643
=========================
=========================
*** COPY ***
3, 6, 12.2, 34.1, 34.56, 1000
-------------------------
Total of 6 number(s)
Largest number:  1000
Smallest number: 3
Average :        181.643
=========================
End Test 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2

Content of "numbers.txt"
*****************************************************************
3
6
12.2
34.1
34.56
1000
*****************************************************************
Test 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3

In this test we use your insertion and extraction operators to do
File IO. This makes sure your implementation is done correctly
using the reference of istream and ostream and NOT cin and cout

End Test 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3

Content of "numbers.txt"
*****************************************************************
-5
3
6
12.2
34.1
34.56
222.1
333.2
1000
*****************************************************************

Content of "add.txt"
*****************************************************************
-5
222.1
333.2
*****************************************************************

Content of "output.txt"
*****************************************************************
=========================
numbers.txt
-5, 3, 6, 12.2, 34.1, 34.56, 222.1, 333.2, 1000
-------------------------
Total of 9 number(s)
Largest number:  1000
Smallest number: -5
Average :        182.24
=========================
*****************************************************************

```


## LAB Submission (part 1)

Upload your source code and the tester program (**Numbers.cpp, Numbers.h and numbersTester.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w6/p1
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


## Submission

Run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w6/p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
