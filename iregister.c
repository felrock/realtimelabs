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
  return r->content & (1 << i);
}

void assignNibble(int pos, int value, iRegister *r){
  int nib_mask;
  if (pos == 1){
    nib_mask = -1 << 4;
  }
  else if (pos == 2){
    nib_mask = -1 << 8;
    nib_mask += 15;
  }
  r->content &= nib_mask;
  r->content ^= value;
}

int getNibble(int pos, iRegister *r){
  int nib_mask;
  if (pos == 1){
    nib_mask = 15;
  }
  else if (pos == 2){
    nib_mask = 255;
    nib_mask ^= 15;
  }
  return r->content & nib_mask;
}

char *reg2str(iRegister r){
  char *ar = malloc(33*sizeof(char));
  int mask = (1 << 31);
  for(int i=0; i < 32; i++){
    
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

