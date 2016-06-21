#include <bits/stdc++.h>

using namespace std;

void LCS(string k,string p)
{
	int m=k.length();
	int n=p.length();

	int L[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0){
				L[i][j]=0;
			}
			else if(k[i-1]==p[j-1]){
				L[i][j] = 1+L[i-1][j-1];
			}
			else if(L[i-1][j] >=L[i][j-1]){
				L[i][j] = L[i-1][j];
			}
			else{
				L[i][j] = L[i][j-1];
			}
		}
	}
	cout<<"Length of LCS : "<<L[m][n]<<endl;
	int i= m;
	int pre = L[m][n];
	int j=n;
	char lcs[pre+1];
	while(i>0 && j>0){
		if(k[i-1] == p[j-1]){
			lcs[pre-1] = k[i-1];
			pre--;
			i--;
			j--;
		}
		else if(L[i-1][j]>L[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	cout<<"LCS   : "<<lcs<<endl;
}
		
int main()
{
	string k;
	string p;
	cin>>k>>p;

	LCS(k,p);
	//cout<<gg<<endl;
	return  0;
}
