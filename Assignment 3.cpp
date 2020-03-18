/*
Name:				Deron Washington II
Class:				CECS 282
Instructor :			Minhthong Nguyen
Purpose:			Complex Number Calculator
Last updated :	3/18/2020
*/

#include "pch.h"
#include "nodeType.h"
#include "DoublyLinkedList.h"
#include "StackDoublyLinkedList.h"
#include "Complex.h"
#include "myFunctions.h"
#include <fstream>
#include <iostream>
#include <string>


bool isLeftParen(const char c)
{
	if (c == '(')
		return true;

	return false;
}

bool isRightParen(const char c)
{
	if (c == ')')
		return true;

	return false;
}

bool isParen(const char c)
{
	if (c == '(' || c == ')')
		return true;

	return false;
}

//function to see if the character taken in is an operator
bool isOperator(const char c)
{
	// check for the various operators
	if ((c == '+') || (c == '-')
		|| (c == '*') || (c == '/')
		|| (c == '%'))
	{
		return true; // return true if it is
	}

	else
	{
		return false; //false if character is not an operator
	}

} // end function isOperator

int precedence(char op1, char op2)
//determines the precedence between two operators
//Postcondition: returns value true if the first operator is of higher precedence
//than the second operator returns the value false
{
	int pre1,
		pre2; //declare variables to compare the precedence

	//GETS PRECEDENCE OF THE FIRST OPERATOR
	if ((op1 == '+') || (op1 == '-'))
	{
		pre1 = 1;  // high precedence
	}
	else if ((op1 == '*') || (op1 == '/'))
	{
		pre1 = 0; // low precedence
	}
	else if (op1 == '%')
		pre1 = 1; // high precedence
	/*else if (isRightParen(op1) == true)
		pre1 = 100;*/
	else
		pre1 = -1;

	//GETS PRECEDENCE OF THE SECOND OPERATOR
	if ((op2 == '+') || (op2 == '-'))
	{
		pre2 = 1;  // high precedence
	}
	else if ((op2 == '*') || (op2 == '/'))
	{
		pre2 = 0; // low precedence
	}
	else if (op2 == '%')
		pre2 = 1; // high precedence
	/*else if (isRightParen(op2) == true)
		pre2 = 100;*/
	else
		pre2 = -1;

	//// if left paren keep it same place so make them equal precedence
	//if (isLeftParen(op1) == true
	//	|| isLeftParen(op2) == true)
	//	pre2 = pre1;

	//if (isRight)

	//COMPARE THE PRECEDENCE OF THE OPERATORS AND RETURN TRUE OR FALSE

	if (pre1 == pre2) //equal precedence of op1 & op2 return 0;
	{
		return 0;
	}
	else if (pre1 > pre2) //higher precedence of op1 over op2 return 1;
	{
		return 1;
	}
	else //lower precedence of op1 over op2
	{
		return -1;
	}

} // end function precedence

int numOfOperands(const char c)
{
	if (c == '+'
		|| c == '-'
		|| c == '*'
		|| c == '/')
		return 2;

	else if (c == '%')
		return 1;
}

void writeToOutputFile()
{
	ofstream outFile("result.txt");



}


/**
	Function to convert a given string to postfix 
	@param
				infix = mathematical equation
	@return
				= a string value that is a postfix version
					of infix
*/
string convertToPostfix(string infix)
{
	string infx = infix;
	string pfx = "";
	StackDoublyLinkedList<char> stackPtr;

	if (infx != "")
	{
		// RULE A
		pfx = "";
		stackPtr.intializeList();

		//RULE B
		int i = 0;

		string temp;
		temp = new char[100]; // indices 0 - length b/c null character
		temp = infx;

		int length = infx.length();

		i = length;
		char sym = NULL; // variable to get the next symbol from infx

		for (int j = 0; j <= i; j++) // runs until all characters in the infx has been taken in
		{
			sym = temp[j]; // RULE B 


			// TESTS TO SEE IF SYM IS AN OPERAND
			if (((sym >= 48) && (sym <= 57))
				|| ((sym >= 65) && (sym <= 90))
				|| ((sym >= 97) && (sym <= 122))
				|| (sym == '$'))
			{
				pfx = pfx + sym; //RULE B.1
				continue;
			}

			switch (sym)
			{
			case '(': //RULE B.2
				stackPtr.addBack(sym);
				break;
			case ')': //RULE B.3
			{
				char poppedSym = NULL;

				while (poppedSym != '(' && (stackPtr.isEmptyList() == false)) //runs until the left parentheses is popped off or stack is empty
				{
					poppedSym = stackPtr.getTop();
					pfx = pfx + poppedSym;
					stackPtr.popBack();
					poppedSym = stackPtr.getTop();
				}
				stackPtr.popBack(); // pops off the left parentheses

				break;
			} // end last case
			default:
				break;
			} // end switch 

			if (isOperator(sym) == true) // RULE B.4
			{
				char tempOp = NULL;

				if (stackPtr.isEmptyList() == false)
				{
					tempOp = stackPtr.getTop(); // returns the top element and stores in tempOp

					while ((tempOp != '(') && (stackPtr.isEmptyList() == false) //RULE B.4.1
						&& (precedence(tempOp, sym) == 0 || precedence(tempOp, sym) == 1))
					{
						pfx = pfx + stackPtr.getTop();
						stackPtr.popBack();
						if (stackPtr.isEmptyList() == false)
						{
							tempOp = stackPtr.getTop();
						}
					}
				}

				stackPtr.addBack(sym); // END OF RULE B.4.2
			} // END OF RULE B
		} // end of for loop to take in and process infx

		// RULE C
		while (stackPtr.isEmptyList() == false)
		{
			pfx = pfx + stackPtr.getTop();
			stackPtr.popBack();
		}

		return pfx;
	} // end of first if statement

	else
	{
		cout << endl << "There is not an infix expression to convert.";
	}
} // end convert function

/**
	Function to clearly define where a number begins and
	ends in a given string that will be used when converting
	a string to postfix and performing the necessary operations
	@param
				str = mathematical equation
	@return
				= a string value that clearly defines where a number
					begins and ends using the '$' character
*/
string defineNumbers(string str)
{
	bool endDesignator = false;

	for (int i = 0; i < str.length(); i++)
	{
		endDesignator = false;

		// find next alphaNumeric char
		while (isAlphaNumeric(str[i]) == false && i < str.length() )//&& str[i] != '-')
		{

			if (i == str.length())
				break;

			//if (str[i] == '-')
			//{
			//	// if there is an i between the negative sign and the next operator 
			//	// then add a $
			//}
			i++;
		}

		if (i >= str.length())
			continue;

		// found next alphaNumeric char 
		// if at the beginning insert start designator at the beginning
		if (i == 0)
			str.insert(str.begin(), '$');

		//else if (str[i] == '-')
		//{
		//	// 
		//}

		// found next numeric char so insert right before
		else
			str.insert(str.begin() + i, '$');

		//update i after inserting
		i++;

		// find spot to insert the ending number designator at
		while (endDesignator == false)
		{
			i++; // update i

			if (isOperator(str[i]) == true)
			{
				str.insert(str.begin() + i, '$');
				endDesignator = true;
				i++; // update i
			}

			else if (isParen(str[i]) == true && isDigit(str[i - 1]) == true)
			{
				str.insert(str.begin() + i, '$');
				endDesignator = true;
				i++; // update i

			}

			else if (str[i] == 'i' || str[i - 1] == 'i')
			{
				// if prev char is an operator then insert before 'i' and after 'i'
				if (isOperator(str[i - 1]) == true || (str[i - 1] == '$'))
				{
					str.insert(str.begin() + i, '$');
					i++; // back to i
					str.insert(str.begin() + (i + 1), '$');
					i++; // most updated char
				}

				else // insert after 'i'
				{
					if (str[i] == 'i')
						str.insert(str.begin() + (i + 1), '$');
					else
						str.insert(str.begin() + i, '$');
					i++; // most updated char
				}

				endDesignator = true;
			}

			else if (str[i] == '=' && str[i - 1] != '$' &&
				isParen(str[i - 1]) == false && isOperator(str[i - 1]) == false)
			{
				str.insert(str.begin() + i, '$');
				endDesignator = true;
				i++; // update i
			}
		}

	}

	return str;
}


/**
	Function to make negative numbers negative and change all subtraction 
	operators to addition operators
	@param
				str = mathematical equation that has been run through 
						defineNumbers function
	@return
				= a string value that clearly defines negative numbers and changes
					all subtraction to addition by making the operands negative and 
					setting up addition
*/
void fixNegNums(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')
		{
			// change it to positive and move the negative inside $
			str[i] = '+';
			str.insert(i + 2, "n");
			i = i + 2;
		}
	}
}

/**
	Function to perform an arithmetic operation on complex numbers
	@param
				_operand1 = one operand
				_operand2 = another operand
				_operator   = operator of arithmetic operation
	@return
				the result of the arithmetic operation
*/
Complex performOperation(Complex _operand1, Complex _operand2, char _operator)
{
	// perform the calculation
	switch (_operator)
	{
	case '+':
	{
		Complex sum;
		sum = _operand1 + _operand2;
		return sum;
	} // end '+'
	break;

	case '-':
	{
		Complex difference;
		difference = _operand1 - _operand2;
		return difference;
	} // end '-'
	break;

	case '*':
	{
		Complex product;
		product = _operand1 * _operand2;
		return product;
	} // end '*'
	break;

	case '/':
	{
		Complex quotient;
		quotient = _operand1 / _operand2;
		return quotient;
	} // '/'
	break;

	case '%':
	{
		Complex conjugate = _operand1;
		conjugate.im *= -1;
		return conjugate;
	} // end '%'
	break;

	default:
	{
		cout << "Operand doesn't exist";
		system("pause");
		terminate(); // close program
	}

	} // end switch 


	return Complex();
}


/*
Creates complex number in the correct format
@param
			oneLine    = one line of input from file
			i			   = current position in the line from input file
			tempNum = string to represent the number
@return
			= the complex number represented by tempNum in oneLine
*/
Complex createComplexNum(string oneLine, int i, string tempNum)
{
	// create complex number 
	Complex newNum;

	if (oneLine[i - 1] == 'i' || oneLine[i] == 'i') // possibly get rid of part before the or
	{
		if (tempNum == "i")
			newNum.im = 1;
		else
			newNum.im = stoi(tempNum);
	}
	else if (oneLine[i - 1] == '/')
		newNum.dem = stoi(tempNum);
	else
		newNum.re = stoi(tempNum);

	return newNum;
}

struct Vector
{
	// Default Constructor 
	Vector()
	{
		vec = new vector<Complex>();
	}

	// Parameterized Constructor
	Vector(vector<Complex> myVec)
	{
		*vec = myVec;
	}

	// Overloaded Parameterized Constructor
	Vector(vector<Complex>* myVec)
	{
		vec = myVec;
	}


	void pushComplex(Complex _cNum)
	{
		vec->push_back(_cNum);
	}

	/*
	Function to pop the last element and
	return it
	*/
	Complex popComplex()
	{
		if (vec->size() == 0)
		{
			cout << "Not enough elements to pop.";
			system("pause");
			terminate();
		}

		else
		{
			Complex _return = vec->at(vec->size() - 1);
			vec->pop_back();
			return _return;
		}

	}

	/*
	Function to return the size of this container
	*/
	int size()
	{
		return vec->size();
	}

	/*
	Function to return the complex number
	at the specified index
	*/
	Complex get(int index)
	{
		// between 0 and (size - 1)
		if (index > -1 && index < vec->size())
			return vec->at(index);

		else
		{
			cout << "Vector Index Out of Bounds";
			system("pause");
			terminate();
		}
	}

public:
	vector<Complex>* vec;
};

struct Point
{
	// Default Constructor
	Point()
	{
		number = 0;
		isReal = true;
	}


	// Parameterized Constructor
	Point(int n, bool _isReal)
	{
		number = n;
		isReal = _isReal;
	}

public:
	int number = 0;
	bool isReal = true;

};

/*
Return the number within the $
@param
			oneLine = one line of input from file
			i			= index of where you currently are in oneLine
@return
			= a Point object (number being returned, whether the  number is real or imaginary part of complex number)
*/
Point returnNum(string oneLine, int& i)
{
	string temp = "";
	bool isReal = true;
	char c = 0;

	int endNum = findNext('$', oneLine, i + 1);

	if (oneLine[endNum - 1] == 'i')
	{
		temp = oneLine.substr(i + 1, endNum - (i + 1));
		isReal = false;
	}

	else
		temp = oneLine.substr(i + 1, endNum - (i + 1));

	if (temp == "i")
		temp = "1";

	else if (temp == "-i")
		temp = "-1";

	// update i
	i = endNum;
	return Point(stoi(temp), isReal);
}


/**
Function to turn every 'n' to a minus 
@param	
			str = one line of input from file ran through fixNegNums & convertToPostfix
*/
void nToMinus(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		i = findNext('n', str, i);

		if (i != -999)
			str[i] = '-';

		else
			return;
	}
}

void main()
{
	// MAIN 
	ifstream inFile;
	fstream outFile;
	string oneLine = "";
	StackDoublyLinkedList<Complex> finalResultTest;
	StackDoublyLinkedList<char> finalResult;
	string tempNum = "";
	string tempLine = "";

	inFile.open("expressions.txt");
	outFile.open("result.txt");

	if (inFile.good() && outFile.good())
	{
		if (inFile.is_open() && outFile.is_open()) // if file is open
		{
			while (!inFile.eof()) // while not eof
			{
				// process the line and make it into a complex number
				// perform necessary operations then output to result.txt
				getline(inFile, oneLine);
				oneLine = noWhiteSpace(oneLine);
				tempLine = oneLine;
				oneLine = defineNumbers(oneLine);
				fixNegNums(oneLine);
				oneLine = convertToPostfix(oneLine);
				nToMinus(oneLine);
				cout << tempLine << endl;
				cout << oneLine << endl;

				// variable declarations to process oneLine
				string tempNumTest = "";
				int endTempNum = -99;
				Complex operand1(INT_MAX, INT_MAX, INT_MAX);
				Complex operand2(INT_MAX, INT_MAX, INT_MAX);
				Complex operand3(INT_MAX, INT_MAX, INT_MAX);
				char _operatoR = 0;

				// used to hold the operands which can be created dynamically
				vector<Complex>* vec = new vector<Complex>();
				Vector myVEC;

				// Point variable to hold the operands as a integer and whether it is real or imaginary
				Point point;

				// to process oneLine if you are at i = 0 and a '$' then grab everything within the '$' and create a 
				// complex number then go back up to loop and grab next char which should be only a '$' (same process as before)
				// or an operator which you will store as operator and then perform the operation using the last two operands stored
				// after performing operation reset operands and operator and go back up to looping condition
				for (int i = 0; i < oneLine.length(); i++)
				{
					if (oneLine[i] == '$')
					{
						// get number for an operand and determine if it is real or imaginary
						point = returnNum(oneLine, i);

						// real
						if (point.isReal == true)
							myVEC.pushComplex(Complex(point.number, 0, 1));

					// imaginary
						else
							myVEC.pushComplex(Complex(0, point.number, 1));
					}

					else if (isOperator(oneLine[i]) == true)
					{
						_operatoR = oneLine[i];

						if (_operatoR != '%')
						{
							// 2 or more in VEC just grab the last two in VEC 
							// and add to the back
							if (myVEC.size() > 1)
							{
								finalResultTest.addBack(performOperation(myVEC.get(myVEC.size() - 2), myVEC.get(myVEC.size() - 1), _operatoR));
								myVEC.popComplex();
								myVEC.popComplex();
							}
							
							// 1 in VEC and 1 in finalResultTest
							else if (myVEC.size() == 1 && finalResultTest.isEmptyList() == false)
							{
								finalResultTest.addBack(performOperation(finalResultTest.getNPopTop(), myVEC.popComplex(), _operatoR));
							}

							// 0 in VEC and at least 2 in finalResultTest
							else if (myVEC.size() == 0 && finalResultTest.getSize() >= 2)
							{
								// 1st pop is the 1st operand 
								operand2 = finalResultTest.getNPopTop();
								operand1 = finalResultTest.getNPopTop();
								finalResultTest.addBack(performOperation(operand1, operand2, _operatoR));
							}

							// VEC and finalResultTest are both empty
							else
							{
								cout << "Error can't perform operation without necessary operands. Error in main processing oneLine.";
								system("pause");
								terminate();
							}
						}

						else if (_operatoR == '%')
						{
							// VEC is empty and finalResultTest is nonempty
							if (isOperator(oneLine[i - 1]) == true && finalResultTest.isEmptyList() == false)
								finalResultTest.addBack(performOperation(finalResultTest.getNPopTop(), Complex(), _operatoR));

							// VEC is nonempty and finalResultTest is empty
							else if (myVEC.size() > 0)
								finalResultTest.addBack(performOperation(myVEC.popComplex(), Complex(), _operatoR));

							// VEC is empty and finalResultTest is empty = ERROR
							else
							{
								cout << "Error can't perform % operation without necessary operand. Error in main processing oneLine.";
								system("pause");
								terminate();
							}
						}
					}

					else
					{
						cout << "Error in processing oneLine";
						system("pause");
						terminate();
					}
				} // end for loop

				outFile << finalResultTest.end().current->data << endl;
				cout << finalResultTest.end().current->data << endl<< endl;
				finalResultTest.intializeList(); // reset
			} // end if the file is not eof

			// close files
			inFile.close();
			outFile.close();

		} // end if the file is open

	} // end of if file exists


	printf("\n\n");
	system("pause");
} // end main
