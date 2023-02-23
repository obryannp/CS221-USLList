//file name: Node.cpp
//purpose: create a class that instantiates a node object for USLList.cpp
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#include "Node.h"
#include <iostream>
using namespace std;

//default constructor
Node::Node()
{
	item = NULL;             
	next = NULL;
}

//destructor
Node::~Node()
{
	delete item;
	item = NULL;
	next = NULL;
	cout << "Thank you for using this program (Node)!\n";
}

//constructor that takes pointer arguement for a new item of type ItemType             //had to create two constructors for USLList.cpp to work, see line 32 in USLList.cpp
Node::Node(ItemType* newItem)                                                  //first constructor takes ItemType pointer arguement, second constructor takes ItemType value to satisfy program requirements
{
	item = newItem;
}

//constructor that takes ItemType arguement passes it by reference
Node::Node(ItemType &newItem)
{
	item = &newItem;
}

//sets the pointer location of the next item
void Node::SetNext(Node* location)
{
	next = location;
}

//returns the data that is at the address of item
ItemType Node::GetItem()
{
	return *item;
}

//returns the next pointer
Node* Node::Next()
{
	return next;
}
