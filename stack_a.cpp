#include <iostream>
#include "stack_a.h"
using namespace std;
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
	Stack_A::Stack_A(){
		size = 0;
	}
	
	void Stack_A::push(int data){
		//here size is the current size
		if (size<1024){
			stk[size] = data;
			size += 1;
		}
		else{
			throw std::runtime_error("Stack Full");
		}
	}
	
	int Stack_A::pop( ){
		//stack has not exceeded the size limit
		//size represents the actual length
		//stk[size] is not part of the stack
		if (size > 0){
			size -= 1;
			return stk[size];
		}
		else{
			throw std::runtime_error("Empty Stack");
		}
	}
	
	int Stack_A::get_element_from_top(int idx){
		int b = size - 1;
		if (idx>b || idx < 0){
			throw std::runtime_error("Index out of range");
		}
		else{
			return stk[size-idx-1];
		}
	}
	
	int Stack_A::get_element_from_bottom(int idx){
		int b = size - 1;
		if ( idx >= 0 && idx <= b ){
			return stk[idx];
		}
		else{
			throw std::runtime_error("Index out of range");
		}
	}

	void Stack_A::print_stack(bool top){
		/*	size represents the physical size not the indexed
			top = 1 print from top
			else from bottom
			size > 0{ simple for loop }
				two cases {top=1 || top=0}
			size <= 0 { print nothing  }
		*/
		//no excpetions can be created here
		if (size > 0){
			if (top == 1){
				for (int i = size - 1; i >= 0; i = i - 1){
					cout << stk[i] << endl;
				}
			}
			else{
				for (int i = 0; i < size; i++){
					cout << stk[i] << endl;
				}
			}
		}
	}
	
	int Stack_A::add () {
		// pop last two elements and add and replace
		// sequence
		// if can pop can push back as well
		// try pop 1 -> try pop 2 -> add -> push back
		if ( size <= 1 ){
			throw runtime_error("Not Enough Arguments");
		}
		else{
			int sum = this->pop() + this->pop();
			this->push(sum);
			return sum;
		}
		return 0;
	}
	int Stack_A::subtract(){
		if (size <= 1){
			throw runtime_error("Not Enough Arguments");
		}
		else{
			int val1 = this->pop(); // top
			int val2 = this->pop(); // next to top
			int diff = val2 - val1;
			this->push(diff);
			return diff;
		}
		return 0;
	}

	int Stack_A::multiply () {
		if (size <= 1){
			throw runtime_error("Not Enough Arguments");
		}
		else{
			int mul = this->pop() * this->pop();
			this->push(mul);
			return mul;
		}
		return 0;
	}

	int Stack_A::divide () {
		//check if pop-able
			// if zero non
		//else -> throw error
		if (size <= 1){
			throw runtime_error("Not Enough Arguments");
		}
		else{
			int val1 = this->pop();
			int val2 = this->pop();
			if (val1 == 0){
				throw runtime_error("Divide by Zero Error");
			}
			else{
				int res = floor(val1, val2);
				this->push(res);
				return res;
			}
		}
		return 0;
	}

	int* Stack_A::get_stack(){
		return &stk[0];
	}

	int Stack_A::get_size(){
		return size;
	}	
