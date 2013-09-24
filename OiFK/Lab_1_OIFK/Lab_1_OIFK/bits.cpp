#include "stdafx.h"

/* 
*BSUIR
*Class:   Fundamentals of Computer Organization
*Faculty: Computer Aided Design
*Lab1:    Manipulating Bits Using C
*/


/* 
* bitAnd - x&y using only ~ and | 
*   Example  : bitAnd(6, 5) = 4
*   Legal ops: ~ |
*   Max ops: 8
*/
char bitAnd(char x, char y) 
{
	char result = ~x | ~y;
	return ~result;
}

/* 
* bitXor - x^y using only ~ and & 
*   Example: bitXor(4, 5) = 1
*   Legal ops: ~ &
*   Max ops: 14
*/
char bitXor(char x, char y)
{
	return ~(~(~x&y)&~(x&~y));
}


/* 
* getByte - Extract byte n from word x
*   Bytes numbered from 0 (LSB) to 3 (MSB)
*   Examples: getByte(0x12345678,1) = 0x56
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 6
*/
char getByte(int x, char n) 
{
	if (n < 0 && n > 5)
	{
		return -1;
	}

	char result = x >> (n - 1) * 8;
	return result;
}

/*
* logicalShift - shift x to the right by n, using a logical shift
*   Can assume that 0 <= n <= 31
*   Examples: logicalShift(0x87654321,4) = 0x08765432
*   Legal ops: ~ & ^ | + << >>
*   Max ops: 20
*/
int logicalShift(int x, char n) {
	return 2;
}

/*
* bitNot - Compute !x without using !
*   Examples: bang(3) = 0, bang(0) = 1
*   Legal ops: ~ & ^ | + << >>
*   Max ops: 12
*/
char bitNot(char x) 
{
	char result = x ^ 0xff;
	return result;
}

/* 
* conditional - same as x ? y : z
*   Example: conditional(2,4,5) = 4
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 16
*/
char myconditional(char x, char y, char z) 
{
	return y*(!!x) + (!x)*z;
}

/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
*  Examples: sign(130) = 1
*            sign(-23) = -1
*  Legal ops: ! ~ & ^ | + << >>
*  Max ops: 10
*/
char sign(int x) 
{
	char a=!(x>>8)-!!(x>>8)-!x;
	return a;
}

/*
* fitsBits - return 1 if x can be represented as an 
*  n-bit, two's complement integer.
*   1 <= n <= 32
*   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 15
*/
char fitsBits(int x, char n) 
{
	char degree = n - 1;
	int min = -(1 << degree);
	int max = (1 << degree) - 1;
	char result = (x <= max) * (x >= min);
	return result;
}


/* 
* addOK - Determine if can compute x+y without overflow
*   Example: addOK(0x80000000,0x80000000) = 0,
*            addOK(0x80000000,0x70000000) = 1, 
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 20
*/
char addOK(int x, int y) 
{
	int f = (x >> 31);
	int s = (y >> 31);
	int t = ((x + y) >> 31);																																											
	char result = ((f == s) * (s == t)) | (f != s);

	return result;
}

/*
* isPower2 - returns 1 if x is a power of 2, and 0 otherwise
*   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
*   Note that no negative number is a power of 2.
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 20
*/
int isPower2(int x) {
	return 2;
}  