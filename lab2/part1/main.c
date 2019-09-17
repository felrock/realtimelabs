#include <stdlib.h>
#include <stdio.h>
#include "expStruct.h"
#include "CUnit/Basic.h"


static ExpStruct * expF;
/*
 * The suite initialization function.
 */
int init_SuiteIexp(){
	if ((expF = (ExpStruct *)malloc(sizeof(ExpStruct))) == NULL){
		return -1;
	}
	return 0;
}

/*
 * The suite cleanup function.
 */
int clean_SuiteIexp(){
	free(expF);
	return 0;
}


void testSuiteIexp(void){
	/*
	* Test positive
	*/
	expF = iexp(5);
  CU_ASSERT(91 == expF->expInt);
	CU_ASSERT(42 == expF->expFraction);

	/*
	* Test negative number, (n+1) terms gives negative amount. accordingly to
	* lab specification.
	*/
	expF = iexp(-5);
	CU_ASSERT(1 == expF->expInt);
	CU_ASSERT(0 == expF->expFraction);

	/*
	* Test large number, gives negative number because of signed integer type.
	*/
	expF = iexp(25);
	CU_ASSERT(0 > expF->expInt);

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
	return runAllTests();
	/*
	ExpStruct * v = iexp(-4);
	printf("expInt: %d\n", v->expInt);
	printf("expFraction: %d\n", v->expFraction);
	return 0;
	*/
}


// gcc -Wall -o test main.c expStruct.c -lcunit
