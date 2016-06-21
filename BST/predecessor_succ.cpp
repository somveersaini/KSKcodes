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
void getpresucc(node *root,node*& pre,node*& suc,int p)
{
	if(root==NULL){
		return;
	}
	if(root->data ==p){
		if(root->left!=NULL){
			node *temp = root->left;
			while(temp->right!=NULL){
				temp = temp->right;
			}
			pre  = temp;
		}
		if(root->right !=NULL){
			node *temp = root->right;
			while(temp->left!=NULL){
				temp = temp->left;
			}
			suc = temp;
		}
		return;
	}
	if((root->data)>p)
	{
		suc = root;
		getpresucc(root->left , pre,suc,p);
	}
	else {
		pre = root;
		getpresucc(root->right , pre,suc,p);
	}
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
	int p;
	cout<<"Enter the element for finding pre succ:"<<endl;
	cin>>p;
	node *pre=NULL,*suc = NULL;
	getpresucc(root,pre,suc,p);
	if (pre != NULL)
		cout << "Predecessor is " << pre->data << endl;
	else
		cout << "No Predecessor";

	if (suc != NULL)
		cout << "Successor is " << suc->data<<endl;
	else
		cout << "No Successor";
	return 0;
}
