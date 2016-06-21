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
	int maj_index = 0;
	int count  =1 ;
	for(int j=1;j<n;j++){
		if(a[j] == a[maj_index]){
			count++;
		}
		else{
			count--;
		}
		if(count == 0){
			maj_index=j;
			count  = 1;
		}
	}
	count = 0;
	for(int i=0 ; i<n;i++){
		if(a[i] == a[maj_index]){
			count++;
		}
	}	
	if(count>n/2){
		cout<<a[maj_index]<<" "<<count<<endl;
	}
	else{
		cout<<"NO majority element "<<endl;
	}

	return 0;
}
