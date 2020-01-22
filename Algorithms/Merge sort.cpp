#include <iostream>
using namespace std;
// Written at 13/11/2018

void print(int arr[],int length){
	cout << endl;
	for (int x=0;x<length;x++) cout << arr[x] << " ";
}

int* merge(int left[], int right[], int first_size, int second_size){
	int p1 = 0, p2 = 0, key = 0;
	int* final_array = new int[first_size+second_size];
	while(p1 < first_size && p2 < second_size){
		if( left[p1] < right[p2]){
			final_array[key] = left[p1];
			p1++;
		}
		else {
			final_array[key] = right[p2];
			p2++;
		}
		key++;
	}
	if(p1 <= (first_size-1) ){
		while(p1<first_size){
			final_array[key] = left[p1];
			p1++;
			key++;
		}
	}
	else if(p2 <= (second_size-1)){
		while(p2<second_size){
			final_array[key] = right[p2];
			p2++;
			key++;
		}
	}
	//cout << "\n+ Sorted as ";
	//print(final_array,(first_size+second_size));
	//cout << endl;
	return final_array;
}

int* sort_this(int arr[], int arr_size){
	if (arr_size==1) return arr;
	int mid = (arr_size/2);
	int* left = new int[mid];
	int* right = new int[arr_size-mid];
	for(int x=0;x<=mid;x++){
		left[x]  = arr[x];
		right[x] = arr[x+mid];
	}
	cout << "\n +Splited to "; 
	print(left,mid);
	print(right,arr_size-mid);
	cout << endl;
	left  = sort_this(left,mid);
	right = sort_this(right,arr_size-mid);
	return merge(left,right,mid,(arr_size-mid));
}

void main(){
	int length;
	cout << "Enter size of the array: ";cin >> length;
	int*arr = new int[length];
	for(int x=0;x<length;x++){
		cout << "\nEnter element index "<<x<<" value: ";cin >> arr[x];
	}
	arr = sort_this(arr,length);
	cout << endl;
	for (int x=0;x<length;x++) cout << arr[x] << " ";

cout << endl;
system("pause");
}