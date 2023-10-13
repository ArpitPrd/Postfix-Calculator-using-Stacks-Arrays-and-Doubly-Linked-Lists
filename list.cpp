#include <iostream>
#include "node.h"
#include "list.h"
using namespace std;

	List::List(){
		try {
			sentinel_head = new Node(true);
			sentinel_tail = new Node(true);
			sentinel_head->next = sentinel_tail;
			sentinel_tail->prev = sentinel_head;
		}
		catch (runtime_error e){
			throw runtime_error("Out of Memory");
		}
	}

	void List::insert(int v){
		try {
			Node *n = new Node(v, sentinel_tail, sentinel_tail->prev);
			sentinel_tail->prev->next = n;
			sentinel_tail->prev = n;
		}
		catch (runtime_error e){
			throw runtime_error("Stack Full");
		}
	}

	int List::delete_tail(){
		Node* n;
		n = sentinel_tail->prev;
		if ( n->prev != NULL){
			/*
			int b = sentinel_tail->prev->value;
			sentinel_tail->prev = sentinel_tail->prev->prev;
			sentinel_tail->prev->prev->next = sentinel_tail;
			delete sentinel_tail->prev;
			return b;
			*/
			int b = n->get_value();
			n->prev->next = sentinel_tail;
			sentinel_tail->prev = n->prev;
			delete n;
			return b;
		}
		else {
	
			throw runtime_error ("Empty Stack");
		}
		
	}

	int List::get_size() {
		int count = 0;
		Node* n;
		n = sentinel_head;
		while ( n->next != NULL && n->next->next != NULL ){
			count += 1;
			n = n->next;
		}
		return count;
	}

	Node* List::get_head(){
		return sentinel_head;
	}

	List::~List(){
		int size = this->get_size();
		for (int i = 0; i < size; i++){
			this->delete_tail();
		}
		delete sentinel_head;
		delete sentinel_tail;
	}

/*
int main() {
	List l;
	try{
		for (int i = 0; i<20; i++){
			l.insert(i);	
		}
		l.print(true);
	}
	catch (runtime_error e){
		cout << e.what() << endl;
	}
	return 0;
}*/

