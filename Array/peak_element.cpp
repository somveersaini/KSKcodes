#include <bits/stdc++.h>

using namespace std;

int peak_element(int a[],int n)
{
	for(int i=0;i<n;i++){
		if(i==0 && a[0]>a[1]){
		       return 0;
		}
		else if(i==n-1 && a[n-1]>a[n-2]){
			return 	n-1;
		}
		else {
			if(a[i]>a[i-1] && a[i]>a[i+1]){
				return i;
			}
		}
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
	int k = peak_element(a,n);
	cout<<k<<endl;

	return 0;
}
