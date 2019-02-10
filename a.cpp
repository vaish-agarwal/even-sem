#include <iostream>
using namespace std;

 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(){
        next = NULL;
    }

};

class LinkedList{
    // Head + Circles inside linked with each other
    public:
    // Head -> Node type ptr
    Node * head;
    Node * tail;

    // Construct
    LinkedList(){
        head = NULL;
        tail = NULL;
    } 
    // Circles inside linked with each other
    // Rules how circles will be linked


//**********************************
    void countItems(){
	//if it is empty
	if(head==NULL){
	cout<<"There are no elements."<<endl;
	}

	else{
	//initialise counting 
	Node *current = head;
	int i=1;
	
	//count all items	
	while(current->next!=NULL){
	i++;
	current= current->next;
	}
    //display
    cout<<"Number of elements in linked list is:"<< i<<endl;

	}
    }


//**********************************


    // Insert
    void insert(int value){
       // If 1st Node is added
       Node * temp = new Node; 
       // Insert value in the node
       temp->data = value;
       // 1st Node only.
       if(head == NULL){
            head = temp;
       }
       // Any other Node only.
       else{
            tail->next = temp;
       }
       tail = temp;
    } 

    void insertAt(int pos, int value){


        // Reach the place before the pos
if(pos!=1){

//initialise counting 
	Node *current = head;
	int a=1;
	
	//count all items	
	while(current->next!=NULL){
	a++;
	current= current->next;      
        } 

if(pos>a){
cout<<"The linked list does not contain "<< a <<" elements."<<endl;
}


else{
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
        current->next = temp;

}
if(head->next==NULL)tail=head;
}  



       //************************************************************************************************** Update the code for 1st position
else{

//Create a new node
Node *temp=new Node;

//move ptr
temp->next=head;

//assign new head
head=temp;

//enter the value in new head
head-> data = value;


}
    }

    // Deletion of last element
    void delet(){

	if(head==NULL){

	}


	 else if(head->next ==NULL){
	 //store head in temp
	  Node *temp = head;

	  //make new head
	  head=head->next;

	  //delete previous head
	  delete temp;
	}


	else{
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

	//delete temp
	delete temp;
        
        // Update the code for 1st position
  }
  
  else{
if(head==NULL){

}

else{
  //store head in temp
  Node *temp = head;

  //make new head
  head=head->next;

  //delete previous head
  delete temp;
  
}
}


    }
//**************************************************

    // Display
    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout << endl;
    }

//rev display*******************************************************************************************************
	 void revDisplay1(){
	revDisplay(head);//if head is private
	}


	void revDisplay(Node *current){
	//move till last element
	    if(current == NULL)return;
	    else{
		revDisplay(current->next);
		 
		//print after calling the func
		cout<<current->data<<"->";

	    }
		
	    }

//rev linkedlist*******************************************

	void revLl1(){
	 Node *temp = head;
	 revLl(head);
	 temp->next= NULL;//IMPORTANT
	}


	void revLl(Node*current){
	//for empty ll
		if(current == NULL)return;

		//ll having 1 element and when reaches last element of ll
		else if(current->next == NULL){
		head = current;//runs for ll containing elements>= 1
		return;
		}

		//for rest
		else{
		revLl(current->next);
		(current ->next)->next = current;
		}

	}
	};

