//file name: USLList.cpp
//purpose: create a class that contains all functions needed for an unsorted linked list
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#include "Node.h"
#include "USLList.h"
#include <iostream>
using namespace std;

//default constructor
USLList::USLList()
{
	head = NULL;
	curPos = NULL;
}

//destructor
USLList::~USLList()
{
	if (head != NULL)
	{
		MakeEmpty();
	}
	head = NULL;
	curPos = NULL;
}

//function to add an item to the front of the list
bool USLList::PutItem(ItemType* userItem)
{
	//checks if item is in the list
	bool found;
	if(GetItem(userItem, found) == NULL)
	{
		//allocates a new Node object to heap
		Node* newNode = new Node(userItem);

		//if item is not the first item in list
		if (newNode != NULL && head != NULL)
		{
			newNode->SetNext(head);
			head = newNode;
			curPos = head;

			//output to user
			cout << "Added: " << head->GetItem().GetData() << "\t" << head << "\n";
			return true;
		}

		//if item is the first item in list
		else if (newNode != NULL && head == NULL)
		{
			head = newNode;
			curPos = head;
			newNode->SetNext(NULL);

			//output to user
			cout << "Added: " << head->GetItem().GetData() << "\t" << head << "\n";
			return true;
		}

		//if newNode == NULL
		else
		{
			cout << "Something went wrong, please try again.\n\n";

			return false;
		}
	}

	//if item is already in list
	else
	{
		cout << "That item is already in the list. Try again with a different item.\n\n";

		return false;
	}
}

//function to find a specific item in the list
ItemType* USLList::GetItem(ItemType* userItem, bool& found)
{
	//resets curPos
	curPos = head;

	//while loop to iterate the list
	while (curPos != NULL)
	{
		cout << "Searching... ";

		//if userItem and an item in the list match
		if (curPos->GetItem().Compare(userItem->GetData()) == EQUAL)
		{
			found = true;
			cout << "Item was found, bool = " << found << "\n\n";
			return userItem;
		}

		//iterator for curPos when items do not match
		else
		{
			cout << curPos->GetItem().GetData() << "     ";
			curPos = curPos->Next();
		}
	}

	//if there is no match in the list for userItem
	found = false;
	cout << "Item was not found, bool = " << found << "\n\n";
	return NULL;
}

//function to delete an item from the list
bool USLList::DeleteItem(ItemType* userItem)
{

	//instantiating all variables needed
	curPos = head;
	Node* previousPtr = NULL;
	Node* nextPtr = NULL;
	Node* toDeletePtr = NULL;

	cout << "DeleteItem(): \n";

	//iterates through list
	while (curPos != NULL)
	{

		if (curPos->GetItem().Compare(userItem->GetData()) == EQUAL)
		{
			//if item to be deleted equals head
			if (curPos == head)
			{
				toDeletePtr = curPos;
				nextPtr = toDeletePtr->Next();
				head = nextPtr;

				//output
				cout << "Deleted: " << userItem->GetData() << "   " << userItem << "\n";

				//cleanup
				delete toDeletePtr;
				toDeletePtr = NULL;
			}

			//if item to be deleted equals tail
			else if (curPos->Next() == NULL)
			{
				toDeletePtr = curPos;
				previousPtr->SetNext(NULL);

				//output
				cout << "Deleted: " << userItem->GetData() << "   " << userItem << "\n";

				//cleanup
				delete toDeletePtr;
				toDeletePtr = NULL;
			}

			//if item to be deleted is in middle of list
			else
			{
				toDeletePtr = curPos;
				nextPtr = toDeletePtr->Next();
				previousPtr->SetNext(nextPtr);

				//output
				cout << "Deleted: " << userItem->GetData() << "   " << userItem << "\n";

				//cleanup
				delete toDeletePtr;
				toDeletePtr = NULL;

			}

			//since item is deleted, returns true        (tried to add delete statements, but it was deleting data out of the list.)
			return true;
		}

		//iterator for curPos and previousPtr when items do not match, this preserves the previous pointer
		else
		{
			previousPtr = curPos;
			curPos = curPos->Next();
		}
	}
	//since item was not deleted, returns false           (tried to add delete statements, but it was deleting data out of the list.)
	cout << "Item was not found.";
	return false;
}

//function that sets curPos to head
void USLList::ResetList()
{
	curPos = head;
}

//function that empties the list and deallocates the memory
void USLList::MakeEmpty()
{
	curPos = head;
	Node* nextPtr = NULL;
	Node* toDeletePtr = NULL;

	//iterates the list
	while (curPos != NULL)
	{
		toDeletePtr = curPos;
		nextPtr = toDeletePtr->Next();

		//iterate curPos
		curPos = nextPtr;

		//cleanup
		delete toDeletePtr;
		toDeletePtr = NULL;
	}

	cout << "End of list reached, list is empty.\n";
	head = NULL;
	curPos = NULL;
}

//function that prints the list to console
void USLList::PrintList()
{
	//resets list and prints list from beginning
	cout << "\nPrintList():\n";
	curPos = head;
	
	//iterates list and prints each node's data and address
	while (curPos != NULL)
	{
		cout << curPos->GetItem().GetData() << " - " << curPos << "\n";
		curPos = curPos->Next();
	}

	curPos = head;
}

//function that increments the curPos pointer and returns it
Node* USLList::GetNext()
{
	//sets curPos pointer to the next pointer and returns the curPos pointer
	if (curPos != NULL)
	{
		curPos = curPos->Next();
		return curPos;
	}

	//check for curPos NULL pointer
	else
	{
		return NULL;
	}
}

//function that returns the length of the list
int USLList::GetLength()
{
	//reset curPos and instantiate length
	curPos = head;
	int length = 0;

	//iterates the list
	while (curPos != NULL) 
	{
		curPos = curPos->Next();
		length++;
	}

	//tells list length to user
	cout << "List is " << length << " items long.\n\n";
	return length;
}