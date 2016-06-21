#include <bits/stdc++.h>

using namespace std;

int IsFull(int *top)
{
	if((*(top))>=999){
		return 1;
	}
	else{
		return 0;
	}
}
int IsEmpty(int *top)
{
	if(*(top)==-1){
		return 1;
	}
	else{
		return 0;
	}
}
void push(int a[],int item,int *top)
{
	*(top)=*(top)+1;
	a[*top] = item;
}
int pop(int a[],int *top)
{
	int item  = a[*top];
	*(top) = *(top)-1;

	return item;
}
void display(int a[],int *top)
{
	for(int i = 0 ;i<=*(top);i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int a[1000];
	int item,choice,top;
	top = -1;
	while(1){
		cout<<"1: push 2:pop "<<endl;
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Enter the item to be pushed"<<endl;
				cin>>item;
				if(IsFull(&top)){
					cout<<"stack is overflow";
				}
				else{
					push(a,item,&top);
					cout<<"top: "<<top<<endl;
					display(a,&top);
					break;
				}
			case 2:
				if(IsEmpty(&top)){
					cout<<"stack is underflow"<<endl;
				}
				else{
					item = pop(a,&top);
					display(a,&top);
					cout<<"poped element is ";
					cout<<item<<endl;
				}
		}
	}

	return 0;
}
