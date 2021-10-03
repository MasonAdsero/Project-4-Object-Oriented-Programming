//Adsero Mason
//rangeGen.cpp
//24 February 2020
//Windows
//
//Revision History:
//	Jan 22:
//		created the class constructors and destructors.
//	Jan 23:
//		implemented all other private functionality and tweaked some functions.
//	Jan 24:
//		added a check to deletes to ensure that only array with data are
//		deallocated by the destructor.
//  Feb 24:
//  	overloaded addition, subtraction, mixed mode, comparison, +=, -= operators
//  	fot the class.
//Implementation Invariant:
//	1. Move semantics included for use with smart pointers. 
//	2. Deep copying is supported with copy constructor and overloaded
//	   assignment operator.
//	3. Numbers for numGen are randomly generated in this class.
//	4. This class takes in user input for the size and for the x value
//	   renamed user input in this case which provides the indices for the
//	   three main functionality.
//	5. A couple helper functions are also implemented like copy to make
//	   the class mroe functionally decomposed. 
//  6. Size of the numGen array and users input are recieved from the user
//     at the construction of the object.
//  7. When inactive object functions are called they return 0 if they can be
//     negative. If they output only positive like numDivisible -1 is returned 
//     instead.
//  8. Default values are included for error processing.
//  9. Included a helper function to ensure no numGen remains inactive.
//  10. Comparison overloads compare the size of the rangeGens as comparing the
//      numGens makes little sense and comparing the sizes of rangeGen classes 
//      is more useful.
//  11. For consistency subtraction and mixed mode operations are also implemented
//      since the user expects these if additions is supplied.
//  12. See numGen.cpp for full details since many of these functions are callbacks to
//      overloaded numGen operators.
#include "rangeGen.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>
#include "numGen.h"
using namespace std;

RangeGen::RangeGen(unsigned int rangeGen, unsigned int userNum)
{
	if (rangeGen <= 0)
	{
		rangeGen = DEFAULT_SIZE;
	}
	if (userNum > rangeGen)
	{
		userNum = DEFAULT_INPUT;
	}
	rangeNum = rangeGen;
	rangeArray = new NumGen[rangeNum];
	for (int i = 0; i < (int)rangeNum; i++)
	{
		numOne = rand() %  MAX + 1;
		numTwo = rand() % MAX + 1;
		if (numTwo == numOne)
		{
			numTwo = rand() % MAX + 1;;
		}
		NumGen one(numOne, numTwo);
		rangeArray[i] = one; 
	}
	userInput = userNum;		
	isActive = true;			
}

RangeGen::RangeGen(const RangeGen& one)
{
	copy(one);
}

RangeGen& RangeGen::operator=(const RangeGen& one)
{
	if (this != &one)
	{
		if(rangeArray != nullptr)
			delete []rangeArray;
		copy(one);
	}
	return *this; 
}

RangeGen::RangeGen(RangeGen&& src)
{
	rangeNum = src.rangeNum;
	rangeArray = src.rangeArray;
	src.rangeNum = 0;
	src.rangeArray = nullptr;
}

RangeGen& RangeGen::operator=(RangeGen&& src)
{
	std::swap(rangeNum, src.rangeNum);
	std::swap(rangeArray, src.rangeArray);
	return *this;
}

RangeGen::~RangeGen()
{
	if(rangeArray != nullptr)
		delete []rangeArray;
}

int RangeGen::sumOfNumGen()
{
	int sum = 0;
	if(isActive)
	{
		for (int i = 0; i < (int)userInput; i++)
		{
			
			resetNumGenIndex(i);
			sum = sum + rangeArray[i].value();
		}
		return sum;
	}
	return 0;
}

int RangeGen::valueOfXth()
{
	int index = ((int)userInput-1);
	if (isActive)
	{
		resetNumGenIndex(index);
		return rangeArray[(index)].value();
	}
	return 0;
}

int RangeGen::numDivisible()
{
	int count = 0;
	if (isActive)
	{
		for(int i = 0; i < (int)rangeNum; i++)
		{
			resetNumGenIndex(i);
			if((rangeArray[i].value() % userInput) == 0)
				count++;
		
		}
		return count;
	}
	return -1;
}

bool RangeGen::getActive()
{
	return isActive;
}

void RangeGen::toggleActive()
{
		isActive = !isActive;
}

void RangeGen::resetNumGenIndex(int i)
{
	if (!rangeArray[i].getActive())
	{
		rangeArray[i].revive();
	}	
}

void RangeGen::copy(const RangeGen& one)
{
	rangeNum = one.rangeNum;
	userInput = one.userInput;
	isActive = one.isActive;
	rangeArray = new NumGen[rangeNum];
	for (int i = 0; i < (int)rangeNum; i++)
	{
		rangeArray[i] = one.rangeArray[i];
	} 
}

RangeGen RangeGen::operator+(const RangeGen& src)
{
	int minSize;
	RangeGen local(src);
	minSize = rangeNum < local.rangeNum? rangeNum: local.rangeNum;
	for (int i = 0; i < minSize; i++)
	{
		local.rangeArray[i] += rangeArray[i];	
	}
	return local;	 
}

RangeGen RangeGen::operator+(const int number)
{
	RangeGen local(rangeNum);
	for (int i = 0; i < (int)rangeNum; i++)
	{
		local.rangeArray[i] = rangeArray[i] + number;
	}
	return local;	
}

RangeGen RangeGen::operator+(const NumGen& src)
{
	RangeGen local(rangeNum);
	for(int i = 0; i < (int)rangeNum; i++)
	{	
		local.rangeArray[i] = rangeArray[i] + src;
	}
	return local;	
}

RangeGen RangeGen::operator-(const RangeGen& src)
{
	int minSize;
	minSize = rangeNum < src.rangeNum? rangeNum: src.rangeNum;
	RangeGen local(src);
	for (int i = 0; i < minSize; i++)
	{
		local.rangeArray[i] -= rangeArray[i];
	}
	return local;		
}

RangeGen RangeGen::operator-(int number)
{
	RangeGen local(rangeNum);
	for (int i = 0; i < (int)rangeNum; i++)
	{
		local.rangeArray[i] = rangeArray[i] - number;
	}
	return local;
}

RangeGen RangeGen::operator-(const NumGen& src)
{
	RangeGen local(rangeNum);
	for (int i = 0; i < (int)rangeNum; i++)
	{
		local.rangeArray[i] = rangeArray[i] - src;
	}
	return local;	
}

RangeGen RangeGen::operator++()
{
	for(int i = 0; i < (int)rangeNum; i++)
	{
		++rangeArray[i];
	}
	return *this;  
}

RangeGen RangeGen::operator++(int dummy)
{
	RangeGen oldState = *this;
	for (int i = 0; i < (int)rangeNum; i++)
	{
		++rangeArray[i];
	}
	return oldState;		
}

RangeGen RangeGen::operator--()
{
	for (int i = 0; i < (int)rangeNum; i++)
	{
		--rangeArray[i];
	}
	return *this;
}

RangeGen RangeGen::operator--(int dummy)
{
	RangeGen oldState = *this;
	for (int i = 0; i < (int)rangeNum; i++)
	{
		--rangeArray[i];		
	}
	return oldState;
}

RangeGen RangeGen::operator+=(const RangeGen& one)
{
	int minSize;
	minSize = rangeNum < one.rangeNum? rangeNum: one.rangeNum;
	for (int i = 0; i < minSize; i++)
	{
		rangeArray[i]+= one.rangeArray[i];
	}
	return *this;	
}

RangeGen RangeGen::operator+=(int number)
{
	for (int i = 0; i < (int)rangeNum; i++)
	{
		rangeArray[i]+= number;		
	}
	return *this;	
}

RangeGen RangeGen::operator+=(const NumGen& src)
{
	for(int i = 0; i < (int)rangeNum; i++)
	{
		rangeArray[i] += src;
	}
	return *this;
}

RangeGen RangeGen::operator-=(const RangeGen& one)
{
	int minSize;
	minSize = rangeNum < one.rangeNum? rangeNum: one.rangeNum;
	for (int i = 0; i < minSize; i++)
	{
		rangeArray[i] -= one.rangeArray[i];		
	}
	return *this;
}

RangeGen RangeGen::operator-=(int number)
{
	for (int i = 0; i < (int)rangeNum; i++)
	{
		rangeArray[i] -= number;
	}
	return *this;
}

RangeGen RangeGen::operator-=(const NumGen& src)
{
	for (int i = 0; i < (int)rangeNum; i++)
	{
		rangeArray[i] -= src;
	}
	return *this;
}

bool RangeGen::operator==(const RangeGen& one)
{
	return (rangeNum == one.rangeNum);	
}

bool RangeGen::operator!=(const RangeGen& one)
{
	return (rangeNum != one.rangeNum);
}

bool RangeGen::operator<(const RangeGen& one)
{
	return (rangeNum < one.rangeNum);
}

bool RangeGen::operator>(const RangeGen& one)
{
	return (rangeNum > one.rangeNum);
}

bool RangeGen::operator<=(const RangeGen& one)
{
	return (rangeNum <= one.rangeNum);
}

bool RangeGen::operator>=(const RangeGen& one)
{
	return (rangeNum >= one.rangeNum);
}

ostream& operator<<(ostream& output, const RangeGen& d){
	const int LOOP = 3;
	output << endl;
	for(int i = 0; i < LOOP; i++)
	{
		output << "NumGen " << i+1 << ": "  << d.rangeArray[i] << endl;
	}
	return output;
} 

