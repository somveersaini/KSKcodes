#include <bits/stdc++.h>

using namespace std;

void print(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		}
	cout<<"\n";
}
//bubble sort :- repeatedly swapping the adjacent element
void bubble_sort_optimized(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<"PASS"<<i<<endl;
		int flag=0;
		// in every pass maximum element goes right most  ........so j<n-i-1
		for(int j=0;j<n-i-1;j++){
				if(a[j]>a[j+1]){
					swap(a[j],a[j+1]);
					flag=1;
					}
				print(a,n);
			}
		if(flag==0){
			break;//if there is no  swap then no need to go next pass
			}
		}
}
/*void bubble_sort(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<"PASS"<<i<<endl;
		for(int j=0;j<n-1;j++){
				if(a[j]>a[j+1]){
					swap(a[j],a[j+1]);
					}
				print(a,n);
			}
		}
}*/
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
	//bubble_sort(a,n);
	bubble_sort_optimized(a,n);	
	cout<<"sorted Array " <<endl;
	print(a,n);
	
	return 0;
}
	
