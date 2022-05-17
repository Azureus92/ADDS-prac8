#include "LinkedList.h"
#include <limits>
#include <cstddef>
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
	head = new Node();
};

LinkedList::LinkedList(int arr[], int siz) {
	if (siz < 1) {
		return;
	}

	for (int i = 0; i < siz; i++) {
		Node * temp_node = new Node();
		temp_node->setData(arr[siz - 1 - i]);
		if (i > 0) {
			temp_node->setNext(head);
		}		
		head = temp_node;
	}

};

void LinkedList::addFront(int newItem) {
	Node * temp_node = new Node();
	temp_node->setData(newItem);
	temp_node->setNext(head);
	head = temp_node;
};

void LinkedList::addEnd(int newItem) {
	Node * temp_node = new Node();
	temp_node->setData(newItem);
	temp_node->setNext(nullptr);
	Node * pos = head->getNext();
	while (pos->getNext() != nullptr) {
		pos = pos->getNext();
	}
	pos->setNext(temp_node);
};

void LinkedList::addAtPosition(int position, int newItem) {
	Node * new_node = new Node();
	Node * pos_sav;
	new_node->setData(newItem);
	cout << "First check" << endl;
	if (position < 1) {
		new_node->setNext(head);
		head = new_node;
		return;
	}
	cout << "Second check " << position << " " << newItem << endl;
	Node * pos = head;
	for (int i = 0; i < position - 2; i++) {
		if (pos->getNext() == nullptr) {
			new_node->setNext(nullptr);
			pos->setNext(new_node);
			return;
		}
		pos = pos->getNext();
	}
	pos_sav = pos->getNext();
	pos->setNext(new_node);
	new_node->setNext(pos_sav);
}; 

int LinkedList::search(int item) {
	Node * pos = head;
	int i = 1, found = 0;
	while (pos->getNext() != nullptr) {
		if (pos->getData() == item) {
			found = 1;
			break;
		}
		pos = pos->getNext();
		i++;
	}
	if (found == 0) {
		i = 0;
	}
	cout << i << " ";
	return i;
};

void LinkedList::deleteFront() {
	Node * to_delete = head;
	head = head->getNext();
	delete to_delete;
};

void LinkedList::deleteEnd() {
	Node * pos = head;
	while (pos->getNext()->getNext() != nullptr) {
		pos = pos->getNext();
	}
	delete pos->getNext();
	pos->setNext(nullptr);
};

//KINDA BAD
void LinkedList::deletePosition(int position) {
	if (position < 1) {
		cout << "outside range" << endl;
		return;
	}
	Node * pos = head;
	for (int i = 0; i < position - 2; i++) {
		if (pos == nullptr) {
			cout << "outside range" << endl;
			return;
		}
		pos = pos->getNext();
	}
	Node * temp = pos->getNext();
	pos->setNext(temp->getNext());
	delete temp;
};

int LinkedList::getItem(int position) {
	if (position < 1) {
		cout << numeric_limits<int>::max() << " ";
		return numeric_limits<int>::max();
	}
	Node * pos = head;
	for (int i = 0; i < position - 1; i++) {
		if (pos == nullptr) {
			cout << numeric_limits<int>::max() << " ";
			return numeric_limits<int>::max();
		}
		pos = pos->getNext();
	}
	cout << pos->getData() << " ";
	return pos->getData();

};

void LinkedList::printItems() {
	if (head->getData() == numeric_limits<int>::max() && head->getNext() == nullptr) {
		return;
	}
	Node * pos = head;
	while (pos != nullptr) {
		cout << pos->getData() << " ";
		pos = pos->getNext();
	}
};

LinkedList::~LinkedList() {
	while (head->getNext() != nullptr) {
		this->deleteEnd();
	}
	delete head;
};