#ifndef __UTILIDADES__H__
#define __UTILIDADES__H__

 
// Returns an uppercase string
char * upperCase(char * string);

// lowerCase: Returns a lowercase string
char * lowerCase(char * string);

// palindrome: Returns the Palindrome of a string
char * palindrome(char * string);

//countWords: count the number of words of a string
int countWords(char * string);

//countVowels: count the number of vowels of a string
int countVowels(char * string);

//charOccurrences: count the number of characters in a string
int charOccurrences (char * string, char character);

  
//countWords: get an array of words of a string
char ** getWords(char * string);

//writeWords: print the words of a string
void writeWords(char * string);

#endif // __UTILIDADES__H__

