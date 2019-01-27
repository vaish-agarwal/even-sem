#include<iostream>
using namespace std;
class Node{
public:
//enter data
int data;

//circular connectivity(next)

Node *next;

//default constructor
Node(){
next =NULL;  
}
};

class circularLl{
//defining head and tail

public:
    Node * head;
   

    // Constructor
    circularLl(){
        head = NULL;
        
    } 

//count items

 void countItems(){
	//initialize counting 
	Node *current = head;
	int i=1;
	
	//count all items	
	while(current->next!=head){
	i++;
	current= current->next;
	}
    //display
    cout<<"Number of elements in linked list is:"<< i<<endl;
    }

 
//insert

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
	      else{ // If not empty list. 
            Node * current = head;
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
        temp->next = head;
            
       
      
    } 


//inserAt

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


//delete

void delet(){
	    Node *temp;
            Node * current = head;
            while(current->next->next != head)
                current = current->next;
            temp = current->next;

        // update 
	current->next=head;        
        // delete temp
         delete temp;
    }

//deleteAt


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


//display


void display(){
        Node * current = head;
        if(current == NULL) {
            cout << " elements: 0 " << endl;
            return;
        }
        while(current->next != head){ 
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printlast element
        cout << current -> data ;
        cout << endl;
    }

};
  

int main(){
circularLl a;
a.insert(1);
a.insert(2);
a.insert(3);
a.insert(4);
a.insert(5);
a.countItems();
a.display();
a.insertAt(3,9);
a.display();
a.delet();
a.display();
a.deletAt(4);
a.display();

}
