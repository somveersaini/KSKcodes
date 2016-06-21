#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node *next;
};
struct node *push(node *head,int item,node *top)
{
	if(top==NULL){
	top = (node*)malloc(sizeof(node));
	top->next = NULL;
	top->data=item;
	}
	else{
	node *temp = (node*)malloc(sizeof(node));
	temp->next = top;
	temp->data = item;
	top = temp;
	}
	head = top;
	return head; 
}
void display(node *head)
{
	node *temp1 =  head;
	while(temp1!=NULL){
		cout<<temp1->data<<" ";
		temp1=temp1->next;
	}
	cout<<endl;
}
int main()
{
	int item,choice;
	node *head = NULL;
	node **top = head;
	while(1){
		cout<<"1: push 1:pop"<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the item to be pushed"<<endl;
				cin>>item;
				push(head,item,&top);
				display(head);
				break;
			//case 2:
			//	pop(head,top);
			//	break;
		}
	}
	return 0;
}
