#pragma once
#ifndef H_STACKDLL
#define H_STACKDLL

#include "pch.h"
#include "DoublyLinkedList.h"

template<class Type>
class StackDoublyLinkedList : public DoublyLinkedList<Type> 
{
public: 
	/*
	Default Constructor 
	*/
	StackDoublyLinkedList(); 

	/*
	Conversion Constructor
	*/
	explicit StackDoublyLinkedList(const DoublyLinkedList<Type>& DLL);

	/*
	Conversion Assignment
	*/
	StackDoublyLinkedList<Type>& operator =(const DoublyLinkedList<Type>& DLL);

	/*
	Type Cast Operator Overload
	*/
	operator DoublyLinkedList<Type>();

	/*
	Conversion Constructor (String)
	*/
	explicit StackDoublyLinkedList(const string& str);

	/*
	Destructor
	*/
	~StackDoublyLinkedList();
	
	/*
	Displays a stack on the console
	*/
	void displayStack() const; 

	/*
	Return the element at the top of the stack
	Precondition:
						- the stack is not empty
	@return element at the top of the stack
	*/
	Type getTop() const;

	/*
	Return the element at the top of the stack
	and pop
	*/
	Type getNPopTop();

};
#endif

template<class Type>
StackDoublyLinkedList<Type>::StackDoublyLinkedList()
{
	DoublyLinkedList<Type>();
}

template<class Type>
StackDoublyLinkedList<Type>::StackDoublyLinkedList(const DoublyLinkedList<Type>& DLL)
{
	this->copyList(DLL);
}

//template<class Type>
//StackDoublyLinkedList<Type>::StackDoublyLinkedList(const string& str)
//{
//	// INSERT
//}

template<class Type>
StackDoublyLinkedList<Type>::~StackDoublyLinkedList()
{
	//DoublyLinkedList<Type>::~DoublyLinkedList();
	this->DoublyLinkedList<Type>::~DoublyLinkedList();
}

template<class Type>
void StackDoublyLinkedList<Type>::displayStack() const
{
	//DoublyLinkedList<Type>::displayList();
	this->displayList();
}

template<class Type>
Type StackDoublyLinkedList<Type>::getTop() const
{
	/*if (DoublyLinkedList<Type>::head != nullptr)
		return DoublyLinkedList<Type>::tail->data;

	else
		return (Type)NULL;*/

	if (this->head != nullptr)
		return this->tail->data;

	else
		return Type();
}

template<class Type>
Type StackDoublyLinkedList<Type>::getNPopTop()
{
	Type _return = getTop();
	this->popBack();
	return _return;
}
