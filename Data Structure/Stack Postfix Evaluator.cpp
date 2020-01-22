#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Written at 16/4/2018
const string operators = "+-*/";
int result;
class Postfix_Evaluator{
	stack<int> mystack;
	public:
		bool isoperator(char op){ return (operators.find(op)!=-1); }
		bool isnumber(char num){ return (num>='0' && num <='9'); }
		int char2int(char num){
			switch (num){
				case '0':
					return 0;
				case '1':
					return 1;
				case '2':
					return 2;
				case '3':
					return 3;
				case '4':
					return 4;
				case '5':
					return 5;
				case '6':
					return 6;
				case '7':
					return 7;
				case '8':
					return 9;
				case '9':
					return 9;
			}
		}

		void eval_op(char op,int x,int y) {
			int eval_result;
			if(op == '+') eval_result =  x +y;
			else if(op == '-') eval_result =  x - y;
			else if(op == '*') eval_result =  x * y;
			else if(op == '/') eval_result =  x / y;
			mystack.push(eval_result);
		}

		void eval( string expression){
			while(!mystack.empty()) mystack.pop();
			bool error=false;
			for(int n=0;n<expression.length();n++){
				if(expression[n]==' ') continue;
				else if(isoperator(expression[n])){
					if (mystack.empty()){
						cout << "[Error] Stack is empty! Please enter a postfix expression";
						error=true;
						break;
					}
					int x = char2int(mystack.top());mystack.pop();

					if (mystack.empty()){
						cout << "[Error] Stack is empty! Please enter a postfix expression";
						error=true;
						break;
					}
					int y = char2int(mystack.top());mystack.pop();
					eval_op(expression[n],x,y);
				}
				else{
					if( isnumber(expression[n]) ) mystack.push(expression[n]);
					else continue;
					}
				}
			if(!error){
				int xXx = mystack.top();
				mystack.pop();
				if(mystack.empty()) cout << "The answer is " << xXx<<endl;
				else cout << "[Error] Incorrect expression! Please enter a postfix expression";
			}
		}
};

int main(){
	while(true){
		Postfix_Evaluator myevalator;
		string expression;// = "3 5 4 2 3 / - * +";
		//cout << "Expression : "<< expression<<endl;
		cout << "\nEnter expression : ";getline(cin,expression);
		myevalator.eval(expression);
	}

cout << endl;
system("pause");
return 0;
}
