#ifndef __FICHEROS__H__
#define __FICHEROS__H__


int countFileWords(char * fileName);

int countFileLines(char * fileName);

int readFile(char * fileName);

int writeNumbersFile(char * fileName, int number[], int size);

int * readNumbersFile(char * fileName, int * size);

//Check if a file exists, return 1 if and only if the file exists, 0 else 
int fileExists(const char* file);

// copy one srcFileName to srcFileName. The original name and the destination are parameters of the function. The destination file must have protections that allow it to be read by any user, but only to be modified by the owner.
int copyFile(char * srcFileName, char * outFileName); 

// if the files are equal, return 1, otherwise return 0
int compareFiles(char * FileName1, char * FileName2);

// save the content of a folder in a filename
int printDirContent(char * dir, char * fileName); 

// return the size of a file
long getFileSize(char * fileName);

#endif // __FICHEROS__H__
