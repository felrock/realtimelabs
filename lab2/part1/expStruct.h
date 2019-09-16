
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

ExpStruct * iexp ( int );
