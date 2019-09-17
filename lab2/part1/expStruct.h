
/**
 *  expStruct
 *  An expStruct is a structure which represents 2 32-bit register and
 *  is equipped with a operation to calculate the value of e^n
 *	(n = the input parameter) with two degrees of precision.
 */

typedef struct expStruct ExpStruct;

struct expStruct {
	int expInt;
	int expFraction;
};

/** @brief Calculates Exponential function of e^n
 *
 *  @param n, an Integer..
 *
 *  @return void
 *
 *  Pre-condition: iRegister != Null
 *
 *  Post-condition: after reset(i, r) all bits of iRegister is 0
 *  properties:
 *  after resetAll(r),  getBit(i, r) = 0
 *  if getBit(i, r) == 0 then
 *    getBit(j, r) returns 0 for all j
 *  0 <= j < 32 and j <> i before and after resetBit(i, r)
 *
 *  test-cases:
 *  Allocate memory to an iRegister r
 *  first set r->content to random value
 *  then do resetAll(&r),
 *  then all memory should be equal to 0, by using assert
 *  display the result after each and every call by
 *    printf("test x is passed!");
 */
ExpStruct * iexp (int n);
