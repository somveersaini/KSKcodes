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
void Mirror(struct node* root)
{
	if(root==NULL){
		return;
	}
	
 	Mirror(root->left);
	Mirror(root->right);
	
	struct node* temp ;
	temp = root->left;
	root->left= root->right;
	root->right = temp;	
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
	int count = 0;
	INORDER(root);
	cout<<"\n";
	Mirror(root);
	INORDER(root);
	cout<<"\n";
	
	return 0;
}

	
		
