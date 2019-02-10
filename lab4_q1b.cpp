#include<iostream>
#include"a.cpp"

using namespace std;


class stack{
public:
LinkedList l1;

//declare top;
Node *top;

//default cons
stack(){
top = l1.head;
}

//push
void push(int value){
l1.insertAt(1,value);

//top=new head
top=l1.head;
}


//pop
void pop(){
l1.deletAt(1);

//top=new head
top=l1.head;
}


//empty or not
bool isEmpty(){
if (top== NULL)return true;
return false;
}

//size
void size(){
l1.countItems();
}

//display
void display(){
l1.display();
}

};


int main(){
stack s1;

for(int i=1;i<5;i++){
s1.push(i);
}
s1.display();
s1.pop();
s1.display();
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
