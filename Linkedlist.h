#pragma once
#include <iostream>

using namespace std;

template <class T>
//create a template class T to broad the data type for the data element of the node
class Linkedlist
{
public:
	struct Node {
		T data;  //define data element with data type T
		Node* next; //define the next as a Node reference/pointer


		//Default construct for Node
		Node() {
			data = NULL;
			next = nullptr;
		}

		//Explicit contruct for Node
		Node(T initData, Node* initNext) {
			data = initData;
			next = initNext;
		}

	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int ListSize = 0; //how many nodes in the linkedlist

	void addFirst(T key) {
		//Create a new node by declare the data (key) and the next reference (head)
		Node* tmp = new Node(key, head);
		head = tmp;
		ListSize++;
	}

	int insertAfter(T key, T toInsert) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->data != key) {
			tmp = tmp->next;
		}
		if (tmp != nullptr) {
			//locate the key, tmp is currently referencing the key node
			tmp->next = new Node(toInsert, tmp->next);
			ListSize++;
			return 0;
		}
		else {
			//can not find the key in the linkedlist
			return -1;
		}

	}
	//the printList function to print out the node values from the first node to the last node
	void printList() {
		Node* tmp = head;
		while (tmp != nullptr) {
			cout << tmp->data << "->";
			tmp = tmp->next;
		}
	}

	int insertBefore(T key, T toInsert) {
		if (head == nullptr) {
			cout << "The linkedlist is empty." << endl;
			return -1;
		}
		if (head->data == key) {
			addFirst(toInsert);
			return 0;
		}
		Node* prev = nullptr;
		Node* cur = head;
		while (cur != nullptr && cur->data != key) {
			prev = cur;
			cur = cur->next;
		}
		if (cur != nullptr) {
			//cur is point at the key node, ready to insert
			prev->next = new Node(toInsert, cur);
			ListSize++;
			return 0;
		}
		else {
			//cur is point at null, the key not exist in the linkedlist
			cout << "The key is not exist in the linkedlist." << endl;
			return -1;
		}
	}

	int Remove(T key) {
		if (head == nullptr) {
			cout << "This is an empty linkedlist." << endl;
			return -1;
		}
		if (head->data == key) {
			head = head->next;
			ListSize--;
			return 0;
		}
		Node* prev = nullptr;
		Node* cur = head;
		while (cur != nullptr && cur->data != key) {
			prev = cur;
			cur = cur->next;
		}
		if (cur != nullptr) {
			//cur is point at the key node
			prev->next = cur->next;
			ListSize--;
			return 0;
		}
		else {
			cout << "The key is exist in the linkedlist" << endl;
			return -1;
		}
	}

	void addLast(T key) {
		if (head == nullptr) {
			addFirst(key);
		}
		else {
			Node* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node(key, nullptr);
			ListSize++;
		}
	}

	Linkedlist copy() {
		Node* tmp = head;
		Linkedlist copyed_linkedlist;
		while (tmp != nullptr) {
			copyed_linkedlist.addLast(tmp->data);
			tmp = tmp->next;
		}
		return copyed_linkedlist;
	}
};

