#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "test_pr2.h"
#include "utilidades.h"
#include "ficheros.h"

// Run all tests for PR1
bool run_pr2(tTestSuite * test_suite) {
    bool ok = true;
    tTestSection * section = NULL;

    assert(test_suite != NULL);

    testSuite_addSection(test_suite, "PR2", "Tests for ficheros Library");

    section = testSuite_getSection(test_suite, "PR2");
    assert(section != NULL);

    ok = run_pr2_ex1(section) && ok;
    ok = run_pr2_ex2(section) && ok;
    //ok = run_pr2_ex3(section) && ok;

    return ok;
}

// Run all tests for PR2
bool run_pr2_ex1(tTestSection * test_section) {
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

// Run tests for PR2 exercise 2
bool run_pr2_ex2(tTestSection * test_section) {
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

    // if fail, execute this command in cmd ls -f lib > libDirContent.txt
    
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

// Run tests for PR2
bool run_pr2_ex3(tTestSection * test_section) {
    bool passed = true;
	
    return passed;
}