#include <iostream>
#include "stack_b.h"

using namespace std;
int floor(int a, int b);

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
	Stack_B::Stack_B(){
		size = 0;
		stk = new int[1024];
		capacity = 1024;
	}

	void Stack_B::push(int data){
		int c =2;
		bool count = false;
		bool flag = true;
		int init_cap = capacity;
		int new_cap = capacity * c;
/*
		while (flag){
			if (count){
				cout << "size, capacity " << size << " " << capacity << endl;}
*/
			try{
			//capacity is the present size
			//new_cap is the size we would want to make

				if (size >= capacity){
//					if (count){
//						new_cap = capacity * c;
//					}
					int* temp = new int[new_cap];
//					flag = false;
					for (int i = 0; i < size; i++){
						//if (count) {cout<<1<<endl;}
						temp[i] = stk[i];
					}
					temp[size] = data;
					delete stk;
					stk = temp;
					size++;
					capacity = new_cap;
				}
				else{
//					flag = false;
					stk[size] = data;
					size++;
				}
			}
			catch(bad_alloc e){
//				cout << "caught bad_alloc" << endl;
//				cout << "size, capacity " << size << " " << capacity << endl;
//				count = true;
//				int diff = c * capacity - init_cap;
//				if (diff < 1 && c * capacity > init_cap){
					throw runtime_error("Out of Memory");
//				}
//				else{
//					new_cap = new_cap * 0.9;
//					capacity = new_cap;
//				}
			}
//		}
	}
	
	int Stack_B::get_size(){
		return size;
	}

	int Stack_B::pop(){
		if(size > 0){
			int c = 2;
			int change = capacity/c;
			int est = change / c;
//			cout << "est : " << est << " size : " << size << endl;
			if (size <= est+1){
//				cout << "entered" << endl;
				if (change <= 1024){
					int* temp = new int[1024];
					for (int i = 0; i < size - 1; i++){
						temp[i] = stk[i];
					}
					int ret = stk[size- 1];
					delete stk;
					stk = temp;
					size--;
					capacity = 1024;
					return ret;
				}
				else{
					int* temp = new int[change];
					for (int i = 0; i < size - 1; i++){
						temp[i] = stk[i];
					}
					int ret = stk[size - 1];
					delete stk;
					stk = temp;
					size--;
					capacity /= c;
					return ret;
				}
			}
			else{
//				cout << "other" << endl;
				size--;
				return stk[size];
			}
		}
		else{
			throw runtime_error("Empty Stack");
		}
	}

	int Stack_B::get_element_from_top(int idx){
		int b = size - 1;
		if (idx>b || idx < 0){
                        throw std::runtime_error("Index out of range");
                }
                else{
                        return stk[size-idx-1];
                }
	}
	
	int Stack_B::get_element_from_bottom(int idx){
                int b = size - 1;
                if ( idx >= 0 && idx <= b ){
                        return stk[idx];
                }
                else{
                        throw std::runtime_error("Index out of range");
                }
        }

	void Stack_B::print_stack(bool top){
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
	
	int Stack_B::add () {
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

	int Stack_B::subtract(){
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

	int Stack_B::multiply () {
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

	int Stack_B::divide () {
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
                                int res = floor(val1 ,val2);
                                this->push(res);
                                return res;
                        }
                }
                return 0;
        }

	int* Stack_B::get_stack(){
                return &stk[0];
        }



	Stack_B::~Stack_B(){
		delete stk;
	}

int main (){
	Stack_B s;
	try{
	for (int i = 0; i < 1024; i++){
		s.push(i);
	}
	for (int j = 0; j < 1025; j++){
		s.pop();
	}
	s.print_stack(1);}
	catch(runtime_error e){
		cout << e.what() << endl;
	}
}	
