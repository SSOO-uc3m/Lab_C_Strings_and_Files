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

### Question 2

Which of the following hardware mechanisms is not a requirement to build a multiprogrammed operating system with protection between users? Give reasons for your answer.

a.- Virtual memory.

b.- Memory protection.

c.- I / O instructions that can only be executed in kernel mode.

d.- 2 modes of operation: core and user.

### Question 3

What is the difference between a command and a system call?

### Question 4

How do you request a system call to the operating system?

### Question 5

Give some examples that show the need for the operating system to provide mechanisms for communication and synchronization between processes.

### Question 6

The command interpreter in LINUX in internal or external to the operating system?

Explain you answer.



