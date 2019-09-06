//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "iregister.h"

int main ()
{
  iRegister r;
  char *out;

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

  printf("=============================\n");

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

  printf("=============================\n");

  /* test setAll */
  rTest.content = 0;
  setAll(&rTest);
  assert(rTest.content == -1);
  printf("setAll test 1 passed!\n");

  rTest.content = 15;
  setAll(&rTest);
  assert(rTest.content == -1);
  printf("setAll test 2 passed!\n");

  rTest.content = 27;
  setAll(&rTest);
  assert(rTest.content == -1);
  printf("setAll test 3 passed!\n");

  rTest.content = -1;
  setAll(&rTest);
  assert(rTest.content == -1);
  printf("setAll test 4 passed!\n");

  printf("=============================\n");

  /* test getBit */
  rTest.content = 0;
  assert(getBit(0,&rTest) == 0);
  printf("getBit test 1 passed!\n");

  rTest.content = 4;
  assert(getBit(2,&rTest)  == 1);
  printf("getBit test 2 passed!\n");

  rTest.content = 1 << 30;
  assert(getBit(30,&rTest)  == 1);
  printf("getBit test 3 passed!\n");

  rTest.content = 128;
  assert(getBit(7,&rTest)  == 1);
  printf("getBit test 4 passed!\n");

  printf("=============================\n");

  /* test assignNibble */
  rTest.content = 0;
  assignNibble(1, 15, &rTest);
  assert(rTest.content == 15);
  printf("assignNibble test 1 passed!\n");

  rTest.content = 0;
  assignNibble(2, 1, &rTest);
  assert(rTest.content == 16);
  printf("assignNibble test 2 passed!\n");

  rTest.content = 255;
  assignNibble(3, 11, &rTest);
  assert(rTest.content == 3071);
  printf("assignNibble test 4 passed!\n");

  rTest.content = 1;
  assignNibble(4, 8, &rTest);
  assert(rTest.content == 32769);
  printf("assignNibble test 3 passed!\n");

  printf("=============================\n");

  /* test getNibble */
  rTest.content = 16;
  assert(getNibble(2,&rTest) == 1);
  printf("getNibble test 1 passed!\n");

  rTest.content = 2384;
  assert(getNibble(3,&rTest) == 9);
  printf("getNibble test 2 passed!\n");

  rTest.content = 18768;
  assert(getNibble(4,&rTest) == 4);
  printf("getNibble test 3 passed!\n");

  rTest.content = 2;
  assert(getNibble(1,&rTest) == 2);
  printf("getNibble test 4 passed!\n");

  printf("=============================\n");

  /* test reg2Str */
  char *actual = "0000000000000000000000010000000";
  rTest.content = 128;
  out = reg2str(rTest);
  assert(strcmp(actual, out) == 0);
  printf("reg2Str test 1 passed!\n");

  rTest.content = 256;
  actual = "0000000000000000000000100000000";
  out = reg2str(rTest);
  assert(strcmp(actual, out) == 0);
  printf("reg2Str test 2 passed!\n");

  rTest.content = 201457696;
  actual = "0001100000000100000000000100000";
  out = reg2str(rTest);
  assert(strcmp(actual, out) == 0);
  printf("reg2Str test 3 passed!\n");

  rTest.content = 63;
  actual = "0000000000000000000000000111111";
  out = reg2str(rTest);
  assert(strcmp(actual, out) == 0);
  printf("reg2Str test 4 passed!\n");

  printf("=============================\n");

  /* test shiftRight */
  rTest.content = 2;
  shiftRight(1, &rTest);
  assert(rTest.content == 1);
  printf("shiftRight test 1 passed!\n");

  rTest.content = 1;
  shiftRight(1, &rTest);
  assert(rTest.content == 0);
  printf("shiftRight test 2 passed!\n");

  rTest.content = 128;
  shiftRight(3, &rTest);
  assert(rTest.content == 16);
  printf("shiftRight test 3 passed!\n");

  rTest.content = 1073741824;
  shiftRight(30, &rTest);
  assert(rTest.content == 1);
  printf("shiftRight test 4 passed!\n");

  printf("=============================\n");

  /* test shiftLeft */
  rTest.content = 1;
  shiftLeft(1, &rTest);
  assert(rTest.content == 2);
  printf("shiftLeft test 1 passed!\n");

  rTest.content = 32;
  shiftLeft(5, &rTest);
  assert(rTest.content == 1024);
  printf("shiftLeft test 2 passed!\n");

  rTest.content = 4;
  shiftLeft(3, &rTest);
  assert(rTest.content == 32);
  printf("shiftLeft test 3 passed!\n");

  rTest.content = 0;
  shiftLeft(1, &rTest);
  assert(rTest.content == 0);
  printf("shiftLeft test 4 passed!\n");

  return 0;
}
