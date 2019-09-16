#include <stdlib.h>
#include <stdio.h>
#include "expStruct.h"


// T(x) = 1 + x + x^2/2! + x^3/3!
ExpStruct * iexp (int n){
	ExpStruct exp;
	float ans = 1;
	float temp = 1;

	for(int i = 1; i <= 20; i++){ // change 20 for different accuracy
		temp = (temp*n)/i;
		ans = ans + temp;
	}

	float dec = ans - ((int)ans);
	exp.expInt = (int)ans;
	exp.expFraction = (int)(dec*100);//100 gives 2 decimal precision
	ExpStruct *reExp = &exp;
	return reExp;
}
