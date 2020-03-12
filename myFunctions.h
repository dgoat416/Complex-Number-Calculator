#pragma once

#ifndef H_MYFUNC
#define H_MYFUNC	

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// provide class definition
char intToChar(int x);

string intToString(int x);
	
int charToInt(char x);

int stringToInt(string str);

bool isDigit(char c);

bool isAlpha(char c);

bool isAlpha(string _word);

bool isAlphaNumeric(char c);

string onlyAlphaChars(string _word);

string noWhiteSpace(string str);

string noLeadingWhiteSpace(string str);

string noEndingPunctuation(string _word);

bool isLeapYear(const int year);

string currentDayOfWeek(const int days, const int year);

string getDayAndMonthOfYr(int& days, const int year);

string scramble(string s);

string charToString(char c);

int findNext(char c, string str, int i);

/**
	Function to convert a given string to postfix
	@param
				infix = mathematical equation
	@return
				= a string value that is a postfix version
					of infix
*/
string convertToPostfix(string infix);

#endif