#ifndef __FICHEROS__H__
#define __FICHEROS__H__


int countFileWords(char * fileName);

int countFileLines(char * fileName);


int readFile(char * fileName);

int writeNumbersFile(char * fileName, int number[], int size);

int * readNumbersFile(char * fileName, int * size);

    
#endif // __FICHEROS__H__
