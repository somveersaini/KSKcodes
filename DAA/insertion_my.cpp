#include <bits/stdc++.h>

using namespace std;

void print(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		}
	cout<<"\n";
}
void selection(int a[],int n)
{
	for(int i=1;i<n;i++){
		int insert_value = a[i];
		int position = i;
		
		while(position > 0 && a[position -1]  > insert_value ){
				a[position] = a[position-1];
				position = position-1;
				print(a,n);
				}
		a[position] = insert_value;
		print(a,n);
	}
}
int main()
{
	int n;
	cout<<"Enter no of element "<<endl;
	cin>>n;
	
	int a[n+1];
	
	cout<<"Enter element of array "<<endl;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	selection(a,n);
	cout<<"After sorting Array "<<endl;
	print(a,n);
	return 0;
}
