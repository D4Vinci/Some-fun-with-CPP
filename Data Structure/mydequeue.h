#ifndef mydequeue_H_
#define mydequeue_H_
#include <iostream>
using namespace std;
const int N=2;
template <typename All>
class dequeue {
	All data[N];
	int current_size;
	public:
		dequeue(){
			current_size = 0;
		}
		All front(){
			if(current_size==0) throw "Error! Dequeue is empty!";
			else return data[0];
		}

		void push_front(All New){
			if(current_size>=N) throw "Error! Dequeue is full!";
			else if (current_size==0){
				data[0] = New;
				current_size++;
			}
			else if (current_size>0){
				for( int c=(current_size-1);c>=0;c-- ) data[c+1] = data[c];
				data[0] = New;
				current_size++;
			}
		}

		void pop_front(){
			if(current_size==0) throw "Error! Dequeue is empty!";
			else if (current_size>0){
				for( int c=1;c<current_size;c++ ) data[c-1] = data[c];
				current_size--;
			}
		}

		All rear(){
			if(current_size==0) throw "Error! Dequeue is empty!";
			else return data[current_size-1];
		}

		void push_rear(All New){
			if(current_size>=N) throw "Error! Dequeue is full!";
			else if (current_size==0){
				data[0] = New;
				current_size++;
			}
			else if (current_size>0){
				data[current_size] = New;
				current_size++;
			}
		}

		void pop_rear(){
			if(current_size==0) throw "Error! Dequeue is empty!";
			else if (current_size>0) current_size--;
		}

		int size(){ return current_size; }

		void display(){
			cout << "--> ";
			for( int c=0;c<current_size;c++ ) cout << data[c] << "  ";
			cout << endl;
		}
};

#endif
