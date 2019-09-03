//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "iregister.h"

int main ()
{
  iRegister r;
  char out[33];

  /* Put all your test cases for the implemented functions here */

  printf ("\n");
  
  
  /* test resetAll */
  iRegister rTest, cpy;
  rTest.content = 1;
  resetAll(&rTest);
  assert(rTest.content == 0);
  printf("resetAll test 1 passed!\n");
  
  rTest.content = 15;
  resetAll(&rTest);
  assert(rTest.content == 0);
  printf("resetAll test 2 passed!\n");

  rTest.content = -1;
  resetAll(&rTest);
  assert(rTest.content == 0);
  printf("resetAll test 3 passed!\n");
  
  /* test setBit */
  rTest.content = 0;
  setBit(0, &rTest);
  assert(rTest.content == 1);
  printf("setBit test 1 passed!\n");
  
  rTest.content = 1;
  setBit(1, &rTest);
  assert(rTest.content == 3);
  printf("setBit test 2 passed!\n");
  
  rTest.content = 1;
  setBit(0, &rTest);
  assert(rTest.content == 1);
  printf("setBit test 3 passed!\n");
  
  rTest.content = 0;
  setBit(128, &rTest);
  assert(rTest.content == 0);
  printf("setBit test 4 passed!\n");
  
  /* test setBit */
  
  return 0;
}
