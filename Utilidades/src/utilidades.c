#include "utilidades.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int charOccurrences (char * string, char character){
    int occurrences = 0;
	for(int i = 0; i<  strlen(string); i++){
        if (string[i]==character)
            occurrences ++;
        } 	

	return occurrences;
}

char * copyString (char * string){
	char * sCopy;
 	sCopy = malloc(sizeof(char) * strlen(string));
	strcpy(sCopy,string);

	return sCopy;
}



char * upperCase(char * string){
	char * sUpperCase;
	int i = 0;

	sUpperCase = copyString(string);

	while(sUpperCase[i])
  	{
                   sUpperCase[i] = (char)toupper(sUpperCase[i]);
                    i++;
  	}

	return sUpperCase;

}

char * lowerCase(char * string){

	char * sLowerCase;
	int i = 0;

	sLowerCase = copyString(string);

	while(sLowerCase[i])
  	{
                 sLowerCase[i] = (char)tolower(sLowerCase[i]);
                 i++;
  	}

	return sLowerCase;

}

char * palindrome(char * string){
	char * sPalindrome;

	sPalindrome = copyString(string);

	int i = 0, j = 0;
	char temp;
              j = strlen(sPalindrome) - 1;
 
   	while (i < j) {
                 temp = sPalindrome[i];
                 sPalindrome[i] = sPalindrome[j];
                sPalindrome[j] = temp;
                 i++;
                 j--;

   	}

	return sPalindrome;
}

int countVowels(char * string){
     
    char *pt;    
    int vowels = 0;
    //assign address of str1 to pt
    pt=string;
     
   
    while (*pt)
    {
        if(*pt=='A' ||*pt=='E' ||*pt=='I' ||*pt=='O' ||*pt=='U' ||*pt=='a' ||*pt=='e' ||*pt=='i' ||*pt=='o' ||*pt=='u'){
            vowels++;
        }
        pt++; //pointer is increasing for searching the next character
    }     
       
    return vowels;
}
    
int countWords(char * string){
  
   int state = 0;  
   char * str = string;
   unsigned wc = 0; // word count  
  
    // Scan all characters one by one  
    while (*str)  
    {  
        // If next character is a separator, set the  
        // state as OUT  
        if (*str == ' ' || *str == '\n' || *str == '\t' || *str == ',' || *str == '.' || *str == ';')  
            state = 0;  
  
        // If next character is not a word separator and  
        // state is OUT, then set the state as IN and  
        // increment word count  
        else if (state == 0)  
        {  
            state = 1;  
            ++wc;  
        }  
  
        // Move to next character  
        ++str;  
    }  
  
    return wc; 
}

char ** getWords(char * string){
  
  char * token;
  char * delim = " ,.-()";
  char ** words;
  int i = 0;
  int size = countWords(string);
   char copy[strlen(string)];
   strcpy(copy, string);
  //printf("getWords %d\n",size);
   words =  malloc (size* sizeof(char*));
   if (words == NULL){
        perror("Error");    
        return NULL;
   }
   

  // split a string into a series of tokens using the delimiter delim.
  token = strtok (copy,delim);
  while (token != NULL)
  {
    size = strlen(token);
    words[i] = malloc ( size* sizeof(char*));
    if (words[i] == NULL){
        perror("Error");
        //free(words);
        return NULL;
    }
        
    strcpy(words[i],token);
    //printf("getwords %s %d\n",words[i],size);
    
    token = strtok (NULL, delim);
    i++;
  }
 
 return words;
}
   


void writeWords(char * string){
  char * token;
  char * delim = " ,.-()";
  char copy[strlen(string)];
   strcpy(copy, string);
  // split a string into a series of tokens using the delimiter delim.
  token = strtok (copy,delim);
  printf("Words: \n");
  while (token != NULL)
  {
    printf ("%s\n",token);
    token = strtok (NULL, delim);
  }

	
}
