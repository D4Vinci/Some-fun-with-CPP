#include <iostream>
using namespace std;
// Written at 25/12/2018

void print(int arr[],int length){
	cout << endl;
	for (int x=0;x<length;x++) cout << arr[x] << " ";
}

void Insertion(int arr[],int length){
	int current,previous=0;
	for(int i=1;i<length;i++){
		current = arr[i];
		previous = i - 1;
		while(previous>=0 && arr[previous]>current){
			arr[previous+1] = arr[previous];
			previous--;
		}
		arr[previous+1] = current;
	}
	print(arr, length);
}

void main(){
	int length;
	cout << "Enter size of the array: ";cin >> length;
	int*arr = new int[length];
	for(int x=0;x<length;x++){
		cout << "\nEnter element index "<<x<<" value: ";cin >> arr[x];
	}
	Insertion(arr,length);

cout << endl;
system("pause");
}