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
     * but it is not 1200Mhz or 300Mhz or anything we
     * found online. 
     *
     * *edit* lets say its 1200Mhz and the for loop takes
     * about 7 cycles per iteration, then the constant
     * should be (1200000000/7) to ms -> 171428 cycles per
     * ms wait.
     *
     * *edit 2* throw logic out the window and trial and error.
     * 
     * */
    long time_to_wait = 1722 * ms; 
    for(long i=0L; i<time_to_wait; i++)
    {
      asm("nop");
    }
}

int main()
{
    /* Enable GPIO16 as an output */
    long delay=1000;
    GPIO->GPFSEL1 |= (1 << 18);

    while(1) 
    {
        GPIO->GPSET0 |= (1 << 16);
        wait(50);
        GPIO->GPCLR0 |= (1 << 16);
        wait(delay);
        delay *= 2;
    }
	return 0;
}
