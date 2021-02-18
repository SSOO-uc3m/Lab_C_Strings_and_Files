#ifndef __FICHEROS__H__
#define __FICHEROS__H__

//Count the number of words in a file
int countFileWords(char * fileName);

//Count the number of lines in a file
int countFileLines(char * fileName);

// read a file and print its content in the console
int readFile(char * fileName);

// write a file with the content of an array of numbers
int writeNumbersFile(char * fileName, int number[], int size);

// read a file with numbers in the console
int * readNumbersFile(char * fileName, int * size);

/**
 * Check if a file exists
 * @return 1 if and only if the file exists, 0 else
 */
int fileExists(const char* file);


// copy one srcFileName to srcFileName. The original name and the destination are parameters of the function. The destination file must have protections that allow it to be read by any user, but only to be modified by the owner.
int copyFile(char * srcFileName, char * outFileName); 

// if the files are equal, return 1, otherwise return 0
int compareFiles(char * FileName1, char * FileName2);
#endif // __FICHEROS__H__
