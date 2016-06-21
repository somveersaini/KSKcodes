#include <bits/stdc++.h>

using namespace std;

void printarray(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void swap(int *x,int *y)
{
	int temp=*x;
	*x = *y;
	*y = temp;
}
void bubblesort(int a[],int n)
{
	for(int i=0;i<n-1;i++){
		cout<<i<<"th pass "<<endl;
		for(int j=0;j<n-i-1;j++){//last i elements are already in place
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
			}
			printarray(a,n);
		}

	}
}
int main()
{
	int n;
	cout<<"Enter the value of n"<<endl;
	cin>>n;
	int a[n+1];
	cout<<"Enter the element of array"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bubblesort(a,n);
	printarray(a,n);

	return 0;
}
