#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "test_pr3.h"
#include "student.h"
#include "ficheros.h"

// Run all tests for PR1
bool run_pr3(tTestSuite * test_suite) {
    bool ok = true;
    tTestSection * section = NULL;

    assert(test_suite != NULL);

    testSuite_addSection(test_suite, "PR3", "Tests for student library");

    section = testSuite_getSection(test_suite, "PR3");
    assert(section != NULL);

    ok = run_pr3_ex1(section) && ok;
    ok = run_pr3_ex2(section) && ok;
    //ok = run_pr3_ex3(section) && ok;

    return ok;
}

// Run all tests for PR1
bool run_pr3_ex1(tTestSection * test_section) {

bool passed = true, failed = false;

    int result;

    tStudentTable students;
    tStudent student1, student2, student3, student4;
    tStudent * studentAux;
    float marks[3];
    // TEST 1: Initialize the table of students
    failed = false;
    start_test(test_section, "PR1_EX1_1", "Initialize the table of students");
    studentTable_init(&students);

    if (studentTable_size(&students) != 0) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "PR1_EX1_1", false);
        passed = false;
    }
    else {
        end_test(test_section, "PR1_EX1_1", true);
    }

    // TEST 2: Initialize a student
    failed = false;
    
    marks[0] = 5;
	marks[1] = 6;
	marks[2] = 7;
    
    result = student_init(&student1, "Alice Smith", marks, 3);

    if (result < 0) {
        failed = true;
	}
	
	marks[0] = 3;
	marks[1] = 6;
	marks[2] = 6;

    start_test(test_section, "PR1_EX1_2", "Initialize a student");

    result = student_init(&student2, "Bob Freeman", marks, 3);

     if (result < 0)
        failed = true;      

    if (student_equals(&student1, &student2)) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "PR1_EX1_2", false);
        passed = false;
    }
    else {
        end_test(test_section, "PR1_EX1_2", true);
    }

    // TEST 3: Add a new student
    failed = false;
    start_test(test_section, "PR1_EX1_3", "Add a new student");

    result = studentTable_add(&students, &student1);
     if (result < 0){
        failed = true;
    }
	
    if (studentTable_size(&students) != 1) {
        failed = true;
    }
	
    studentAux = studentTable_find(&students, "Alice Smith");
    if (studentAux == NULL) {
        failed = true;
    }	
    else if (!student_equals(studentAux, &student1)) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "PR1_EX1_3", false);
        passed = false;
    }
    else {
        end_test(test_section, "PR1_EX1_3", true);
    }

    // TEST 4: Add more students
    failed = false;
    start_test(test_section, "PR1_EX1_4", "Add more students");
    
  	marks[0] = 10;
	marks[1] = 9;
	marks[2] = 10;

    result = student_init(&student3, "John Connor", marks, 3);
    
	marks[0] = 10;
	marks[1] = 10;
	marks[2] = 10;
	
    result = student_init(&student4, "Sarah Connor", marks, 3);

    result = studentTable_add(&students, &student3);
    if (result < 0){
        failed = true;
    }
    
    if (studentTable_size(&students) != 2) {
        failed = true;
    }
    
    studentAux = studentTable_find(&students, "John Connor");
    if (studentAux == NULL) {
        failed = true;
    }
    if (!student_equals(studentAux, &student3)) {
        failed = true;
    }
    result = studentTable_add(&students, &student4);
    if (result < 0){
        failed = true;
    }
    
    if (studentTable_size(&students) != 3) {
        failed = true;
    }
    
    studentAux = studentTable_find(&students, "Sarah Connor");
    if (studentAux == NULL) {
        failed = true;
    }
    else if (!student_equals(studentAux, &student4)) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "PR1_EX1_4", false);
        passed = false;
    }
    else {
        end_test(test_section, "PR1_EX1_4", true);
    }

    // TEST 5: Remove a student
    failed = false;
    start_test(test_section, "PR1_EX1_5", "Remove a student");

    studentAux = studentTable_find(&students, "John Connor");
    if (studentAux == NULL) {
        failed = true;
    }
        
    result = studentTable_remove(&students, &student3);
    if (result < 0){
        failed = true;
    }
    
    if (studentTable_size(&students) != 2) {
        failed = true;
    }    
    
    studentAux = studentTable_find(&students, "John Connor");
    if (studentAux != NULL) {
        failed = true;
    }
    
    studentAux = studentTable_find(&students, "Sarah Connor");
    if (studentAux == NULL) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "PR1_EX1_5", false);
        passed = false;
    }
    else {
        end_test(test_section, "PR1_EX1_5", true);
    }

    // TEST 6: Remove a non existing student
    failed = false;
    start_test(test_section, "PR1_EX1_6", "Remove a non existing student");

    result = studentTable_remove(&students, &student3);
    if (result == 0){
        failed = true;
    }
    
    if (studentTable_size(&students) != 2) {
        failed = true;
    }
    
    studentAux = studentTable_find(&students, "John Connor");
    if (studentAux != NULL) {
        failed = true;
    }
    
    studentAux = studentTable_find(&students, "Sarah Connor");
    if (studentAux == NULL) {
        failed = true;
    }
    
    studentAux = studentTable_find(&students, "Alice Smith");
    if (studentAux == NULL) {
        failed = true;
    }

    if (failed) {
        end_test(test_section, "PR1_EX1_6", false);
        passed = false;
    }
    else {
        end_test(test_section, "PR1_EX1_6", true);
    }

    // Remove used memory
    student_free(&student1);
    student_free(&student2);
    student_free(&student3);
    student_free(&student4);
    
    studentTable_free(&students);

}

// Run tests for PR1 exercise 2
bool run_pr3_ex2(tTestSection * test_section) {
    bool passed = true, failed;
	int result;

    tStudentTable students;
    tStudent student1, student2;
    float marks[3];
	
    //Initialize the table of students
	studentTable_init(&students);
	
	marks[0] = 5;
	marks[1] = 6;
	marks[2] = 7;
	
	student_init(&student1, "Alice Smith", marks, 3);
	studentTable_add(&students, &student1);

	marks[0] = 3;
	marks[1] = 6;
	marks[2] = 6;


    student_init(&student2, "Bob Freeman", marks, 3);
	
    studentTable_add(&students, &student2);

	
    failed = false;
    start_test(test_section, "PR1_EX2_1", "Save file students");

	result = writeStudentsFile("students.bin",&students);
	
    if (result < 0){
        failed = true;
    }

    if (failed) {
        end_test(test_section, "PR1_EX2_1", false);
        passed = false;
    }
    else {
        end_test(test_section, "PR1_EX2_1", true);
    }

    
    	

    return passed;
}

// Run tests for PR1 exercise 3
bool run_pr3_ex3(tTestSection * test_section) {
	
	bool passed = true, failed = false;   
    tStudent classroom[NUM_STUDENTS];
    float *averageMatrix;
	srand(time(NULL));
    int nRandonMark;  
	float averageCalculated[NUM_STUDENTS];

	int numStudents = NUM_STUDENTS;
    
	for (int i=0;i<NUM_STUDENTS; i++) {
	   sprintf(classroom[i].name , "student %d", i);

	   averageCalculated[i] = 0;
    }


	for (int i=0;i<NUM_STUDENTS; i++){
		for (int j=0; j<NUM_MARKS;j++) {
			nRandonMark= rand()%((10+1)-1) + 1; // random number from 1 to 10
			
			averageCalculated[i] = averageCalculated[i] + nRandonMark;
			classroom[i].marks[j]=nRandonMark;
		}
		averageCalculated[i] = averageCalculated[i]/NUM_MARKS;
	}
	
	start_test(test_section, "StudentsEX_01", "get student ");
  
    if (failed) {
        end_test(test_section, "StudentsEX_01", false);
        passed = false;
    } else {
        end_test(test_section, "StudentsEX_01", true);
    }


	start_test(test_section, "StudentsEX_02", "calculate average");
    averageMatrix=calculateAverage (classroom, numStudents);

    for (int i=0;i<NUM_STUDENTS; i++){
		if (averageMatrix[i] != averageCalculated[i]) {
			printf("%f - %f\n",averageMatrix[i] ,averageCalculated[i]);
			failed = true;
		}
	}

    if (failed) {
        end_test(test_section, "StudentsEX_02", false);
        passed = false;
    } else {
        end_test(test_section, "StudentsEX_02", true);
    }

	
    //getAverage(averageMatrix, numStudents);
	
    free(averageMatrix); 

    return passed;
}