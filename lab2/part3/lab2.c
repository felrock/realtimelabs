/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <rpi3.h>
#include "expStruct.h"
#include <string.h>

void wait(long ms)
{
    long time_to_wait = 1722 * ms;
    for(long i=0L; i<time_to_wait; i++)
    {
      asm("nop");
    }
}

int main()
{
  /* Enable GPIO16 as an output */
  GPIO->GPFSEL1 |= (1 << 18);

  int n = 1;
  ExpStruct * exp;
  while (n <= 22){
    GPIO->GPSET0 |= (1 << 16);
    wait(50);
    GPIO->GPCLR0 |= (1 << 16);
    exp = iexp(n);
    wait(2000);
    n++;
  }

	return 0;
}
