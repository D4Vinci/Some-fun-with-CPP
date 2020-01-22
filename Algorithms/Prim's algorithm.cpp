#include <iostream>
using namespace std;
// Written at 24/12/2018

void main(){
	int length;
	cout << "Enter the length of the graph: ";cin>>length;
	int** matrix = new int *[length]; //It's 1D now so let's make it 2D
	for(int i=0;i<length;i++){
		matrix[i] = new int [length]; //Now it's 2D LOL
		for(int j=0;j<length;j++){ //Initialized with the biggest number
			matrix[i][j] = INT_MAX;
		}
	}
	int edges;
	cout << "\nEnter the number of edges: ";cin>>edges;
	cout << "\nEnter the matrix edges with weight:\n";
	int temp,temp2,weight;
	for(int i=0;i<edges;i++){
		cout << "("<<i+1<<")> ";cin >> temp >> temp2 >> weight;
		if(temp>=0 && temp<length && temp2>=0 && temp2<length){
			matrix[temp][temp2] = weight;
			matrix[temp2][temp] = weight;
		}
		else {
			cout << "\nInvalid edge!\n";
			system("pause");
			exit(0);
		}
	}
	int *connected_with = new int [length];
	int *shortest  = new int [length];  //This will have the shortest path to each node   
	for(int i=0;i<length;i++) shortest[i] = INT_MAX;
	shortest[0] = 0,connected_with[0]=-1;
	for(int u=0;u<length;u++){
		for(int v=0;v<length;v++){
			if(matrix[u][v]<shortest[v] && connected_with[u]!=v){ //This will prevent using the same edge twice
				connected_with[v] = u;      //So edges is connected_with[v] --> u = shortest[v]
				shortest[v]= matrix[u][v];
			}
		}
	}

	cout << "------------------------\n";
	for(int i=1;i<length;i++) cout << "Shortest Path to " << i << " is edge (" << connected_with[i] << " - "<< i << ") with weight " << shortest[i] << endl;

cout << endl;
system("pause");}