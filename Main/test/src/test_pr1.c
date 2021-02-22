#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "test_pr1.h"
#include "utilidades.h"
#include "ficheros.h"

// Run all tests for PR1
bool run_pr1(tTestSuite * test_suite) {
    bool ok = true;
    tTestSection * section = NULL;

    assert(test_suite != NULL);

    testSuite_addSection(test_suite, "PR1", "Tests for utilidades and ficheros Libraries");

    section = testSuite_getSection(test_suite, "PR1");
    assert(section != NULL);

    ok = run_pr1_ex1(section) && ok;
    ok = run_pr1_ex2(section) && ok;
    ok = run_pr1_ex3(section) && ok;

    return ok;
}

// Run all tests for PR1
bool run_pr1_ex1(tTestSection * test_section) {

    bool passed = true, failed = false;

    char exampleString[] = "Lorem Ipsum Dolor Sit Amet";
    char emptyString[10];
    emptyString[0] = '\0';

    char * result;
    int number = 0;

    failed = false;
    start_test(test_section, "Utilidades_EX_01", "uppercase basic test");

    result = upperCase(exampleString);

    if (result == NULL) {
        failed = true;
    } else if (strcmp(result, "LOREM IPSUM DOLOR SIT AMET") != 0) {
        failed = true;

    }

    if (failed) {
        end_test(test_section, "Utilidades_EX_01", false);
        passed = false;
    } else {
        end_test(test_section, "Utilidades_EX_01", true);
    }

    free(result);

    failed = false;
    start_test(test_section, "Utilidades_EX_02", "uppercase empty string");

    result = upperCase(emptyString);

    if (result == NULL) {
        failed = true;
    } else if (result[0] != '\0') {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "Utilidades_EX_02", false);
        passed = false;
    } else {
        end_test(test_section, "Utilidades_EX_02", true);
    }
    free(result);

    failed = false;

    start_test(test_section, "Utilidades_EX_03", "lowercase basic test");

    result = lowerCase(exampleString);

    if (result == NULL) {
        failed = true;
    } else if (strcmp(result, "lorem ipsum dolor sit amet") != 0) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "Utilidades_EX_03", false);
        passed = false;
    } else {
        end_test(test_section, "Utilidades_EX_03", true);
    }

    free(result);

    failed = false;
    start_test(test_section, "Utilidades_EX_04", "lowercase empty string");

    result = lowerCase(emptyString);

    if (result == NULL) {
        failed = true;
    } else if (result[0] != '\0') {
        failed = true;
    }

    free(result);

    if (failed) {
        end_test(test_section, "Utilidades_EX_04", false);
        passed = false;
    } else {
        end_test(test_section, "Utilidades_EX_04", true);
    }

    failed = false;
    start_test(test_section, "Utilidades_EX_05", "palindrome");

    result = palindrome(exampleString);

    if (result == NULL) {
        failed = true;
    } else if (strcmp(result, "temA tiS roloD muspI meroL") != 0) {
        failed = true;
    }

    free(result);

    if (failed) {
        end_test(test_section, "Utilidades_EX_05", false);
        passed = false;
    } else {
        end_test(test_section, "Utilidades_EX_05", true);
    }

    failed = false;
    start_test(test_section, "Utilidades_EX_06", "countWords");

    number = countWords(exampleString);

    if (number != 5) {
        failed = true;
    }

    number = countWords("En un lugar de la mancha ,\n \tde cuyo lugar no quiero acordarme .");

    if (number != 12) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "Utilidades_EX_06", false);
        passed = false;
    } else {
        end_test(test_section, "Utilidades_EX_06", true);
    }

    failed = false;
    start_test(test_section, "Utilidades_EX_07", "getWords");
    char ** words;

    words = getWords(exampleString);
    number = countWords(exampleString);

    if (words == NULL) {
        failed = true;
    } else if (number != 5) {

        printf("\n%s %d", exampleString, number);

        failed = true;
    } else {
        if ((strcmp(words[0], "Lorem") != 0) ||
            (strcmp(words[1], "Ipsum") != 0) ||
            (strcmp(words[2], "Dolor") != 0) ||
            (strcmp(words[3], "Sit") != 0) ||
            (strcmp(words[4], "Amet") != 0))
            failed = true;
    }

    if (words != NULL) {
        for (int i = 0; i < 5; i++) {
            free(words[i]);
        }
        free(words);
    }
    if (failed) {
        end_test(test_section, "Utilidades_EX_07", false);
        passed = false;
    } else {
        end_test(test_section, "Utilidades_EX_07", true);
    }

    failed = false;
    start_test(test_section, "Utilidades_EX_08", "count vowels");

    number = countVowels(exampleString);
    if (number != 9) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "Utilidades_EX_08", false);
        passed = false;
    } else {
        end_test(test_section, "Utilidades_EX_08", true);
    }

    return passed;
}

// Run tests for PR1 exercise 2
bool run_pr1_ex2(tTestSection * test_section) {
    bool passed = true, failed = false;

    int result = 0;

    failed = false;
    start_test(test_section, "Ficheros_EX_09", "read file");

    result = readFile("../hamlet.txt");

    if (result != 0) {
        failed = true;

    }

    if (failed) {
        end_test(test_section, "Ficheros_EX_09", false);
        passed = false;
    } else {
        end_test(test_section, "Ficheros_EX_09", true);
    }

    failed = false;
    start_test(test_section, "Ficheros_EX_10", "count words");

    result = countFileWords("../hamlet.txt");

    if (result < 0) {

        failed = true;
    } else {

        if (result != 34208) {
            printf("\nwords %d\n", result);
            failed = true;
        }
    }

    if (failed) {
        end_test(test_section, "Ficheros_EX_10", false);
        passed = false;
    } else {
        end_test(test_section, "Ficheros_EX_10", true);
    }

    failed = false;
    start_test(test_section, "Ficheros_EX_11", "count lines");

    result = countFileLines("../hamlet.txt");  
    if (result < 0) {
        failed = true;
    } else {
        if (result != 4459)
            failed = true;
    }

    if (failed) {
        end_test(test_section, "Ficheros_EX_11", false);
        passed = false;
    } else {
        end_test(test_section, "Ficheros_EX_11", true);
    }

    return passed;
}

// Run tests for PR1 exercise 3
bool run_pr1_ex3(tTestSection * test_section) {
    bool passed = true, failed = false;
    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (sizeof numbers) / (sizeof numbers[0]);
    int * receivedNumbers;

    int result = 0;
    long lResult = 0;

    failed = false;
    start_test(test_section, "Ficheros_EX_12", "write file");

    result = writeNumbersFile("../numbers", numbers, size);

    if (result != 0) {
        failed = true;

    }

    if (failed) {
        end_test(test_section, "Ficheros_EX_12", false);
        passed = false;
    } else {
        end_test(test_section, "Ficheros_EX_12", true);
    }

    failed = false;
    start_test(test_section, "Ficheros_EX_13", "read file");

    receivedNumbers = readNumbersFile("../numbers", & size);

    if (receivedNumbers == NULL) {
        failed = true;

    } else if (size != 10) {
        failed = true;
    }

    free(receivedNumbers);

    if (failed) {
        end_test(test_section, "Ficheros_EX_13", false);
        passed = false;
    } else {
        end_test(test_section, "Ficheros_EX_13", true);
    }

    failed = false;
    start_test(test_section, "Ficheros_EX_14", "copy file");

    result = copyFile("../hamlet.txt", "../copy_hamlet.txt");

    if (result != 0) {
        printf("\ncopyFile %d\n", result);
        failed = true;

    }

    result = compareFiles("../hamlet.txt", "../copy_hamlet.txt");

    if (result < 0) {
        failed = true;

    }

    if (failed) {
        end_test(test_section, "Ficheros_EX_14", false);
        passed = false;
    } else {
        end_test(test_section, "Ficheros_EX_14", true);
    }

    failed = false;
    start_test(test_section, "Ficheros_EX_15", "print dir content");

    result = printDirContent("../lib", "../libDir.txt");

    if (result < 0) {
        failed = true;

    }

    result = compareFiles("../libDirContent.txt", "../libDir.txt");

    if (result < 0) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "Ficheros_EX_15", false);
        passed = false;
    } else {
        end_test(test_section, "Ficheros_EX_15", true);
    }

    failed = false;
    start_test(test_section, "Ficheros_EX_16", "get file size");

    lResult = getFileSize("../hamlet.txt");

    if (lResult < 0) {
        failed = true;

    }

    if (lResult != 191726) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "Ficheros_EX_16", false);
        passed = false;
    } else {
        end_test(test_section, "Ficheros_EX_16", true);
    }
    return passed;
}