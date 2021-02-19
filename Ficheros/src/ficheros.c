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
    int file, nread;
    int number;
    int * numbers = NULL;
    int i = 0;
    int arraySize = 0;
    
	if (!fileExists(fileName)){
		return(NULL); // file does not exist
		}
		 
    file = open(fileName, O_RDONLY);
    if ( file  < 0 )
		return(NULL); // cannot read file 
	
	
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
		return (NULL); 	/* error reading*/
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
	
	if (!fileExists(fileName)){
		return(-1); // file does not exist
		}
	
	if ( (file = open(fileName, O_RDONLY) ) < 0 ){
        perror("cannot open file");
		return(-2); // cannot open file 
    
    }
	//read file BUFSIZE characters at once
	while( (nread = read(file, buffer, LINES) ) > 0 )
	{
		//printf("%s",buffer);
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
	 
	if (!fileExists(fileName)){
		return(-1); // file does not exist
		}
		 
	if ( (file = open(fileName, O_RDONLY) ) < 0 ){
        perror("cannot open file");
		return(-1); /
    
    }
	

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
	char buffer [LINES];
	
	if (!fileExists(fileName)){
		return(-1); // file does not exist
		}
	
	if ( (file = open(fileName, O_RDONLY) ) < 0 ){
        perror("cannot open file");
		return(-2); // cannot open file 
    
    }
	//read file number of characters of a line (LINES) at once
	while( (nread = read(file, buffer, LINES) ) > 0 )
	{
		//printf("%s",buffer);
        words+=countWords(buffer);
	}
	if (nread==-1){
        perror("Error reading");
		return (-4); 	// error  
        }
        
	close(file);
    
    
    return words;
}


int readFile(char * fileName){
    int file, nread;
	char buffer [BUFSIZE];
	
	if (!fileExists(fileName)){
		perror("file does not exist");
		return(-1); // file does not exist
	}
	
	if ( (file = open(fileName, O_RDONLY) ) < 0 ){
        perror("cannot open file");
		return(-2); 
	
	}
	
	//read file BUFSIZE characters at once
	while( (nread = read(file, buffer, BUFSIZE) ) > 0 )
	{
		printf("%s",buffer);
	}
	if (nread==-1){
		perror("Error reading");
		return (-4); 	// error 	}
	
	close(file);
    
    return 0;

}

// check if a file exists
int fileExists(const char* file) {
    struct stat buf;
    return (stat(file, &buf) == 0);
}

// copy one srcFileName to srcFileName. The original name and the destination are parameters of the function. The destination file must have protections that allow it to be read by any user, but only to be modified by the owner.
int copyFile(char * srcFileName, char * outFileName){
   int infile, outfile, nread;
	char buffer [BUFSIZE];
	
	if (!fileExists(srcFileName)){
		perror("file does not exist");
		return(-1); // file does not exist
	}
	
	if ( (infile = open(srcFileName, O_RDONLY) ) < 0 )
		return(-1); // cannot open file
	if ( (outfile = creat (outFileName, PERM) ) < 0 ) {
		close (infile);
		return (-2); //cannot create file
		}
	//read file BUFSIZE characters at once
	while( (nread = read(infile, buffer, BUFSIZE) ) > 0 )
	{
		//write the buffer to the outfile 
		if (write (outfile, buffer, nread) < nread)
		{
			close(infile);
			close(outfile);
			return (-3); 			// error writting 
		}
	}
	if (nread==-1)
		return (-4); 	// error reading 
	close(infile);
	close(outfile);
	return(0); 
    
}

// if the files are equal, return 1, otherwise return 0
int compareFiles(char * FileName1, char * FileName2){
    int file1,file2, nread;
    int lines = 0;
	char character1, character2;
    
	if (!fileExists(FileName1) || !fileExists(FileName2)){
		perror("file does not exist");
		return(-1); // file does not exist
	}	

	
	if ( (file1 = open(FileName1, O_RDONLY) ) < 0 ){
        perror("cannot open file");
		return(-1); // cannot open file
    
    }
    if ( (file2 = open(FileName2, O_RDONLY) ) < 0 ){
        perror("cannot open file");
		return(-1); // cannot open file
    
    }
	
	while( (nread = read(file1, &character1, sizeof(char)) ) > 0 )
	{
        nread = read(file2, &character2, sizeof(char));
		if (character1 != character2){
            close(file1);
			close(file2);
			return (0);
            }
            
	}
	if (nread==-1){
        perror("Error reading");
		return (-4); 	// error  
        }
    
	close(file1);    
    close(file2); 
    
    return 1;
}
