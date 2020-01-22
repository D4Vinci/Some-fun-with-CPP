#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
// Written at 10/12/2018
int total_steps = 0;

//check if we can reach the target from the starting point using breadth first
bool check(vector<queue<int>> our_data, int start, int target, int length){
	queue<int> order;
	int current_top, *visited = new int [length], temp;
	order.push(start);
	visited[start] = 1;
	cout << "Path is " << start ;
	while(!order.empty()){ // Because when it's empty every node would be already visited
		current_top = order.front();
		//cout << "Current_top >"<<current_top<<endl;
		order.pop();
		while(!our_data[current_top].empty()){
			temp = our_data[current_top].front();
			if(visited[temp]!=1){
				cout << " --> ";
				our_data[current_top].pop();
				order.push(temp);
				visited[temp] = 1;
				total_steps++;
				cout << temp ;
			}
			else our_data[current_top].pop();
			if(temp==target){ 
				cout <<endl;
				return true;
			}
		}
	}
	return false;
}

void main(){
	vector<queue<int>> our_data;
	int length,edges;
	cout << "Enter the number of the nodes: ";cin>>length;
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
	int start,target;
	queue<int> before;
	string full_path;
	cout << "Enter the start node: ";cin>>start;
	cout << "Enter the target node: ";cin>>target;
	if(start==target) cout << "Starting point is the target!\n";
	else if(check(our_data, start, target, length)==false){
		cout << "\n-> Can't reach the target from this starting point!\n";
		system("pause");
		exit(0);
	}
	cout << "\n-> Target is reachable from the starting point!\n";
	cout << "Distance is "<<total_steps;

cout << endl;
system("pause");}