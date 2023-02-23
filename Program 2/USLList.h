//file name: USLList.h
//purpose: Class definition and function prototypes for USLList.cpp
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class USLList
{
private:

	Node* head = NULL;
	Node* curPos = NULL;

public:

	USLList();
	~USLList();

	bool PutItem(ItemType* item);
	ItemType* GetItem(ItemType* item, bool &found);
	bool DeleteItem(ItemType* item);
	void ResetList();
	void MakeEmpty();
	void PrintList();
	Node* GetNext();
	int GetLength();
};
