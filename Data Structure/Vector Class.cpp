#include <iostream>
using namespace std;
// Written at 22/5/2018

//ToDo:
//size                  (Done)
//insert(pos, elem)     (Done)
//push_back(elem)       (Done)
//empty()               (Done)
//clear()               (Done)
//erase(pos)            (Done)
//erase(a,b)            (Done)

template <class Alltypes>
class vector{
  Alltypes* x,*y;
  int Current_size;
public:
  vector(){
	Current_size = 0;
    x = new Alltypes;
  }

  void push_back(Alltypes N){
    int n = Current_size;
    y = new Alltypes[n];
    for(int i=0;i<n;i++) y[i] = x[i];
    delete[] x;
    x = new Alltypes[n+1];
    for(int i=0;i<n;i++) x[i] = y[i];
    x[n]=N;
    delete[] y;
	Current_size++;
  }

  void pop_back(){
	  if(Current_size==0) cout << "Error! there's no elements\n";
	  else{
		  int n = Current_size;
		  y = new Alltypes[n];
		  for(int i=0;i<n;i++) y[i] = x[i];
		  delete[] x;
		  x = new Alltypes[n-1];
		  for(int i=0;i<(n-1);i++) x[i] = y[i];
		  delete[] y;
		  Current_size -=1;
	  }
  }

  void display(){
	cout << "->";
	for(int i=0;i<Current_size;i++) cout << x[i] << " ";
	cout << endl;
  }

  Alltypes size(){
	return Current_size;
  }

  void at(int n){
	  if(Current_size==0) cout << "Error! there's no elements\n";
	  else if(n>Current_size || n <0) cout << "Error in index !!\n";
	  else cout << "->"<<x[n] << endl;
  }
  void operator[](int n) {
	  at(n);
  }

  void Clear(){
	  delete[] x;
	  x = new Alltypes;
	  Current_size = 0;
  }

  bool empty(){
	  if(Current_size==0) return 1;
	  else return 0;
  }

  void front(){
	  if(Current_size==0) cout << "Error! there's no elements\n";
	  else cout << "->"<< x[0] << endl;
  }

  void back(){
	  if(Current_size==0) cout << "Error! there's no elements\n";
	  else cout << "->"<< x[Current_size-1] << endl;
  }

  void insert(int pos, Alltypes elem){
	if(Current_size==0 || pos==Current_size) push_back(elem);
	else if(pos >= Current_size || pos < 0)cout << "Error index not found!\n";
	else{
		int n = Current_size;
		y = new Alltypes[n+1];
		if(pos==0){
			y[0]=elem;
			for(int i=1;i<(n+1);i++) y[i] = x[i-1];
			delete[] x;
			x = new Alltypes[n+1];
			for(int i=0;i<(n+1);i++) x[i] = y[i];
			delete[] y;
			Current_size++;
		}
		else{
			for(int i=0;i<pos;i++) y[i] = x[i];
			y[pos] = elem;
			for(int i=(pos);i<(n+1);i++) y[i+1] = x[i];
			delete[] x;
			x = new Alltypes[n+1];
			for(int i=0;i<(n+1);i++) x[i] = y[i];
			delete[] y;
			Current_size++;
		}
	}
  }

  void erase(int pos) {
	if(pos>=Current_size || pos<0) cout << "Error index not found!\n";
	else if( pos==(Current_size-1) ) pop_back();
	else{
		int n = Current_size-1;
		y = new Alltypes[n];
		for(int i=pos;i<n;i++) y[i] = x[i+1];
		delete[] x;
		x = new Alltypes[n];
		for(int i=0;i<n;i++) x[i] = y[i];
		delete[] y;
		Current_size--;
	}
  }

  void erase(int from,int to) {
	if(from>=Current_size || from<0) cout << "Error index 1 not found!\n";
	else if(to>=Current_size || to<0) cout << "Error index 2 not found!\n";
	else if(from==to) erase(from);
	else{
		if(from>to){
			int temp = from;
			from = to;
			to = temp;
		}
		int out = (to-from)-1;
		int n = Current_size-out;
		y = new Alltypes[n];
		for(int i=0;i<=from;i++) y[i] = x[i];
		int nn = from+1;
		for(int i=to;i<=n;i++){
			y[nn] = x[i];
			nn++;
		}
		delete[] x;
		x = new Alltypes[n];
		for(int i=0;i<n;i++) x[i] = y[i];
		delete[] y;
		Current_size = Current_size - out;
	}
  }

};
int main(){
	vector <int> v1;
	int somedata1,somedata2;
	int looper = 0;
	while(looper==0){
		int choice;
		cout << "               -------------------------";
		cout << "\n          Say hi to the vector program :D\n";
		cout << "(01)Size  (02)push_back  (03)pop_back  (04)Clear   (05)empty\n";
		cout << "(06)At    (07)front      (08)back      (09)display (10)insert\n";
		cout << "(11)erase(pos)    (12)erase(from,to)\n";
		cout << "                  (0)exit\n";
		cout << "\nYour choice : ";cin >> choice;
		if(choice >12 || choice <0) continue;
		else{
			switch(choice){
				default:
					looper=1;
					break;
				case 1:
					cout << "Size : "<<v1.size()<<endl<<endl;
					break;
				case 2:
					cout << "Integer to push : ";cin >> somedata1;
					v1.push_back(somedata1);
					break;
				case 3:
					v1.pop_back();
					break;
				case 4:
					v1.Clear();
					break;
				case 5:
					cout << "\nChecking if vector is empty...\n";
					if(v1.empty()) cout << "Vector is empty!\n";
					else cout << "Vector is not empty!\n";
					break;
				case 6:
					cout << "Index : ";cin >> somedata1;
					v1[somedata1];
					break;
				case 7:
					v1.front();
					break;
				case 8:
					v1.back();
					break;
				case 9:
					v1.display();
					break;
				case 10:
					cout << "Index : ";cin >> somedata1;
					cout << "Data : ";cin >> somedata2;
					v1.insert(somedata1,somedata2);
					break;
				case 11:
					cout << "Index : ";cin >> somedata1;
					v1.erase(somedata1);
					break;
				case 12:
					cout << "Index 1 : ";cin >> somedata1;
					cout << "Index 2  : ";cin >> somedata2;
					v1.erase(somedata1,somedata2);
					break;
			}
		}
	}

cout << endl;
system("pause");
return 0;
}
