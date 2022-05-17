#include "LinkedList.h"
#include "Node.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<string> input;
	int i = 0;
	string temp_input, temp = "";

	getline(cin, temp_input);
	while (temp_input[i] != '\0') {
		if (temp_input[i] == ' ') {
			input.push_back(temp);
			
			temp = "";
		} else {
			temp = temp + temp_input[i];
		}
		i++;
	}

	input.push_back(temp);

	i = input.size();

	int nums[i-3];
	for (int j = 0; j < i - 3; j++) {
		nums[j] = stoi(input[j]);
	}

	string comm = input[i-3];
	int p1 = stoi(input[i - 2]), p2 = stoi(input[i - 1]);

	LinkedList * l1 = new LinkedList(nums, i-3);
	
	if (comm == "AF") {
		l1->addFront(p1);
	} else if (comm == "AE") {
		l1->addEnd(p1);
	} else if (comm == "AP") {
		l1->addAtPosition(p1, p2);
	} else if (comm == "S") {
		l1->search(p1);
	} else if (comm == "DF") {
		l1->deleteFront();
	} else if (comm == "DE") {
		l1->deleteEnd();
	} else if (comm == "DP") {
		l1->deletePosition(p1);
	} else if (comm == "GI") {
		l1->getItem(p1);
	} 

	l1->printItems();
	cout << endl;

	delete l1;
}