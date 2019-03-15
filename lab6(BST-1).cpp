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

/*

height();
deletNode();
*/

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
