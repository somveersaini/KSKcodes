#include <bits/stdc++.h>

using namespace std;

int stack1[100];
int top =-1;

void push(int x)
{
	top = top+1;
	stack1[top]=x;
}
int pop()
{
	int a = stack1[top];
	top = top-1;

	return a;
}
void calculatespan(int a[],int n)
{
	int s[n+1];
	push(a[0]);
	s[0] = 1;
	for(int i=1;i<n;i++){
		int element = a[i];
	       while(top!=-1 && element >= pop()){
	       		pop();
	       }
	if(top==-1){
 		s[i]=i+1;
	}
	else{
		cout<<top<<"gg"<<endl;
	s[i] = i-top;
	}	
	push(a[i]);
	}
	
	for(int h=0;h<n;h++){
		cout<<s[h]<<" ";
	}
	cout<<"\n";
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	calculatespan(a,n);

	return 0;
}
