#ifndef NODE_H
#define NODE_H

class Node {
private:
	int data;
	Node * next;
public:
	Node();
	int getData();
	void setData(int d);
	Node * getNext();
	void setNext(Node * n);
};

#endif