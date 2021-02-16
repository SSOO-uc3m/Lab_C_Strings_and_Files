#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "test_pr1.h"
#include "utilidades.h"
#include "ficheros.h"

// Run all tests for PR1
bool run_pr1(tTestSuite* test_suite) {
    bool ok = true;
    tTestSection* section = NULL;

    assert(test_suite != NULL);

    testSuite_addSection(test_suite, "PR1", "Tests for utilidades Library");

    section = testSuite_getSection(test_suite, "PR1");
    assert(section != NULL);

    ok = run_pr1_ex1(section) && ok;
    ok = run_pr1_ex2(section) && ok;
    ok = run_pr1_ex3(section) && ok;

    return ok;
}

// Run all tests for PR1
bool run_pr1_ex1(tTestSection* test_section) {

   bool passed = true, failed = false;

   char exampleString [] = "Lorem Ipsum Dolor Sit Amet";
   char emptyString [10];
   emptyString[0] = '\0';
    
   char * result;
   int number = 0;
   
   failed = false;
   start_test(test_section, "PR1_EX1_01", "uppercase basic test");   

   result = upperCase(exampleString);
   
     
    if (result== NULL){       
        failed = true;
    }
    else if (strcmp(result,"LOREM IPSUM DOLOR SIT AMET") != 0) {
        failed = true;
        
        }
        
   if (failed) {
        end_test(test_section, "PR1_EX1_01", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR1_EX1_01", true);
    }    

   free(result);
   
   failed = false;
   start_test(test_section, "PR1_EX1_02", "uppercase empty string");   

   result = upperCase(emptyString);
   
   if (result== NULL){       
        failed = true;
   }
   else if ( result[0]!='\0') {
        failed = true;
        } 
        
   if (failed) {
        end_test(test_section, "PR1_EX1_02", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR1_EX1_02", true);
    }    
   free(result);
   
   failed = false;
   
   start_test(test_section, "PR1_EX1_03", "lowercase basic test");   

   result = lowerCase(exampleString);
   
   if (result== NULL){       
        failed = true;
   }
   else if (strcmp(result,"lorem ipsum dolor sit amet") != 0) {
        failed = true;
        } 
        
   if (failed) {
        end_test(test_section, "PR1_EX1_03", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR1_EX1_03", true);
    }    

   free(result);
   
   failed = false;
   start_test(test_section, "PR1_EX1_04", "lowercase empty string");   

   result = lowerCase(emptyString);
   
   if (result== NULL){       
        failed = true;
   }
   else if ( result[0]!='\0') {
        failed = true;
        } 
        
   free(result);
 
   if (failed) {
        end_test(test_section, "PR1_EX1_04", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR1_EX1_04", true);
    }   
    
   failed = false;
   start_test(test_section, "PR1_EX1_05", "palindrome");   

   result = palindrome(exampleString);
   
   if (result== NULL){       
        failed = true;
   }
   else if (strcmp(result,"temA tiS roloD muspI meroL") != 0) {
        failed = true;
   } 
        
   free(result);
 
   if (failed) {
        end_test(test_section, "PR1_EX1_05", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR1_EX1_05", true);
    }   
    
   failed = false;
   start_test(test_section, "PR1_EX1_06", "countWords");   

   number = countWords(exampleString);

   if (number != 5) {
        failed = true;
        } 
        
   
   if (failed) {
        end_test(test_section, "PR1_EX1_06", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR1_EX1_06", true);
    } 
    
    
   failed = false;
   start_test(test_section, "PR1_EX1_07", "getWords");   
   char ** words;

   words = getWords(exampleString);   

      
   if(words == NULL){
        failed = true;        
       }   
   else if (number!=5){
       failed = true;
       }
    else {
            if ((strcmp(words[0],"Lorem") != 0) || 
                (strcmp(words[1],"Ipsum") != 0) || 
                (strcmp(words[2],"Dolor") != 0) || 
                (strcmp(words[3],"Sit") != 0) || 
                (strcmp(words[4],"Amet") != 0) )
                failed = true;
        }
    
    if(words != NULL){    
        for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++){
            free(words[i]);
            }        
        free(words);
    }
   if (failed) {
        end_test(test_section, "PR1_EX1_07", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR1_EX1_07", true);
    } 
    
    
   failed = false;
   start_test(test_section, "PR1_EX1_08", "count vowels"); 
  
   number = countVowels(exampleString);
   if (number != 9) {
        failed = true;
        } 
        
   if (failed) {
        end_test(test_section, "PR1_EX1_08", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR1_EX1_08", true);
    } 
 
   return passed;
}




// Run tests for PR1 exercise 2
bool run_pr1_ex2(tTestSection* test_section) {
    bool passed = true, failed = false;

    
   int result = 0;
   
   failed = false;
   start_test(test_section, "PR2_EX1_01", "read file");   

   result = readFile("../hamlet.txt");   
   
   if (result != 0) {
        failed = true;
        
        }  
   
   if (failed) {
        end_test(test_section, "PR2_EX1_01", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR2_EX1_01", true);
    }   
    
     failed = false;
   start_test(test_section, "PR2_EX2_01", "count words");   

   result = countFileWords("../hamlet.txt");   
   
   if (result < 0 ) {
        failed = true;        
        }  
    else {
        if (result != 32307)
            failed = true; 
        }
   
   if (failed) {
        end_test(test_section, "PR2_EX2_01", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR2_EX2_01", true);
    }  
    
    failed = false;
   start_test(test_section, "PR2_EX2_02", "count lines");   

   result = countFileLines("../hamlet.txt");   
   
   if (result < 0 ) {
        failed = true;        
        }  
    else {
        if (result != 4459)
            failed = true; 
        }
   
   if (failed) {
        end_test(test_section, "PR2_EX2_02", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR2_EX2_02", true);
    } 
    
    return passed;
}


// Run tests for PR1 exercise 3
bool run_pr1_ex3(tTestSection* test_section) {
    bool passed = true, failed = false;
    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (sizeof numbers) / (sizeof numbers[0]);
    int *receivedNumbers;
    
   int result = 0;
   
   failed = false;
   start_test(test_section, "PR3_EX1_01", "write file");   

   result = writeNumbersFile("../numbers",numbers, size);   
   
   if (result != 0) {
        failed = true;
        
        }  
   
   if (failed) {
        end_test(test_section, "PR3_EX1_01", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR3_EX1_01", true);
    }   
    
  failed = false;
   start_test(test_section, "PR3_EX2_01", "read file");   

   receivedNumbers = readNumbersFile("../numbers",&size);   
   
      
   if (receivedNumbers == NULL) {
        failed = true;
        
        }  
    else if (size!=10 ) {
        failed = true;
    }
    else {
        /*for(int i=0;i<size;i++){    
            if (receivedNumbers[i]!=i)
                failed = true;
            }        
        */
        }
   
   if (failed) {
        end_test(test_section, "PR3_EX2_01", false);
        passed = false;
    }
   else {
        end_test(test_section, "PR3_EX2_01", true);
    }  
    
	
    return passed;
}
