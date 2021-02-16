#include "ficheros.h"
#include "utilidades.h"
#include "stdio.h"
#include <sys/types.h> // open
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // read
#include <stdlib.h> // realloc


#define BUFSIZE		512			
#define LINES		75

int * readNumbersFile(char * fileName, int * size){
    int file, nread;
    int number;
    int * numbers = NULL;
    int i = 0;
    int arraySize = 0;
    
    file = open(fileName, O_RDONLY);
    if ( file  < 0 )
		return(NULL); /* cannot create file */
	
	/*lectura de name1 BUFSIZE caracteres de una vez*/
	while( (nread = read(file, &number, sizeof(number)) ) > 0 )
	{
        arraySize = (i+1) * sizeof(int); 
		//printf("%d\n",number);
        numbers = (int *)realloc(numbers, arraySize);
        if(numbers == NULL){
            perror("Error realloc");
            *size = 0;
            return NULL;
            }
        numbers[i] = number;
        //printf("%d %d\n",numbers[i],arraySize);
        i++;
	}
	if (nread==-1)
		return (NULL); 	/* error al leer */
	close(file);    
    *size = i;
    return numbers;
}

int writeNumbersFile(char * fileName, int number[], int size){
    int file, sz;
    file = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if ( file  < 0 )
		return(-1); /* cannot create file */
        
	for(int i=0; i < size; i++)
	{
        //printf("%d\n",number[i]);
		sz = write(file, &number[i], sizeof(number[i])); 
        if (sz < 0){
            perror("Error writing file");
            close(file);
            return(-2);
            }
	}
	
	close(file);
    
    return 0;
}



int countFileLines(char * fileName){
    int file, nread;
    int lines = 0;
	char buffer [LINES];
	if ( (file = open(fileName, O_RDONLY) ) < 0 ){
        perror("cannot open file");
		return(-1); /* no puede abrirse */
    
    }
	/*lectura de name1 BUFSIZE caracteres de una vez*/
	while( (nread = read(file, buffer, LINES) ) > 0 )
	{
		printf("%s",buffer);
        lines+=charOccurrences(buffer,'\n');
	}
	if (nread==-1){
        perror("Error reading");
		return (-4); 	/* error  */
        }
        
	close(file);
    
    
    return lines;
}

/*
int countFileLines(char * fileName){
    int file, nread;
    int lines = 0;
	char character;
	if ( (file = open(fileName, O_RDONLY) ) < 0 ){
        perror("cannot open file");
		return(-1); // no puede abrirse 
    
    }
	
	//lectura de name1 BUFSIZE caracteres de una vez
	while( (nread = read(file, &character, sizeof(char)) ) > 0 )
	{
		if (character == '\n')
            lines++;
	}
	if (nread==-1){
        perror("Error reading");
		return (-4); 	// error  
        }
    
	close(file);    
    
    return lines;
}*/

int countFileWords(char * fileName){
    int file, nread;
    int words = 0;
	char buffer [BUFSIZE];
	if ( (file = open(fileName, O_RDONLY) ) < 0 ){
        perror("cannot open file");
		return(-1); /* no puede abrirse */
    
    }
	/*lectura de name1 BUFSIZE caracteres de una vez*/
	while( (nread = read(file, buffer, BUFSIZE) ) > 0 )
	{
		printf("%s",buffer);
        words+=countWords(buffer);
	}
	if (nread==-1){
        perror("Error reading");
		return (-4); 	/* error  */
        }
        
	close(file);
    
    
    return words;
}


int readFile(char * fileName){
    int file, nread;
	char buffer [BUFSIZE];
	if ( (file = open(fileName, O_RDONLY) ) < 0 )
		return(-1); /* no puede abrirse */
	
	/*lectura de name1 BUFSIZE caracteres de una vez*/
	while( (nread = read(file, buffer, BUFSIZE) ) > 0 )
	{
		printf("%s",buffer);
	}
	if (nread==-1)
		return (-4); 	/* error al leer */
	close(file);
    
    return 0;

}