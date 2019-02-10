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


class stack{
 public:
Node *top;

stack(){
top = NULL;
}

//push
void push(int value){
Node *temp= new Node;
temp->data=value;
temp->next=top;
top=temp;

}

//pop
void pop(){

if(top==NULL){

}

else{
Node *temp=top;
top=top->next;
delete temp;
}
}

//is empty
bool isEmpty(){
if(top==NULL){
return true;
}
else{
return false;
}

}

//size
void size(){
if(top==NULL){
cout<<"No elements."<<endl;
}
 else{
Node *current=top;
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
if(top==NULL){
cout<<"There are no elements."<<endl;
}

else{
Node *current = top;

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
stack s1;

for(int i=1;i<6;i++){
s1.push(i);
}

s1.display();

s1.pop();
s1.display();
s1.isEmpty();
s1.pop();
s1.display();
s1.size();
s1.pop();
s1.display();
s1.pop();
s1.display();
s1.pop();
s1.display();
s1.pop();
s1.display();
s1.size();
s1.isEmpty();
}

*/









