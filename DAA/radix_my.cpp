#include <bits/stdc++.h>

using namespace std;

void print(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		}
	cout<<"\n";
}
void count_sort(int a[],int n,int exp)
{
	int C[10];
	for(int i=0;i<10;i++){
			C[i]=0;
			}
	for(int i=0;i<n;i++){
		C[(a[i]/exp)%10]++;
		}
		//print(C,range+1);
	for(int i=1;i<10;i++){
		C[i] = C[i-1]+C[i];
		}
		//print(C,range+1);
		int b[n+1];
	for(int i=n-1;i>=0;i--){
		b[C[(a[i]/exp)%10]-1] = a[i];
		
		C[(a[i]/exp)%10] = C[(a[i]/exp)%10] - 1;
		}
	for(int i=0;i<n;i++){
			a[i] =  b[i];
			}
		print(a,n);
}
void radix_sort(int a[],int n)
{
		int m  =  a[0]; 
    for(int i=1;i<n;i++){
     		if(a[i]>m){
     			m = a[i];
     			}
     		}
     	//cout<<m<<endl;
     for(int exp=1;m/exp>0;exp*=10){
			count_sort(a,n,exp);
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
	radix_sort(a,n);
	print(a,n);	
	return 0;
}
