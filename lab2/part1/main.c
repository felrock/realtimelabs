#include <stdlib.h>
#include <stdio.h>
#include "expStruct.h"

int main(){
	ExpStruct * v = iexp(4);
	printf("expInt: %d\n", v->expInt);
	printf("expFraction: %d\n", v->expFraction);
	return 0;
}
