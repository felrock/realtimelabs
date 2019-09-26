#include <stdlib.h>
#include <stdio.h>
#include <rpi3.h>
#include "expStruct.h"


// T(x) = 1 + x + x^2/2! + x^3/3! ... + x^n/n!
ExpStruct * iexp (int n, int *count){
	ExpStruct *exp = (ExpStruct *)malloc(sizeof(ExpStruct));
	if (exp == NULL){
		return NULL;
	}
	float ans = 1;
	float temp = 1;

	for(int i = 1; i <= n; i++){
    if(*count % 20 == 0){//interleaving function
      GPIO->GPSET0 |= (1 << 16);
      wait(50);
      GPIO->GPCLR0 |= (1 << 16);
    }
		temp = temp*n/i;
		ans = ans + temp;
    *count = *count +1;
	}
	float dec = ans - (int)ans;
	exp->expInt = (int)ans;
	exp->expFraction = (int)((dec+0.005)*100);//2 decimal precision incl. rounding
	return exp;
}
