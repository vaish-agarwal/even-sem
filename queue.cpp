#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *next;

Node(){
next= NULL;

}

};


class queue{
 public:
Node *front;
Node *end;

queue(){
front = NULL;
end= NULL;
}

//enqueue
void enqueue(int value){

if(end==NULL){
Node *temp= new Node;
temp->data=value;
end=temp;
front=temp;
}
else{
Node *temp= new Node;
temp->data= value;
temp->next=end;
end=temp;

}

}
//dequeue
void dequeue(){

if(end==NULL){

}

else if(end->next==NULL){
Node *temp= end;
end=end->next;
delete temp;
}

else{
Node *temp = front;
Node *current= end;
while(current->next!=front){
current=current->next;
} 

current->next= NULL;
front= current;
delete temp;
}
}

//is empty
bool isEmpty(){
if(end==NULL){
return true;
}
else{
return false;
}

}

//size
void size(){
if(end==NULL){
cout<<"No elements."<<endl;
}
 else{
Node *current=end;
int i=1;
while(current->next!=NULL){
i++;
current= current->next;
}
cout<<"It has "<<i<<" elements."<<endl;

}
}

//display
void display(){
if(end==NULL){
cout<<"There are no elements."<<endl;
}

else{
Node *current = end;

while(current !=NULL){
cout<<current->data<<" ->";
current=current->next;

}
cout<<endl;

}
}
};


/*
int main(){
queue q1;

for(int i=1;i<6;i++){
q1.enqueue(i);
}
 
q1.display();
q1.dequeue();
q1.display();
q1.dequeue();
q1.display();
q1.dequeue();
q1.display();
q1.dequeue();
q1.display();
q1.dequeue();
q1.display();
q1.dequeue();
q1.display();

}
*/










