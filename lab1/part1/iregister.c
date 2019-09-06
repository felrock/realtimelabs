//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"

void resetBit(int i, iRegister *r) {
  r->content &= ~(1 << i);
}

void resetAll(iRegister *r){
  r->content = 0;
}

void setBit(int i, iRegister *r){
  if( i >= 0 && i < 32){
    r->content |= (1 << i);
  }
}

void setAll(iRegister *r){
  r->content = -1;
}

int getBit(int i, iRegister *r){
  if ((r->content & (1 << i)) > 0){
    return 1;
  }
  return 0;
}

void assignNibble(int pos, int value, iRegister *r){
  int nib_mask = ~(15 << (pos-1)*4);

  r->content &= nib_mask;
  r->content ^= (value << (pos-1)*4);
}

int getNibble(int pos, iRegister *r){
  int nib_mask = (15 << (pos-1)*4);
  return (r->content & nib_mask) >> (pos-1)*4;
}

char *reg2str(iRegister r){
  char *ar = malloc(33*sizeof(char));
  int mask = (1 << 30);
  for(int i=0; i < 31; i++){
    if(mask & r.content){
      ar[i] = '1';
    }
    else{
      ar[i] = '0';
    }
    mask >>= 1;
  }
  ar[32] = '\0';
  return ar;
}

void shiftRight(int n, iRegister *r){
  r->content >>= n;
}

void shiftLeft(int n, iRegister *r){
  r->content <<= n;
}
