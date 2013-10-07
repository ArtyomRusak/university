#include "stdafx.h"
#include <math.h>
/*
* Return the size of an integer in bytes.
*/
int intSize() {
	int intArray[10];
	int * intPtr1;
	int * intPtr2;

	intPtr1 = &intArray[0];
	intPtr2 = &intArray[1];
	int result = (unsigned long)intPtr2 ^ (unsigned long)intPtr1;

	return result;
}

/*
* Return the size of a double in bytes.
*/
int doubleSize() {
	double doubArray[10];
	double * doubPtr1;
	double * doubPtr2;

	doubPtr1 = &doubArray[0];
	doubPtr2 = &doubArray[1];
	int result = (unsigned long)doubPtr1 ^ (unsigned long)doubPtr2;
	return result;
}

/*
* Return the size of a pointer in bytes.
*/
int pointerSize() {
	double * ptrArray[10];
	double ** ptrPtr1;
	double ** ptrPtr2;

	ptrPtr1 = &ptrArray[0];
	ptrPtr2 = &ptrArray[1];
	int result = (unsigned long)ptrPtr1 ^ (unsigned long)ptrPtr2;

	return result;
}

/*
* Modify intArray[5] to be the value 351 using only &intArray and
* pointer arithmetic.
*/
int changeValue() {
	int intArray[10];
	int * intPtr1 = intArray;
	int * intPtr2;
	int var = 351;
	intPtr2 = &var;

	intPtr1 += 5;
	*intPtr1 = *intPtr2;

	return intArray[5];
}


/*
* Return 1 if ptr1 and ptr2 are within the *same* 64-byte aligned
* block (or word) of memory. Return zero otherwise.
*
* Operators / and % and loops are NOT allowed.
*/
int withinSameBlock(int * ptr1, int * ptr2)
{
	int addressOfFirstPointer = (unsigned long) ptr1;
	int addressOfSecondPointer = (unsigned long) ptr2;
	bool check = false;

	for (int i = 0; i < 3; i++)
	{
		char firstByte = addressOfFirstPointer >> (i + 1) * 8;
		char secondByte = addressOfSecondPointer >> (i + 1) * 8;

		if(firstByte != secondByte)
		{
			check = true;
			break;
		}
	}

	if (check)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
* Return 1 if ptr points to an element within the specified intArray,
* 0 otherwise.
*/
int withinArray(int * intArray, int size, int * ptr) 
{
	bool check = false;
	int addressOfPointer = (unsigned long) ptr;

	for (int i = 0; i < size; i++)
	{
		int address = (unsigned long) (intArray + i);

		if (address == addressOfPointer)
		{
			check = true;
			break;
		}
	}

	if (check)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*
* Return x with the n bits that begin at position p inverted (i.e.,
* turn 0 into 1 and vice versa) and the rest left unchanged. Consider
* the indices of x to begin with the low-order bit numbered as 0.
*/
int invert(int x, int p, int n) 
{
	
	return 2;
}