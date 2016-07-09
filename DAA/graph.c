#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
	int conn;
	node *next;
};

int front = -1;
int rear = -1;

void memset1(int visited[],int ver)
{
	for(int i=0;i<=ver;i++){
		visited[i]=0;
		}
}
void push(int qu[],int num)
{
	if(front==-1&&rear==-1)
 	 {
      front=rear=0;
      qu[rear]=num;
  	}
  	else if(rear==99 && front!=0)
  	{
    rear=0;
    qu[rear]=num;
  	}
 	 else
 	 {
      rear++;
      qu[rear]=num;
 	 }
}
int pop(int qu[])
{
	int element=qu[front];
  	if(front==rear)
     front=rear=-1;
  	else
  	{
   	 if(front==99)
      front=0;
   	 else
      front++;
  	}
  	
  return element;
 }
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

void dfsRecur(node *q[],int vis[],int j)
{
	printf("%d ",j);
	vis[j]=1;
	
	node *temp=q[j];
	while(temp!=NULL) {
		if(!vis[temp->conn])
			dfsRecur(q,vis,temp->conn);
		temp=temp->next;
	}
}

void dfs(node *p[],int ver)
{
	int visited[ver+1];
	memset1(visited,ver);
	for(int i=0;i<ver;++i) {
		if(!visited[i])
			dfsRecur(p,visited,i);
	}
	printf("\n");
}

void bfsQueue(node *q[],int vis[],int j)
{
	int  qu[100];
	vis[j]=1;
	
	push(qu,j);


	while(front!=-1) {
		int ele=pop(qu);
		printf("%d ",ele);

		node *temp=q[ele];
		while(temp!=NULL) {
			if(!vis[temp->conn]) {
				vis[temp->conn]=1;
				push(qu,temp->conn);
			}
			temp=temp->next;
		}
	}
}

void bfs(node *p[],int ver)
{
	int visited[ver+1];
	memset1(visited,ver);

	for(int i=0;i<ver;++i) {
		if(!visited[i]) 
			bfsQueue(p,visited,i);
	}
	printf("\n");
}


void display(node *p)
{
	node *temp=p;
	while(temp!=NULL) {
		printf("%d",temp->conn);
		printf(" ");
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	int v,i,e,x,y,w;
	node *adjlist[100];
	scanf("%d",&v);
	for(i=0;i<v;++i) adjlist[i]=NULL;
	scanf("%d",&e);
	for(i=0;i<e;++i) {
		scanf("%d %d",&x,&y);
		adjlist[x]=addedge(adjlist[x],y);
		//adjlist[y]=addedge(adjlist[y],x);  // for undirected graph
	}

	for(i=0;i<v;++i) {
		printf("%d",i);
		printf(":");
		display(adjlist[i]);
	}
	printf("dfs:   ");
	dfs(adjlist,v);

	printf("bfs:   ");
	bfs(adjlist,v);


	return 0;
}
