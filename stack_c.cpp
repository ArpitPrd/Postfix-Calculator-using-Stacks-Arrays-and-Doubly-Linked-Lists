#include <iostream>
#include "stack_c.h"
using namespace std;
int floor(int a, int b);
/*
int floor(int val1, int val2){
        float a = (float) val1;
        float b = (float) val2;
        float c = b / a;
        int d = (int) c;
        int k = val2 / val1;
        if (c > 0){
                return d;
        }
        else{
                return k-1;
        }
}
*/
	Stack_C::Stack_C(){
		try{
			stk = new List;
		}
		catch (runtime_error e){
			throw runtime_error("Out of Memory");
		}
	}
	void Stack_C::push(int data){
		try {
			stk->insert(data);
		}
		catch (runtime_error e){
			throw runtime_error(e.what());
		}
	}

	int Stack_C::pop() {
		try{
			int c = stk->delete_tail();
			return c;
		}
		catch (runtime_error e){
			throw runtime_error(e.what());
		}
	}
	
	void Stack_C::print_stack(bool top_or_bottom){
		if (not top_or_bottom){
                	Node *n;
                	n = stk->get_head();
                	while (n->next != NULL && n->next->next != NULL){
                        	n = n->next;
                        	cout << n->get_value() << endl;
                	}
		}
        	else{
                	Node *n;
			n = stk->get_head()->next;
			int size = stk->List::get_size();
			for (int i = 0; i<size; i++){
				n =n->next;
			}
                	while (n->prev != NULL && n->prev->prev != NULL){
                        	n = n->prev;
                        	cout << n->get_value() << endl;
                	}
        	}
	}

	int Stack_C::get_element_from_top(int idx){
		int b = stk->get_size() - 1;
		if (idx <= b && idx>=0){
			Node *n;
                	n = stk->get_head()->next;
                	int size = stk->get_size();
			int c = size - idx - 1;
                	for (int i = 0; i < c; i++){
                        	n = n->next;
                	}
			return n->get_value();
		}
		else{
			throw runtime_error("Index out of range");
		}
	}

	int Stack_C::get_element_from_bottom(int idx){
		int b = stk->get_size() - 1;
		if (idx <= b){
			Node* n;
			n = stk->get_head()->next;
			int size = stk->get_size();
			for (int i = 0; i < idx; i++){
				n = n->next;
			}
			return n->get_value();
		}
		else{
			throw runtime_error("Index out of range");
		}
	}

	int Stack_C::add(){
		int b = stk->get_size();
		if ( b >= 2){
			int sum = this->pop() + this->pop();
			this->push(sum);
			return sum;
		}
		else{
			throw runtime_error("Not Enough Arguments");
		}
	}

	int Stack_C::subtract(){
		if (stk->get_size() >= 2){
			int val1 = this->pop();
			int val2 = this->pop();
			int diff = val2 - val1;
			this->push(diff);
			return diff;
		}
		else{
			throw runtime_error("Not Enough Arguments");
		}
	}

	int Stack_C::multiply(){
		if ( stk->get_size() >= 2){
                        int mul = this->pop() * this->pop();
                        this->push(mul);
                        return mul;
                }
                else{
                        throw runtime_error("Not Enough Arguments");
                }
	}

	int Stack_C::divide(){
		if (stk->get_size()>=2) {
			int val1 = this->pop();
			int val2 = this->pop();
			if (val1 != 0){
				int div = floor(val1, val2);
				this->push(div);
				return div;
			}
			else{
				throw runtime_error("Divide by Zero Error");
			}
		}
		else{
			throw runtime_error("Not Enough Arguments");
		}
	}

	List* Stack_C::get_stack(){
		return stk;
	}

	int Stack_C::get_size(){
		return stk->get_size();
	}

	Stack_C::~Stack_C(){
		delete stk;
	}
/*
int main (){
	try{
	Stack_C s;
	for (int i = 0; i < 100; i++){
		s.push(i+1);
	}
	cout << s.get_element_from_top(101) << endl;
	}
	catch(runtime_error e){
		cout << e.what() << endl;
	}
}*/
