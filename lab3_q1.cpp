#include<iostream>
using namespace std;

class Node{
public:
//data
int data;

//pointer to the next and previous node
Node *next;
Node *prev;

//constructor to make both ptrs to NULL
 Node(){
 next=NULL;
 prev=NULL; 
}

};
 

class LinkedList{
public:
//head ->node type ptr
Node *head;
Node *tail;

//default constructor
 LinkedList(){
 head=NULL;
 tail=NULL;
}

//count Items
void countItems(){
	Node *current=head;
	
	int i=1;
	//run a loop till tail
	while(current->next!= NULL){
	i++;
	current=current->next;
	}
	//display result
	cout<<"The no. of items in the Linked List is :"<<i<<endl;
}


//insert
void insert(int value){
//1st Node
Node *temp = new Node;

//insert value
temp ->data= value;

//1st node
if(head == NULL){
head = temp;
}

//rest nodes
else{
tail-> next= temp;
temp->prev=tail;
}
 
tail = temp;

}

void insertAt(int pos, int value){
        // Reach the place before the pos
if(pos!=1){
        Node * current = head;
        int i =1;
        while(i < pos-1){
            i++;
            current = current->next;
        }

        // Create a node
        Node * temp = new Node;
        temp -> data = value;


        // Moving ptrs like magic ! if not head
        temp->next = current->next;
	temp->prev = current;
	temp->next->prev= temp;
        current->next = temp;
}        
 
       //************************************************************************************************** Update the code for 1st position
else{
//Create a new node
Node *temp=new Node;

//move ptr
temp->next=head;
head->prev= temp;

//assign new head
head=temp;

//enter the value in new head
head-> data = value;
}
    }

    // Deletion of last element
    void delet(){
        // store the tail in temp
        Node * temp = tail;
        // before tail has to point to null
        Node * current = head;
        while(current->next != tail){
            current = current->next;
        }
        current->next = NULL; 

        // update tail
        tail = current;
        // delete temp
         delete temp;
    }

//**********************************************
    //deletion at particular place 

    void deletAt(int a){
  if(a!=1){
        // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < a-1){
            i++;
            current = current->next;
        }

        // store the deleted node in temp
        Node * temp = current->next;

        // Moving ptrs like magic ! if not head
        current->next=temp->next;
	temp->next->prev=current;

	//delete temp
	delete temp;
        
        // Update the code for 1st position
  }
  
  else{
  //store head in temp
  Node *temp = head;

  //make new head
  head=head->next;
  head->next->prev=NULL;

  //delete previous head
  delete temp;
  }


    }



//display
void display(){
Node *current=head;
while(current!=NULL){
cout<<current->data<<"->";
current= current->next;
}
cout<<endl;
}
};


int main(){ 
LinkedList l1;
l1.insert(1);
l1.insert(2);
l1.insert(3);
l1.insert(4);
l1.insert(5);
l1.insert(6);
l1.display();
l1.insertAt(2,9);
l1.display();
l1.delet();
l1.display();
l1.deletAt(2);
l1.display();
l1.countItems();


}
