# Lab C Strings and Files

## Utilidades

Utilidades is a Library to manage strings in c language

### Problem 1: 

``char * upperCase(char * string)`` Returns an uppercase string

[8 kyu MakeUpperCase](https://www.codewars.com/kata/57a0556c7cb1f31ab3000ad7)

### Problem 2: 

``char * lowerCase(char * string);`` Returns a lowercase string  string

### Problem 3: 

``char * palindrome(char * string);`` Returns the Palindrome of a string

[8 kyu Reversed Strings](https://www.codewars.com/kata/5168bb5dfe9a00b126000018)

### Problem 4: 

``int countWords(char * string);`` count the number of words of a string

### Problem 5: 

``int countVowels(char * string);``  count the number of vowels of a string

### Problem 6: 

``int charOccurrences (char * string, char character);`` count the number of characters in a string

[7 kyu Ordered Count of Characters](https://www.codewars.com/kata/57a6633153ba33189e000074)

### Problem 7: 

``char ** getWords(char * string);``  get an array of words of a string

[7 kyu Find the nth occurrence of a word in a string!](https://www.codewars.com/kata/5b1d1812b6989d61bd00004f)

### Problem 8: 

``void writeWords(char * string);`` print the words of a string

## Ficheros

Ficheros is a Library to manage files in c language

### Problem 9: 

``int countFileWords(char * fileName);`` Count the number of words in a file

### Problem 10: 
``int countFileLines(char * fileName);`` Count the number of lines in a file

### Problem11: 

``int readFile(char * fileName);`` opens a file, checks that it exists and reads all its content and displays it on the screen.

### Problem 12: 
``int writeNumbersFile(char * fileName, int number[], int size);`` write a file with the content of an array of numbers

### Problem 13
``int * readNumbersFile(char * fileName, int * size);``  read a file with numbers and displays it on the screen.

### Problem 13
``int copyFile(char * srcFileName, char * outFileName);``  copy one srcFileName to outFileName. The original name and the destination are parameters of the
function. The destination file must have protections that allow it to be read by any user, but only to be modified by the owner.

### Problem 14

``int compareFiles(char * FileName1, char * FileName2);`` if the files are equal, return 1, otherwise return 0

### Problem 15

Refactor the following program to store and read students from a file

[Problem 6](https://github.com/SSOO-uc3m/Lab_C_pointers/tree/master/Problem_06)

### Problem 16

``int printDirContent(char * dir, char * fileName); `` save the content of a folder in a filename

### Problem 17

``long getFileSize(char * fileName);`` return the size of a file


## Test

### Question 1

Which are the main functions of an operating system?

````
The operating system is a program that is responsible for covering the hardware to facilitate the use of the computer, which it carries
out by performing three main functions:

- Management of system resources.

- Execution of services for programs.

- Execution of programs by users.

````

### Question 2

Which of the following hardware mechanisms is not a requirement to build a multiprogrammed operating system with protection between users? Give reasons for your answer.

a.- Virtual memory.

b.- Memory protection.

c.- I / O instructions that can only be executed in kernel mode.

d.- 2 modes of operation: core and user.

````

The correct answer is a: Virtual Memory

Although it is necessary to have a large amount of main memory, this does not require the use of said service.

On the other hand, the remaining options are necessary.
````


### Question 3

What is the difference between a command and a system call?
````
A command is a program external to the operating system that allows users to interactively dialogue with the system through
the shell or command interpreter.

System calls are a set of services that the operating system offers to programs that can be requested when needed. They are called from external programs through system libraries, but the implementation of the system calls is internal to the operating system.

The set of system calls defines the services of the operating system.
````
### Question 4

How do you request a system call to the operating system?
````
It is requested through an interrupt mechanism. When requested by a running process, it uses a TRAP instruction that generates an interrupt. As shown in Figure, the TRAP interrupt handling routine uses an internal table of the S.O. to determine which routine to activate depending on which call is requested.

When programmed in a high-level language, the request for services to the operating system is made through a call to a specific function, which is responsible for generating the
system call and the corresponding trap.

![system call](img/system-call.png)


````
### Question 5

Give some examples that show the need for the operating system to provide mechanisms for communication and synchronization between processes.

````
- Two processes that write to the same file.

Until one is finished, the other cannot begin: they must do it in an orderly manner. That is, they must communicate with each other
so that their writing operations do not overlap.

- Two processes that print on the screen.

If they did it at the same time, the information would be mixed. In this way there would be no synchronization between the
processes.

- Two processes that manage the entry and exit of money
from a bank account.

If the process in charge of withdrawing money is running, the process that consults the balance must be synchronized with the first one and wait for it to finish before executing its balance inquiry function.

![bank account processes](img/bank-account-processes.png)


````
### Question 6

The command interpreter in LINUX in internal or external to the operating system?

Explain you answer.

````
The command interpreter in LINUX is external to the OS. It is call “Shell”

A good example is the case of LINUX, in which you can install as many command interpreters as you want. There are several installed in the system.

![command interpreter](img/command-interpreter.png)


Bsh, csh, ksh, …

````


