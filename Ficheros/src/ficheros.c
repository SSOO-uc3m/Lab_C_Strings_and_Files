#include "ficheros.h"
#include "utilidades.h"
#include "stdio.h"
#include <sys/types.h> // open
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // read
#include <stdlib.h> // realloc

#define PERM 		0644
#define BUFSIZE		512			
#define LINES		75

int * readNumbersFile(char * fileName, int * size){
    
    return NULL;
}

int writeNumbersFile(char * fileName, int number[], int size){
        
    return -1;
}



int countFileLines(char * fileName){
    
    
    return -1;
}


int countFileWords(char * fileName){
    
    return -1;;
}


int readFile(char * fileName){
    
    return -1;
}

int fileExists(const char* file) {
    return -1;
}
    
int copyFile(char * srcFileName, char * outFileName){
    return -1;
}

int compareFiles(char * FileName1, char * FileName2){
    return -1;
}

int printDirContent(char * dir, char * fileName){
    return -1;
} 

long getFileSize(char * fileName){
    return -1;
}