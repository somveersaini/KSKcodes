#include <bits/stdc++.h>

using namespace std;

int search_k(int a[100][100],int m,int n,int x)
{
	int i=0,j=n-1;
	while(i>=0  && j<n){
		if(a[i][j]==x){
			cout<<"Found "<<i<<" " <<j<<endl;
			return 1;
		}
		if(x>a[i][j]){
			i++;
		}
		else{
			j--;
		}
	}
	cout<<"NOT FOUND"<<endl;
	return 0;
}
int main()
{
	int m,n;
	cin>>m>>n;
	int a[100][100];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int x;
	cin>>x;
	search_k(a,m,n,x);

	return 0;
}
