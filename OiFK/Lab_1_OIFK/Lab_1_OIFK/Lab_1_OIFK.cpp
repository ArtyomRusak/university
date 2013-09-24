// Lab_1_OIFK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "bits.h"
#include <iostream>
#include "pointer.h"

using namespace std;


int main() {

	//char bA, bB, bC, bD;

	////1. Test bitAnd()
	//bA = 59; bB = 100;
	//bC = bitAnd(bA, bB);
	//printf("bitAnd(%x,%x)=%x \n", bA, bB, bC);
	//bD = bA&bB;
	//printf("True answer  =%x \n", bD);

	////2. ...

	char resultForBitAnd = bitAnd('7', '9');
	cout << (int)resultForBitAnd << endl;
	cout << endl;

	char resultForBitXor = bitXor((char)-255, (char)25);
	char r = -255 ^ 25;
	cout << (int)resultForBitXor << "        " << (int)r << endl;


	char resultForGetByte = (char) getByte(-1022, 2);
	cout << hex << (int)resultForGetByte << endl;

	char variable = 253;
	char resultForBitNot = bitNot(variable);
	cout << (int)resultForBitNot << "  " << (int)~variable << endl;

	//int a = 0x7f / 16;

	char resultForConditional = myconditional((char)-112, variable, 'l');
	cout << (int)resultForConditional << "  " << (int)variable << endl;

	int b = 0 ? 10 : 100;
	cout << dec << b << endl;

	cout << (int)sign(10) << endl;
	cout << (int)sign(-10) << endl;

	int sizeOfInt = intSize();
	int* pointer;
	cout << "Size of int = " << sizeOfInt << endl;
	int sizeOfDouble = doubleSize();
	cout << "Size of double = " << sizeOfDouble << endl;
	int sizeOfPointer = pointerSize();
	cout << "Size of pointer = " << sizeOfPointer << endl;
	cout << changeValue() << endl;
	cout << sizeof(pointer) << endl;

	return 0;
}

