#pragma once
#include <iostream>

template <typename Type> class QueueList
{
private:
	// Node struct
	struct Node
	{
		Type data;
		Node* next;
	};

	// Head node
	Node* head;
	// iter node used for traversal
	Node* iter;
public:
	// Ctor
	QueueList();

	// Dtor
	~QueueList();

	// Assignment Operator
	QueueList<Type>& operator=(const QueueList<Type>& that);

	// Copy Constructor
	QueueList(const QueueList<Type>& that);

	// Adding a new head or entry to the line
	void Enqueue(Type _data);

	// Removing the head from the line & returning the value
	Type Dequeue();

	// Print out whole list
	void DisplayAll();

	// Clear out whole list
	void ClearAll();
};

template <typename Type>
QueueList<Type>::QueueList()
{
	head = nullptr;
	iter = nullptr;
}

template <typename Type>
QueueList<Type>::~QueueList()
{
	// going through the list and deleting the nodes
	while (head != nullptr)
	{
		iter = head;
		head = head->next;
		delete iter;
	}
}

// Assignment Operator
template <typename Type>
QueueList<Type>& QueueList<Type>::operator=(const QueueList<Type>& that)
{
	// error check
	if (this == &that || that.head == nullptr)
		return *this;

	// We first clear out list
	ClearAll();
	// We start copying from their head
	iter = that.head;
	Node* headReference = new Node();
	headReference->data = iter->data;
	head = headReference;

	// Now we loop through the whole list and add it to our list
	while (iter->next != nullptr)
	{
		// moving out iter down the list
		iter = iter->next;
		// Making the new node a copy of the one from the iter
		Node* newNode = new Node();
		newNode->data = iter->data;
		// Making sure our new list is being linked to the nodes being created
		headReference->next = newNode;
		headReference = headReference->next;
	}

	// making sure the last node is pointing to null
	headReference->next = nullptr;
}

// Copy ctor
template <typename Type>
QueueList<Type>::QueueList(const QueueList<Type>& that)
{
	// We start copying from their head
	iter = that.head;
	Node* headReference = new Node();
	headReference->data = iter->data;
	head = headReference;

	// Now we loop through the whole list and add it to our list
	while (iter->next != nullptr)
	{
		// moving out iter down the list
		iter = iter->next;
		// Making the new node a copy of the one from the iter
		Node* newNode = new Node();
		newNode->data = iter->data;
		// Making sure our new list is being linked to the nodes being created
		headReference->next = newNode;
		headReference = headReference->next;
	}

	// making sure the last node is pointing to null
	headReference->next = nullptr;
}

template <typename Type>
void QueueList<Type>::Enqueue(Type _data)
{
	// adding a new entry to the end of the line
	Node* temp = new Node();
	temp->data = _data;

	// basically if the list is empty
	if (head == nullptr)
	{
		temp->next = nullptr;
		head = temp;
		return;
	}

	// else, we go through the list until we reach the end
	iter = head;
	while (iter->next != nullptr)
		iter = iter->next;

	// When we're done, it means we're on the last node on the list
	iter->next = temp;
	temp->next = nullptr;
	// all we did here was make the new node be the end node by having the previous last node point to the
	// new node, and have the new node's next be null
}

// Removing the head from the line, and returning the data inside
template <typename Type>
Type QueueList<Type>::Dequeue()
{
	// Value being returned
	Type _return;

	// Making sure we're not working with an empty list
	if (head == nullptr)
		return -1;

	// Moving the head node to the next one
	iter = head->next;
	// Saving the data from the node being removed
	_return = head->data;
	// removing the node from the list
	delete head;
	// setting the new head
	head = iter;

	// finally, returning the node
	return _return;
}

// Prints out the data in the whole list from the head down
template <typename Type>
void QueueList<Type>::DisplayAll()
{
	iter = head;
	while (iter != nullptr)
	{
		std::cout << iter->data << " ";
		iter = iter->next;
	}

	std::cout << std::endl << std::endl;
}

// Clear out whole list
template <typename Type>
void QueueList<Type>::ClearAll()
{
	// leave if list is empty
	if (head == nullptr)
		return;

	// going through the list and deleting the nodes
	while (head != nullptr)
	{
		iter = head;
		head = head->next;
		delete iter;
	}

	// setting our head to null
	head = nullptr;
}