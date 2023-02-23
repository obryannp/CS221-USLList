//file name: ItemType.h
//purpose: Class definition and function prototypes for ItemType.cpp
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#pragma once
#include <iostream>
using namespace std;

enum Comparison {LESS, GREATER, EQUAL};

class ItemType
{
private:

	int data = 1;

public:

	ItemType();
	ItemType(int userNum);
	~ItemType();

	Comparison Compare(int compareInt);

	int GetData();
	void SetData(int userData);
};
