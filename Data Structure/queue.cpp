#include <iostream>
#include "myqueue.h"
using namespace std;
// Written at 17/4/2018

int main(){
	//Linked_queue<int> myqueue;
	Static_queue<int> myqueue;
	int choice;
	int anydata;
	while(true){
		cout << "\t < 1.Front   2.Push  3.Pop  4.Empty  5.Size >\n";
		cout << "Choice >> ";cin >> choice;
		switch(choice){
			case 1 :
				try{
					cout << "\tTop is "<<myqueue.front()<<endl;
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 2:
				try{
					cout << "\tData : ";cin >> anydata;
					myqueue.push(anydata);
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 3:
				try{
					myqueue.pop();
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 4:
				if(myqueue.empty()) cout << "\tStack is empty!"<<endl;
				else cout << "\tStack is not empty!";
				break;
			case 5:
				cout << "\tSize is "<<myqueue.size()<<endl;
				break;
			default:
				cout << "\tError please choose from the menu!";
				break;
		}
	}

cout << endl;
system("pause");
return 1;}
