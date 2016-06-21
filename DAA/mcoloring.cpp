#include <bits/stdc++.h>

using namespace std;

void print(int x[],int n)
{
	for(int k=0;k<n;k++){
		cout<<x[k]<<" " ;
	}
	cout<<"\n";
}
bool IsSafe(int graph[][100],int k,int n,int m,int c,int x[])
{
	for(int i=0;i<n;i++){
		if(graph[k][i]==1 && c == x[i]){
			return false;
		}
	}
	return true ;
}
void graphcolor(int graph[][100],int k,int n,int m,int x[])
{
	//cout<<k<<endl;
	for(int c=1;c<=m;c++){
		if(IsSafe(graph,k,n,m,c,x) == true){
			x[k] = c;
			if((k+1) < n){
				graphcolor(graph,k+1,n,m,x);
			}
			else {
				print(x,n);
				return;
			}
		}
	}
}
int main()
{
	int n;
	cout<<"number of nodes "<<endl;
	cin>>n;
	int graph[100][100];
	cout<<"Enter adjacency matrix "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	int m;
	cout<<"How many colors "<<endl;
	cin>>m;
	int x[n+1];
	for(int i=0;i<n;i++){
		x[i]=0;
	}
	graphcolor(graph,0,n,m,x);

	return 0;
}
