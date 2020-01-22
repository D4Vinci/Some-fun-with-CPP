#include <iostream> 
#include <string>
using namespace std;
// Written at 30/10/2018

void out_with_msg(string text){ // Or just pause and out without printing msg :D
	cout << "\n" << text<<endl;
	system("pause");
	exit(0);
}

void main(){
	int length, element, total_loops;
	cout << "Enter size of the array: ";cin >> length;
	int*arr = new int[length];
	for(int x=0;x<length;x++){
		cout << "\nEnter element index "<<x<<" value: ";cin >> arr[x];
		if(x!=0 && arr[x]<=arr[x-1]){
			out_with_msg("[Error] array must be sorted from smallest to biggest!");
		}
	}
	cout << "\nEnter element you want to search about: ";cin >> element;
	
	for(int loops=0;loops<length;loops++){
		total_loops = loops+1;
		if(element<arr[loops]){
			cout << "\n[Finished] Didn't find the element "<<element<<" - Loops: "<<total_loops;
			out_with_msg("");
		}
		else if(element==arr[loops]){
			cout << "\n[Finished] Found the element "<<element<<" at index "<<loops<<" - Loops: "<<total_loops;
			out_with_msg("");
		}
	}
	cout << "\n[Finished] Didn't find the element "<<element<<" - Loops: "<<total_loops<<endl;
	system("pause");
};