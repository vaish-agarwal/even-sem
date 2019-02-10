#include<iostream>
using namespace std;
class stackArr{
private:
int arr[30];
int *top;

public:
stackArr(){
top=NULL;

}
 
void push(int value){
if(top== arr+30)
cout<<"stackArr is full."<<endl;

else{
	if (top==NULL){
	top=arr;
	*top=value;
	}

	else{
	top++;
	*top=value;
	}

}
}

int pop(){
int a;
if(top==NULL){
cout<<"There are no elements."<<endl;
}
else{
	if(top==arr){
	a=*top;
	top=NULL;
	}

	else{
	a= *top;
	top--;
	}
}
return a;
}


bool isEmpty(){
if (top==NULL)
return true;
else
return false;
}

int size(){
return top- arr +1;
}

void display(){
if(top==NULL){
cout<<"There are no elements."<<endl;
}
else{
	for(int i=0;i<size();i++){
	cout<<*(top-i);
	}
}
cout<<endl;
}


};




int main(){
stackArr s1;
for(int i=1;i<6;i++){
s1.push(i);
}
s1.display();

cout<<s1.pop()<<endl;
s1.display();
s1.isEmpty();

}
