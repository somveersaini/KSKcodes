#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *left,*right;
};
void findElement(node *root,int x)
{
	node *temp=root;
	if(temp==NULL){
		cout<<"data not found"<<endl;
		return ;
	}
	else if(x < (temp->data)){
		findElement(root->left,x);
	}
	else if(x>(temp->data)){
		findElement(root->right,x);
	}
	else{
		cout<<"data found"<<" "<<endl;
	}
	return ;
}

//inorder traversel
void traverse(node *root)
{
	node *temp = root; 
	if(temp!=NULL){
		traverse(temp->left);
		cout<<temp->data<<" ";
		traverse(temp->right);
	}
}
node* createNode(int x)
{
	node *newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data=x;
	newNode->left=NULL;
	newNode->right=NULL;
	return(newNode);
}
void insertion(node **root,int x)
{
	if(*root==NULL){
		*root = createNode(x);
	}
	else if(x<((*root)->data)){
		insertion(&((*root)->left),x);
	}
	else if(x>((*root)->data)){
		insertion(&((*root)->right),x);
	}
}
int main()
{
	struct node *root=NULL;
	int n,x;
	int choice;
	while(1){
		cout<<"1: insertion 2:traversal 3:search 4: deletion 5: exit"<<endl;
		cout<<"Enter your choice "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"How many elements are in the tree"<<endl;
				cin>>n;
				for(int i=0;i<n;i++){
				cin>>x;
				insertion(&root,x);
				}
				break;
			case 2:
				traverse(root);
				break;
			case 3:
				cout<<"Enter the element to be found"<<endl;
				cin>>x;
				findElement(root,x);
				break;
			case 4:
	
			case 5:
				exit(0);
			default:
				cout<<"Wrong option";
				break;
		}
	}
	return 0;
}
