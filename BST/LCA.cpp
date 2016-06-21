#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node *left,*right;

};

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

node *LCA(node *root ,int n1,int n2)
{
	if(root==NULL){
		return NULL;
	}
	if(root->data >n1 && root->data > n2){
		return LCA(root->left , n1,n2);
	}
	if(root->data <n1 && root->data < n2){
		return LCA(root->right ,n1,n2);
	}

	return root;
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
	int n1,n2;
	cout<<"Enter the value n1 : n2 : "<<endl;
	cin>>n1>>n2;
	node *temp = LCA(root,n1,n2);
	cout<<temp->data<<endl;
	return 0;
}

