#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int des;
	int weight;
	node *next;
};
int top = -1;
void push(int path[],int k)
{
	 top = top+1;
	 path[top]=  k;
}
int pop(int path[])
{
	int p = path[top];
	top  = top-1;
	
	return p;
}
void printstack(int path[])
{
	while(top!=-1){
		int kk = pop(path);
		printf("%d " ,kk);
		}
	printf("\n");
}
void printSP(struct node *adjlist[] ,int ver ,int src ,int dist[] ,int parent[])
{
	for(int i=0;i<ver;i++){
		int path[100];
		push(path,i);
		int pr  = parent[i] ;
		while(pr!=src){
			push(path,pr);
			pr = parent[pr];//push parent of parent of parent ................until not reached at starting node 
		}
		push(path,src);
		printf("%d -> %d -> : %d : path ",src , i ,dist[i]);//source destitaion distance 
		printstack(path);//printing path from source
	}
}
int mindistance(int dist[],int sp[],int ver)
{
	int mn_index;
	int mn_dist=INT_MAX;
	for(int i=0;i<ver;i++){
		if(sp[i] == 0 && dist[i] < mn_dist){//until no visited and having minimum distance 
			mn_dist = dist[i];
			mn_index = i;
		}
	}
	return mn_index;//return node which has minimum distance from source
}
void dijkstra(struct node *adjlist[],int ver ,int src)
{
	int parent[ver],dist[ver],sp[ver];//storing parent,distance from source , node visited or not
	
	for(int i=0;i<ver;i++){	
		dist[i] = INT_MAX;//all node distance assign to infinite
		sp[i] = 0;//at start all nodes are unvisited
		}
	dist[src] = 0;//distance from source to source assign to zero
	parent[src] = src;//parent of source is source 
	
	for(int i=0;i<ver-1;i++){
		int mn = mindistance(dist , sp,ver);
		sp[mn] = 1;
		
		struct node *temp = adjlist[mn];//find minimum distance node 
		while(temp!=NULL){
			if((sp[temp->des])==0 && ((dist[mn] + temp->weight) < dist[temp->des])){
			dist[temp->des]=dist[mn] + temp->weight;//assign minimum distance to adjancy node of minimum distance node 
			parent[temp->des]= mn;//store parent
			}
			temp = temp->next;
		}
	}
	printSP(adjlist,ver,src,dist,parent);
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
		printf("\nPRINTING GRAPH\n");
		printgraph(adjlist,v);
		
		printf("dijkstra\n");
		dijkstra(adjlist,v,2);//adjlist , vertex , source
		
	return 0;
}
