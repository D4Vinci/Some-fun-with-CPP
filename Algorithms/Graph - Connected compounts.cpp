#include <iostream>
#include <stack>
using namespace std;
// Written at 7/12/2018

void main(){
	int length;
	cout << "Enter the length of the graph: ";cin>>length;
	int** matrix = new int *[length]; //It's 1D now so let's make it 2D
	for(int i=0;i<length;i++){
		matrix[i] = new int [length]; //Now it's 2D LOL
		for(int j=0;j<length;j++){ //Initialized with zeros
			matrix[i][j] = 0;
		}
	}
	int edges;
	cout << "\nEnter the number of edges :";cin>>edges;
	cout << "\nEnter the matrix edges:\n";
	int temp,temp2;
	for(int i=0;i<edges;i++){
		cout << "> ";cin >> temp >> temp2;
		if(temp>=0 && temp<length && temp2>=0 && temp2<length){
			matrix[temp][temp2] = 1;
			matrix[temp2][temp] = 1;
		}
		else {
			cout << "\nInvalid edge!\n";
			system("pause");
			exit(0);
		}
	}
	stack<int> our_stack;
	int *visited = new int [length];
	cout << "\nEnter the number to work on: ";cin >> temp;
	for(int i=0;i<length;i++){
		if(matrix[temp][i]==1) our_stack.push(i);
		visited[i]=0; //Initializing it by the way lol
	}
	visited[temp]=1;
	cout << "\nThe final result is "<<temp;
	while(true){
		if(our_stack.empty()) break;
		temp = our_stack.top();
		our_stack.pop();
		cout << " " << temp; // To print the connected components in order
		visited[temp] = 1;
		for(int i=0;i<length;i++){
			if(matrix[temp][i]==1 && visited[i]==0) our_stack.push(i);
		}
	}

cout << endl;
system("pause");}