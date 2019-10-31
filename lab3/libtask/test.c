#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <task.h>
#include <task.c>
#include <setjmp.h>
#include "CUnit/Basic.h"

int buffer;
int v1;
jmp_buf buf;


void f1(void* args);
void taskmain(int argc, char** argv);

/*
 * The suite initialization function.
 */
int init_SuiteTS(){
  
    v1 = 0;
    return 0;
}
/*
 * The suite cleanup function.
 */
int clean_SuiteTS(){
    return 0;
}

/*
 * Test Suite for taskswitch
 */
void testSuiteTS(void){

	Channel *c;
	c = chancreate(sizeof(int), buffer);
    if(!setjmp(buf)) 
    {
        // create task and swap to it
	    taskcreate(f1, c, 32768);
        taskswitch();
    }else
    {
        // assert that v1 has been changed
	    CU_ASSERT(v1 == 1);
    }
}

int runAllTests(){

    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
   
    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_taskSwitch", init_SuiteTS, clean_SuiteTS);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "Task switch test", testSuiteTS))){
    CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

void f1(void* args)
{
    // set value and jump back
    v1 = 1;
    longjmp(buf, 1);
}

void taskmain(int argc, char** argv)
{
	runAllTests();
}
