#include <iostream>
#include "mystack.h"
#include <string>
using namespace std;
// Written at 19/4/2018

class Balance_checker{
	Linkedlist_Stack<char> stack;
	int size;
	string opening,closing,text;
	bool balanced;
	public:
		Balance_checker(){
			balanced = true;
			text = "";
			opening = "([{";
			closing  = ")]}";
		}
		bool test(string to_test){
			size = to_test.length();
			text = to_test;
			balance();
			return balanced;
		}

		bool is_opening(char ch){
			return (opening.find(ch)!=-1);
		}

		bool is_closing(char ch){
			return (closing.find(ch)!=-1);
		}

		bool is_bracket(char ch){
			string brackets = opening + closing;
			return (brackets.find(ch)!=-1);
		}

		bool compare(char ch){
			if(ch==')' && stack.top()=='(') return true;
			else if(ch==']' && stack.top()=='[') return true;
			else if(ch=='}' && stack.top()=='{') return true;
			else return false;
		}

		void balance(){
			char a;
			for(int n=0;n<size;n++){
				a = text[n];
				if( is_bracket(a) ){
					if( is_opening(a) ){
						stack.push(a);}
					else if( is_closing(a) ){
						if(stack.empty() || !compare(a) ){
							balanced = false;}
						else {
							balanced= true;
							stack.pop();
						}
					}
				}
			}
			if(!stack.empty()) balanced = false;
		}
};

int main(){
	while(true){
		Balance_checker checker;
		string text;
		cout << "Enter data -> ";getline(cin,text);
		bool s = checker.test(text);
		if(s) cout << "String is balanced!\n";
		else cout << "String is not balanced!\n";
	}
cout << endl;
system("pause");
return 1;}
