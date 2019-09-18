#include <stdlib.h>
#include <stdio.h>
#include "expStruct.h"
#include "CUnit/Basic.h"
/*
* Compilation: gcc -o test main.c expStruct.c -lcunit
*/

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
	* 1. Test middle of pre-condition
	*/
	expF = iexp(10);
  CU_ASSERT(12842 == expF->expInt);
	CU_ASSERT(31 == expF->expFraction);
	/*
	* 2. Test edge of pre-condition (inside/just outside)
	*/
	expF = iexp(22);
  CU_ASSERT(1994556672 == expF->expInt);
	CU_ASSERT(0 == expF->expFraction);
	expF = iexp(0);
  CU_ASSERT(1 == expF->expInt);
	CU_ASSERT(0 == expF->expFraction);
	/*
	* 3. Test outside pre-conditions
	* negative numbers give e^0 because of there cannot exist negative terms.
	* large positive gives negative because of integer overflow.
	*/
	expF = iexp(-1);
	CU_ASSERT(1 == expF->expInt);
	CU_ASSERT(0 == expF->expFraction);
	expF = iexp(23);
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
}
