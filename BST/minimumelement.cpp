#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node *left,*right;

};

void traversal(node *root)
{
	node *temp = root;
	if(temp!=NULL){
		traversal(temp->left);
		cout<<temp->data<<" " ;
		traversal(temp->right);
	}
}
node* createnode(int x)
{
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return(newnode);
}

void insertion(node **root,int x)
{
	if(*root==NULL){
		*root =  createnode(x);
	}
	else if(x<((*root)->data)){
		insertion(&((*root)->left),x);
	}
	else if(x>((*root)->data)){
		insertion(&((*root)->right),x);
	}
}	 
int getmin(node *root)
{
	node *temp = root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return(temp->data);
}
int main()
{
	struct node *root = NULL;
	
	int n,x;
	cout<<"Enter the number of node "<<endl;
	cin>>n;
	cout<<"Enter node values "<<endl;
	for(int i=0;i<n;i++){
		cin>>x;
		insertion(&root,x);
	}
	traversal(root);
	cout<<endl;
	int min = getmin(root);
	cout<<"minimum element :"<<min<<endl;
	return 0;
}
