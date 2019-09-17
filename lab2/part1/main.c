#include <stdlib.h>
#include <stdio.h>
#include "expStruct.h"
#include "CUnit/Basic.h"


static ExpStruct * expF;
/* The suite initialization function.
 *
 */
int init_SuiteIexp(){
	expF = (ExpStruct *)malloc(sizeof(ExpStruct));
	return 0;
}

/* The suite cleanup function.
 *
 */
int clean_SuiteIexp(){
	free(expF);
	return 0;
}


void testSuiteIexp(void){//FIX TEST CASES
  CU_ASSERT(0 == 0);
  CU_ASSERT(2 == 2);
  CU_ASSERT(7 == 7);
}


int runAllTests(){

	CU_pSuite pSuite = NULL;
   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_Iexp", init_SuiteIexp, clean_SuiteIexp);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "Exponential function test", testSuiteIexp))){
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

int main(){
	/*
	ExpStruct * v = iexp(4);
	printf("expInt: %d\n", v->expInt);
	printf("expFraction: %d\n", v->expFraction);
	*/
	return runAllTests();
}


// gcc -Wall -o test main.c expStruct.c -lcunit
