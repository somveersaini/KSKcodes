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
int IDENTICAL(struct node* root,struct node* root1)
{
	if(root==NULL  && root1==NULL){
		return 1;
	}
	if(root!=NULL && root!=NULL){
		return ((root->data == root1->data) && IDENTICAL(root->left,root1->left) && IDENTICAL(root->right,root1->right));
	}
	else{
		return 0;
	}
		
}
int main()
{
	struct node* root = newNode(1);
	root->left  = newNode(3);
	root->left->left  = newNode(5);
	root->left->left->left  = newNode(4);
	root->left->right  = newNode(6);
	root->right = newNode(10);
	root->right->left = newNode(7);
	root->right->right = newNode(9);
	
	struct node* root1 = newNode(1);
	root1->left  = newNode(3);
	root1->left->left  = newNode(5);
	root1->left->left->left  = newNode(4);
	root1->left->right  = newNode(6);
	root1->right = newNode(1);
	root1->right->left = newNode(7);
	root1->right->right = newNode(9);
		
	int count = 0;
       	int h = IDENTICAL(root,root1);
	cout<<h<<"\n";
	
	return 0;
}

	
		
