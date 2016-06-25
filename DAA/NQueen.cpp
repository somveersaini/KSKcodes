#include <bits/stdc++.h>

using namespace std;

int counter =0;//counting all solution of n queen

void printsolution(int a[][100],int n)
{
	counter++;
	//printing all solutions
	cout << "***************solution ************ "<< counter << endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
			}
		cout<<"\n";	
	}
}
int IsSafe(int a[][100] ,int col,int n,int row)
{
	// checking same column
	for(int i=0;i<n;i++){
		if(a[i][col]==1){
			return 0;
			}
	}
	//checking same row
	for(int i=0;i<n;i++){
		if(a[row][i]==1){
			return 0;
		}
	}
	//checking diagonal
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//checking right diagonal 
			if((((i+j)==(row+col))&&a[i][j])==1){
				return 0;
				}
				// checking left diagonal 
			if((((i-j)==(row-col))&&a[i][j])==1){
				return 0;
				}
		}
	}
	return 1;
}
int findsolution(int a[][100],int row,int n)
{
	if(row==n){
		printsolution(a,n);
	}

	for(int col=0;col<n;col++){

		if(IsSafe(a,col,n,row)==1){//checking current queen position is correct or not 
			a[row][col]=1;
			
			//increment row 
			if(findsolution(a,row+1,n)){//backtracking if its not true //if there is a backtrack then go previous row and increment the col then find the solution
				printsolution(a,n); // printing all solutions 

			}
			a[row][col]=0;//if backtrack the reset the value of a[row][col] 
		}
	}	
	return 0;
}

int main()
{
	int n;//number of Queens
	cout<<"Enter Number of Queen "<<endl;
	cin>>n;
	int a[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}	
	//find solution of n queens
	findsolution(a,0,n);//(array,current row,total number of rows)
	// here current row start from 0 
	if(n<4){
		cout<<"Solution does not Exist"<<endl;
	}

	return 0;
}

	
