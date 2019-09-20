/*
 * CS:APP Data Lab
 *
 * <Jack Hogan  jfhogan>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  //made the not andl equivelant of ~(x|y) usind demorgans
  int yNot = ~y;
  int xNot = ~x;
  return (xNot&yNot);
}
/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
   int templateAllOdd0 = 0x55;
   int save;
   templateAllOdd0 = (templateAllOdd0<<8) + 0x55;
   templateAllOdd0 = (templateAllOdd0<<16) + templateAllOdd0;
   save = templateAllOdd0 & x;
  return (!(save ^ templateAllOdd0));
}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  int blankSlate = 0xFF;
  int nByte;
  int mByte;
  int shifter = 0x3;
  int shifterN = n<<shifter;
  int shifterM = m<<shifter;
  int byteClearer;
  nByte = (x>>shifterN) & blankSlate; //blank slate here is now the desired byte
  mByte = (x>>shifterM) & blankSlate;
  nByte = nByte<<(shifterM);
  mByte = mByte<<(shifterN);
  byteClearer = ~((blankSlate<<shifterN) | (blankSlate<<shifterM));
  x = x&byteClearer;
  return (x|mByte|nByte);
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int checkOne;
  int checkTwo;
  int shiftToFirstBitTwo;
  int standardizedRange;
  int overFlowSweep;
  checkOne = 0x30;
  checkTwo = x + 6;
  overFlowSweep = (checkOne ^ x)>>4;//all zeros if in range
  //shiftToFirstBitOne = checkOne>>3;
  shiftToFirstBitTwo = (checkTwo ^ checkOne)>>4;
  standardizedRange = overFlowSweep | shiftToFirstBitTwo;
  standardizedRange = !(standardizedRange);
  return (standardizedRange);
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
  int toZero = 0x01;
  int nInverse = ~(~31 + n);
  toZero = ~((~toZero)<<nInverse);
  x = (x>>n);
  x = x & toZero;
  return x;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int sign  = x >> 31;
  int regulator = x^sign;
  int carbonCopy = regulator;
  int medianValue;
  int sum;
  int inverseSum;
  //this is just a binary search, using carbon copy to regulate which direction
  //we go based on the value of medianValue
  medianValue = !((carbonCopy >> 16)) << 4;
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !((carbonCopy >> 24)) << 3;
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !((carbonCopy >> 28)) << 2;
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !((carbonCopy >> 30)) << 1;
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !((carbonCopy >> 31));
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !((carbonCopy >> 31));
  sum = sum + medianValue;
  //so I found the first 1 which gives the amount
  inverseSum = ~(~33+sum);
  return inverseSum;
}
/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  int isZero = !x; //is one if zero
  int shifted = x>>31;
  x = shifted + (!isZero+shifted);
  return x;
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  int ret = x^y;
  return !ret;
}
/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {
  int inkPad = x;
  int replacer = 0x00;
  int nInverse = ~(~32 + n);
  replacer = ~((~replacer)<<nInverse);//
  x = x >> n;
  x = x & replacer;
  x = x | inkPad<<nInverse;
  return x;
}
/*
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
 //this can be improved by invertng 2totheminusOne
 //then inverting the two and operations
 //and regulating slate with the changed 22totheminusOne
 // also check behavior of pos vs neg
int rempwr2(int x, int n) {
  int zeroHolder = 0x00;
  int twoToTheNMinueOne = ~((~zeroHolder)<<n);// ones for n places zeros else
  int signBitsMed = x>>31;
  int slate = (signBitsMed | twoToTheNMinueOne);//slate saves leading 1's for negative and 0's for positive
  int positiveMod = (~(x) + 1) & twoToTheNMinueOne;//negate then save inverted data
  positiveMod = (~positiveMod + 1 & slate);//uninvert data then regulate leading bits with slate
  return positiveMod;
}
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x) {
  int carbonCopy = x;
  int medianValue;
  int sum;
  //this is just a binary search, using carbon copy to regulate which direction
  //we go based on the value of medianValue
  medianValue = !(~(carbonCopy >> 16)) << 4;
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !(~(carbonCopy >> 24)) << 3;
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !(~(carbonCopy >> 28)) << 2;
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !(~(carbonCopy >> 30)) << 1;
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !(~(carbonCopy >> 31));
  carbonCopy = carbonCopy << medianValue;
  sum = sum + medianValue;

  medianValue = !(~(carbonCopy >> 31));
  sum = sum + medianValue;
  return sum;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
  int compareSign = !((x^y)>>31); // 1 if same 0 if different
  int sum = x+y;
  int osi;
  int adjustment = ~(0x01 <<31); //largest positive number
  int sign = x>>31;
  int overflowNums = adjustment ^ sign;
  int compareSum = (sum^x)>>31; //all 1 if the sum is diff from x all 0 if x is same as sum
  int iso = compareSign & compareSum; //1 if in same out diff else 0
  iso = ~iso +1;
  osi = iso & overflowNums;
  iso = ~iso & sum;

  return iso | osi;
}
/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int nanMask = 0x80000000;

  int outPut = nanMask ^ uf;
  int abs = 0x7fffffff & uf;
  if(abs > 0x7f800000){
    outPut = uf;
  }
 return outPut;
}
/*
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
 //right shift mantisa

unsigned float_half(unsigned uf) {
  int nanMask = 0x7f800000;
  int mantisaMask = 0x007fffff;
  int signBit = 0x80000000;
  int lastDigits = !((uf & 0x00000003) ^ 0x0000003);
  signBit = signBit & uf;
  nanMask = nanMask & uf;
  mantisaMask = mantisaMask & uf;
  if(nanMask == 0x7f800000){
    return uf;
  }
  if (!(0xff000000 & nanMask)){
    mantisaMask = mantisaMask >>1;
      if(lastDigits){
        mantisaMask = mantisaMask + 1;
      }
      if (nanMask == 0x00800000){
        mantisaMask = mantisaMask + 0x00400000;
      }
    return (signBit| mantisaMask);
  }
    nanMask = ~(~nanMask +0x00800000);
  return (signBit | mantisaMask | nanMask);
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
int mantisa;
int mask = 0x1<<31;
int signGetter = x&mask;
int exp = 158;
if (!x){
  return 0;
}
if(x == mask  ) {
  return mask | (exp << 23);
}
if (signGetter<0){
  x = -x;
}

while (!(x & mask)){
  x = x<<1;
  exp =exp -1;
}

mantisa =(x&(~mask))>>8;
if((x& 0x80) && ((x & 0x7f) > 0 || mantisa & 1)){
  mantisa++;
}

  return signGetter + (exp << 23) + mantisa;
}
