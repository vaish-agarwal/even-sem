#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *left;
Node *right;

Node(int value){
data = value;
left = NULL;
right = NULL;
}
};


class Bist{
public:
Node *root;

Bist(){
 root = NULL;
}

void insert(int value){
insertHelper(root,  value);
}

void insertHelper(Node *curr,int value){

	//base case i.e current= NULL;
	if(curr ==NULL){
	curr= new Node(value);
	if(root==NULL)root=curr;
	}

	//else compare 
	else{
		//if curr<value then RIGHT
		if(curr->data<value){
			if(curr->right==NULL){
			Node *temp=new Node(value);
			curr->right= temp;
			}
			else{
			insertHelper(curr->right,value);
			}
		}
		//else LEFT
		else if(curr->data>value){
			if(curr->left==NULL){
			Node *temp=new Node(value);
			curr->left= temp;
			}
			else{
			insertHelper(curr->left,value);
			}
		}
	}
}
void display(){
display1(root);
}


void display1(Node *curr){
//base condition
if(curr== NULL)return;


//display L
display1(curr->left);

//display curr
cout<<curr->data<<" , ";

//display R
display1(curr->right);

}

Node * search(int value){
return search1(root, value);
}



Node * search1(Node*curr ,int value){
if (curr==NULL || curr->data==value)return curr;
else if(value<curr->data)return search1(curr->left,value);
else return search1(curr->right,value);
}



//minimum
Node *findmin(int value){
fm(search(value));
}


Node *fm(Node *curr){
if(curr->>left==NULL){
return curr;
}
else fn(curr->left);
}



//replace at parent

void replace_at_parent(int value){
//if value doenot exist in tree
Node *curr=search (value);
Node *temp=curr->parent;

	if (temp->left==NULL && temp->parent->right==temp){
	//replace right to parent
	curr->parent=temp->parent;
	temp->parent->right=curr;
	delete temp;
	}

	else if(temp->left==NULL && temp->parent->left==temp){
	curr->parent=temp->parent;
	temp->parent->left=curr;
	delete temp;
	}

	else if(temp->right==NULL && temp->parent->right==temp){
	curr->parent=temp->parent;
	temp->parent->right=curr;
	delete temp;
	}
}

void delet(int value){
		//delete leaf
		Node*curr=Search(value);
		if(curr==NULL){cout<<"given value doesn't exist in tree"<<endl;}
		else{
			if(curr->left==NULL and curr->right==NULL){
				if(curr->parent->left==curr){
					curr->parent->left=NULL;			
					delete curr;
				}
				else{curr->parent->right=NULL;delete curr;}
			}	
			
			//delete two child node
			//three stage 1.find the delere one node by search
			//2.find smallest elemnt right side of element
			//3.replace with this one (basically we replace it)
			else if(curr->left!=NULL and curr->right!=NULL){
				Node*temp=findmin(curr->right->data);
				curr->data=temp->data;
					//delete temp;
			//we can not directly delete temp because it may have more children
			//that's sure that if it have children then they must be right side
			//now repalace with parent but with two cases..............
				if(temp->right==NULL){
					//means it have no children
					if(temp->parent->left==temp){temp->parent->left=NULL;delete temp;}
					else{temp->parent->right=NULL;delete temp;}
				}
				//else it have childrens
				else{
					if(temp->parent->right==temp){
						//replace right child to parent
						temp->right->parent=temp->parent;
						temp->parent->right=temp->right;
						delete temp;
					}
					else{
						temp->right->parent=temp->parent;
						temp->parent->left=temp->right;
						delete temp;
					}
				}		
			}
			else{
			//delete one child node
			//same as replace at parent
				if(curr->left==NULL and curr->parent->right==curr){
					//replace right child to parent
					curr->right->parent=curr->parent;
					curr->parent->right=curr->right;
					delete curr;
				}
				else if(curr->left==NULL and curr->parent->left==curr){
					curr->right->parent=curr->parent;
					curr->parent->left=curr->right;
					delete curr;	
				}	
				else if(curr->right==NULL and curr->parent->right==curr){
					curr->right->parent=curr->parent;
					curr->parent->right=curr->right;
					delete curr;
				}
				else if(curr->right==NULL and curr->parent->left==curr){
					curr->left->parent=curr->parent;
					curr->parent->left=curr->left;
					delete curr;
				}
			}
		}
	}




};

int main(){
Bist b1;
b1.insert(4);
b1.insert(2);
b1.insert(3);
b1.insert(1);
b1.display();

cout<<"address: "<<b1.search(3)<<endl;
cout<<"address: "<<b1.search(7)<<endl;
cout<<"address: "<<b1.search(8)<<endl;

}


