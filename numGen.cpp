//Adsero Mason
//numGen.cpp
//24 February 2020
//Windows
//
//Revision History:
//	Jan 19:
//		implemented all functions from c# into functional c++
//	Jan 23:
//		found and fixed incorrect variable initialization in the class.

//Implementation Invariant:
//	1. Revive when called on an active object permanantly disables it. The state
//	   of being able to be revived is determined by the isReviveable bool.
//	2. Reset is implementes so that it restarts the cycle of an active NumGen
//	   and it doe not work on inactive NumGen's
//	3. Both default anf parameterized constructors are supported by this class.
//	4. isActive bool determines the state of activity of an object.
//	5. numGen addition, subtraction, +=, -=, and mixed mode addition and
//	   subtraction are implemented so that numOne and numTwo may never
//	   be negative.
//	6. This is done by simply inverting a negative value to positive if any of these
//	   operations result in negative numbers.
//	7. For all comparisons both numOne and numTwo are compared to there respective
//	   counterparts in the other numGen being compared. For the comparision to be
//	   true both these comparisons must be true.
//	8. Multiplication and division are not supported by numGen or rangeGen.
//	9. As mentioned earlier subtraction is implemented normally meaning numOne 
//	   will be subtracted by some value and numTwo will be subtracted by another.
//	   It only behaves differently if the result is negative and returns the 
//	   absolute value of the result instead in this case. This is because as
//	   unsigned ints numOne and numTwo cannot be negative.
// 10. This is why addition and subtraction were implemented using a temp variable
// 	   and validNumCheck was used to ensure the value returned to numOne and numTwo
// 	   was greater than 0 and non-negative. 
#include <iostream>
#include "numGen.h"
using namespace std;

NumGen::NumGen(unsigned numOne, unsigned numTwo)
{
	if (numOne == 0){
		numOne = DEFAULT_ONE;
	}
	if (numTwo == 0) {
		numTwo = DEFAULT_TWO;
	}
	this->numOne = numOne;
	this->numTwo = numTwo;
	numCount = 0;
	isActive = true;
	isReviveable = true;	
}

NumGen::NumGen(const NumGen& one)
{
	this->numOne = one.numOne;
	this->numTwo = one.numTwo;
	numCount = one.numCount;
	isActive = one.isActive;
	isReviveable = one.isReviveable;
}

bool NumGen::getActive()
{
	return isActive;
}

bool NumGen::getRevive()
{
	return isReviveable;
} 

int NumGen::value()
{
	checkIfActive();
	if(isActive)
	{   
		numCount += 1;
		switch (numCount % 4)
		{
			case 1:
				return (int)numOne;
			case 2:
				return (int)numTwo;
			case 3:
				return (int)-numOne;
			case 0:
				return (int)-numTwo;
		}
	}
	return 0;
}

void NumGen::revive()
{
	if (isActive)
	{
		isActive = !isActive;
		isReviveable = !isReviveable;
	}
	else 
	{
		isActive = !isActive;
	}
}

void NumGen::checkIfActive()
{
	if ((numCount) == (4*((int)numOne+(int)numTwo)))
	{
		isActive = !isActive;
		numCount = 0;
	}
}

bool NumGen::reset()
{
	if (isActive)
	{
		numCount = 0;
	}
	return isActive;
}

void NumGen::validNumCheck(int& temp)
{
	if (temp < 0)
	{
		temp = -temp;
	}
	if (temp == 0)
	{
		temp = DEFAULT_VAL;
	}
}

NumGen NumGen::operator+(const NumGen& one)
{
	NumGen local(one);
	local.numOne += numOne;
	local.numTwo += numTwo;
	return local;
}

NumGen NumGen::operator+(int number)
{
	int temp;
	NumGen local(numOne, numTwo);
	temp = local.numOne;
	temp += number;
	validNumCheck(temp);
	local.numOne = (unsigned int)temp;
	temp = local.numTwo;
	temp += number;
	validNumCheck(temp);
	local.numTwo = (unsigned int)temp;
	return local;
}

NumGen NumGen::operator-(const NumGen& one)
{
	int temp;
	NumGen local(one);
	temp = local.numOne;
	temp -= numOne;
	validNumCheck(temp);
	local.numOne = (unsigned int)temp;
	temp = local.numTwo;
	temp -= numTwo;
	validNumCheck(temp);
	local.numTwo = (unsigned int)temp;	
	return local;
}

NumGen NumGen::operator-(int number)
{	
	int temp;
	NumGen local(numOne, numTwo);
	temp = local.numOne;
	temp -= number;
	validNumCheck(temp);
	local.numOne = (unsigned int)temp;
	temp = local.numTwo;
	temp -= number;	
	validNumCheck(temp);
	local.numTwo = (unsigned int)temp;
	return local;	
}

NumGen NumGen::operator+=(const NumGen& one)
{
	numOne += one.numOne;
	numTwo += one.numTwo;
	return *this;
}

NumGen NumGen::operator+=(int number)
{
	int temp = number;
	if (temp < 0)
	{
		temp = -temp;
	}
	numOne += temp;
	numTwo += temp;
	return *this;
}

NumGen NumGen::operator-=(const NumGen& one)
{	
	int temp;
	temp = numOne;
	temp -= one.numOne;
	validNumCheck(temp);
	numOne = temp;
	temp = numTwo;
	temp -= one.numTwo;
	validNumCheck(temp);
	numTwo = temp;
	return *this;	
}

NumGen NumGen::operator-=(int number)
{
	int temp;
	temp = numOne;
	temp -= number;
	validNumCheck(temp);
	numOne = temp;
	temp = numTwo;
	temp -= number;
	validNumCheck(temp);
	numTwo = temp;
	return *this;
}

NumGen NumGen::operator++()
{
	++numOne;
	++numTwo;
	return *this;
}

NumGen NumGen::operator++(int dummy)
{
	NumGen oldState = *this;
	++numOne;
	++numTwo;
	return oldState;	
}

NumGen NumGen::operator--()
{
	if(numOne > 1)
	{
		--numOne;
	}
	if(numTwo > 1)
	{
		--numTwo;
	}
	return *this; 
}

NumGen NumGen::operator--(int dummy)
{
	NumGen oldState = *this;
	if(numOne > 1)
	{
		--numOne;
	}
	if(numTwo > 1)
	{
		--numTwo;
	}
	return oldState;
}

bool NumGen::operator==(const NumGen& one)
{
	return (numOne == one.numOne && numTwo == one.numTwo);
}

bool NumGen::operator!=(const NumGen& one)
{
	return (numOne != one.numOne && numTwo != one.numTwo);
}

bool NumGen::operator<(const NumGen& one)
{
	return (numOne < one.numOne && numTwo < one.numTwo); 
}

bool NumGen::operator>(const NumGen& one)
{
	return (numOne > one.numOne && numTwo > one.numTwo);
}

bool NumGen::operator<=(const NumGen& one)
{
	return (*this < one || *this == one);
}

bool NumGen::operator>=(const NumGen& one)
{
	return (*this > one || *this == one);
}

ostream& operator<<(ostream& output, const NumGen& src)
{
	output << " numOne: " << src.numOne << " numTwo: " << src.numTwo; 
	return output;
} 
