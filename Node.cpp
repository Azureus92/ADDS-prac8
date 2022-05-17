#include "Node.h"
#include <cstddef>
#include <limits>

using namespace std;

Node::Node() {
	data = numeric_limits<int>::max();
	next = nullptr;
};

int Node::getData() {
	return data;
};

void Node::setData(int d) {
	data = d;
};

Node * Node::getNext() {
	return next;
};

void Node::setNext(Node * n) {
	next = n;
};

