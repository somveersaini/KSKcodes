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
void DELETETREE(struct node* root)
{
	if(root==NULL){
		return;
	}
	
 	DELETETREE(root->left);
	DELETETREE(root->right);
	cout<<root->data<<" ";
	free(root);	
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
	DELETETREE(root);
	cout<<"\n";
	
	return 0;
}

	
		
