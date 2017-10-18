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