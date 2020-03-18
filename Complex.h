#pragma once
#ifndef H_COMPLEX
#define H_COMPLEX

#include "pch.h"

class Complex
{
public: 
	/*______________CONSTRUCTORS & OPERATOR OVERLOADS & TOSTRING _____________________________*/
	
	/*
	Default Constructor to initialize the parts of a complex number
	Postcondition:
						- re = 0
						- im = 0
						- dem = 1
	*/
	Complex(); 

	/*
	Parameterized Constructor to initialize the parts of a complex 
	number
	Postcondition:
						- re = r
						- im = i
						- dem = d
	*/
	Complex(int   r, int   i, int   d);  

	/*
	Operator overload of the + operator for addition of complex 
	numbers
	@return 
				= (a + bi) + (c + di) = (a + c) + (b + d)i
	*/
	Complex operator+(Complex right);

	/*
	Operator overload for the - operator for subtraction of complex
	numbers
	@return 
				= (a + bi) - (c + di) = (a - c) + (b - d)i
	*/
	Complex operator-(Complex right);

	/*
	Operator overload for the * operator for multiplication of complex
	numbers
	@return 
				= (a + bi) * (c + di) = (ac – bd) + (ad + bc)i
	*/
	Complex operator*(Complex right);

	/*
	Operator overload for the / operator for division of complex
	numbers
	@return 
				= (a + bi) / (c + di) = ((ac + bd) + (bc – ad)i) / (c^2 + d^2)
	*/
	Complex operator/(Complex right);

	/*
	Operator overload for the logical operator == for comparison
	@return 
				= true if each corresponding data member equal to the other object's 
				= false if each corresponding data member != to the other object's
	*/
	bool operator ==(const Complex& right);

	/*
	Operator overload for the logical operator == for comparison
	@return
				= true if each corresponding data members are not equal to the other object's
				= false if each corresponding data member equal to the other object's
	*/
	bool operator !=(const Complex& right);

	/*
	Operator overload for the logical operator >= for comparison
	@return
				= true if each corresponding data member equal to the other object's
				= false if each corresponding data member != to the other object's
	*/
	bool operator >=(const Complex& right);

	/*
	Operator overload for the extraction operator using complex numbers
	@return 
				the ostream object which will output the complex number in 
				the form:				[re + imi]/dem
	*/
	friend ostream& operator<< (ostream& stream, Complex& a);

	/*
	toString method to output the complex number as a string in the 
	the format:						 [re + imi]/dem
	*/
	string toString() ; //Format [re + imi]/dem

	/*
	Reformat so that real portion is always positive
	*/
	void reFormat(); 
	
	/*_______________________ PARTS OF A COMPLEX NUMBER __________________________________________*/
	int   re;   //real part of a complex number
	int   im;   //imaginary part of a complex number
	int   dem;    //denominator part of a complex number
	
	/* _________________ METHODS TO HELP WITH OPERATOR OVERLOADS ________________________________*/
	//Find gcd and lcm to reduce fraction and add fraction
	/*
	Finds the greatest common denominator of the two parameters
	@param a = an integer value
	@param b = an integer value
	@return 
				= the greatest common denominator 
	*/
	int   gcd(int   a, int   b);

	/*
	Finds the least common multiple of the two parameters
	@param a = an integer value
	@param b = an integer value
	@return 
				= the least common multiple
	*/
	int   lcm(int   a, int   b);

};
#endif