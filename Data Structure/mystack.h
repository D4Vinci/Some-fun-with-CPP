#ifndef mystack_H_
#define mystack_H_
#include <iostream>
using namespace std;

struct node{
	int data;
	node*next;
	node(int new_data,node*new_item=NULL):data(new_data),next(new_item){}
};

template <typename all>
class Linkedlist_Stack{
	node*current_top;
	int current_size;
	public:
		Linkedlist_Stack(){
			current_top = NULL;
			current_size = 0;
		}
		void push(all new_item){
			current_top = new node(new_item,current_top);
			current_size++;
		}
		void pop(){
			if(current_size==0) throw "Error stack is empty\n";
			else{
				current_top = current_top ->next;
				current_size--;
			}
		}
		all top(){
			if(current_size==0) throw "Error stack is empty\n";
			else return current_top->data;
		}
		bool empty(){
			return (current_size==0);}
		int size(){
			return current_size;}

};

template <typename all>
class Stack{
	all*data,*temp;
	int current_size;
	public:
		Stack(){
			data = new all;
			current_size=0;
		}
		void push(all new_item){
			temp = new all [current_size+1];
			for(int n=0;n<current_size;n++) temp[n] = data[n];
			delete data;
			data = new all[current_size+1];
			for(int n=0;n<current_size;n++) data[n] = temp[n];
			data[current_size] = new_item;
			delete temp;
			current_size++;
		}

		void pop(){
			if(current_size==0) throw "Error stack is empty\n";
			else{
				temp = new all [current_size-1];
				for(int n=0;n<(current_size-1);n++) temp[n] = data[n];
				delete data;
				data = new all[current_size-1];
				for(int n=0;n<(current_size-1);n++) data[n] = temp[n];
				delete temp;
				current_size--;
			}
		}

		all top(){
			if(current_size==0) throw "Error stack is empty\n";
			return data[current_size-1];
		}

		bool empty(){
			return (current_size==0);}

		int size(){
			return current_size;}
};

#endif
