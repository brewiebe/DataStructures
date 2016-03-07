//COSC 222
//Breanne Wiebe
//300219945

#include <iostream>
#include <iomanip>

using namespace std;

struct Node{
	char digit; 
	Node *next;

	Node(){
		next = NULL;
	}
};

class LinkedList {

	public:
		Node *head;
		Node *tail;
		int count;

	LinkedList() {
		count = 0;
		head = NULL;
		tail = NULL;
	}

	void addItemFront(char& d) {
		Node *newNode = new Node();
		newNode -> digit = d;

		newNode -> next = head;
		head = newNode;
		
		count++;
	}

	void addItemBack(char& d) {
		Node *current;
		current = head;
		Node *newNode = new Node();
		newNode -> digit = d;

		if (head == NULL) {
			head = newNode;
			count++;
			return;
		}

		while (current -> next != NULL) {
			current = current -> next;
		}

		current -> next = newNode; 
		count++;
	}

	string popItemsBack() {
		Node *current;
		current = head;
		string s;

		if (head == NULL) {
			s = "List is empty!";
			return s;
		}
		
		while (current != NULL)	{
			s += current -> digit;
			current = current -> next;
		}

		return s;
	}

	char popTop() {
		char d;

		if (count == 0) {
			d = '0';
			return d;
		}

		d = head -> digit;
		head = head -> next;
		count--; 
		return d;
	}
	
	void deleteList() {
		Node * temp;

		while (head != NULL) {
			temp = head;
			head = head -> next;
			delete temp;
		}

		head = NULL;
		count = 0;
	}



};
