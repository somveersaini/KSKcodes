#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum;
	cout<<"Enter the value of sum "<<endl;
	cin>>sum;
	int l=0;
	int r=n-1;
	sort(a,a+n);
	while(l<n){
		if(a[l]+a[r]==sum && a[l]!=a[r]){
			cout<<a[l]<<" "<<a[r]<<endl;
			break;
		}
		else if(a[l]+a[r]<sum){
			l++;
		}
		else {
			r--;
		}
	}
	return 0;
}

