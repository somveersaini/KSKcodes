#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->left  = NULL;
	temp->right = NULL;

	return temp;
}
void INORDER(struct node* root)
{
	if(root==NULL){
		return ;
	}
	INORDER(root->left);
	cout<<root->data<<" ";
	INORDER(root->right);
}
void PREORDER(struct node* root)
{
	if(root==NULL){
		return ;
	}
	cout<<root->data<<" ";
	PREORDER(root->left);
	PREORDER(root->right);
}
void POSTORDER(struct node* root)
{
	if(root==NULL){
		return ;
	}
	POSTORDER(root->left);
	POSTORDER(root->right);
	cout<<root->data<<" ";
}
int main()
{
	struct node* root = newNode(1);
	root->left  = newNode(3);
	root->left->left  = newNode(5);
	root->left->left->left  = newNode(4);
	root->left->right  = newNode(6);
	root->right = newNode(1);
	root->right->left = newNode(7);
	root->right->right = newNode(9);

	INORDER(root);
	cout<<"\n";
	PREORDER(root);
	cout<<"\n";
	POSTORDER(root);
	cout<<"\n";

	return 0;
}

	
		
