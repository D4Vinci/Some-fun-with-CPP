#include <iostream>
#include "mydequeue.h"
using namespace std;
// Written at 23/4/2018
int main(){
	dequeue<int> my;
	int choice;
	int anydata;
	while(true){
		cout << "\t---------------------------------------------\n";
		cout << "\t < 1.front   2.Push_front  3.Pop_front >\n";
		cout << "\t < 4.rear    5.Push_rear   6.Pop_rear  7.Size  8.Display >\n";
		cout << "Choice >> ";cin >> choice;
		switch(choice){
			case 1 :
				try{
					cout << "\tFront is "<<my.front()<<endl;
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 2:
				try{
					cout << "\tData : ";cin >> anydata;
					my.push_front(anydata);
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 3:
				try{
					my.pop_front();
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 4:
				try{
					cout << "\tRear is "<<my.rear()<<endl;
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 5:
				try{
					cout << "\tData : ";cin >> anydata;
					my.push_rear(anydata);
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 6:
				try{
					my.pop_rear();
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 7:
				cout << "\tSize is "<<my.size()<<endl;
				break;

			case 8:
				my.display();
				break;

			default:
				cout << "\tError please choose from the menu!";
				break;
		}
	}

cout << endl;
system("pause");
return 1;}
