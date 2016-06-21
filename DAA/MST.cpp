#include <bits/stdc++.h>

using namespace std;

int minkey(int key[],bool mstSet[],int n)
{
	int min =INT_MAX,min_index;
	cout<<"tttt"<<endl;
	for(int v=0;v<n;v++){
		if(mstSet[v] = false && key[v]<min){
			min = key[v];
			min_index = v;
		}
	}
	return min_index;
}
int printMST(int parent[],int n,int graph[][100])
{
	cout<<"EDGE    WEIGHT "<<endl;
	for(int i=0;i<n;i++){
		cout<<parent[i]<<" " <<i<<" "<<graph[i][parent[i]]<<endl;
	}	
}
void primMST(int graph[][100],int n)
{
	int parent[n];
	int key[n];
	bool mstSet[n];

	for(int i=0;i<n;i++){
		key[i] = INT_MAX;
		mstSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	cout<<"KSt"<<endl;
	for(int count =0;count<n;count++){
		cout<<"ppp"<<endl;
		int u =minkey(key,mstSet,n);
		mstSet[u] = true ;

		for(int v=0;v<n;v++){
			if(graph[u][v] && mstSet[v] == false && graph[u][v] <key[v])
				parent[v] = u;
				key[v] = graph[u][v];
		}
	}
	printMST(parent ,n,graph);
}
int main()
{
	int n;
	cout<<"Number of vertics "<<endl;
	cin>>n;
	int graph[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	primMST(graph,n);

	return 0;
}
