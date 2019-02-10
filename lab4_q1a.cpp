#include<iostream>
#include"a.cpp"
using namespace std;
 
class queue{
public:
LinkedList l1;

//declare end and front
Node *end;
Node *front; 

//default cons
queue(){
end=l1.head;// NULL 
front= l1.tail;
}

//enqueue
void Enqueue(int value){

l1.insertAt(1,value);


//end=new head
end= l1.head;

}

//dequeue
void Dequeue(){

l1.delet();

//front=new tail
front=l1.tail;
}

//empty or not
bool isEmpty(){
if (end== NULL) return true;
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
queue a1;


for(int i=1;i<3;i++)
a1.Enqueue(i);

a1.display();

//a1.isEmpty();

a1.Dequeue();
a1.display();





a1. size();


}
