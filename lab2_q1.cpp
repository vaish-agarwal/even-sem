#include <iostream>
using namespace std;

// Generic Programming - Ignore 

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

	//delete temp
	delete temp;
        
        // Update the code for 1st position
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
};


int main(){
    LinkedList l1;
//**************insert*********************
    l1.insert(2);
    l1.insert(77);
    l1.insert(3);
    l1.insert(5);
    l1.insert(6);
    l1.insert(9);
    l1.display();
//***************delete*********************
    l1.delet();
    l1.display();
//****************insertAt******************
    l1.insertAt(4,4);
    l1.display();
    l1.insertAt(1,1);
    l1.display();
//****************deleteAt******************
    l1.deletAt(3);
    l1.display();
    l1.deletAt(1);
    l1.display();
//****************count items***************
    l1.countItems();
    return 0;
}
