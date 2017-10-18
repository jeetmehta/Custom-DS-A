#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedList {
	
	private:
		Node* head;
		int size;
	
	public:

		// constructor
		LinkedList();

		// inserts
		void insertNodeAtHead(int data);
		void insertNodeAtEnd(int data);
		void insertNodeAtPos(int data, int pos);

		// deletes
		void deleteNodeAtHead();
		void deleteNodeAtEnd();
		void deleteNodeAtPos(int pos);

		// search & access
		Node* getNodeAtPos(int pos);
		int getPosForNode(Node* node);
		bool nodeInList(Node* node);

		// Range checks & print
		bool isEmpty();
		void printLinkedList();
}

// constructor
LinkedList::LinkedList()
{
	head = 0;
	size = 0;
}

// inserts
void LinkedList::insertNodeAtHead(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = 0;

	if (head == 0)
	{
		head = newNode;
		size++;
	}
	else
	{
		Node* temp = head;
		head = newNode;
		head->next = temp;
		size++;
	}
}

void LinkedList::insertNodeAtEnd(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = 0;

	if (head == 0)
	{
		head = newNode;
		size++;
	}
	else
	{
		Node* temp = head;
		while (temp->next != 0)
			temp = temp->next;

		temp->next = newNode;
		size++;
	}
}

void LinkedList::insertNodeAtPos(int data, int pos)
{
	if (pos < 0 || pos >= size)
		return;
	else if (pos == 0)
	{
		insertNodeAtHead(data);
		return;
	}
	else if (pos == size - 1)
	{
		insertNodeAtEnd(data);
		return;
	}
	else
	{
		Node* temp = head;
		Node* behindTemp = temp;
		int current_pos = 0;

		while (current_pos != pos)
		{
			behindTemp = temp;
			temp = temp->next;
			current_pos++;
		}

		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = temp;
		behindTemp->next = newNode;
		size++;
	}
}

// deletes
void LinkedList::deleteNodeAtHead()
{
	if (size == 0)
		return;

	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
	return;
}

void LinkedList::deleteNodeAtEnd()
{
	if (size == 0)
		return;
	else if (size == 1)
	{
		deleteNodeAtHead();
		return;
	}
	else
	{
		Node* temp = head;
		Node* behindTemp = temp;
		while (temp->next != 0)
		{
			behindTemp = temp;
			temp = temp->next;
		}

		behindTemp = temp->next;
		delete temp;
		size--;
	}
}

void LinkedList::deleteNodeAtPos(int pos)
{
	if (pos < 0 || pos >= size)
		return;
	else if (pos == 0)
	{
		deleteNodeAtEnd();
		return;
	}
	else if (pos == size-1)
	{
		deleteNodeAtEnd();
		return;
	}
	else
	{
		Node* temp = head;
		Node* behindTemp = temp;
		int current_pos = 0;

		while (current_pos != pos)
		{
			behindTemp = temp;
			temp = temp->next;
			current_pos++;
		}

		behindTemp->next = temp->next;
		delete temp;
	}
}

// search & access
Node* LinkedList::getNodeAtPos(int pos)
{
	if (pos < 0 || pos >= size)
		return 0;

	Node* temp = head;
	int current_pos = 0;
	while(current_pos != pos)
	{
		temp = temp->next;
		current_pos++;
	}
	return temp;
}

int LinkedList::getPosForNode(Node* node)
{
	if (node==0)
		return -1;
	else if (head == node)
		return 0;
	
	Node* temp = head;
	int current_pos = 0;
	while (temp != node || temp != 0)
	{
		temp = temp->next;
		current_pos++;
	}

	if (temp)
		return current_pos;

	return -1;
}

bool LinkedList::nodeInList(Node* node)
{
	if (node == head)
		return true;

	Node* temp = head;
	while (temp != node || temp != 0)
		temp = temp->next;

	if (temp)
		return true;

	return false;
}

// Range checks & print
bool LinkedList::isEmpty()
{
	return (size == 0) ? true : false
}

void LinkedList::printLinkedList()
{
	if (head == 0)
		return;

	Node* temp = head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}