#include <iostream>
using namespace std;
// Written at 23/4/2018

//////Needed to be included :
//[01]Add_last(int x)                   (done)
//[02]Add_first(int x)                  (done)
//[03]Add_Position(data,index)			(done)
//[04]Search_index(index)               (done)
//[05]Search_data(data)					(done)
//[06]Delete_data(data)					(done)
//[07]Delete_index(index)				(done)
//[08]replace_data(data,data)			(done)
//[09]replace_index(index,data)			(done)
//[10]swap_data(data,data)              (done)
//[11]swap_index(index,index)           (done)
//[12]reversed_display()                (done)


struct node{
	int data;
	node *next;
};

class linkedlist{
	node* head;
	int total_size;
	public:
		linkedlist(){
			head=NULL;
			total_size = 0;
		}

		void NewNode(int x){
			node*temp = new node;
			temp->data=x;
			temp->next=NULL;
			head=temp;
			total_size++;
		}

		void AddLast(int x){
			if(head==NULL) NewNode(x);
			else{
				node*temp = head;
				for(int c=0;c<(total_size-1);c++) temp = temp ->next;
				node*P=new node;
				P->data=x;
				P->next=head;
				temp->next=P;
				total_size++;
			}
		}

		void AddFirst(int x){
			if(head==NULL) NewNode(x);
			else{
				node*P=new node;
				P->data=x;
				P->next=head;
				head = P;
				total_size++;
			}
		}

		void Add_Position(int data,int index){
			if(head==NULL) cout << "List is empty!\n";
			else{
				if(index==0) AddFirst(data);
				else{
					if(index <= total_size && index >=0){
						node*temp = head,*previous;
						for(int n=0;index!=n;n++){
							previous = temp;
							temp = temp ->next;
						}
						node*P=new node;
						P->data=data;
						P->next=temp;
						previous->next=P;
						total_size++;
					}
					else cout << "Error in index!!\n";
				}
			}
		}

		void Search_index(int index){
			if(head!=NULL){
				if(index <= total_size && index >=0){
					node*temp = head;
					for(int n=0;index!=n;n++) temp = temp ->next;
					cout << "Data at index "<<index<<" is "<<temp->data<<endl;
				}
				else cout << "Not found!\n";
			}
			else cout << "List is empty !\n";
		}

		void Search_data(int data){
			if(head!=NULL){
				node*temp = head;
				int index=0;
				bool found=false;
				for(int c=0;c!=total_size;c++){
					if( data==temp->data){
						cout << "Data "<<data<<" is at index "<<index<<endl;
						found=true;
						break;
					}
					else{
						temp = temp ->next;
						index++;
					}
				}
				if(!found) cout << "Not found!\n";
			}
			else cout << "List is empty !\n";
		}

		void Delete_data(int data){
			if(head!=NULL){
				node*temp=head,*previous;
				bool found=false;
				if(data==temp->data){
					head = head->next;
					found=true;
				}
				else{
					for(int c=0;c!=total_size;c++){
						if(data==temp->data){
							previous ->next = temp->next;
							total_size--;
							found=true;
							break;
						}
						else{
							previous = temp;
							temp = temp ->next;
						}
					}
				}
				if(!found) cout << "Not found!\n";
			}
			else cout << "List is empty !\n";
		}

		void Delete_index(int index){
			if(head!=NULL){
				if(index <= total_size && index >=0){
					node*temp=head,*previous;
					if(index==0) head = head->next;
					else{
						for(int n=0;index!=n;n++){
							previous = temp;
							temp = temp ->next;
						}
						previous->next = temp->next;
						total_size--;
					}
				}
				else cout << "Not found!\n";
			}
			else cout << "List is empty !\n";
		}

		void replace_data(int data1,int data2){
			if(head!=NULL){
				node*temp =head;
				bool found=false;
				for(int c=0;c!=total_size;c++){
					temp = temp ->next;
					if(temp->data==data1){
						found=true;
						break;
					}
				}
				if(found) temp ->data = data2;
				else cout << "Not found!\n";
				}
			else cout << "List is empty !\n";
		}

		void replace_index(int index,int data){
			if(head!=NULL){
				if(index <= total_size && index >=0){
					node*temp = head;
					for(int n=0;index!=n;n++) temp = temp ->next;
					temp ->data = data;
				}
				else cout << "Not found!\n";
			}
			else cout << "List is empty !\n";
		}

		void swap_data(int data1,int data2){
			if(head==NULL) cout << "List is empty so can't find this element!\n";
			else{
				node*temp1 =head,*temp2;
				bool found1=false,found2=false;
				bool finished=false;
				while(data1!=temp1->data && data2!=temp1->data){
					temp1 = temp1 ->next;
					if(temp1==NULL) break;
					else if (data1==temp1->data) found1 = true;
					else if (data2==temp1->data){
						found2 = true;
						temp2 = temp1;
					}
					if (found1 && found2){
						finished=true;
						break;
					}
				}
				if(finished){
					int temp = temp1 ->data;
					temp1 ->data=temp2->data;
					temp2 ->data=temp;
				}
				else{
					if(!found1) cout << "Data 1 not found in the linkedlist\n";
					if(!found2) cout << "Data 2 not found in the linkedlist\n";
				}
			}
		}

		void swap_index(int index1,int index2){
			if(head==NULL) cout << "List is empty so can't find this element!\n";
			else{
				if(index1 <= total_size && index1 >=0){
					node*temp1 =head,*temp2;
					for(int n=0;index1!=n;n++){
						temp1 = temp1 ->next;
						if(index2==n) temp2 = temp1;
					}
					if(index2 <= total_size && index2 >=0){
						int temp = temp1 ->data;
						temp1 ->data=temp2->data;
						temp2 ->data=temp;
					}
					else cout << "Error in index 2 !\n";
				}
				else cout << "Error in index 1 !\n";
			}
		}

		void reverse_display(){
			node*temp =head;
			int*list;
			list = new int [total_size];
			cout << "\n-> ";
			for(int c=0;c!=total_size;c++){
				list[c]=temp->data;
				temp = temp->next;
			}
			for(int x=(total_size-1);x>=0;x--) cout << list[x] << " ";
		}

		void display(){
			node*temp;
			temp=head;
			cout << "\n-> ";
			for(int c=0;c!=total_size;c++){
				cout << temp->data <<" ";
				temp = temp->next;
			}
		}
};

int main(){
	linkedlist data;
	int somedata1,somedata2;
	int looper = 0,choice;
	while(looper==0){
		cout << "\n                     -------------------------";
		cout << "\n                Say hi to the linkedlist program :D\n\n";
		cout << "(1)AddLast(int x)                       ||Make an element the last one\n";
		cout << "(2)Add_first(int x)                     ||Make an element the first one\n";
		cout << "(3)Add_Position(int data,int index)     ||Add an element at a specific index\n";
		cout << "(4)Search_index(int index)              ||Grabing an element data by it's index\n";
		cout << "(5)Search_data(int data)                ||Grabing an element index by it's data\n";
		cout << "(6)Delete_data(int data)                ||Deleting an element by it's data\n";
		cout << "(7)Delete_index(int index)              ||Deleting an element by it's index\n";
		cout << "(8)replace_data(int data1,int data2)    ||Replacing an element data with another data by data\n";
		cout << "(9)replace_index(int index,int data)    ||Replacing an element data with another data by index\n";
		cout << "(10)swap_index(int index1,int index2)   ||Swaping two elements data by their indexes\n";
		cout << "(11)swap_data(int data1,int data2)      ||Swaping two elements data by their data\n";
		cout << "(12)reverse_display()                   ||Display the current list nodes data reversed\n";
		cout << "(13)display()                           ||Display the current list nodes data\n";
		cout << "(0)exit\n";
		cout << "\nYour choice : ";
		if (!(cin >> choice)){
			cout << "\nPlease enter integers only!\n";
			cin.clear();
			cin.ignore();
			continue;
		}
		if(choice >13 || choice <0) continue;
		else{
			switch(choice){
				default:
					looper=1;
					break;
				case 1:
					cout << "Integer to add last : ";cin >> somedata1;
					data.AddLast(somedata1);
					break;
				case 2:
					cout << "Integer to add first : ";cin >> somedata1;
					data.AddFirst(somedata1);
					break;
				case 3:
					cout << "Data : ";cin >> somedata1;
					cout << "index : ";cin >> somedata2;
					data.Add_Position(somedata1,somedata2);
					break;
				case 4:
					cout << "index : ";cin >> somedata1;
					data.Search_index(somedata1);
					break;
				case 5:
					cout << "data : ";cin >> somedata1;
					data.Search_data(somedata1);
					break;
				case 6:
					cout << "data : ";cin >> somedata1;
					data.Delete_data(somedata1);
					break;
				case 7:
					cout << "index : ";cin >> somedata1;
					data.Delete_index(somedata1);
					break;
				case 8:
					cout << "Data 1 : ";cin >> somedata1;
					cout << "Data 2 : ";cin >> somedata2;
					data.replace_data(somedata1,somedata2);
					break;
				case 9:
					cout << "Index : ";cin >> somedata1;
					cout << "Data : ";cin >> somedata2;
					data.replace_index(somedata1,somedata2);
					break;
				case 10:
					cout << "Index 1 : ";cin >> somedata1;
					cout << "Index 2 : ";cin >> somedata2;
					data.swap_index(somedata1,somedata2);
					break;
				case 11:
					cout << "Data 1 : ";cin >> somedata1;
					cout << "Data 2 : ";cin >> somedata2;
					data.swap_data(somedata1,somedata2);
					break;
				case 12:
					data.reverse_display();
					break;
				case 13:
					data.display();
					break;
			}
		}
	}
cout << endl;
system("pause");
return 0;
}
