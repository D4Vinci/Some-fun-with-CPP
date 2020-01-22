#include <iostream>
using namespace std;
// Written at 7/12/2018

struct node{
	int data;
	node*right; //A node that has data bigger than this one
	node*left; //A node that has data smaller than this one
};

class Tree{
	private:
		int total_size;
		node*root;
		node* make_this_node(int data){
			node*temp = new node;
			temp->data  = data;
			temp->right = temp->left = NULL;
			return temp;
		}
		void Inorder(node* our_node){ //left -> root -> right
			if(our_node->left!=NULL) Inorder(our_node->left);
			cout << our_node->data << " ";
			if(our_node->right!=NULL) Inorder(our_node->right);
		}

		void Preorder(node* our_node){ //root -> left-> right
			cout << our_node->data << " ";
			if(our_node->left!=NULL) Preorder(our_node->left);
			if(our_node->right!=NULL) Preorder(our_node->right);
		}

		void Postorder(node* our_node){ //left -> right -> root
			if(our_node->left!=NULL) Postorder(our_node->left);
			if(our_node->right!=NULL) Postorder(our_node->right);
			cout << our_node->data << " ";
		}

	public:
		Tree(){
			total_size = 0;
			root = new node;
		}

		void insert(int data){
			node*new_node = make_this_node(data);
			node*pointer = root;
			while(true){
				if( data>(pointer->data) ){ //Then let's go right
					if( (pointer->right)==NULL){
						pointer->right = new_node;
						//total_size++;
						break;
					}
					else {
						pointer = pointer->right;
						continue;
					}
				}
				else if( data<(pointer->data) ){ //Then let's go left
					if( (pointer->left)==NULL){
						pointer->left = new_node;
						//total_size++;
						break;
					}
					else{ 
						pointer = pointer->left;
						continue;
					}
				}
				else if(data==(pointer->data)){ //Then someone is trying to repeat nodes :D
					total_size--;
					break;
				}
			}
		}

		void initialize_tree(int arr[],int length){
			//node*temp = new node;
			total_size = length;
			root->data = arr[0];
			root->right = root->left = NULL;
			//root = temp;
			for(int i=1;i<length;i++) insert(arr[i]);
			cout << "\nTree Initialized :D"<<endl;
		}

		bool exists(int data){
			node*pointer = root;
			if(data==(pointer->data)) return 1;
			while(1){
				if( data>(pointer->data) ){ //Then let's go right
					if( (pointer->right)==NULL) return 0;
					else {
						pointer = pointer->right;
						if(data==(pointer->data)) return 1;
						continue;
					}
				}
				else if( data<(pointer->data) ){ //Then let's go left
					if( (pointer->left)==NULL) return 0;
					else{ 
						pointer = pointer->left;
						if(data==(pointer->data)) return 1;
						continue;
					}
				}
			}
		}

		int Size(){
			return total_size;
		}

		bool empty(){
			if(total_size==0) return 1;
			else return 0;
		}

		void print(){
			cout << "In-Order :";
			Inorder(root);
			cout << endl << endl;

			cout << "Pre-Order :";
			Preorder(root);
			cout << endl << endl;

			cout << "Post-Order :";
			Postorder(root);
			cout << endl << endl;
		}

		node* delete_this_node(node* pointer,int data){
			if(pointer==NULL) return pointer;//NULL
			else if (data > pointer->data) pointer->right = delete_this_node(pointer->right,data); //In case the right side is changed
			else if (data < pointer->data) pointer->left = delete_this_node(pointer->left,data); //In case the left side is changed
			else { //data==pointer->data
				//In case this is a leaf or the tree is empty
				if ( pointer->right==NULL && pointer->left==NULL){
					delete pointer;
					pointer = NULL;
					cout << "[+] Node deleted successfully! :D\n";
					total_size--;
				}

				//-----------------------------------
				//It can have only left side
				else if(pointer->right==NULL){
					node*temp = pointer; //To clear the memory after reconnecting
					pointer = pointer->left;
					delete temp;
					cout << "[+] Node deleted successfully! :D\n";
					total_size--;
				}

				//It can have only right side
				else if(pointer->left==NULL){
					node*temp = pointer; //To clear the memory after reconnecting
					pointer = pointer->right;
					delete temp;
					cout << "[+] Node deleted successfully! :D\n";
					total_size--;
				}

				//-----------------------------------
				//Now it have right and left
				else{
					//So we try to find the smallest of the largest (The smallest node of the right side)
					node*smallest  = pointer->right;
					//Now find the most left node
					while( smallest->left!=NULL ) smallest = smallest->left;
					cout << "The smallest is "<<smallest->data<<endl;
					pointer->data  = smallest->data;
					pointer->right = delete_this_node(pointer->right,smallest->data); 
					//Notice that we pass only the right side not the whole tree :D
					cout << "[+] Node deleted successfully! :D\n";
					total_size--;
				}
				return pointer; 
			}
		}

		void Delete(int data){
			delete_this_node(root,data);
		}  
};

void main(){
	Tree our_tree;
	int length;
	cout << "Enter number of the elements you will enter: ";cin >> length;
	int*arr = new int[length];
	for(int x=0;x<length;x++){
		cout << "\nEnter element value: ";cin >> arr[x];
	}
	our_tree.initialize_tree(arr,length);
	int somedata1,somedata2;
	int looper = 0;
	while(looper==0){
		int choice;
		cout << "               -------------------------";
		cout << "\n          Choose a function\n";
		cout << "(01)Size  (02)Insert  (03)Is_exists  (04)Is_empty\n";
		cout << "(05)Print (06)Delete  \n";
		cout << "                  (0)exit\n";
		cout << "\nYour choice : ";cin >> choice;
		if(choice >6 || choice <0) continue;
		else{
			switch(choice){
				default:
					looper=1;
					break;
				case 1:
					cout << "Size : "<<our_tree.Size()<<endl;
					break;
				case 2:
					cout << "Integer to insert : ";cin >> somedata1;
					our_tree.insert(somedata1);
					break;
				case 3:
					cout << "Integer to check : ";cin >> somedata1;
					if(our_tree.exists(somedata1)) cout << "Element exist"<<endl;
					else cout << "Element not exist"<<endl;
					break;
				case 4:
					if(our_tree.empty()) cout << "Tree is empty"<<endl;
					else cout << "Tree is not empty"<<endl;
					break;
				case 5:
					our_tree.print();
					break;
				case 6:
					cout << "Integer to delete : ";cin >> somedata1;
					our_tree.Delete(somedata1);
					break;
			}
		}
	}
cout << endl;
system("pause");}