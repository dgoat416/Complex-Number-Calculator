#pragma once

#ifndef H_nodeType
#define H_nodeType


template <class Type>
struct nodeType
{
public:
	// CONSTRUCTORS, DESTRUCTORS, & OPERATOR OVERLOADS
	//___________________________________________________________

	/*
	Default constructor
	Postcondition:
						prev = nullptr;
						next = nullptr;
	*/
	nodeType();

	/*
	Copy constructor to initialize this object to the values
	of the explicit parameter and thus create a deep copy
	@param otherNode = object to create a deep copy and
									initialize this object to
	Postcondition:
				  this = otherNode
	*/
	nodeType(const nodeType<Type> &otherNode);

	/*
	Destructor
	Deallocates memory from the pointer member
	variables
	*/
	~nodeType();


	/*
	Overload the assignment operator
	@param right = the object to be copied
	Postcondition:
						this = right;
	*/
	const nodeType<Type>& operator=(const nodeType<Type>& right);


	// MEMBER VARIABLES / MEMBER FIELDS (PUBLIC FOR EZ ACCESS)
	//______________________________________________________

	/* Holds the data of the node */
	Type data;

	/* pointer to the previous node in the list */
	nodeType<Type> *prev;

	/* pointer to the next node in the list */
	nodeType<Type> *next;
};

#endif // !NODETYPE.H



// IMPLEMENTATION _____________________________________________________________________

template <class Type>
nodeType<Type>::nodeType()
{
	prev = nullptr;
	next = nullptr;
	//data = Type(NULL);
}

template <class Type>
nodeType<Type>::nodeType(const nodeType<Type> &otherNode)
{
	data = otherNode.data;
	prev = otherNode.prev;
	next = otherNode.next;
}

template <class Type>
nodeType<Type>::~nodeType()
{
	prev = nullptr;
	next = nullptr;
	delete prev;
	delete next;
}

template <class Type>
const nodeType<Type>& nodeType<Type>:: operator=(const nodeType<Type>& right)
{
	if (this != &right)
	{
		prev = nullptr;
		next = nullptr;
		delete prev;
		delete next;

		prev = right.prev;
		next = right.next;
		data = right.data;
	}

	return *this;
}

