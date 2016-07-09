#include <bits/stdc++.h>
using namespace std;

//node actually depicts an edge structure
struct node {
	int dest;
	int weight;
	node *next;
};

node *newnode(int d,int w)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->dest=d;
	temp->weight=w;
	temp->next=NULL;

	return temp;
}

node *addedge(node *p,int dest,int weight)
{
	if(p==NULL) p=newnode(dest,weight);
	else {
		node *temp=p;
		while(temp->next!=NULL) temp=temp->next;
		temp->next=newnode(dest,weight);
	}

	return p;
}

int minweight(int k[],bool m[],int v)
{
	int mn_index,mn=INT_MAX;
	for(int i=0;i<v;++i)
		if(m[i]==false && k[i]<mn)
			mn_index=i,mn=k[i];
	
	return mn_index;
}

void printMST(node *q[],int v,int par[],int k[])
{
	for(int i=1;i<v;++i) {
		/*node *temp=q[par[i]];
		while(temp!=NULL) { 
			if(temp->dest==i) break;
			temp=temp->next;
		}
		cout<<par[i]<<"->"<<i<<" : "<<temp->weight<<"\n";*/
		cout<<par[i]<<"->"<<i<<" : "<<k[i]<<"\n";
	}
}

// O(V^2) implementation 
void primMST(node *p[],int ver)
{
	int parent[ver],key[ver]; // key values to pick and store min weight edge to vertex ver
	bool mst[ver];

	for(int i=0;i<ver;++i)
		key[i]=INT_MAX,mst[i]=false;
	key[0]=0,parent[0]=-1;

	for(int i=0;i<ver-1;++i) {
		int mn=minweight(key,mst,ver);
		mst[mn]=true;

		node *temp=p[mn];
		while(temp!=NULL) {
			if(mst[temp->dest]==false && temp->weight < key[temp->dest]) {
				key[temp->dest]=temp->weight;  // update the key value for the destination vertex to the min of the weights of the edges to it 
				parent[temp->dest]=mn;
			}
			temp=temp->next;
		}
	}
	
	printMST(p,ver,parent,key);
}

int mindist(int d[],bool p[],int v)
{
	int mn_index,mndist=INT_MAX;
	for(int i=0;i<v;++i)
		if(p[i]==false && d[i]<mndist)
			mndist=d[i],mn_index=i;

	return mn_index;
}

void printstack(stack<int> &s)
{
	while(!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"\n";
}

void printSP(node *q[],int v,int s,int d[],int par[])
{
	for(int i=0;i<v;++i) {
		stack<int> path;
		path.push(i);
		int pr=par[i];
		while(pr!=s) {
			path.push(pr);
			pr=par[pr];
		}
		path.push(s);
		cout<<s<<" -> "<<i<<" : "<<d[i]<<"\t,path: ";
		printstack(path);
	}
}

void dijkstra(node *p[],int ver,int src)
{
	int parent[ver],dist[ver];
	bool sp[ver];

	for(int i=0;i<ver;++i)
		dist[i]=INT_MAX,sp[i]=false;
	dist[src]=0,parent[src]=src;
	
	for(int i=0;i<ver-1;++i) {
		int mn=mindist(dist,sp,ver);
		sp[mn]=true;

		node *temp=p[mn];
		while(temp!=NULL) {
			if(sp[temp->dest]==false && dist[mn]+temp->weight < dist[temp->dest]) {
				dist[temp->dest]=dist[mn]+temp->weight;
				parent[temp->dest]=mn;
			}
			temp=temp->next;
		}
	}

	printSP(p,ver,src,dist,parent);
}

void display(int j,node *p[])
{
	node *temp=p[j];
	while(temp!=NULL) {
		cout<<j<<"->"<<temp->dest<<": "<<temp->weight<<"\n";
		temp=temp->next;
	}
}

int main()
{
	int v,e,i,x,y,key;
	cin>>v;
	node *adjlist[v+1];
	for(i=0;i<v;++i) adjlist[i]=NULL;

	cin>>e;
	for(i=0;i<e;++i) {
		cin>>x>>y>>key;
		adjlist[x]=addedge(adjlist[x],y,key);
		//adjlist[y]=addedge(adjlist[y],x,key);
	}
	// adjlist[i] is an edge that stores the destination and the weight of the edge from vertex i.

	cout<<"graph:\n";
	for(i=0;i<v;++i) display(i,adjlist);

	cout<<"primMST:\n";
	primMST(adjlist,v);
	
	cout<<"dijkstra:\n";
	dijkstra(adjlist,v,0);

	return 0;
}
