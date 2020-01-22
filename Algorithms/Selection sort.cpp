#include <iostream>
using namespace std;
// Written at 25/12/2018

void main(){
	int length,min,checked;
	cout << "Enter array size: ";cin >> length;
	int* elements = new int[length];
	for(int x=0;x<length;x++){
		cout << "\nEnter element index "<<x<<" value: ";cin >> elements[x];
	}
	for(int loops=0;loops<(length-1);loops++){
		min = elements[loops];
		for(int checks=(loops+1);checks<(length);checks++){
			if(elements[checks]<min){
				min = elements[checks];
				checked = checks;
			}
		}
		//Swaping
		if(min!=elements[loops]){ // Then we found a smaller element
			int temp = elements[checked];
			elements[checked] = elements[loops];
			elements[loops] = temp;
		}
	}
	cout << "\n--> ";
	for(int i=0;i<length;i++) cout << elements[i] << " ";
	cout << endl;
	system("pause");
}