
/**
 *  expStruct
 *  An expStruct is a structure which represents 2 integers and
 *  is equipped with a operation to calculate the value of e^n
 *	(n = the input parameter) with two degrees of precision. This is calculated
 *	using taylor series with (n+1) terms.
 */

typedef struct expStruct ExpStruct;

struct expStruct {
	int expInt;
	int expFraction;
};

/** @brief Calculates Exponential function of e^n using taylor series, and
 *	returns a struct expStruct which holds 2 integers, the integer part and the
 * 	fractional part. the function uses n+1 number of terms to calculate.
 *
 *  @param n, an Integer which holds the value of the exponent.
 *
 *  @return struct extStruct
 *
 *  Pre-condition: 0 <= n <= 22
 *
 *  Post-condition: after iexp(n) both integers are set.
 *
 *  properties: After iexp(n) the attributes can be expected accordingly if
 *	pre-conditions are followed.
 *	1 <= expInt < 1994556672
 * 	0 <= expFraction <= 99
 *
 *  test-cases:
 *	the function is tested with n as a value:
 *	1. in the middle of the pre-condition
 *	2. at the edges.
 *	3. outside the pre-conditions.
 */
ExpStruct * iexp (int n, int *count);
