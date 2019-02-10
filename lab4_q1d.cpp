#include<iostream>

using namespace std;

class QueueArr{

private :

int Queue[20];
int *end;
int *front;

public :

QueueArr() {
end=NULL;
front=NULL;
}
int *plusOne(int *point){
	if(point==Queue+19)
	point=Queue;
	else
	point++;
	return point;
}

void push(int in) {

	if(plusOne(end)==front)
			cout<<"Queue overflow";
	else{
		if(end==NULL){
			end=Queue;
			front=Queue;
			*end=in;
		}
		else{
			end=plusOne(end);
			*end=in;
		}
	}
}


int pop() {

	if(end==NULL){
		cout<<"Queue underflow";
		return 0;
	}
	else{
		int retu=*front;
		if(end==front){
			end=NULL;
			front=NULL;
		}
		else
			front=plusOne(front);
		return retu;
	}
}

int size() {
int *temp=front;
if(front==NULL)
return 0;
else{
int count=1;
while(temp!=end){
temp=plusOne(temp);
count++;

}
return count;
}
}

bool isEmpty(){
	if(end==NULL)
		return true;
	else
		return false;

}

void display(){
int *temp=front;
for(int i=0;i<size();i++){
cout<<" -> "<<*temp;
temp=plusOne(temp);
}
cout<<endl;
}

};










int main()
{
QueueArr s1;
cout<<s1.size()<<endl;
s1.push(4);

for(int i=1;i<6;i++)
s1.push(i);

s1.display();
cout<<s1.pop()<<endl;
s1.display();
cout<<s1.pop()<<endl;
s1.display();
cout<<s1.pop()<<endl;
s1.display();
cout<<s1.pop()<<endl;
s1.display();
}
