#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node* next;
};

node *insert_at_begin(node *head, int x)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	temp->next = head;
	head = temp;
	return head;
}
node *insert_at_end(node *head,int x)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head = temp;
	}
	else{
		node* temp1=head;
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}	
		temp1->next=temp;
		temp->next=NULL;
	}
	return head;
}
node *insert_after_anynode(node *head,int x)
{
	int node_value;
	cout<<"ENTER THE NODE VALUE WHICH AFTER YOU WANT INSERT"<<endl;
	cin>>node_value;
	node* temp = (node*)malloc(sizeof(node));
	temp->data=x;
	node* temp1 = head;
	while(temp1->next!=NULL && temp1->data!=node_value){
		temp1=temp1->next;
	}
	if(temp1->data=node_value){
		temp->next = temp1->next;
		temp1->next=temp;
	}
	else{
		cout<<"node_value not found"<<endl;
	}
	return head;
}
node *delete_node(node *head,int x)
{
	node* temp = head;
	if(head==NULL){
		cout<<"No node to be deleted"<<endl;
	}
	else{
		node *temp2;
			if(x==head->data){
				head = head->next;
				free(temp);	
				return head;
			}
		while(temp->data!=x){
				temp2 = temp;
				temp=temp->next;
				node* temp1 = temp->next;
				temp2->next=temp1;
				free(temp);
				return head;
		}
	}
}
void reverse_linkedlist(node** head)
{
	node* first;
	node* rest;
	if(*head==NULL){
		return;
	}
	first = *head;
	rest = first->next;
	if(rest==NULL){
		return;
	}
	reverse_linkedlist(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
}
void print(node *head)
{
	node* temp1 = head;
	while(temp1 !=NULL)
	{

		cout<<temp1->data<<" ";
		temp1=temp1->next;
	}
	cout<<endl;
}
int main()
{
	node *head=NULL;
	int n,x;
	cout<<"how many number"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		int choice;
		cout<<"enter choice 1:insert begin 2:insert end 3:insert any 4:delete node 5:reverse linked list"<<endl;
		cin>>choice;

		switch(choice)	
		{
			case 1:
				cout<<"enter  the element"<<endl;
				cin>>x;
				head = insert_at_begin(head,x);
				print(head);
				break;
			case 2:
				cout<<"enter  the element"<<endl;
				cin>>x;
				head = insert_at_end(head, x);
				print(head);
				break;
			case 3:
				cout<<"enter  the element"<<endl;
				cin>>x;
				head = insert_after_anynode(head,x);
				print(head);
				break;
			case 4:
				cout<<"enter the node_value to be deleted "<<endl;
				cin>>x;
				head = delete_node(head,x);
				print(head);
				break;
			case 5:
				cout<<"reverse linked list"<<endl;
				reverse_linkedlist(&head);
				print(head);
				break;
		}	
	}
	return 0;
}
