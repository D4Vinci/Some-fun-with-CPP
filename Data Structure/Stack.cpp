#include <iostream>
#include "mystack.h"
using namespace std;
// Written at 17/4/2018

int main(){
	//Linkedlist_Stack<int> mystack;
	//Dynamic_Stack<int> mystack;
	Static_Stack<int> mystack;
	int choice;
	int anydata;
	while(true){
		cout << "\t < 1.Top   2.Push  3.Pop  4.Empty  5.Size >\n";
		cout << "Choice >> ";cin >> choice;
		switch(choice){
			case 1 :
				try{
					cout << "\tTop is "<<mystack.top()<<endl;
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 2:
				try{
					cout << "\tData : ";cin >> anydata;
					mystack.push(anydata);
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 3:
				try{
					mystack.pop();
					break;
				} catch(const char* msg) {
					cout << msg <<endl;
					break;
				}
			case 4:
				if(mystack.empty()) cout << "\tStack is empty!"<<endl;
				else cout << "\tStack is not empty!";
				break;
			case 5:
				cout << "\tSize is "<<mystack.size()<<endl;
				break;
			default:
				cout << "\tError please choose from the menu!";
				break;
		}
	}

cout << endl;
system("pause");
return 1;}
