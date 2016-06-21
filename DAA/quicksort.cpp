#include <bits/stdc++.h>

using namespace std;

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
} 
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int  partition(int a[],int low,int high)
{
	int pivot = a[high];
	int i = low-1;
	for(int j=low;j<high;j++){
		if(a[j]<=pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
}

void quicksort(int a[],int low,int high)
{
	if(low<high){
		int k = partition(a,low,high);
		
		quicksort(a,low,k-1);
		quicksort(a,k+1,high);
	}
}	
int main()
{
	int n;
	cout<<"How many number do you want "<<endl;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	printArray(a,n);
	return 0;
}
