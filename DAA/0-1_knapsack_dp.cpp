#include <bits/stdc++.h>

using namespace std;
int knapsack(int WW ,int wt[],int val[],int n)
{
	int K[n+1][WW+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=WW;j++){
			if(i==0||j==0){
				K[i][j]=0;
			}
			else if(wt[i-1]<=j){
				K[i][j] = max(val[i-1]+K[i-1][j-wt[i-1]],K[i-1][j]);
			}
			else {
				K[i][j]=K[i-1][j];
			}
		}
	}
	return K[n][WW];
}
int main()
{
	int n;
	cout<<"Enter number of items"<<endl;
	cin>>n;
	int wt[n+1];
	int val[n+1];
	cout<<"Enter : Weight  Value "<<endl;
	for(int i=0;i<n;i++){
		cin>>wt[i]>>val[i];
	}
	int WW;
	cout<<"Enter Capacity "<<endl;
	cin>>WW;
	int k = knapsack(WW,wt,val,n);
	cout<<k<<endl;
	
	return 0;
}
