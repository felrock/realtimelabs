//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.


// Updated by Felix Stenbäck & Jonatan Jönsson.
// Students at Halmstad University, taking Real-Time Embedded Systems.


#ifndef lab0_iregister_h
#define lab0_iregister_h

/**
 *  iRegister
 *  An iRegister is a structure which represents an 32-bit register and
 *  is equipped with standard operations to modify and display them.
 */ 

typedef struct{
    int content;
} iRegister;

/**
 *  Bellow you find the declarations for the functions to modify and display the
 *  memory content of a iRegister data structure. Before each declaration, a brief 
 *  description about what the function shall do is given. 
 *  Later in this file, the documentation for the resetBit function is given. 
 *  Students should follow that format.
 */ 

/** @brief Resets all bits in the register.
 *
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: after reset(i, r) all bits of iRegister is 0
 *  properties: 
 *  after resetAll(r),  getBit(i, r) = 0
 *  if getBit(i, r) == 0 then  
 *    getBit(j, r) returns 0 for all j 
 *  0 <= j < 32 and j <> i before and after resetBit(i, r)
 * 
 *  test-cases: 
 *  Allocate memory to an iRegister r
 *  first set r->content to random value
 *  then do resetAll(&r),
 *  then all memory should be equal to 0, by using assert
 *  display the result after each and every call by 
 *    printf("test x is passed!");
 */
void resetAll(iRegister *);

/** @brief Sets the i'th bit of the iRegister (to 1).
 *
 *  @param i Is i'th bit of the iRegister to be set.
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after setBit(i, r) the i'th bit of iRegister is 1, all other 
 *  bits remain unchanged
 *  properties: 
 *  after setBit(i, r),  getBit(i, r) = 1
 *  if getBit(i, r) == 1 then  
 *    getBit(j, r) returns the same value for all 
 *  0 <= j < 32 and j <> i before and after setBit(i, r)
 * 
 *  test-cases: 
 *  1,2,3. Allocate memory to an iRegister r
 *  first do resetAll(&r),
 *  then set the i'th bit of &x by random int for i = 0, 15 and 23 and then
 *  display the result after each and every call by 
 *    printf("test x passed!");
 */
void setBit(int, iRegister *);

/** @brief Sets all the bits in the register(to 1).
 *
 *  @param i Is i'th bit of the iRegister to be set
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: after setAll(i, r) all bits are set(to 1).
 *  properties: 
 *  after setAll(r),  getBit(i, r) = 1 for all i, 0 =< i < 32
 * 
 *  test-cases: 
 *  1,2,3. Allocate memory to an iRegister r
 *  first set r->content to a random value
 *  then do setAll(r), r->content == -1
 *  display the result after each and every call by 
 *    printf("test x passed!\n"); 
 */
void setAll(iRegister *);

/** @brief Gets the i'th bit of the iRegister (which is either 0 or 1).
 *
 *  @param i Is i'th bit of the iRegister to get.
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return integer, either 1 or 0.
 * 
 *  Pre-condition: iRegister != Null and 0 <= int < 32.
 * 
 *  Post-condition: after getBit(i, r) all bits remain unchanged.
 *  properties: 
 *  after getBit(i, r)
 *  getBit(j, r) returns the same value for all 
 *  0 <= j < 32 and j <> i before and after resetBit(i, r)
 * 
 *  test-cases: 
 *  1,2,3. Allocate memory to an iRegister r
 *  first set r->content to a random value
 *  pick a i, where if the bit is set or not is known.
 *  then do getBit(i, r), which is either 1 or 0.
 *  display the result after each and every call by 
 *    printf("test x passed!\n"); 
 */
int getBit(int, iRegister *);

/** @brief Assign the nibble at pos in r with value.
 *
 *  @param pos Is the position of the nibble to assign.
 *  
 *  @param value Is the value to assign the nibble at pos.
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= int < 8, int, Register != Null
 * 
 *  Post-condition: after assignNibble(pos, i, r), the value at pos is set
 *  to value i, the other bits are unchanged.
 *  properties: 
 *  after assignNibble(pos, value, r)
 *  getNibble(pos, r) returns the value that was passed to assignNibble.
 * 
 *  test-cases: 
 *  1,2,3. Allocate memory to an iRegister r
 *  first set r->content to a random value, in the nibble range pos.
 *  pick a value, pos.
 *  do assignNibble(pos, value, r)
 *  then do getNibble(pos, value, r), which is either 1 or 0.
 *  display the result after each and every call by 
 *    printf("test x passed!\n"); 
 */
void assignNibble(int, int, iRegister *);

/** @brief Get nibble at pos in register r.
 *
 *  @param pos The position of the nibble.
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return int, value of the nibble.
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after getNibble(pos, r) all bits remain unchanged in 
 *  the register.
 *  properties: 
 *  after getNibble(i, r), value is returned and all bits remain unchanged.
 * 
 *  test-cases: 
 *  1,2,3. Allocate memory to an iRegister r
 *  first set the pos nibble of &x by setNibble(pos, value, &r) for random values.
 *  then do getNibble(pos, &r),
 *  the nibble is tested to be the same as the random value assigned.
 *  display the result after each and every call by 
 *    printf("%s",reg2str(r)) 
 */
int getNibble(int, iRegister *);

/** @brief Creates the string represtation of the bits in the register.
 *
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return char*, representation of the register memory.
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: after reg2str(r) all
 *  properties: 
 *  after reg2str(r)
 *  getBit(j, r) returns the same value for all 
 *  where 0 <= j < 32
 * 
 *  test-cases: 
 *  Allocate memory to an iRegister r
 *  write random value to r->content
 *  then do reg2str, compare str with pre-defined char array.
 *  display the result after each and every call by 
 *    printf("test x passed!\n");
 */
char *reg2str(iRegister);

/** @brief Shifts the register i places to the right(which is the opposite of left).
 *
 *  @param i Is i'th places to shift.
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after shiftRight(i, r) 0, will occpy the shifted places.
 *  properties: 
 *  after shiftRight(i, r),  getBit(j, r) == 0 for j < i.
 * 
 *  test-cases: 
 *  Allocate memory to an iRegister r
 *  set r->content to a random int.
 *  first do resetShift(i, &r),
 *  then verify shift, bits before i is eq zero and rest is eq shifted values.
 *  display the result after each and every call by 
 *    printf("test x passed!\n");
 */
void shiftRight(int, iRegister *);

/** @brief Shifts the register i places to the left(which is the opposite of left).
 *
 *  @param i Is i'th places to shift.
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after shiftLeft(i, r) 0, will occpy the shifted places.
 *  properties: 
 *  after shiftRight(i, r),  getBit(j, r) == 0 for j > 31-i.
 * 
 *  test-cases: 
 *  Allocate memory to an iRegister r
 *  set r->content to a random int.
 *  first do resetLeft(i, &r),
 *  then verify shift, bits before i is eq zero and rest is eq shifted values.
 *  display the result after each and every call by 
 *    printf("test x passed!\n");
 */
void shiftLeft(int, iRegister *);

/** @brief Resets the i'th bit of the iRegister (to 0)
 *
 *  @param i Is i'th bit of the iRegister to be reset
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after reset(i, r) the i'th bit of iRegister is 0, all other 
 *  bits remain unchanged
 *  properties: 
 *  after resetBit(i, r),  getBit(i, r) = 0
 *  if getBit(i, r) == 0 then  
 *    getBit(j, r) returns the same value for all 
 *  0 <= j < 32 and j <> i before and after resetBit(i, r)
 * 
 *  test-cases: 
 *  Allocate memory to an iRegister r
 *  first do resetAll(&r),
 *  then set the i'th bit of &x by setBit(i, &r) for i = 0, 15 and 23 and then
 *  display the result after each and every call by 
 *    printf("test x passed!\n"); 
 */
void resetBit(int, iRegister *);

#endif
