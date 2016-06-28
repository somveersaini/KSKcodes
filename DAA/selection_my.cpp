#include <bits/stdc++.h>

using namespace std;

void print(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		}
	cout<<"\n";
} 
// selection sort never take more than o(n) swaps
void selection_sort(int a[],int n)
{
	int t=n;
	int k=0;
	while(t--){
		int min=INT_MAX;
		int p;
		for(int i=k;i<n;i++){//finding minimum element in the array 
			if(a[i]<min){
				p=i;
				min=a[i];
				}
			}
		swap(a[k],a[p]);//swap minimum element with it's correct index element
		print(a,n);//upto k index array is sorted  and after k is unsorted array
		k++;
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
	clock_t t1  = clock();//starting time 
	selection_sort(a,n);
	clock_t t2 = clock();//ending time
	
	float time = (float)(t2-t1)/CLOCKS_PER_SEC;
	cout<<time<<"seconds"<<endl;
	return 0;
}
