#include <iostream>
#include <string>
using namespace std;
// Written at 23/5/2018
int string_size(string text) {
	if (text=="") return 0;
	else return 1 + string_size(text.substr(1));
}
void print_chars(string str) {
	if (str == "") return;
	else {
		cout << str.at(0) << endl;
		print_chars(str.substr(1));
	}
}

void reversed_chars(string str) {
	if (str == "") return;
	else {
		reversed_chars(str.substr(1));
		cout << str.at(0) << endl;
	}
}

int factorial(int n) {
	if (n == 0) return 1;
	else return (n*factorial(n-1));
}

string bin="";
string dicimal_binary(int n){
	if(x==0) return bin;
	else{
		if ((x%2)==0) bin +="0";
		else bin+="1";
		dic_bi(x/2);
	}
}

int main(){
	int choice;
	string anydata;
	int anydata2;
	while(true){
		cout << "\n\n\t < 1.String_Size   2.Prints_chars  3.Reversed_chars  4.Factorial >\n";
		cout << "Choice >> ";cin >> choice;
		switch(choice){
			case 1:
				cout << "\tData : ";cin >> anydata;
				string_size(anydata);
				break;
			case 2:
				cout << "\tData : ";cin >> anydata;
				print_chars(anydata);
				break;
			case 3:
				cout << "\tData : ";cin >> anydata;
				reversed_chars(anydata);
				break;
			case 4:
				cout << "\tData : ";cin >> anydata2;
				factorial(anydata2);
				break;
			default:
				cout << "\tError please choose from the menu!";
				break;
		}
	}

cout << endl;
system("pause");
return 1;}
