#pragma once
#ifndef H_DOUBLYLINKEDLIST
#define H_DOUBLYLINKEDLIST

#include "pch.h"
#include "nodeType.h"
#include <cassert>

//******************* DOUBLY LINKED LIST ITERATOR CLASS DEFINITION **************************************
template <class Type>
class DoublyLinkedListIterator
{
public:
	/*
	Default constructor. 
	Postcondition: current = nullptr
	*/
	DoublyLinkedListIterator()
	{
		current = nullptr;
	}

	/*
	Parameterized constructor
	Postcondition: current = ptr;
	*/
	DoublyLinkedListIterator(nodeType<Type> *ptr)
	{
		current = ptr;
	}

	/*
	Function to overload the dereferencing operator *. 
	Postcondition: Returns the info contained in the node
	*/
	Type operator*()
	{
		return current->data;
	}

	/*
	Overload the pre-increment operator. 
	Postcondition: The iterator is advanced to the next node.
	*/
	DoublyLinkedListIterator<Type> operator++()
	{
		current = current->next;
		return *this;
	}

	/*
	Overload the pre-decrement operator. 
	Postcondition: The iterator is advanced to the next node.
	*/
	DoublyLinkedListIterator<Type> operator--()
	{
		current = current->prev;
		return *this;
	}

	/*
	Overload the arithmetic + operator
	Postcondition:
						Returns current advanced advancePtr number of
						pointers
	*/
	DoublyLinkedListIterator<Type> operator+(int advancePtr)
	{
		while (current != nullptr && advancePtr > 0)
		{
			current = current->next;
			advancePtr--;
		}
		

		return *this;
	}

	/*
	Overload the [] operator
	Postcondition: 
						Returns the current at the specified index location
	*/
	DoublyLinkedListIterator<Type> operator[](int index)
	{
		
	}


	/*
	Overload the equality operator.
	Postcondition:
						Returns true if this iterator is equal to the iterator specified by right, 
						otherwise it returns false.
	*/
	bool operator==(const DoublyLinkedListIterator<Type>& right) const
	{
		if (current == right.current)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	/*
	Overload the not equal to operator. 
	Postcondition: Returns true if this iterator is not equal to the iterator specified by right, 
	otherwise it returns false.
	*/
	bool operator!=(const DoublyLinkedListIterator<Type>& right) const
	{
		if (current != right.current)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	//pointer to point to the current node in the linked list
	nodeType<Type> *current;
		  
};



template<class Type>
class DoublyLinkedList 
{   
public: 
	
	// CONSTRUCTORS, DESTRUCTORS, & OPERATOR OVERLOADS
	//___________________________________________________________

	/*
	Default Constructor 
	Initializes all protected members
	Postcondition:
						head = nullptr;
						tail = nullptr;
						size = 0;
	*/
	DoublyLinkedList();

	/*
	Copy Constructor
	Creates a deep copy of the parameter
	Postcondition:
						head = otherList.head
						tail = otherList.tail
						size = otherList.size
	*/
	DoublyLinkedList(const DoublyLinkedList<Type>& otherList);

	///*
	//Copy Constructor (downcast)
	//Creates a deep copy of the parameter
	//Postcondition:
	//					head = otherList.head
	//					tail = otherList.tail
	//					size = otherList.size
	//*/
	//DoublyLinkedList(const StackDoublyLinkedList<Type>& otherList);

	/*
	Destructor
	Postcondition:
						head = nullptr and deleted
						tail = nullptr and deleted
	*/
	~DoublyLinkedList();

	/*
	Overload the assignment operator 
	Postcondition:
						this = right
						creates deep copy
	*/
	const DoublyLinkedList<Type>& operator=(const DoublyLinkedList<Type>& right);



	// ADDS, DELETES, SETTERS AND GETTERS___________________________________________________

	/*
	Add the right object to the back of this object
	Postcondition:
						this.tail = right.tail
						adds the right to the back of this
						
						*creates deep copy of that portion of the list*
	*/
	void join(const DoublyLinkedList<Type>& right);

	/*
	Create a substring version of this
	Postcondition:
						return
								= new DLL w/ head = newHead and tail = new.tail
						
						*creates deep copy of that portion of the list*
	*/
	DoublyLinkedList<Type> subList(nodeType<Type>* newHead, nodeType<Type>* newTail) const;

	/*
	Add a node at the beginning of a doubly linked list
	@param d = data/node to add to front of doubly linked list
	Postcondition:
						- size += 1
						- head points to newNode
						- all necessary connections are made to keep
						  the integrity of the doubly linked list
					
	*/
	void addFront(Type d); 

	/*
	Removes a node from the beginning of a doubly linked list
	Precondition:
						- The list is nonempty
	Postcondition:
						- size -= 1
						- head points to the node after the deleted node
						- all necessary connections are made to keep
						  the integrity of the doubly linked list

	*/
	void popFront(); 

	/*
	Add a node at the end of a doubly linked list
	@param d = data/node to add to back of doubly linked list
	Postcondition:
						- size += 1
						- tail points to newNode
						- all necessary connections are made to keep
						  the integrity of the doubly linked list

	*/
	void addBack(Type d); 

	/*
	Removes a node from the end of a doubly linked list
	Precondition:
						- The list is nonempty
	Postcondition:
						- size -= 1
						- tail points to the node before the deleted node
						- all necessary connections are made to keep
						  the integrity of the doubly linked list

	*/
	void popBack(); 



	/*
	Add a node after the iter parameter in a doubly linked list
	@param d = data/node to add to doubly linked list
	Postcondition:
						- size += 1
						- all necessary connections are made to keep
						  the integrity of the doubly linked list

	*/
	void addNode(Type d, nodeType<Type>* iter);  

	/*
	Removes a node from somewhere in a doubly linked list
	@param d = data/node to remove from a doubly linked list
	Precondition:
						- The list is not empty
	Postcondition:
						- size -= 1
						- all necessary connections are made to keep
						  the integrity of the doubly linked list

	*/
	void deleteNode(Type d, nodeType<Type>* iter);  

	/*
	Find a node in the doubly linked list
	@param d = data/node to find in a doubly linked list
	Precondition:
						- the list is not empty 
	@ return 
				- a pointer to a node in a doubly linked list 
				- NULL otherwise

	*/
	nodeType<Type>* findNode(Type d);

	/*
	Find a node in the doubly linked list from the back
	@param d = data/node to find in a doubly linked list
	Precondition:
						- the list is not empty
	@ return
				- a pointer to a node in a doubly linked list
				- NULL otherwise

	*/
	nodeType<Type>* findNodeBack(Type d);

	/*
	Find a node in the doubly linked list from the nodeType param
	@param start = starting point of where to search (moving forwards)
	@param d = data to find in a doubly linked list
	Precondition:
						- the list is not empty
	@ return
				- a pointer to a node in a doubly linked list
				- NULL otherwise

	*/
	nodeType<Type>* findNext(nodeType<Type>* start, Type d);

	/*
	Returns the size of the doubly linked list
	@return		
				- size member variable
	*/
	int getSize() const;

	/*
	Returns the size of the doubly linked list
	w/out parentheses
	@return
				- size member variable - num of parentheses
	*/
	int getSizeNoP() const;

	/*
	Function to determine whether the list is empty.
	@return 
				- true if list is empty
				- false otherwise
	*/
	bool isEmptyList() const;

	/*
	Function to serialize a doubly linked list
	Postcondition: the list is outputted
	*/
	void displayList() const;

	/*
	Function to reset the list
	*/
	void intializeList();

	/*
	Function to return an iterator to the first element of the doubly linked list
	@return 
				- an iterator to the beginning of the doubly linked list
	*/
	DoublyLinkedListIterator<Type> begin();

	/*
	Function to return an iterator to the last element of the doubly linked list. 
	@return
				- an iterator to the end of the doubly linked list
	*/
	DoublyLinkedListIterator<Type> end();
	

protected:

	// function to copy the list 
	void copyList(const DoublyLinkedList<Type>& otherList);

	// function to destroy list as if starting from new object
	void destroyList();

	//pointer to the first node of a doubly linked list
	nodeType<Type>* head; 

	//pointer to the last node of a doubly linked list
	nodeType<Type>* tail;
	
	//size of a doubly linked list 
	int size;    
};  


#endif 



// IMPLEMENTATION _____________________________________________________________________

template<class Type>
DoublyLinkedList<Type>::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}


template<class Type>
void DoublyLinkedList<Type>::copyList(const DoublyLinkedList<Type>& otherList)
{
	nodeType<Type>*newNode, *current;

	// if this list is nonempty then make it empty
	if (head != nullptr || tail != nullptr)
		destroyList();

	if (otherList.head == nullptr || otherList.tail == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}

	else
	{
		// set current to point to the list to be copied
		current = otherList.head;

		// create new node
		newNode = new nodeType<Type>;
		
		// define newNode
		newNode->next = nullptr;
		newNode->prev = nullptr;

		// copy the first element in the linkedList
		head = newNode;										// create the node
		head->data = current->data;						// copy the data over
		tail = newNode;											// tail points to the last node (make last point to the first node)                           
		//size++;

		// update current
		current = current->next;

		// copy the remaining stack
		while (current != nullptr)
		{
			newNode = new nodeType<Type>;	
			
			newNode->data = current->data;	

			/*
		1. Connect newNode to the last node in the
		doubly linked list
		*/
			newNode->prev = end().current;

			/*
			2. Connect last node to the newNode
			*/
			end().current->next = newNode;

			/*
			3. set newNode's next to nullptr
			*/
			newNode->next = nullptr;

			/*
			4. set tail equal to newNode
			& increase size
			*/
			tail = newNode;
			//size++;

			//newNode->prev = tail; // tail->prev;
			//newNode->next = nullptr;
			//tail = newNode;

			// update current
			current = current->next;
		} // end while
	} // end else

	size = otherList.size;
} // end copyList


template<class Type>
void DoublyLinkedList<Type>::destroyList()
{
	nodeType<Type>* temp = nullptr;

	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	tail = nullptr;
	size = 0;

}


template<class Type>
DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList<Type>& otherList)
{
	head = nullptr;
	tail = nullptr;
	copyList(otherList);
}

template<class Type>
DoublyLinkedList<Type>::~DoublyLinkedList()
{
	destroyList();
}

template<class Type>
const DoublyLinkedList<Type>& DoublyLinkedList<Type>::operator=(const DoublyLinkedList<Type>& right)
{
	if (this != &right) // avoid the self-copy
		copyList(right);
		
	return *this;
}

template<class Type>
void DoublyLinkedList<Type>::join(const DoublyLinkedList<Type>& right) 
{	
	nodeType<Type>* current = right.head;

	while (current != nullptr)
	{
		addBack(current->data);
		current = current->next;
	}
	
}


template<class Type>
DoublyLinkedList<Type> DoublyLinkedList<Type>::subList(nodeType<Type>* newHead, nodeType<Type>* newTail) const
{
	DoublyLinkedList<Type> subList;
	nodeType<Type>* curr = newHead;

	while (curr != newTail->next)
	{
		subList.addBack(curr->data);
		curr = curr->next;
	}

	return subList;
}

template<class Type>
void DoublyLinkedList<Type>::addFront(Type d)
{
	// create the node to add to the list
	nodeType<Type> *newNode = new nodeType<Type>;
	newNode->data = d;


	// if the doubly linked list is empty 
	if (isEmptyList() == true)
	{
		// define newNode
		newNode->next = nullptr;
		newNode->prev = nullptr;

		// create first element of the doubly linked list
		head = newNode;
		tail = newNode;
		size++;
	}

	// doubly linked list is not empty
	else
	{
		/*
		insert newNode  & make all necessary 
		connections so it remains a doubly linked list
		*/
		DoublyLinkedListIterator<Type> tempIter = begin();
		newNode->prev = nullptr;
		newNode->next = tempIter.current;
		tempIter.current->prev = newNode;
		head = newNode;
		size++;
	}
}


template<class Type>
void DoublyLinkedList<Type>::popFront()
{
	// if the doubly linked list is empty
	if (isEmptyList() == true)
		return;

	// not empty
	else if (size > 1)
	{
		// node that will be deleted and the node directly before it
		nodeType<Type> *deletedNode = begin().current;
		nodeType<Type> *trailDeletedNode = (++begin()).current;

		/*
		1. set second node prev = nullptr so that it 
		no longer points to the node that will be 
		deleted
		*/
		(++begin()).current->prev = nullptr;

		/*
		2. set first node's next to nullptr
		*/
		deletedNode->next = nullptr;

		/*
		3. connect head to second node
		(which will become first node)
		*/
		head = trailDeletedNode;

		/*
		4. delete the previous first node
		& decrease size of doubly linked list
		*/
		delete deletedNode;
		size--;
	}

	else if (size == 1)
	{
		destroyList();
	}
}


template<class Type>
void DoublyLinkedList<Type>::addBack(Type d)
{
	// create node to add to back of the doubly linked list
	nodeType<Type>* newNode = new nodeType<Type>;
	newNode->data = d;


	// if doubly linked list is empty
	if (isEmptyList() == true)
	{
		head = newNode;
		tail = newNode;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		size++;
	}

	// not empty
	else
	{
		/*
		1. Connect newNode to the last node in the
		doubly linked list
		*/
		newNode->prev = end().current;

		/*
		2. Connect last node to the newNode 
		*/
		end().current->next = newNode;

		/*
		3. set newNode's next to nullptr
		*/
		newNode->next = nullptr;

		/*
		4. set tail equal to newNode
		& increase size
		*/
		tail = newNode;
		size++;

	}
}


template<class Type>
void DoublyLinkedList<Type>::popBack()
{
	// if list is empty
	if (isEmptyList() == true)
		return;

	// list is not empty
	else if (size > 1)
	{
		/*
		pointers to keep track of node that will be
		deleted and the node directly before it 
		*/
		nodeType<Type>* deletedNode = end().current;
		nodeType<Type>* trailDeletedNode = (--end()).current;

		/*
		1. set second to last node next = nullptr so that it
		no longer points to the node that will be deleted
		*/
		trailDeletedNode->next = nullptr;

		/*
		2. set last node's prev to nullptr
		*/
		deletedNode->prev = nullptr;

		/*
		3. connect tail to second to last node
		(which will become last node)
		*/
		tail = trailDeletedNode;

		/*
		4. delete the previous last node
		& decrease size of doubly linked list
		*/
		delete deletedNode;
		size--;
	}

	else if (size == 1)
	{
	destroyList();
	}
}


// ADD THE ADDNODE AND DELETENODE FUNCTIONS HERE

template<class Type>
void DoublyLinkedList<Type>::addNode(Type d, nodeType<Type>* iter)
{
	// if list is empty add the node to the list
	if (isEmptyList() == true)
	{
		addBack(d);
		return;
	}

	// start from front 
	nodeType<Type>* current = head, *newNode = nullptr, *ahead = current->next;

	// stop when you reach the iterator
	while (current != iter)
	{
		current = current->next;
		ahead = current->next;
	}

	// if adding after the last element
	if (current == end().current && ahead == nullptr)
	{
		addBack(d);
		return;
	}

	// create new node
	newNode = new nodeType<Type>;
	newNode->data = d;

	// add to the middle of the DLL

	// make connections for new node
	newNode->next = ahead;
	newNode->prev = current;

	// make connections for ahead
	ahead->prev = newNode;

	// make connections for current node (node before newNode)
	current->next = newNode;

}

template<class Type>
void DoublyLinkedList<Type>::deleteNode(Type d, nodeType<Type>* iter)
{
	// if list is empty
	if (isEmptyList() == true)
		return;

	/*
		pointers to keep track of node that will be
		deleted and the node directly before it
		*/
	nodeType<Type>* current = iter;
	nodeType<Type>* trailCurrent = iter->prev;

	if (head->data == d)
	{
		current = head;
		head = head->next;

		if (head != nullptr)
			head->prev = nullptr;
		else
			tail = nullptr;

		delete current;
		size--;
	}
	// list is not empty
	else if (size > 1) // add if size > 1
	{

		bool found = false;
	
		current = head;

		while (current != nullptr && !found) //search the list 
			if (current->data >= d) 
				found = true; 
			else
				current = current->next;
			
		if (current == nullptr)
			cout << "The item to be deleted is not in the list." << endl;

		else if (current->data == d) //check for equality 
		{
			trailCurrent = current->prev;
			trailCurrent->next = current->next;
			if (current->next != nullptr)
				current->next->prev = trailCurrent;

			if (current == tail)
				tail = trailCurrent;

			delete current;
			size--;
		}

		else
			cout << "The item to be deleted is not in the list." << endl;
		
	} // end else

	else if (size == 1)
	{
		destroyList();
	}
}

//template<class T>
// T DoublyLinkedList<T>::popNode(T d, nodeType<T>* iter)
//{
//	 // if list is empty
//	 if (isEmptyList() == true)
//		 return;
//
//	 // list is not empty
//	 else if
//	 {
//		 /*
//		 pointers to keep track of node that will be
//		 deleted and the node directly before it
//		 */
//		 nodeType<T>* current = iter;
//		 nodeType<T>* trailCurrent = iter->prev;
//		 bool found = false;
//
//		 current = head;
//
//		 while (current != nullptr && !found) //search the list 
//			 if (current->data >= d)
//				 found = true;
//			 else
//				 current = current->next;
//
//		 if (current == nullptr)
//			 cout << "The item to be deleted is not in the list." << endl;
//
//		 else if (current->data == d) //check for equality 
//		 {
//			 trailCurrent = current->prev;
//			 trailCurrent->next = current->next;
//			 if (current->next != nullptr)
//				 current->next->prev = trailCurrent;
//
//			 if (current == tail)
//				 tail = trailCurrent;
//
//			 int data = current.data;
//			 delete current;
//			 size--;
//
//			 return data;
//		 }
//
//		 else
//			 cout << "The item to be deleted is not in the list." << endl;
//
//		 return -1; // something is wrong
//	 } // end else
//}

template<class Type>
nodeType<Type>* DoublyLinkedList<Type>::findNode(Type d)
{
	DoublyLinkedListIterator<Type> traverser = begin();

	while (traverser.current != nullptr)
	{
		if (traverser.current->data == d)
			return traverser.current; // or return index if I overload the [] operator

		++traverser;
	}

	return nullptr;
}

template<class Type>
nodeType<Type>* DoublyLinkedList<Type>::findNodeBack(Type d)
{
	DoublyLinkedListIterator<Type> traverser = end();

	while (traverser.current != nullptr)
	{
		if (traverser.current->data == d)
			return traverser.current; // or return index if I overload the [] operator

		--traverser;
	}

	return nullptr;
}

template<class Type>
nodeType<Type>* DoublyLinkedList<Type>::findNext(nodeType<Type>* start, Type d)
{
	nodeType<Type>* traverser = start;

	while (traverser != nullptr)
	{
		if (traverser->data == d)
			return traverser; 

		traverser = traverser->next;
	}

	return nullptr;
	return NULL;
}

template<class Type>
int DoublyLinkedList<Type>::getSize() const
{
	return size;
}

template<class Type>
int DoublyLinkedList<Type>::getSizeNoP() const
{
	int count = 0;
	DoublyLinkedListIterator<char> it;

	for (it = begin(); it < end(); ++it)
	{
		if (it.current->data == '('
			|| it.current->data == ')')
			count++;
	}

	return size - count;
}

template<class Type>
bool DoublyLinkedList<Type>::isEmptyList() const
	{
		return(head == nullptr);
	}


template<class Type>
void DoublyLinkedList<Type>::displayList() const
{
	string serializedDLL = "";
	DoublyLinkedListIterator<Type> temp(head);
	
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			serializedDLL += temp.current->data;

		else 
			serializedDLL.push_back(temp.current->data);

		temp = temp.current->next;
	}

	cout << "\n" << serializedDLL;


}

template<class Type>
void DoublyLinkedList<Type>::intializeList()
{
	destroyList();
}

template<class Type>
DoublyLinkedListIterator<Type> DoublyLinkedList<Type>::begin()
{
	DoublyLinkedListIterator<Type> temp(head);

	return temp;
}

template<class Type>
DoublyLinkedListIterator<Type> DoublyLinkedList<Type>::end()
{
	DoublyLinkedListIterator<Type> temp(tail);

	return temp;
}
