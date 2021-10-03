//Adsero Mason
//numGen.h
//24 February 2020
//Windows
//
//Revision History:
//	Jan 16:
//		created the header for this class in c++ along with its member
//		functions.
//	Feb 22:
//		overloaded addition, subtraction, comparison, and mixed mode operators
//Class Invariants:
//	1. The class encapsulates two non-negative integers
//	2. The client must keep track of active and reviveable stats of the 
//	   object.
//	3. An message teelling the client about a permanantly invalidated object
//	   after revive is called on an active object.
//	4. if zero or no arhument is given default values will be assigned by the 
//	   constructor.
//	5. If a value is requested from an inactive object zero is returned.
//  6. Multiplication and division are not supported as they are not 
//     required and wouldn't particualarly benefit users.
//  7. Addition and subtraction will never yield negative numbers for numOne and numTwo
//     as these are unsigned integer. If it a negative number is calculated it is inverted
//     and returned as the result.
//  8. comparison operators compare both numOne and numTwo to another objects numOne and numTwo
//     for a comparison to be true both numOne and numTwo must compare to be true.
//Interface Invariants:
//	1. Only non-zero positive integers may be input into the constructor
//	2. Revive is supported only for inactive objects.
//	3. reset is supported only for active objects;
//	4. copying is not supported by numGen except by default
//	   copy constructor.
//	5. addition and subtraction and mixed mode are supported.
//	6. comparison operators are widely supported.
//	7. += and -= supported.
//	8. multiplication and division are not supported by numGen.

#ifndef NUMGEN_H
#define NUMGEN_H

#include <iostream>
using namespace std;

class NumGen
{
	public:
		NumGen(unsigned int numOne = DEFAULT_ONE, unsigned int numTwo = 
			   DEFAULT_TWO);
		NumGen(const NumGen& src); 
		bool getActive();
		bool getRevive();
		//Preconditions: object is in an active state
		//PostConstions: object may become deactive.
		int value();
		//Preconditions: object is inactive.
		//Postconditions: object is returned to an active state.
		//or may become permantly deactivated if called illegally.
		void revive();
		//Precondtions: object is in an active state.
		bool reset();
		NumGen operator+(const NumGen& one);
		NumGen operator+(int number);
		NumGen operator-(const NumGen& one);
		NumGen operator-(int number);
		NumGen operator+=(const NumGen& one);
		NumGen operator+=(int number);
		NumGen operator-=(const NumGen& one);
		NumGen operator-=(int number);
		NumGen operator++();
		NumGen operator++(int dummy);
		NumGen operator--();
		NumGen operator--(int dummy);
		bool operator==(const NumGen& one);
		bool operator!=(const NumGen& one);
		bool operator<(const NumGen& one);
		bool operator>(const NumGen& one);
		bool operator<=(const NumGen& one);
		bool operator>=(const NumGen& one);
		friend ostream& operator<<(ostream& output, const NumGen& src);	
	private:
		const static unsigned int DEFAULT_ONE = 3, DEFAULT_TWO = 4, DEFAULT_VAL = 5;
		unsigned int numOne, numTwo;
		int numCount;
		bool isActive, isReviveable;
		//Preconditions: object is active
		//PostConditions: object may become inactive.
		void checkIfActive();
		void validNumCheck(int& temp);
};

inline NumGen operator+(int number, NumGen& one)
{
	return one + number;
}

inline NumGen operator-(int number, NumGen& one)
{
	return one - number;
}

#endif			
