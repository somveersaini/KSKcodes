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
int Height(struct node* root)
{
	if(root==NULL){
		return 0;
	}
	if((Height(root->left)) >= Height(root->right)){
		return Height(root->left)+1;
		}
	else{
		return Height(root->right)+1;
		}
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
	root->right->right->right = newNode(10);
	root->right->right->right->right = newNode(11);
	int count = 0;
	int h = Height(root);
	cout<<h<<"\n";
	
	return 0;
}

	
		
