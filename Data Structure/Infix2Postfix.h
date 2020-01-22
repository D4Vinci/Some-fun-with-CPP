#ifndef infix2postfix_H_
#define infix2postfix_H_
#include <iostream>
#include "mystack.h"
using namespace std;

class to_postfix{
	string postfix,operators,opening,closing;
	Linkedlist_Stack<char> stack;
	public:
		to_postfix(){
			postfix = "", opening = "([{", closing = ")]}", operators = "+-*/";
		}
		bool isopening(char s) { return (opening.find(s)!=-1); }
		bool isclosing(char s) { return (closing.find(s)!=-1); }
		bool is_operator(char ch) { return (operators.find(ch)!=-1); }
		int priority(char ch) {
			char p[] = {1,1,2,2};
			return p[operators.find(ch)];
		}
		string convert(string infix){
			for(int n=0;n<infix.size();n++){
				if(infix[n]!=' '){
					if(is_operator(infix[n])==false){//operand
						postfix += infix[n];
						postfix += " ";
					}
					else {
						if( isopening(infix[n]) ){
							stack.push(infix[n]);
							continue;
						}
						else if( isclosing(infix[n]) ){
							while( !isopening(stack.top()) ){
								postfix += stack.top();
								postfix += " ";
								stack.pop();
							}
							continue;
						}
						else{
							while( !stack.empty() && ( priority(stack.top()) >priority(infix[n]) ) ){
									postfix += stack.top();
									postfix += " ";
									stack.pop();
								}
							stack.push(infix[n]);
						}
					}
				}
				else continue;
				cout << infix[n] << endl;
			}
			while(!stack.empty()){
				postfix += stack.top();
				postfix += " ";
				stack.pop();
			}
			return postfix;
		}
};

#endif
