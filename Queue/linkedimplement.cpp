#include <bits/stdc++.h>

using namespace std;

struct Queue{
	int data;
	Queue  *next;
};
struct Queue* front =NULL;
struct Queue* rear= NULL;
void print()
{

	Queue *temp = front ;
	while(temp!=rear){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}
void EnQueue(int x)
{
	struct Queue* temp = (Queue*)malloc(sizeof(Queue));
	temp->data =x;
        temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return ;
	}
	rear->next=temp;
	rear =temp;
}
int DeQueue()
{
	Queue *temp = front;
	int x = temp->data;
	if(front == NULL){
		return 0;
	}
	if(front == rear && front!=NULL && rear !=NULL){
		front = rear = NULL;
	}
	else{
	front = front->next;
	}
	free(temp);

	return x;
}
int main()
{

	while(1){
		int choice;
		cout<<"1 : EnQueue , 2: Dequeue "<<endl;
		cin>>choice;
	switch(choice){

		case 1:
			int x;
			cout<<"Enter DATA "<<endl;
			cin>>x;
			EnQueue(x);
			print();
			break;
		case 2: 
			int p = DeQueue();
			cout<<"DeQueue Element :"<<p<<endl;
			if(front==rear->next){
				cout<<"No element "<<endl;
			}
			else{
			print();
			}
			break;
		}
	}

	return 0;
}	

