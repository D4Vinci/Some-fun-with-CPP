#include <iostream>
#include <string>
using namespace std;
// Written at 30/10/2018
int total_loops=1;

void out_with_msg(string text){ // Or just pause and out without printing msg :D
	cout << "\n" << text<<endl;
	system("pause");
	exit(0);
}

void binary_search(int elements[], int front, int rear, int element){
	int mid = ((rear-front)/2)+front;
	if(front==rear){
		cout << "\n[Finished] Didn't find the element "<<element<<" - Loops: "<<total_loops<<endl;
		out_with_msg("");
	}
	if(elements[front]==element || elements[rear]==element || elements[mid]==element){
		cout << "\n[Finished] Found the element "<<element<<" - Loops: "<<total_loops;
		out_with_msg("");
	}
	if(element > elements[mid]){
		total_loops++;
		binary_search(elements, mid+1, rear-1, element);
	}
	else{
		total_loops++;
		binary_search(elements, front+1, mid-1, element);
	}
}

void main(){
	int length, element,rear=0;
	cout << "Enter size of the array: ";cin >> length;
	int*arr = new int[length];
	for(int x=0;x<length;x++){
		cout << "\nEnter element index "<<x<<" value: ";cin >> arr[x];
		if(x!=0 && arr[x]<=arr[x-1]){
			out_with_msg("[Error] array must be sorted from smallest to biggest!");
		}
		rear = x;
	}
	cout << "\nEnter element you want to search about: ";cin >> element;
	binary_search(arr, 0, rear, element);
	cout << "\n[Finished] Didn't find the element "<<element<<" - Loops: "<<total_loops<<endl;
	system("pause");
};