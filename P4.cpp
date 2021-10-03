//Adsero Mason
//P4.cpp
//24 February 2020
//Windows
//
//Revision History:
//	Feb 23:
//		created the driver and created all the test for overloaded numGen operations
//		also created test function and most overloaded test operations for rangeGen
//	Feb 24:
//		finished implementing rangeGen overloaded test and completed the driver.
//
//Descriptions:
//	This driver program creates an array of rangeGen and numGen objects and tests all 
//	supported operations, addition, subtraction, mixed mode, and comparison operators for
//	both the arrays. The operation being tested is printed out and then the result is 
//	displayed to show the operation performed without.
//
//input/output:
//	Inputs are all for addition, subtraction and mixed mode operations are any integer.
//	For comparison operations only objects of the same type can be input for comparison.
//	Outputs the results of the operations as specified by their implementation. For
//	coparison this driver outputs a statement saying if the comparison was true or false.
//
//Output: 
//	Outputs the results of the operations as specified by their implementation. For
//	coparison of either objects this driver outputs a statement saying if the comparison 
//	was true or false. numgen outputs both its encapsulated numbers after the operation. 
//	RangeGen operations except comparisin output 3 numGen objects as the result. 
//
//Assumptions:
//	1. User understands what these overloaded operations mean within 
//	   the context of the object in the operation.
//  
//Intent:
//	The intent of this driver is to thoroughly test overloaded operations
//	for both numGen and rangeGen to ensure they were overloaded properly and
//	function correctly.
//	numGen is tested first, then rangeGen is tested finally operations adding
//	rangeGen and  a numGen..
#include "rangeGen.h"
#include "numGen.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void fillNumGen(NumGen arr[]);
void fillRangeArr(RangeGen rangeArr[]);
int randomNumGen();
void testOperators(RangeGen rangeArr[]);
void testAdd(RangeGen range[]);
void testAddNumGen(NumGen arr[]);
void numberAddNumGen(NumGen arr[]);
void testSubNumGen(NumGen arr[]);
void numberSubNumGen(NumGen arr[]);
void testNumGenOperators(NumGen arr[]);
void mixedMode(NumGen arr[]);
void numGenPreInc(NumGen arr[]);
void numGenPostInc(NumGen arr[]);
void numGenPreDec(NumGen arr[]);
void numGenPostDec(NumGen arr[]);
void numGenPlusEqual(NumGen arr[]);
void numGenMinusEqual(NumGen arr[]);
void numGenMixedEqual(NumGen arr[]);
void numGenEquals(NumGen arr[]);
void numGenLess(NumGen arr[]);
void numGenGreater(NumGen arr[]);
void numGenEqualLess(NumGen arr[]);
void numGenEqualGreater(NumGen arr[]);
void testAddNum(RangeGen range[]);
void testSub(RangeGen range[]);
void testSubNum(RangeGen range[]);
void mixedModeRange(RangeGen range[]);
void testPreInc(RangeGen range[]);
void testPostInc(RangeGen range[]);
void testPreDec(RangeGen range[]);
void testPostDec(RangeGen range[]);
void plusEqual(RangeGen range[]);
void minusEqual(RangeGen Range[]);
void mixedEqualRange(RangeGen range[]);
void equals(RangeGen range[]);
void notEquals(RangeGen range[]);
void lessThan(RangeGen range[]);
void greaterThan(RangeGen range[]);
void greaterEqual(RangeGen range[]);
void lessEqual(RangeGen range[]);
void testNumGenRangeOp(RangeGen range[], NumGen arr[]);
void rangePlusNumGen(RangeGen range[], NumGen arr[]);
void rangeMinusNumGen(RangeGen range[], NumGen arr[]);
void rangePlusEqualNumGen(RangeGen range[], NumGen arr[]);
void rangeMinusEqualNumGen(RangeGen range[], NumGen arr[]);
void rangeNumGenMixed(RangeGen range[], NumGen arr[]);
void space();

const int SIZE = 6, MIN = 1, MAX = 40, INC = 1;

int main()
{
	RangeGen rangeArr[SIZE];
	NumGen numArr[SIZE];
	srand(time(NULL));
	fillRangeArr(rangeArr);
	fillNumGen(numArr);
	testNumGenOperators(numArr);
	cout << "Press enter to output rangeGen values:";
	cin.ignore();
	testOperators(rangeArr);
	testNumGenRangeOp(rangeArr, numArr);			
}

void testNumGenRangeOp(RangeGen range[], NumGen arr[])
{
	cout << "Testing operations with RangeGen and NumGen: " << endl;
	rangePlusNumGen(range, arr);
	rangeMinusNumGen(range, arr);
	rangePlusEqualNumGen(range, arr);
	rangeMinusEqualNumGen(range, arr);
	rangeNumGenMixed(range, arr);
}

void rangeNumGenMixed(RangeGen range[], NumGen arr[])
{
	RangeGen temp;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Operation: range[" << i << "] - arr[" << i << "]" << endl;
		cout << "NumGen value: " <<  arr[i] << endl;
		cout << "Range values: " <<  range[i];
		temp = arr[i] + range[i];
		cout << "Result: " << temp;			
		space();
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Operation: range[" << i << "] - arr[" << i << "]" << endl;
		cout << "NumGen value: " <<  arr[i] << endl;
		cout << "Range Values: "  << range[i];
		temp = arr[i] - range[i];
		cout << "Result: " << temp;			
		space();
	}
}

void rangeMinusEqualNumGen(RangeGen range[], NumGen arr[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Operation: range[" << i << "] -= arr[" << i << "]" << endl;
		cout << "NumGen value: " <<  arr[i] << endl;
		cout << "Range values: " << range[i];
		range[i] -= arr[i];
		cout << "Result: " << range[i];			
		space();
	}

}

void rangePlusEqualNumGen(RangeGen range[], NumGen arr[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Operation: range[" << i << "] += arr[" << i << "]" << endl;
		cout << "NumGen value: " <<  arr[i] << endl;
		cout << "range values: " << range[i];
		range[i] += arr[i];
		cout << "Result: " << range[i];			
		space();
	}
}

void rangeMinusNumGen(RangeGen range[], NumGen arr[])
{
	RangeGen temp;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Operation: range[" << i << "] - arr[" << i << "]" << endl;
		cout << "NumGen value: " <<  arr[i] << endl;
		cout <<"range value: " << range[i];
		temp = range[i] - arr[i];
		cout << "Result: " << temp;			
		space();
	}
}

void rangePlusNumGen(RangeGen range[], NumGen arr[])
{
	RangeGen temp;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Operation: range[" << i << "] + arr[" << i << "]" << endl;
	 	cout << "NumGen value: " <<  arr[i] << endl;
		cout << "range values: " <<  range[i];
		temp = range[i] + arr[i];
		cout << "Result: " << temp;			
		space();
	}
}

void testOperators(RangeGen rangeArr[])
{
	cout << "NOW TESTING RANGEGEN OPERATORS: " << endl;
	testAdd(rangeArr);
	testAddNum(rangeArr);
	testSub(rangeArr);
	testSubNum(rangeArr);	
	mixedModeRange(rangeArr);
	testPreInc(rangeArr);
	testPostInc(rangeArr);
	testPreDec(rangeArr);
	testPostDec(rangeArr);
	plusEqual(rangeArr);
	minusEqual(rangeArr);
	mixedEqualRange(rangeArr);
	equals(rangeArr);
	notEquals(rangeArr);
	lessThan(rangeArr);
	greaterThan(rangeArr);		
	greaterEqual(rangeArr);
	lessEqual(rangeArr);
}

void lessEqual(RangeGen range[])
{
	cout << "Testing less than or equal to: " << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: range[" << i << "] <= range[" << i+INC << "]" << endl;
		if (range[i] == range[i+INC])
		{
			cout << "range[" << i << "] is less than or equal to range[" 
				 << i+INC << "]" << endl;
		}
		else
		{
			cout << "range[" << i << "] is not less than or equal range[" 
				 << i+INC << "]" << endl;
		}
		space();
	}
}

void greaterEqual(RangeGen range[])
{
	cout << "Testing greater than equals to: " << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: range[" << i << "] >= range[" << i+INC << "]" << endl;
		if (range[i] == range[i+INC])
		{
			cout << "range[" << i << "] is greater than or equal to range[" 
			<< i+INC << "]" << endl;
		}
		else
		{
			cout << "range[" << i << "] is not greater than or equal to range[" 
			<< i+INC << "]" << endl;
		}
		space();
	}

}

void greaterThan(RangeGen range[])
{
	cout << "Testing greater than: " << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: range[" << i << "] > range[" << i+INC << "]" << endl;
		if (range[i] > range[i+INC])
		{
			cout << "range[" << i << "] is greater than range[" << i+INC << "]" << endl;
		}
		else
		{
			cout << "range[" << i << "] is not greater than range[" << i+INC << "]" << endl;
		}
		space();
	}

}

void lessThan(RangeGen range[])
{
	cout << "Testing less than: " << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: range[" << i << "] < range[" << i+INC << "]" << endl;
		if (range[i] < range[i+INC])
		{
			cout << "range[" << i << "] is less than the range[" << i+INC << "]" << endl;
		}
		else
		{
			cout << "range[" << i << "] is not less than range[" << i+INC << "]" << endl;
		}
		space();
	}
}

void notEquals(RangeGen range[])
{
	cout << "Testing not equal: " << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: range[" << i << "] != range[" << i+INC << "]" << endl;
		if (range[i] != range[i+INC])
		{
			cout << "range[" << i << "] is not equal to range[" << i+INC << "]" << endl;
		}
		else
		{
			cout << "range[" << i << "] is equal range[" << i+INC << "]" << endl;
		}
		space();
	}
}

void equals(RangeGen range[])
{
	cout << "Testing Equals: " << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: range[" << i << "] == range[" << i+INC << "]" << endl;
		if (range[i] == range[i+INC])
		{
			cout << "range[" << i << "] is equal to range[" << i+INC << "]" << endl;
		}
		else
		{
			cout << "range[" << i << "] is not equal range[" << i+INC << "]" << endl;
		}
		space();		
	}
}

void mixedEqualRange(RangeGen range[])
{
	int number;
	for (int i = 0; i < SIZE-INC; i++)
	{
		number = randomNumGen();
		cout << "Operator: range[" << i << "] += " << number << endl;
		cout << "Range: " << range[i] << endl; 
		range[i] += number;
		cout << "Range[" << i << "] new values: " << range[i];
		space();
	}
	for (int i = 0; i < SIZE-INC; i++)
	{
		number = randomNumGen();
		cout << "Operator: range[" << i << "] -= " << number << endl;
		cout << "Range: " << range[i] << endl; 
		range[i] -= number;
		cout << "Range[" << i << "] new values: " << range[i];
		space();
	}
}

void minusEqual(RangeGen range[])
{
	for (int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operator: range[" << i << "] -= range[" << i+INC << "]" << endl;
		cout << "Range: " << range[i] << endl << " Range 2: " << range[i+INC] << endl; 
		range[i] -= range[i+INC];
		cout << "Range[" << i << "] new values: " << range[i];
		space();
	}
}

void plusEqual(RangeGen range[])
{
	for (int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operator: range[" << i << "] += range[" << i+INC << "]" << endl;
		cout << "Range: " << range[i] << endl << " Range 2: " << range[i+INC] << endl; 
		range[i] += range[i+INC];
		cout << "Range[" << i << "] new values: " << range[i];
		space();
	}
}

void testPostDec(RangeGen range[])
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << "Operation: range[" << i << "]--" << endl;
		cout << "old range: " << range[i]-- << endl;
		cout << "new range: " << range[i]; 
		space();	
	}
}

void testPreDec(RangeGen range[])
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << "Operation: --range[" << i << "]" << endl;
		cout << "old range: " << range[i] << endl;
		cout << "new range: " << --range[i]; 
		space();	
	}
}

void testPostInc(RangeGen range[])
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << "Operation: range[" << i << "]++" << endl;
		cout << "old range: " << range[i]++ << endl;
		cout << "new range: " << range[i] << endl;
		space(); 
	}

}

void testPreInc(RangeGen range[])
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << "Operation: ++range[" << i << "]" << endl;
		cout << "old range: " << range[i] << endl;
		cout << "new range: " << ++range[i]; 
		space();	
	}
}

void mixedModeRange(RangeGen range[])
{
	int number;
	cout << "Mixed Mode Addition: " << endl;
	for(int i = 0; i < SIZE; i++)
	{
		number = randomNumGen();
		cout << "Operation: " << number << " + range[" << i << "]" << endl;
		cout << "range[" << i << "] values: " << endl << range[i];
		RangeGen temp;
		temp = number + range[i];
		cout << "Result: " << temp;
		space();	
	}
	cout << "Mixed Mode Subtraction: " << endl;
	for(int i = 0; i < SIZE; i++)
	{
		number = randomNumGen();
		cout << "Operation: " << number << " - range[" << i << "]" << endl;
		cout << "range[" << i << "] values: " << endl << range[i];
		RangeGen temp;
		temp = number - range[i];
		cout << "Result: " << temp;
		space();	
	}	
}

void testSubNum(RangeGen range[])
{
	int number;
	for (int i = 0; i < SIZE; i++)
	{	
		number = randomNumGen();
		cout << "Operation: temp = range[" << i << "] - " << number << endl;
		RangeGen temp;
		cout << "Range: " << range[i] << endl; 
		temp = range[i] - number;
		cout << "Result: " << temp;
		space();	
	}
}

void testSub(RangeGen range[])
{
	for (int i = 0; i < SIZE-INC; i++)
	{	
		cout << "Operation: temp = range[" << i << "] - range[" << i+INC << "]" << endl;
		RangeGen temp;
		cout << "Range: " << range[i] << endl << " Range 2: " << range[i+INC] << endl; 
		temp = range[i] - range[i+INC];
		cout << "Result: " << temp;
		space();	
	}

}

void testAddNum(RangeGen range[])
{
	int number;
	for (int i = 0; i < SIZE; i++)
	{	
		number = randomNumGen();
		cout << "Operation: temp = range[" << i << "] + " << number << endl;
		RangeGen temp;
		cout << "Range: " << range[i] << endl;
		temp = range[i] + number;
		cout << "Result: " << temp;
		space();	
	}
}

void testAdd(RangeGen range[])
{
	for (int i = 0; i < SIZE-INC; i++)
	{	
		cout << "Operation: temp = range[" << i << "] + range[" << i+INC << "]" << endl;
		RangeGen temp;
		cout << "Range: " << range[i] << endl << " Range 2: " << range[i+INC] << endl; 
		temp = range[i] + range[i+INC];
		cout << "Result: " << temp;
		space();	
	}
}
void testNumGenOperators(NumGen arr[])
{
	cout << "Testing overloaded numGen operators:" << endl;
	space();
	testAddNumGen(arr);
	numberAddNumGen(arr);
	testSubNumGen(arr);
	numberSubNumGen(arr);
	mixedMode(arr);
	numGenPreInc(arr);
	numGenPostInc(arr);
	numGenPreDec(arr);
	numGenPostDec(arr);
	numGenPlusEqual(arr);
	numGenMinusEqual(arr);
	numGenMixedEqual(arr);
	numGenEquals(arr);
	numGenLess(arr);
	numGenGreater(arr);
	numGenEqualLess(arr);
	numGenEqualGreater(arr);	
}

void numGenEqualGreater(NumGen arr[])
{
	cout << "Testing >= comparison:" << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operator: Arr[" << i << "] >= Arr[" << i << "]" << endl;  
		cout << "Arr[" << i << "] values: " << arr[i] << endl;
		cout << "Arr[" << i+INC << "] values: " << arr[i+INC] << endl;
		if (arr[i] >= arr[i+INC])
		{
			cout << "Arr[" << i << "] is greater than or equal to Arr[" << i+INC << "]" << endl;
		}
		else
		{
			cout << "Arr[" << i << "] is not greater than or equal to Arr[" << i+INC << "]" << endl;
		}
		space();			
	}
}

void numGenEqualLess(NumGen arr[])
{
	cout << "Testing  <= comparison:" << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operator: Arr[" << i << "] <= Arr[" << i << "]" << endl;  
		cout << "Arr[" << i << "] values: " << arr[i] << endl;
		cout << "Arr[" << i+INC << "] values: " << arr[i+INC] << endl;
		if (arr[i] <= arr[i+INC])
		{
			cout << "Arr[" << i << "] is less than or equal to Arr[" << i+INC << "]" << endl;
		}
		else
		{
			cout << "Arr[" << i << "] is not less than or equal to Arr[" << i+INC << "]" << endl;
		}
		space();			
	}
}

void numGenGreater(NumGen arr[])
{
	cout << "Testing greater than comparison:" << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operator: Arr[" << i << "] > Arr[" << i << "]" << endl;  
		cout << "Arr[" << i << "] values: " << arr[i] << endl;
		cout << "Arr[" << i+INC << "] values: " << arr[i+INC] << endl;
		if (arr[i] > arr[i+INC])
		{
			cout << "Arr[" << i << "] is greater than Arr[" << i+INC << "]" << endl;
		}
		else
		{
			cout << "Arr[" << i << "] is not greater than Arr[" << i+INC << "]" << endl;
		
		}
		space();			
	}
}

void numGenLess(NumGen arr[])
{
	cout << "Testing less than comparison:" << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operator: Arr[" << i << "] < Arr[" << i << "]" << endl;  
		cout << "Arr[" << i << "] values: " << arr[i] << endl;
		cout << "Arr[" << i+INC << "] values: " << arr[i+INC] << endl;
		if (arr[i] < arr[i+INC])
		{
			cout << "Arr[" << i << "] is less than Arr[" << i+INC << "]" << endl;
		}
		else
		{
			cout << "Arr[" << i << "] is not less than Arr[" << i+INC << "]" << endl;
		
		}
		space();			
	}
		
}

void numGenEquals(NumGen arr[])
{
	cout << "Testing Equals and not equals comparison:" << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Arr[" << i << "] values: " << arr[i] << endl;
		cout << "Arr[" << i+INC << "] values: " << arr[i+INC] << endl;
		if (arr[i] == arr[i+INC])
		{
			cout << "These NumGens are equal" << endl;
		}
		if (arr[i] != arr[i+INC])
		{
			cout << "These NumGens are not equal" << endl;
		}
		space();			
	}
}

void numGenMixedEqual(NumGen arr[])
{
	int number;
	cout << "Testing Mixed Equals operators: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		number = randomNumGen();
		cout << "operation: arr[" << i << "] += " << number << endl;
		cout << "arr[" << i << "] original values: " << arr[i] << endl;
		arr[i] += number;
		cout << "arr[" << i << "] new values: " << arr[i] << endl;
		space();	
	}
	for (int i = 0; i < SIZE; i++)
	{
		number = randomNumGen();
		cout << "operation: arr[" << i << "] -= " << number << endl;
		cout << "arr[" << i << "] original values: " << arr[i] << endl;
		arr[i] -= number;
		cout << "arr[" << i << "] new values: " << arr[i] << endl;
		space();	
	}	
}

void numGenMinusEqual(NumGen arr[])
{
	cout << "Testing minusEquals operator: " << endl;
	for (int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operator: arr[" << i << "]-= arr[" << i+INC << "]" << endl;
		cout << "arr[" << i << "] values: " << arr[i] << endl;
		cout << "arr[" << i+INC << "] values: " << arr[i+INC] << endl;
		arr[i]-= arr[i+INC];
		cout << "arr[" << i << "] new values: " << arr[i] << endl;
		space();
	}		
}

void numGenPlusEqual(NumGen arr[])
{
	cout << "Testing plusEqual operator:" << endl;
	for (int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operator: arr[" << i << "]+= arr[" << i+INC << "]" << endl;
		cout << "arr[" << i << "] values: " << arr[i] << endl;
		cout << "arr[" << i+INC << "] values: " << arr[i+INC] << endl;
		arr[i]+= arr[i+INC];
		cout << "arr[" << i << "] new values: " << arr[i] << endl;
		space();
	}
}

void numGenPostDec(NumGen arr[])
{
	cout << "Testing postDecrement operator: " << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: temp = arr[" << i << "]-- + arr[" << i+INC  << "]" 
		     << endl;
		cout << "Arr [" << i << "] original values: ";
		cout << arr[i] << endl;
		cout << "Arr [" << i+INC << "] value: ";
		cout << arr[i+INC] << endl;
		NumGen temp;
		temp = arr[i]-- + arr[i+INC];
		cout << "Resultant NumGen: ";
		cout << temp << endl;
		cout << "Arr[" << i << "] new value:";
		cout << arr[i] << endl;
		space();
	}
}

void numGenPreDec(NumGen arr[])
{
	cout << "Testing PreDecrement operator: " << endl;
	for(int i = 0; i < SIZE; i++)
	{
		cout << "Operation: --arr[" << i << "] " << endl;
		cout << "Arr[" << i << "] original  values:";
		cout << arr[i] << endl;
		--arr[i];
		cout << "arr[i] new values: ";
		cout << arr[i] << endl;
		space();
	}

}

void numGenPostInc(NumGen arr[])
{
	cout << "Testing postIncrement operator: " << endl;
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: temp = arr[" << i << "]++ + arr[" << i+INC  << "]" 
		     << endl;
		cout << "Arr [" << i << "] value: ";
		cout << arr[i] << endl;
		cout << "Arr [" << i+INC << "] value: ";
		cout << arr[i+INC] << endl;
		NumGen temp;
		temp = arr[i]++ + arr[i];
		cout << "Resultant NumGen: ";
		cout << temp << endl;
		cout << "Arr[" << i << "]";
		cout << arr[i] << endl;
		space();
	}
}

void numGenPreInc(NumGen arr[])
{	
	cout << "Testing PreIncrement operator: " << endl;
	for(int i = 0; i < SIZE; i++)
	{
		cout << "Operation: ++arr[" << i << "] " << endl;
		cout << "Arr[" << i << "] values:";
		cout << arr[i] << endl;
		++arr[i];
		cout << "arr[i] new values: ";
		cout << arr[i] << endl;
		space();
	}
}

void mixedMode(NumGen arr[])
{
	int number;
	for(int i = 0; i < SIZE; i++)
	{
		number = randomNumGen();
		cout << "Operation: temp = " << number << "+ arr[" << i << "]" 
		     << endl;
		cout << "Arr [" << i << "] value: ";
		cout << arr[i] << endl;
		NumGen temp;
		temp = number + arr[i];
		cout << "New Num Gen value: ";
		cout << temp << endl;
		space();
	}
	for(int i = 0; i < SIZE; i++)
	{
		number = randomNumGen();
		cout << "Operation: temp = " << number << "- arr[" << i << "]" 
		     << endl;
		cout << "Arr [" << i << "] value: ";
		cout << arr[i] << endl;
		NumGen temp;
		temp = number - arr[i];
		cout << "New Num Gen value: ";
		cout << temp << endl;
		space();
	}

}

void testSubNumGen(NumGen arr[])
{
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: temp = arr[" << i << "] - arr[" << i+INC  << "]" 
		     << endl;
		cout << "Arr [" << i << "] value: ";
		cout << arr[i] << endl;
		cout << "Arr [" << i+INC << "] value: ";
		cout << arr[i+INC] << endl;
		NumGen temp;
		temp = arr[i] - arr[i+INC];
		cout << "New Num Gen value: ";
		cout << temp << endl;
		space();
	}

}

void numberSubNumGen(NumGen arr[])
{
	int number;
	for(int i = 0; i < SIZE; i++)
	{
		number = randomNumGen();
		cout << "Operation: temp = arr[" << i << "] - " << number 
		     << endl;
		cout << "Arr [" << i << "] value: ";
		cout << arr[i] << endl;
		NumGen temp;
		temp = arr[i] - number;
		cout << "New Num Gen value: ";
		cout << temp << endl;
		space();
	}
}

void testAddNumGen(NumGen arr[])
{
	for(int i = 0; i < SIZE-INC; i++)
	{
		cout << "Operation: temp = arr[" << i << "] + arr[" << i+INC  << "]" 
		     << endl;
		cout << "Arr [" << i << "] value: ";
		cout << arr[i] << endl;
		cout << "Arr [" << i+INC << "] value: ";
		cout << arr[i+INC] << endl;
		NumGen temp;
		temp = arr[i] + arr[i+INC];
		cout << "New Num Gen value: ";
		cout << temp << endl;
		space();
	}
}

void numberAddNumGen(NumGen arr[])
{
	int number;
	for(int i = 0; i < SIZE; i++)
	{
		number = randomNumGen();
		cout << "Operation: temp = arr[" << i << "] + " << number 
		     << endl;
		cout << "Arr [" << i << "] value: ";
		cout << arr[i] << endl;
		NumGen temp;
		temp = arr[i] + number;
		cout << "New Num Gen value: ";
		cout << temp << endl;
		space();
	}
}

void fillRangeArr(RangeGen rangeArr[])
{
	int size, userNum;
	for (int i = 0; i < SIZE; i++)
	{
		size = randomNumGen();
		userNum = randomNumGen();
		RangeGen temp(size, userNum);
		rangeArr[i] = temp;
	}	
}

void fillNumGen(NumGen arr[])
{
	int numOne, numTwo;
	for(int i = 0; i < SIZE; i++)
	{
		numOne = randomNumGen();
		numTwo = randomNumGen();
		NumGen temp(numOne, numTwo);
		arr[i] = temp;
	}
}

int randomNumGen()
{
	int random;
	random = rand() % MAX + MIN;
	return 	random;
}

void space(){
 cout << "********************" << endl;
}
