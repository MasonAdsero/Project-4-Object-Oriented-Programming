//Adsero Mason
//rangeGen.h
//24 February 2020
//Windows
//
//Revision History:
//	Jan 20:
//		Created rangeGen class and most member functions and variables
//		and implemented constructor copy constructor and copy assignment.
//	Jan 21:
//		added helper functions NumGen and random number generator.
//	Jan 22: 
//		implemented the three main functionality of RangeGen and a helper
//		copy function.
//	Feb 23:
//		added all overloaded functionality declarations to the header.

//interface invariants:
//	1.	RangeGen creates numGen with randomized numbers where every
//		numGen has two distinct values.
//	2.	RangeGen can create as many numGens as the user wishes.
//	3.	User input into RangeGen constructor is positive and non zero.
//  4.  UserInput variable must be equal to or smaller than the size.
//	5.  User can toggle the state of the object between active and inactivee.
//  6.  User will only recieve valid values while RangeGen is Active.
//  7.  The number the user inputs for finding the sum, numdivisible
//      and xth value is no larger than the size use inputs
//  8. Default constructor supported.
//  9. User can track active state through the function getActive()
//  10. addition and subtraction add the numGens of a rangeGen object.
//      the object of larger sizes numGens are appended to the result
//      once the smaller object has run out of numGens to subtract.
//  11. comparisons compare the size of rangeGens as comparing there numGens makes
//      little since and would be a non-sensicle comparison.
//  12. mixed mode subtraction is supported and will invert the call
//      1 - rangeArray[i] to rangeArray[i] - 1 as you cannot subtract a rangeGen
//      from a number.
//Class invariants:
//	1. All user input is postitive in construction
//	2. numGens are in a dynamically allocated array.
//	3. RangeGen will prevent numGen objects from containing duplicates.
//	4. RangeGen supports copying and move semantics
//	5. RangeGen also checkts if a Numgen is active and resets it if
//	   it is inactive before running primary functionaluty to prevent
//	   the return of invalid data.
//	6. Designed to take user input size and number to use in rangeGen functionality. 
//	7. Copy semantics supported so an object may take responsibility for another.
//	8. Client must track the state of activity which they change through the toggle
//	   active function.
//  9. addition, subtraction and mixed modes of these are supported.
//  10. comparisons are widely supported and compare size of RangeGen objects. 
//  11. rangeGen + a numGen is supported. However you cannot
//      add a rangeGen to a numGen as this makes little senses. Subtraction is 
//      supported in this context. 
//  12. Multiplication and division are not supported. 
#ifndef RANGEGEN_H
#define RANGEGEN_H

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "numGen.h"
using namespace std;

class RangeGen
{
	public:
		RangeGen(unsigned int rangeNum = DEFAULT_SIZE, unsigned int userNum = 
			     DEFAULT_INPUT);
     	RangeGen(const RangeGen& one);
		RangeGen& operator=(const RangeGen& one);
		RangeGen(RangeGen&& src);
		RangeGen& operator=(RangeGen&& src);
		~RangeGen();
		//Precondition: RangeGen Is Active
		int sumOfNumGen();
		//Precondition: RangeGen is active
		int valueOfXth();
		//Preconditions: rangeGen is active
		int numDivisible();
		//Postconditions: object is made active of inactive
		void toggleActive();
		bool getActive();				
		RangeGen operator+(const RangeGen& src);
		RangeGen operator+(int number);
		RangeGen operator+(const NumGen& src);
		RangeGen operator-(const RangeGen& src);
		RangeGen operator-(int number);
		RangeGen operator-(const NumGen& src);
		RangeGen operator++();
		RangeGen operator++(int dummy);
		RangeGen operator--();
		RangeGen operator--(int dummy);
		RangeGen operator+=(const RangeGen& one);
		RangeGen operator+=(int number);
		RangeGen operator+=(const NumGen& src);
		RangeGen operator-=(const RangeGen& one);
		RangeGen operator-=(int number);
		RangeGen operator-=(const NumGen& src);	
		bool operator==(const RangeGen& one);
		bool operator!=(const RangeGen& one);
		bool operator<(const RangeGen& one);
		bool operator>(const RangeGen& one);
		bool operator<=(const RangeGen& one);
		bool operator>=(const RangeGen& one);
		friend ostream& operator<<(ostream& output, const RangeGen& d);
			
	private:
		static const unsigned int DEFAULT_SIZE = 6, MAX = 25, DEFAULT_INPUT = 3; 		
		NumGen * rangeArray;
		int numOne, numTwo;
		unsigned int rangeNum, userInput, size;		
		bool isActive;
		int randomNumGenerator();
		void resetNumGenIndex(int i);
		void copy(const RangeGen& one);
};

inline RangeGen operator-(int number, RangeGen& one)
{
	return one - number;
}

inline RangeGen operator+(int number, RangeGen& one)
{
	return one + number;
}

inline RangeGen operator+(NumGen& src, RangeGen& one)
{
	return one + src;
}

inline RangeGen operator-(NumGen& src, RangeGen& one)
{
	return one - src;
}


#endif
