/* 
 * CS:APP Data Lab 
 * 
 * Name: Anushka Kathait, 
 * ID: anka6253
 *
 * Partnered with Anne Chen for most problems.
 *
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
         
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  /* Equivalent expression using DeMorgan's Law.*/
  return (~x & ~y);
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
    /* x is shifted left and then right 16. if it is within the bounds of a short, the shift will not change x's value; if x is outside the bounds of a short, then the resulting value will be different. the exclusive or and a bang are applied so that if the bits are the same as before and can be represented with 16 bits, 1 will be returned and if they have changed 0 will be returned.  */
    return !(x^((x<<16)>>16)); /* nts: ! returns 1 if the changed output is all 0 bits (can be repped as short). */
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
    /*01001001 00100100 10010010 01001001 is equivalent to
      0x49     0x24     0x92     0x49
      the word is shifted 8 bits at a time and the next hex value is added so that every third bit is set to 1.*/
    
    int round1 = (0x49 << 8) | 0x24;
    int round2 = (round1 << 8) | 0x92;
    return (round2 << 8) | 0x49;
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
    /* creates ...010101 by adding the same sequence with the or operator, then compares x. the !! is necessary because of the specification of "any".*/
    int r1 = (0x55 << 8) | 0x55; 
    int r2 = (r1 << 16) | r1;
    
    return !!(x & r2);
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    /* x is shifted left and then right 31, making it so that the LSB takes the leftmost spot in the sequence of 31 bits and the rest of the sequence becomes the same value as the sequence is shifted right arithmetically. */
    return ((x << 31) >> 31);
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    /* Relation by implication finds that !x | y is equivalent to the conditional in propositional logic. This can be confirmed by creating a truth table of x, y, !x | y, and x->y which will show that the truth values for the two statements are the same. */
    return (!x) | y;                
}
/* 
 * bitMask - Generate a mask consisting of all 1's           
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38                                   //76543210
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31                //00111000
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {              
    /* this solution was developed by comparing it at every round with the example given. to make a number negative, we have to negate and add 1 to it. the resulting binary form must then be shifted to the left by highbit so that the last 1 is at the highbit location, negated so that spots highbit to 0 are 1s, and shifted right (removing the extra 1s) and left (moving the 1s to the right locations) by lowbit.*/
    
    int r1 = (~2 + 1);
    int r2 = r1 << highbit;
    int r3 = ~r2;
    int r4 = r3 >> lowbit;
    int r5 = r4 << lowbit;
    return r5;
}

/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
    /* did not get ops poitns for this, over by 1*/
    /* as stated in the textbook, x >> k divides x by 2^k rounding down while biasing the value with (x + (1 << k) - 1) >> k divides x by 2^k rounding up. we must round down if the value is positive and up if negative. if x, then y, else z is equivalent to the expression (x & y) | (~x & z) */
    
    int mult = x + x + x;
    int s = mult >> 31;       /*if pos, then all zeros*/
    
    return (s & ((mult + (1 << 2) + ~0)) >> 2) | (~s & (mult >> 2));
}

/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
    /* first checks signs of x, 2x, and 3x. if the signs are not equal, overflow conditions are met and the value is saturated; else, returns 3x. if x, then y, else z is equivalent to the expression (x & y) | (~x & z) */
    
    int sign1 = 1 & (x >> 31);
    int sign2 = 1 & ((x + x) >> 31);
    int sign3 = 1 & ((x + x + x) >> 31);
    
    int overflow = (sign1 ^ sign2) | (sign2 ^ sign3);
    int mask = (overflow << 31) >> 31;
    
    int tMin = 1 << 31;
    int saturate = ~(x >> 31) ^ tMin;
    
    return (mask & saturate) | (~mask & (x + x + x));
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
    /* use the exclusive or of each bit with each other (starting from the highest) to see if there iis an odd or even number of 0s. if odd, then the result is 1; f even, then the result is 0. for efficiency, use the exclusive or operatin in 16/8/4/2/1 bit chunks.
     */
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    x = x & 1;
    return x;
}

/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    /* c, the floor log2x, is the position of the leftmost bit. it is split in half five times (32 bits), and the first half is checked for the presence of 1 (via !!) and shifted to save the number, increasing the count in the same line. the left or right side is checked for the next split based on the line before. if 1 exists on the left, x is shifted to check the left and vice versa. */
    
    int c = 0;
    c += (!!(x >> 16)) << 4;
    c += (!!(x >> (c + 8))) << 3;
    c += (!!(x >> (c + 4))) << 2;
    c += (!!(x >> (c + 2))) << 1;
    c += (!!(x >> (c + 1)));
    return c;                                   
    /*nts: like a binary search! ALSO c = c + __ is not the same as c += here bc associations!!!*/
}

/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)           //2x/4 + x/4
{
    /*
     *
     */
     int integer = (x >> 1) + (x >> 2);         
     int frac = ((((x & 1) << 1) + (x & 3)) & 7);       
	
	 return integer + ((frac >> 2) & 1) + ((!!(frac & 3)) & (integer >> 31));
}





/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.///////////////////////////////
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
     /*(refer to fp section in textbook 2.4 ish) check 8 bits after sign bit which are the exp bits, not a number (nan) indicates that exp section is 1s and frac section is not bit-less lol */
    unsigned exp = 0xff << 23;  
    
    if(((exp & uf) == exp) && (uf & ((1 << 23) + (~0)))){
        return uf;
    }
    else{
        return (0x80000000 ^ uf);                /*changed sign bit returned*/ 
    }
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
  return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  return 2;
}
