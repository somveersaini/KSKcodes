#include <bits/stdc++.h>

using namespace std;

void print(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		}
	cout<<"\n";
}

void counting_sort(int a[],int n,int range)
{
	int C[range+1];
	for(int i=0;i<=range;i++){
			C[i]=0;
			}
	for(int i=0;i<n;i++){
		C[a[i]]++;
		}
		//print(C,range+1);
	for(int i=1;i<=range;i++){
		C[i] = C[i-1]+C[i];
		}
		//print(C,range+1);
		int b[n+1];
	for(int i=0;i<n;i++){
		b[C[a[i]]-1] = a[i];
		
		C[a[i]] = C[a[i]] - 1;
		}
	print(b,n);
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
	int range;
	cout<<"range of input :  Enter maximum input value"<<endl;
	cin>>range;
	counting_sort(a,n,range);
	//print(a,n);	
	return 0;
}
