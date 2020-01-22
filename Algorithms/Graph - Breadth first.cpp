#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Written at 15/12/2018

void main(){
	vector<queue<int>> our_data;
	queue<int> order;
	int length,edges;
	cout << "Enter the number of the nodes: ";cin>>length;
	int *levels = new int [length], *visited = new int [length];;
	for(int i=0;i<length;i++) levels[i] = 0;
	cout << "\nEnter the number of edges: ";cin>>edges;
	cout << "\nEnter the graph edges:\n";
	int temp,temp2;
	for(int i=0;i<=length;i++) our_data.assign(i,queue<int>());
	for(int i=0;i<edges;i++){
		cout << "> ";cin >> temp >> temp2;
		if(temp>=0 && temp<length && temp2>=0 && temp2<length){
			our_data[temp].push(temp2);
			our_data[temp2].push(temp);
		}
		else {
			cout << "\nInvalid edge!\n";
			system("pause");
			exit(0);
		}
	}
	int current_top,current_level=0;
	order.push(0);
	visited[0] = 1, levels[0] = current_level;
	while(!order.empty()){ // Because when it's empty every node would be already visited
		current_top = order.front();
		//cout << "Current_top >"<<current_top<<endl;
		order.pop();
		current_level = levels[current_top];
		while(!our_data[current_top].empty()){
			temp = our_data[current_top].front();
			if(visited[temp]!=1){
				our_data[current_top].pop();
				order.push(temp);
				visited[temp] = 1;
				levels[temp] = current_level+1;
			}
			else our_data[current_top].pop();
		}
	}
	cout << "Nodes     Level\n";
	for(int i=0;i<length;i++){
		cout << i << "     -->    " << levels[i]<<endl;
	}

cout << endl;
system("pause");}