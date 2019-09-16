#include <stdlib.h>
#include <stdio.h>
#include "expStruct.h"


// T(x) = 1 + x + x^2/2! + x^3/3! ... + x^n/n!
ExpStruct * iexp (int n){
	ExpStruct exp;
	float ans = 1;
	float temp = 1;

	for(int i = 1; i <= n; i++){
		temp = temp*n/i;
		ans = ans + temp;
	}
	float dec = ans - (int)ans;
	exp.expInt = (int)ans;
	exp.expFraction = (int)((dec+0.005)*100);//2 decimal precision incl. rounding
	ExpStruct *reExp = &exp;
	return reExp;
}
