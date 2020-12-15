# Workshop #2: Dynamic Memory
*Version 1.0 (submissions will be opened by your prof shortly)*


In this workshop, you will use *references* to modify content of variables in other scopes, overload functions and allocate memory at run-time and deallocate that memory when it is no longer required. 

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- allocate and deallocate dynamic memory for an array;
- overload functions;
- create and use references;

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

# LAB (50%)
***Students' GPA report*** is a program that reads an unknown number of Student records from a file and holds these records of students in a dynamically allocated array of **Student**s. (Each record holds the student's name, student number and GPA of the students in a comma separated value format.)
After loading all the information into a dynamic array of **Student**s, the program will sort the records based on the GPA of the student in an ascending order and prints them on the screen.

## LAB Execution example

```text
1: Maude Flanders, 272754: 1.7
2: Alice Glick, 459608: 1.9
3: Sarah Wiggum, 920562: 2
4: Luann Van Houten, 737447: 2.3
5: Apu Nahasapeemapetilon, 290816: 2.6
6: Surly Duff, 146127: 2.6
7: Homer Simpson, 413084: 2.9
8: Allison Taylor, 747954: 3.2
9: Martin Prince, 575687: 3.5
10: Carl Carlson, 241968: 3.7
11: Bernice Hibbert, 242653: 3.8
12: Abraham Simpson, 324543: 3.9
13: Bart Simpson, 753102: 3.9
14: Lisa Simpson, 693664: 4
```

This program is partially developed; you can find all the files in the lab directory. Your responsibility is to complete the code as stated in the comments in the source code.

## The Code

The structure holding the student record is designed as follows:

```C++
   struct Student {
      char* m_name;
      int m_studentNumber;
      double m_gpa;
   };
```
In addition to holding the student records in an dynamically allocated array of **Student**s, each student's name is also held in a dynamically allocated Cstring in the **Student** structure. Consider the following visual and note that every circle with an arrow in this diagram shows dynamic memory in use.
![DMA](images/mem.png)
  
## Data file  
Here is a sample of the data file in the following format:<br />
```Text
student name,student number,gpa<NEWLINE>
```
```Text
Abraham Simpson,324543,3.9
Alice Glick,459608,1.9
Allison Taylor,747954,3.2
Apu Nahasapeemapetilon,290816,2.6
Bart Simpson,753102,3.9
Bernice Hibbert,242653,3.8
Carl Carlson,241968,3.7
Homer Simpson,413084,2.9
Lisa Simpson,693664,4.0
Luann Van Houten,737447,2.3
Martin Prince,575687,3.5
Maude Flanders,272754,1.7
Sarah Wiggum,920562,2.0
Surly Duff,146127,2.6
```

### The Modules
There are three modules in the program:  
**File**, **Student** and **gpaReport**

#### File Module 
The following functions are already implemented in the **File** module:  
##### openFile
Opens the data file for reading  
##### closeFile  
Closes the data file
##### noOfRecords
Returns an integer that is the number of records in the file; use this function in the **Student** module to determine the size of the dynamic array of students.
#### Your coding responsibility in the File module:
Implement 3 **overloads** of a function called **read**
1. **read** function for the student name:<br />
Returns a **bool** for success and has one Cstring argument to send back the name of the student.
Use the following fscanf function to read the name of the student from the file and return true if it returns 1.  
```C
fscanf(fptr, "%[^,],"......
```
2. **read** function for the student number:<br />
Returns a **bool** for success and has one integer reference argument to pass back the student number.
Use the following fscanf function to read the student number from the file and return true if it returns 1.  
```C
fscanf(fptr, "%d,".......
```
3. **read** function for the student GPA:<br />
Returns a **bool** for success and has one double reference argument to send back the gpa of the student.
Use the following fscanf function to read the GPA from the file and return true if it returns 1.  
```C
fscanf(fptr, "%lf\n",......
```


#### Student Module
The Student Module has two global variables:<br />
```C
int noOfStudents;
```
**noOfStudents** should hold the number of records in the file and therefore it should be used (after setting) to allocate the dynamic array of Students.
```C
Student* students;
```
This **Student** pointer should point to the dynamic array of students. 
#### Functions

The following function is already implemented in the **Student** module:  
##### sort
This function sorts the dynamic array of students based on the GPA of the students.

#### Complete the implementation of the following functions:
##### load 
This overload of the **load** function returns a **bool** and receives a **Student** reference.<br />
In a local array of 128 characters, it will try to read the student name from the file. If successful it will find the actual length of the student name using the **strlen** function and then add one to the length (for null termination) and allocate the same amount of characters in the name of the **Student** reference. Then it will copy the read name (from the local character array) into the newly allocated name of the **Student** reference using **strcpy**.<br />
Afterwards it will read the student number and the gpa into the corresponding variables of the **Student** Reference.<br />
If all the reads were successful, it will return true, otherwise false.
##### load
This overload of the **load** function loads all the student records into the Student array and returns a bool for success and has no arguments.<br />
First open the data file.<br />
Then set the number of students to the number of records in the file and then allocate a dynamic array of students pointed by the global **Student** pointer; **"students"** to the number of the records in the file. <br />
Then load the students one by one from the file into the dynamic array of students.<br />
If the number of records read does not match the number of records, display the following error message and return false.
```text
Error: incorrect number of records read; the data is possibly corrupted.
```
Otherwise return true.

#### Implement the following functions:
##### display
This overload of display function receives a constant student reference and prints it in the following format:  
```text
name, student number: GPA<NEWLINE>
```
##### display
This overload of the display function does not receive or return anything. <br />
First sort the array of **Student**s and then display them one by one with a row number. <br />
See the sample output.
##### deallocateMemory
This function does not return or receive anything.<br />
In a loop go through all the elements of the student array and deallocate the dynamic name of each student. Then deallocate the whole student array.

### gpaReport Module. 
Do not modify the gpaReport Module.


## LAB Submission (part 1)

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w2/p1
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.





# DIY (50%)

Write a **Balance reporting** program that reads series of account numbers and their corresponding balances from a comma separated values file and prints a report of the accounts and their balances sorted in an ascending order based on the balance of the account. 

The data file is called **"accounts.csv"** and is formatted like as follows:
  
```Text
Account number
Comma
Balance
New line
```
Example:
```Text
556001,296.84
246911,37.91
324932,9234.42
125990,7186.83
736456,3744.80
592362,6735.59
642550,605.23
926739,5279.19
166598,8880.70
847262,7384.69
```
## DIY Execution example
```text
Account#: Balance
246911  37.91
556001  296.84
642550  605.23
736456  3744.8
926739  5279.19
592362  6735.59
125990  7186.83
847262  7384.69
166598  8880.7
324932  9234.42
```

Implement this program in 3 modules called balReport, File and Account that can accomplish the above task.  

> you may freely use/copy any logic or code needed from the LAB section.

Files to submit:  
```Text
balReport.cpp <--- contains the main function, do not modify this.
File.cpp
File.h
Account.cpp
Account.h
```
## File Module
The File module is partially implemented. 
## Account Module
The Account module is not implemented.<br /> 
There are three mandatory functions in the Account module, apart from these three functions you are free to choose any method to implement this system, however you must use function overloading, reference and dynamic memory allocation since the number accounts during submission will be much more that what you have for development.
### Account Module mandatory functions:
#### load
This function returns bool for success and receives the name of the data file in a Cstring.<br />
The **load** function should load all the data from the data file and return true if the action is successful.<br />
If the file can not found it should print the following error message: 
```Text
Could not open data file: thedatafilename.whatever
```
If the file is opened successfully but could not be read successfully the following error message is displayed:
```Text
Error: incorrect number of records read; the data is possibly corrupted!
```
#### display
This function returns and receives nothing. 
This function prints the report with the same format as displayed in the [DIY Execution example](#DIY-Execution-example) .
#### deallocateMemory
This function returns and received nothing. 
This function deallocates all the memory allocated by the program.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

> Note: When submitting, your program will be tested against a data file similar to **accounts_subtest.csv**

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w2/p2
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
