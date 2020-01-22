#include <iostream>
using namespace std;
// Written at 25/3/2018

//////Needed to be included :
//[01]Add_last(int x)              (Done)
//[02]Add_first(int x)             (Done)
//[03]Add_Position(data,index)     (Done)
//[04]Search_index(index)          (Done)
//[05]Search_data(data)            (Done)
//[06]Delete_data(data)			   (Done)
//[07]Delete_index(index)          (Done)
//[08]replace_data(data,data)      (Done)
//[09]replace_index(index,data)    (Done)
//[10]swap_data(data,data)         (Done)
//[11]swap_index(index,index)      (Done)
//[12]reversed_display()           (Done)

struct node{
	int data;
	node*next;
	node*prev;
};

class DLinkedList{
	node *head,*tail;
	int total_size;
	public:
		DLinkedList(){
			head=NULL;
			tail=NULL;
			total_size = 0;
		}

		void NewNode(int x){
			node*temp = new node;
			temp->data=x;
			temp->prev=NULL;
			temp->next=NULL;
			head=temp;
			tail=temp;
			total_size++;
		}

		void AddFirst(int x){
			if(head==NULL) NewNode(x);
			else{
				node*P=new node;
				head->prev = P;
				P->data=x;
				P->next=head;
				P->prev=NULL;
				head=P;
				total_size++;
			}
		}

		void AddLast(int x){
			if(head==NULL) NewNode(x);
			else{
				node*P=new node;
				tail->next = P;
				P->data=x;
				P->prev=tail;
				P->next=NULL;
				tail=P;
				total_size++;
			}
		}

		void Add_Position(int data,int index){
			if(index==0) AddFirst(data);
			else if(head==NULL) cout << "List is empty so can't add to this index!\n";
			else{
				if(index <= total_size && index >=0){
					node*temp,*previous;
					temp=head;
					if(index==0) AddFirst(data);
					for(int n=0;index!=n;n++) temp = temp ->next;
					previous = temp ->prev;
					node*P=new node;
					P->data=data;
					P->next=temp;
					P->prev=previous;
					previous->next=P;
					temp->prev=P;
					total_size++;
				}
				else{
					cout << "\nError in index!!\n";
				}
			}
		}

		void Search_index(int index) {
			if(head==NULL) cout << "List is empty so can't find this element!\n";
			else if(index <total_size && index >=0){
				node*temp =head;
				for(int n=0;index!=n;n++) temp = temp ->next;
				cout << "\nData at index "<<index<<" is "<<temp->data<<endl;
			}
			else cout << "\nError in index!\n";
		}

		void Search_data(int data) {
			if(head==NULL) cout << "List is empty so can't find this element!\n";
			else {
				node*temp=head;
				int index=0;
				bool found=false;
				for(int n=0;n!=total_size;n++){
					if(data==temp->data){
						found=true;
						break;
					}
					else{
						temp = temp ->next;
						index++;
					}
				}
				if(found) cout << "\nData "<<data<<" is at index "<<index<<endl;
				else cout << "\nDidn't find this data ("<<data<<")!";
			}
		}

		void Delete_data(int data){
			if(head==NULL) cout << "List is empty so can't find this element!\n";
			else {
				node* temp = head ,*previous;
				bool found = false;
				if(data==head->data) {
					head = head->next;
					head ->prev=NULL;
					total_size--;
				}
				else if(data==tail->data) {
					tail = tail->prev;
					temp->next=NULL;
					total_size--;
				}
				else{
					for(int n=0;n<total_size;n++){
						if(data==temp->data){
							found = true;
							total_size--;
							break;
						}
						else{
							previous=temp;
							temp = temp ->next;
						}
					}
					if(found) {
						previous->next = temp->next;
						temp->prev = previous;
					}
					else cout << "\nDidn't find this data ("<<data<<")!";
				}
			}
		}

		void Delete_index(int index){
			if(head==NULL) cout << "List is empty so can't find this element!\n";
			else{
				if(index <= total_size && index >=0){
					node*temp = head,*previous;
					if(index==0){
						head = head->next;
						head ->prev=NULL;
						total_size--;
					}
					else if(index==(total_size-1)) {
						tail = tail->prev;
						temp->next=NULL;
						total_size--;
				}
					else{
						for(int n=0;index!=n;n++){
							previous = temp;
							temp = temp ->next;
						}
						previous->next = temp->next;
						temp->prev = previous;
						total_size--;
					}
				}
				else{
					cout << "\nNot found!\n";
				}
			}
		}

		void replace_data(int data1,int data2){
			if(head==NULL) cout << "List is empty so can't find this element!\n";
			else{
				node*temp =head;
				bool found=true;
				while(data1!=temp->data){
					temp = temp ->next;
					if(temp==NULL){
						found=false;
						break;
					}
				}
				if(found) temp ->data = data2;
				else cout << "\nNot found!\n";
			}
		}

		void replace_index(int index,int data){
			if(head==NULL) cout << "List is empty so can't find this element!\n";
			else{
				if(index <= total_size && index >0){
					node*temp =head;
					for(int n=0;index!=n;n++) temp = temp ->next;
					temp ->data=data;
				}
				else cout << "\nNot found!\n";
			}
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
				if(index1 <= total_size && index1 >0){
					node*temp1 =head,*temp2;
					for(int n=0;index1!=n;n++){
						temp1 = temp1 ->next;
						if(index2==n) temp2 = temp1;
					}
					if(index2 <= total_size && index2 >0){
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
				node*temp;
				temp=tail;
				cout << "\n-> ";
				while(temp!=NULL){
					cout << temp->data << " ";
					temp = temp->prev;
				}
			}

		void display(){
				node*temp;
				temp=head;
				cout << "\n-> ";
				while(temp!=NULL){
					cout << temp->data <<" ";
					temp = temp->next;
				}
			}

};

int main(){
	DLinkedList data;
	int somedata1,somedata2;
	int looper = 0,choice;
	cout << "\n                     -------------------------";
	cout << "\n                Say hi to the Double linkedlist program :D\n\n";
	cout << "(1)AddLast(int x)                       ||Make an element the last one\n";
	cout << "(2)AddFirst(int x)                      ||Make an element the first one\n";
	cout << "(3)reverse_display()                    ||Display the current list nodes data reversed\n";
	cout << "(4)display()                            ||Display the current list nodes data\n";
	cout << "(5)Add_Position(int data,int index)     ||Add an element at a specific index\n";
	cout << "(6)Search_index(int index)              ||Grabing an element data by it's index\n";
	cout << "(7)Search_data(int data)                ||Grabing an element index by it's data\n";
	cout << "(8)Delete_data(int data)                ||Deleting an element by it's data\n";
	cout << "(9)Delete_index(int index)              ||Deleting an element by it's index\n";
	cout << "(10)replace_data(int data1,int data2)   ||Replacing an element data with another data by data\n";
	cout << "(11)replace_index(int index,int data)   ||Replacing an element data with another data by index\n";
	cout << "(12)swap_index(int index1,int index2)   ||Swaping two elements data by their indexes\n";
	cout << "(13)swap_data(int data1,int data2)      ||Swaping two elements data by their data\n";
	cout << "(0)exit\n";
	while(looper==0){
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
					data.reverse_display();
					break;
				case 4:
					data.display();
					break;
				case 5:
					cout << "Data : ";cin >> somedata1;
					cout << "index : ";cin >> somedata2;
					data.Add_Position(somedata1,somedata2);
					break;
				case 6:
					cout << "Index to search : ";cin >> somedata1;
					data.Search_index(somedata1);
					break;
				case 7:
					cout << "Data to search : ";cin >> somedata1;
					data.Search_data(somedata1);
					break;
				case 8:
					cout << "Data to delete : ";cin >> somedata1;
					data.Delete_data(somedata1);
					break;
				case 9:
					cout << "Index to delete : ";cin >> somedata1;
					data.Delete_index(somedata1);
					break;
				case 10:
					cout << "Data 1 : ";cin >> somedata1;
					cout << "Data 2 : ";cin >> somedata2;
					data.replace_data(somedata1,somedata2);
					break;
				case 11:
					cout << "Index : ";cin >> somedata1;
					cout << "Data : ";cin >> somedata2;
					data.replace_index(somedata1,somedata2);
					break;
				case 12:
					cout << "Index 1 : ";cin >> somedata1;
					cout << "Index 2 : ";cin >> somedata2;
					data.swap_index(somedata1,somedata2);
					break;
				case 13:
					cout << "Data 1 : ";cin >> somedata1;
					cout << "Data 2 : ";cin >> somedata2;
					data.swap_data(somedata1,somedata2);
					break;
			}
		}
	}

cout << endl;
system("pause");
return 0;}
