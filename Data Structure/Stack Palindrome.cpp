#include <iostream>
#include "mystack.h"
#include <string>
using namespace std;
// Written at 22/4/2018
class checker{
	Linkedlist_Stack<char> stack,reversed;
	int size;
	string text;
	public:
		checker(){
			text = "";
		}
		bool test(string to_test){
			size = to_test.size();
			text = to_test;
			to_stack();
			reverse_it();
			return compare();
		}
		void to_stack(){
			for(int n=0;n<size;n++) stack.push(text[n]);
		}
		void reverse_it(){
			for(int n=(size-1);n>=0;n--) reversed.push(text[n]);
		}
		bool compare(){
			bool identical = true;
			char a,b;
			while(identical && !stack.empty()){
				a = stack.top();
				b = reversed.top();
				if(a!=b) {
					identical = false;
					break;
				}
				else{
					stack.pop();
					reversed.pop();
				}
			}
			return identical;
		}
};
int main(){
	while(true){
		checker palindrome_finder;
		string target;
		cout << "Text to check : ";getline(cin,target);
		if(palindrome_finder.test(target)) cout << "Found palindrome!\n";
		else cout << "Palindrome not found!\n";
	}
cout << endl;
system("pause");
return 1;}
