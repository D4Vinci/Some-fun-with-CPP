#ifndef myqueue_H_
#define myqueue_H_
#include <iostream>
using namespace std;
struct node{
	int data;
	node*next,*prev;
	node(int new_data,node*new_item=NULL,node*prev_item=NULL):data(new_data),next(new_item),prev(prev_item){}
};

template <typename all>
class Linked_queue{
	node*current_front;
	int current_size;
	public:
		Linked_queue(){
			current_front = NULL;
			current_size = 0;
		}
		void push(all new_item){
			if( current_front==NULL ){
				current_front = new node(new_item);
			}
			else{
				current_front->next = new node(new_item,NULL,current_front);
				current_front = current_front -> next;
			}
			current_size++;
		}
		void pop(){
			if(current_size==0) throw "Error queue is empty\n";
			else{
				current_front = current_front ->prev;
				current_size--;
			}
		}
		all front(){
			if(current_size==0) throw "Error queue is empty\n";
			else return current_front->data;
		}
		bool empty(){
			return (current_size==0);}
		int size(){
			return current_size;}
};

template <typename all>
class Static_queue{
	all data[3];
	int current_size;
	public:
		Static_queue(){
			current_size=0;
		}

		void push(all new_item){
			if(current_size ==3) throw "Error in stack size\n";
			else {
				data[current_size] = new_item;
				current_size++;
			}
		}

		void pop(){
			if(current_size==0 || current_size>3) throw "Error in queue size\n";
			else {
				current_size--;
				for(int n=0;n<current_size;n++){
					data[n] = data[n+1];
				}
			};
		}

		all front(){
			if(current_size==0 || current_size>3) throw "Error in queue size\n";
			return data[0];
		}

		bool empty(){
			return (current_size==0);}

		int size(){
			return current_size;}
};


#endif
