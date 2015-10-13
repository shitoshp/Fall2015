
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	int data;
	Node* link;
};

void Remove_stuff(Node* head);
void reverse_list(Node* head);
void print_list(Node* head);




int main() {

	int num;

	Node* n = new Node();
	n->link = NULL;
	
	Node* temp = n; 
	Node* head1 = temp; 
	Node* previous = temp; 
	ifstream instream;
	instream.open("integers.txt");

	bool headnode = true;
	while (instream >> num) {

		if (headnode) {
			head1->data = num;
			headnode = false;
			continue;
		}

		if ((num < previous->data) && (num > head1->data)) {
			temp = head1;
			previous = head1;
		}

		while ((num > temp->data) && (temp->link != NULL)) {
			previous = temp;
			temp = temp->link;
		}

		if (num <= head1->data) {
			n = new Node();
			n->data = num;
			n->link = head1;
			head1 = n;
		}

		else if ((temp->link == NULL) && (num >= temp->data)) {

			n = new Node();
			n->data = num;
			n->link = NULL;
			previous = temp;
			temp->link = n;
			temp = n;
		}

		else if ((num >= previous->data) && (num <= temp->data)) {
			n = new Node();
			n->data = num;
			n->link = temp;
			previous->link = n;
			previous = n;
		}
	}
	instream.close();

	cout << "Ascending order: ";
	print_list(head1);
	Remove_stuff(head1);
	reverse_list(head1);
	int a;
	cin >> a;
}


void Remove_stuff(Node* head) {
	Node* cur = head;
	Node* prev = head;

	while (cur->link != NULL) {
		cur = cur->link;
		if (cur->data == prev->data) {
			prev->link = cur->link;
			//free (cur);

		}
		else {
			prev = prev->link;
		}
	}
	cout << "Removing duplicates: ";
	print_list(head);
}


void reverse_list(Node* head) {
	Node* current = head;
	Node* prev = NULL;
	Node* next;

	while (current->link != NULL) {
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	current->link = prev;
	prev = current;
	head = prev;
	cout << "Descending order: ";
	print_list(head);
}



void print_list(Node* head) {
	Node* temp = head;
	cout << head->data << " ";
	while (temp->link != NULL) {

		temp = temp->link;
		cout << temp->data << " ";

	}
	cout << endl << endl;
}
