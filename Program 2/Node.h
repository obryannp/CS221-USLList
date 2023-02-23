//file name: Node.h
//purpose: Class definition and function prototypes for Node.cpp
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#pragma once
#include "ItemType.h"
#include <iostream>
using namespace std;

class Node
{
private:

	ItemType* item = NULL;
	Node* next = NULL;

public:

	Node();
	Node(ItemType* newItem);
	Node(ItemType &newItem);    //check line 28 of Node.cpp for explanation
	~Node();

	void SetNext(Node* location);
	ItemType GetItem();
	Node* Next();
};
