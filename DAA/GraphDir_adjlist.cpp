#include <bits/stdc++.h>
using namespace std;

struct node {
	int conn;
	// int weight;
	node *next;
};

node *newnode(int z)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->conn=z;
	temp->next=NULL;

	return temp;
}

node *addedge(node *p,int y)
{
	if(p==NULL) p=newnode(y);
	else {
		node *temp=p;
		while(temp->next!=NULL) temp=temp->next;  // following tail insertion
		temp->next=newnode(y);
	}

	return p;
}

void dfsRecur(node *q[],bool vis[],int j)
{
	cout<<j<<" ";
	vis[j]=true;
	
	node *temp=q[j];
	while(temp!=NULL) {
		if(!vis[temp->conn])
			dfsRecur(q,vis,temp->conn);
		temp=temp->next;
	}
}

void dfs(node *p[],int ver)
{
	bool visited[ver+1];
	memset(visited,false,sizeof(visited));
	for(int i=0;i<ver;++i) {
		if(!visited[i])
			dfsRecur(p,visited,i);
	}
	cout<<"\n";
}

void bfsQueue(node *q[],bool vis[],int j)
{
	queue<int> qu;
	vis[j]=true;
	qu.push(j);

	while(!qu.empty()) {
		int ele=qu.front();
		cout<<ele<<" ";
		qu.pop();

		node *temp=q[ele];
		while(temp!=NULL) {
			if(!vis[temp->conn]) {
				vis[temp->conn]=true;
				qu.push(temp->conn);
			}
			temp=temp->next;
		}
	}
}

void bfs(node *p[],int ver)
{
	bool visited[ver+1];
	memset(visited,false,sizeof(visited));

	for(int i=0;i<ver;++i) {
		if(!visited[i]) 
			bfsQueue(p,visited,i);
	}
	cout<<"\n";
}

void topologicalSortRec(node *q[],int i,bool vis[],stack<int> *s)
{
	vis[i]=true;

	node *temp=q[i];
	while(temp!=NULL) {
		if(!vis[temp->conn])
			topologicalSortRec(q,temp->conn,vis,s);
		temp=temp->next;
	}
	(*s).push(i);
}

void topologicalSort(node *p[],int ver)
{
	bool visited[ver+1];
	memset(visited,false,sizeof(false));
	stack<int> s;

	for(int i=0;i<ver;++i) {
		if(!visited[i])
			topologicalSortRec(p,i,visited,&s);
	}
	
	while(!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
}

bool isCyclicRec(node *q[],bool vis[],bool recstack[],int j)
{
	// mark the current node as part of recstack
	vis[j]=true;
	recstack[j]=true;
	node *temp=q[j];
	while(temp!=NULL) {
		if(!vis[temp->conn]) {
			if(isCyclicRec(q,vis,recstack,temp->conn))
				return true;
		}
		else if(recstack[temp->conn]) { 
			cout<<temp->conn<<" for "<<j<<":\n";
			return true;
		}
		temp=temp->next;
	}
	recstack[j]=false;  // remove the node from recstack
	return false;
}

bool isCyclicDFS(node *p[],int ver)
{
	bool visited[ver+1];
	memset(visited,false,sizeof(visited));

	for(int i=0;i<ver;++i) {
		if(!visited[i]) {
			bool recstack[(sizeof(*(p[i]))/sizeof(node))+1];
			memset(recstack,false,sizeof(recstack));
			if(isCyclicRec(p,visited,recstack,i))
				return true;
		}
	}
	return false;
}

void display(node *p)
{
	node *temp=p;
	while(temp!=NULL) {
		cout<<temp->conn<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

int main()
{
	int v,i,e,x,y,w;
	node *adjlist[100];
	cin>>v;
	for(i=0;i<v;++i) adjlist[i]=NULL;
	cin>>e;
	for(i=0;i<e;++i) {
		cin>>x>>y;
		adjlist[x]=addedge(adjlist[x],y);
	//	adjlist[y]=addedge(adjlist[y],x);  // for undirected graph
	}

	for(i=0;i<v;++i) {
		cout<<i<<": ";
		display(adjlist[i]);
	}

	cout<<"dfs:\t";
	dfs(adjlist,v);

	cout<<"bfs:\t";
	bfs(adjlist,v);

	cout<<"topological sort:\t";
	topologicalSort(adjlist,v);  // only for a DAG
	cout<<"\n";

	//cout<<sizeof(*(adjlist[1]))<<" "<<sizeof(node)<<"\n";

	bool isCyclic=isCyclicDFS(adjlist,v);
	if(isCyclic) cout<<"is cyclic\n";
	else cout<<"isn't cyclic\n";

	return 0;
}
