/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2016, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <rpi3.h>
/* Function to wait */
void wait(long ms)
{
    /* Random value since we don't know the freq,
     * but it is not 1200hz or 300hz or anything we
     * found online. */
    long time_to_wait = 3000L * ms; 
    for(long i=0L; i<time_to_wait; i++)
    {
      asm("nop");
    }
}

int main()
{
    /* Enable GPIO16 as an output */
    long delay=100;
    GPIO->GPFSEL1 |= (1 << 18);

    while(1) 
    {
        GPIO->GPSET0 |= (1 << 16);
        wait(delay);
        GPIO->GPCLR0 |= (1 << 16);
        wait(delay);
        delay *= 2;
    }
	return 0;
}
