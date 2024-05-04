#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode()
{
    Node* newNode = new Node ();   // step 1 : create a new node
    cout << "/nEnter the roll number of the student : ";
    cin >> newNode -> noMhs;   // assign value to the data field of the new node
    cout << "/nEnter the name of the student : ";
    cin >> newNode -> name;   // assign value to the ddata field of the new node

    // Insert the new node in the list
    if (START != NULL || newNode -> noMhs <= START -> noMhs)
    {
        if (START != NULL && newNode -> noMhs == START -> noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed \033[0m" << endl;
            return;
        }
        // If the list is empty, make the new node the START
        newNode -> next = START;   // step 3 : make the first node point to the new node
        if (START != NULL)
        {
            START -> prev = newNode;   // step 4 : make the first node point to the new node
        } 
        newNode -> prev = NULL;   // step 5 : make the new node point to NULL
        START = newNode;   // step 6 : make the new node the first node
    }

    else
    {
		Node* current = START;
		Node* previous = NULL;

		while (current != NULL && current->noMhs < newNode->noMhs)
		{
			previous = current;
			current = current->next;
		}
		newNode->next = current;
		newNode->prev = previous;

		if (current != NULL)
		{
			current->prev = newNode;
		}

		if (previous != NULL)
		{
			previous->next = newNode;
		}
		else
		{
			START = newNode;
		}
	}
}

bool search(int rollNo, Node** previous, Node** current)
{
	*previous = NULL;
	*current = START;
	while (*current != NULL && (*current)->noMhs != rollNo)
	{
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}
