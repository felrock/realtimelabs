/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <rpi3.h>
#include <string.h>
#include "expStruct.h"

void wait(long ms)
{
    long time_to_wait = 1722 * ms;
    for(long i=0L; i<time_to_wait; i++)
    {
      asm("nop");
    }
}

char * convertIntToChar(int n){
  int count = 1;
  int temp = n;
  int pos;
  char * numbers;
  /*Count length of integer n*/
  while((temp = temp/10) > 0){
    count++;
  }
  numbers = (char*)malloc((count+1)*sizeof(char));
  temp = n;
  pos = count-1;
  numbers[count] = '\0';
  while(pos >= 0){
    numbers[pos] = (char)(temp%10 + 0x30);
    pos--;
    temp = temp/10;
  }
  return numbers;
}

int main()
{
  /* Enable GPIO16 as an output */
  GPIO->GPFSEL1 |= (1 << 18);
  int * count = (int*)malloc(sizeof(int));
  int n = 1;
  ExpStruct * exp;
  while (n <= 22){
    GPIO->GPSET0 |= (1 << 16);
    wait(50);
    GPIO->GPCLR0 |= (1 << 16);
    exp = iexp(n, count);
    char *t1 = convertIntToChar(exp->expInt);
    char *t2 = convertIntToChar(exp->expFraction);
    piface_puts(t1);
    piface_puts(".");
    piface_puts(t2);
    wait(4000);
    piface_clear();
    n++;
  }

	return 0;
}
