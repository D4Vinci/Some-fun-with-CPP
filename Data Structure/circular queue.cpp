#include <iostream>
using namespace std;
// Written at 14/5/2018

const int default_size = 5;
template <typename all>
class circular_queue{
	all data[default_size];
	int front,rear,size,max;
	public:
		circular_queue(){
			front = 0;
			rear  = -1;
			size  = 0;
			max   = default_size - 1;
		}
		void push(all new_data){
			if(size==0){
				size++;
				front = 0;
				rear  = 0;
				data[0] = new_data;
			}
			else{
				if(size==default_size) cout << "[Error] Queue is full! Remove an element first !\n";
				else{
					if(rear==max) rear = -1;
					rear++;
					if(size!=default_size) size++;
					data[rear] = new_data;

				}
			}
		}

		void remove(){
			if(size==0) cout << "[Error] Queue is empty! Push an element first!\n";
			else{
				if(front==max) front = 0;
				else front++;
				size--;
			}
		}

		void get_front(){
			if(size==0) cout << "[Error] Queue is empty! Push an element first!\n";
			else cout << "Front is "<<data[front];
		}

		void get_rear(){
			if(size==0) cout << "[Error] Queue is empty! Push an element first!\n";
			else cout << "Rear is "<<data[rear];
		}
		void display(){
			if(size==0) cout << "[Error] Queue is empty! Push an element first!\n";
			else{
				cout << " Size = " << size << "\tCapacity = " << default_size << endl;
				int display_size=size;
				int begin = 0;
				if(size<default_size && front > 0) display_size = default_size;

				if(front > 0 && rear < front) begin = 0;
				else if(front > 0 ) begin = front;

				for(int n=begin;n<display_size;n++){
					if(n==front && n==rear) cout <<"\t"<< data[n] << "\t<-front \t<-rear\n";
					else if(n==front) cout <<"\t" << data[n] << "\t<-front\n";
					else if(n==rear) cout <<"\t" << data[n] << "\t<-rear\n";
					else cout <<"\t" << data[n] << endl;
				}
			}
		}
};

int main(){
	circular_queue<int> myqueue;
	int choice;
	int anydata;
	while(true){
		cout << "\n\n\t < 1.Front   2.Push  3.Remove  4.Rear  5.Display >\n";
		cout << "Choice >> ";cin >> choice;
		switch(choice){
			case 1:
				myqueue.get_front();
				break;
			case 2:
				cout << "\tData : ";cin >> anydata;
				myqueue.push(anydata);
				break;
			case 3:
				myqueue.remove();
				break;
			case 4:
				myqueue.get_rear();
				break;
			case 5:
				myqueue.display();
				break;
			default:
				cout << "\tError please choose from the menu!";
				break;
		}
	}

cout << endl;
system("pause");
return 1;
}
