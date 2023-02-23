//file name: ItemType.cpp
//purpose: create a class that instantiates an integer object for use in USLList.cpp
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#include "ItemType.h"
#include <iostream>
using namespace std;

//default constructor
ItemType::ItemType()
{
	data = 1;
}

//destructor
ItemType::~ItemType()
{
	//I chose not to put a cout statement because it was "spamming" the console with destructor messages
}

//constructor that allows parameter to be passed
ItemType::ItemType(int userNum)
{
	//checks if parameters are of valid type
	int compareInt = 1;
	if (typeid(userNum) == typeid(compareInt))
	{
		data = userNum;
	}

	else
	{
		cout << "Your input is of the wrong type. Please try again.\n";
	}
}

//comparison function that compares user input to actual data, returns comparison enum
Comparison ItemType::Compare(int compareInt)
{
	if (compareInt < data)
	{
		return LESS;
	}

	else if (compareInt > data)
	{
		return GREATER;
	}

	else
	{
		return EQUAL;
	}
}

int ItemType::GetData()
{
	return data;
}

void ItemType::SetData(int userData)
{
	//checks if parameters are of valid type
	int compareInt = 1;
	if (typeid(userData) == typeid(compareInt))
	{
		data = userData;
	}

	else
	{
		cout << "Your input is of the wrong type. Please try again.\n";
	}
}