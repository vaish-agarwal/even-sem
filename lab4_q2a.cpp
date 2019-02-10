#include<iostream>
#include"stack.cpp"

using namespace std;
class queue{
public:
stack s1;
Node * end;
Node *front;

//default constructor
queue(){
end=NULL;
front=NULL;
} 


//enqueue
void enqueue(int value){
s1.push( value);
}
//dequeue
//is empty

//size
void size(){
s1.size();

}


//display
void display(){
s1.display();
}

};
int main(){
queue q1;

for(int i=1;i<6;i++ ){
q1.enqueue(i);
}

q1.display();
q1.size();

}
