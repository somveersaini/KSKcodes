#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int des;
	int weight;
	node *next;
};
void printMST(struct node *adjlist[] ,int v,int par[],int k[])
{
	for(int i=1;i<v;i++){
		printf("%d -> %d : %d \n" , par[i],i,k[i]);
	}
}
int minweight(int k[] ,int m[] ,int v)
{
	int mn_index,mn=INT_MAX;
	
	for(int i=0;i<v;i++){
		if(m[i]==0 && k[i] <mn){
			mn_index = i;
			mn = k[i];
		}
	}
	return mn_index;
}
void primMST(struct node *adjlist[],int ver)
{	
	int parent[ver],key[ver],mst[ver];
	for(int i=0;i<ver;i++){
		key[i] = INT_MAX;
		mst[i] = 0;
		}
	key[0] = 0;
	parent[0]=-1;
	for(int i=0;i<ver-1;i++){
		int mn = minweight(key,mst,ver);
		mst[mn]= 1;
		
		struct node *temp = adjlist[mn] ;
		while(temp!=NULL){
			if(mst[temp->des]==0 && temp->weight < key[temp->des]){
				key[temp->des] = temp->weight;
				parent[temp->des]=mn;
			}
			temp = temp->next;
		}
	}
	printMST(adjlist,ver,parent,key);
}
void printgraph(struct node *adjlist[],int v)
{
	for(int k=0;k<v;k++){
		struct node *temp = adjlist[k];
		while(temp!=NULL){
			printf("%d -> %d   %d  ",k,temp->des ,temp->weight);
			temp= temp->next;
			}
		printf("\n");
	}
}
struct node *newnode(int dest,int key)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->des =  dest ;
	temp->weight = key;
	temp->next =  NULL;
	
	return temp;
} 
struct node *addedge(struct node *p,int dest,int key)
{	
	if(p==NULL){
		p = newnode(dest,key);
	}
	else{
		struct node *temp = p;
		while(temp->next!=NULL){
			temp = temp->next;
			}
		temp->next = newnode(dest,key);
	}
	return p;
}
int main()
{
		int v;//vertex
		printf("Enter number of vertex \n");
		scanf("%d",&v);
		struct node *adjlist[v+1];//for making adjlist
			for(int i=0;i<v;i++){
				adjlist[i]=NULL;
			}
		int e;//edge
		printf("Enter the number of edges\n");
		scanf("%d\n",&e);
		int x,y,key;//source,destination,weight
		for(int j=0;j<e;j++){
			scanf("%d %d %d",&x,&y,&key);
			adjlist[x] = addedge(adjlist[x],y,key);//making list of node x
			adjlist[y] = addedge(adjlist[y],x,key);//for undirected  graph
		}
		printf("PRINTING GRAPH\n");
		printgraph(adjlist,v);
		
		printf("PRIME\n");
		primMST(adjlist,v);//adjlist , vertex , source
		
	return 0;
}
