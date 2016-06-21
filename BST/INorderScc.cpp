#include  <bits/stdc++.h>

using namespace std;

struct node{
	int data ;
	node *left,*right;
};
node *createnew(int x)
{
	node *newnode;
	newnode  = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return(newnode);
}
void insert(node **root,int x)
{
	if(*root==NULL){
		*root = createnew(x);
	}
	else if((*root)->data > x){
		insert(&((*root)->left),x);
	}
	else if((*root)->data < x){
		insert(&((*root)->right),x);
	}
}
node *findnode(node *root ,int h)
{
	node *temp = root;
	if(temp->data == h){
		return(temp);
	}
	else if(h>temp->data){
		findnode(temp->right,h);
	}
	else{
		findnode(temp->left ,h);
	}
}
node *minvalue(node *gggg)
{
	node *temp = gggg;
	while(temp->left!=NULL){
		temp =temp->left;
	}

	return(temp);
}
node *inorderSucc(node *root ,int h)
{
	/*node *temp = findnode(root,h);
	cout<<temp->data<<endl;
	if(temp->right!=NULL){
		return minvalue(temp->right);
	}*/
	node *succ=NULL;
	while(root!=NULL){
		if(h < root->data){
			succ = root;
			root = root->left;
		}
		else if(h>root->data){
			root = root->right;
		}
		else{
			if(root->right!=NULL){
				return minvalue(root->right);
			}

			break;
		}
	}
	return succ;
}
void traverse(node *root)
{
	node *temp = root;
	if(temp!=NULL){
		traverse(temp->left);
		cout<<temp->data<<" " ;
		traverse(temp->right);
	}
}

int main()
{
	struct node *root = NULL;
	int n,x;
	cout<<"Enter number of node "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		insert(&root,x);
	}
	cout<<"Inorder traversal "<<endl;
	traverse(root);
	node *succ;
	int h;
	cout<<"enter the node value for find succ"<<endl;
	cin>>h;
	succ = inorderSucc(root,h);
	if(succ!=NULL){
		cout<<"succ   :"<<succ->data<<endl;}
	else{
		cout<<"NO SUCC"<<endl;
	}
	return 0;
}

