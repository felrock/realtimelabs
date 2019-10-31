#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <task.h>
#include <task.c>
#include "CUnit/Basic.h"

int buffer;
int v1, v2;

void f1(void* args);
void f2(void* args);

void f3(void* args);
void f4(void* args);

void taskmain(int argc, char** argv);

/*
 * The suite initialization function.
 */

int init_SuiteTS(){

  v1 = 0;
  v2 = 1;
}
/*
 * The suite cleanup function.
 */
int clean_SuiteTS(){

}

/*
 * Test Suite for taskswitch
 */
void testSuiteTS(void){
	Channel *c;
	c = chancreate(sizeof(int), buffer);

	taskcreate(f1, c, 32768);
	taskswitch();
	CU_ASSERT(v1 == 1);
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
    Channel *c;
    c = args;
    v1 = 1;
}

void f2(void* args)
{
    Channel *c;

    v2 = 0;
    assert(v1 != v2);
    print("test two  complete!\n");
    v1 = 1337;
    c = chancreate(sizeof(int), buffer);
	taskcreate(f3, c, 32768);
    c = chancreate(sizeof(int), buffer);
	taskcreate(f4, c, 32768);
    taskswitch();

    while(1){}
}

void f3(void* args)
{
    assert(v1 == 1337);
    printf("test three complete!\n");
    v1 = 7331;
    taskswitch();
    while(1){}
}

void f4(void* args)
{
    assert(v1 == 7331);
    printf("test four complete!\n");
    printf("All tests were completed!\n");
    taskexitall(0);
    while(1){}
}

void taskmain(int argc, char** argv){
	runAllTests();
}


/*void
taskmain(int argc, char **argv)
{
	Channel *c;

    v1 = 0;
    v2 = 1;

	c = chancreate(sizeof(int), buffer);
	taskcreate(f1, c, 32768);
    taskswitch();
    printf("done\n");
    while(1){}
}
*/
