#include <iostream>
#include "mystack.h"
#include "Infix2Postfix.h"
#include <string>
// Written at 22/4/2018

using namespace std;


int main(){
	while(true){
		to_postfix converter;
		string infix;
		cout << "Infix -> ";getline(cin,infix);
		cout << "Postfix -> "<<converter.convert(infix)<<endl;
	}

cout << endl;
system("pause");
return 1;}
