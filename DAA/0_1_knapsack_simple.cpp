#include <bits/stdc++.h>

using namespace std;

int max(int a,int b)
{
	if(a>b){
		return a;
	}
	else {
		return b;
	}
}
int knapsack(int WW,int wt[],int val[],int n)
{
	if(n==0||WW==0){
		return 0;
	}
	if(wt[n-1]>WW){
		return knapsack(WW,wt,val,n-1);
	}
	else {
		
		return max(val[n-1]+knapsack(WW-wt[n-1],wt,val,n-1),knapsack(WW,wt,val,n-1));
	}
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
