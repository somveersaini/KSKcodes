#include <bits/stdc++.h>

using namespace std;

void printArray(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		}
		cout<<endl;
}
void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
	 
void heapify(int a[],int n,int i)
{
	int largest = i;
	int l = 2*i+1;
	int  r = 2*i+2;
	if(l<n && a[l]>a[largest]){
		largest  = l;
	}
	if(r<n && a[r]>a[largest]){
		largest = r;
	}
	if(largest!=i){
		swap(&a[i],&a[largest]);
		heapify(a,n,largest);
	}
}

void heap(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(&a[0],&a[i]);
		heapify(a,i,0);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	heap(a,n);
	printArray(a,n);

	return 0;
}
