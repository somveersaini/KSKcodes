#include <bits/stdc++.h>

using namespace std;

void movetoend(int MpN[] ,int mpn)
{
	int j=mpn-1;
	for(int i=mpn-1;i>=0;i--){
		if(MpN[i]!=-1){
			MpN[j]=MpN[i];
			j--;
		}
	}
}
int merge(int MpN[] ,int N[],int m,int n)
{
	int i=n;
	int j=0;
	int k=0;
	while(k<(m+n))
	{
		if((i<(m+n) && (MpN[i]<=N[j])) || (j==n))
		{
			MpN[k] =  MpN[i];
			k++;
			i++;
		}
		else{
			MpN[k] = N[j];
			k++;
			j++;
		}
	}
}
int main()
{
	int mpn;
	cout<<"value of mplusn"<<endl;
	cin>>mpn;
	int MpN[mpn+1];
	for(int i=0;i<mpn;i++){
		cin>>MpN[i];
	}
	int n;
	cout<<"value of n"<<endl;
	cin>>n;
	int N[n+1];
	for(int j=0;j<n;j++){
		cin>>N[j];
	}
	movetoend(MpN,mpn);
	int m= mpn-n;
	merge(MpN , N, m ,n);
	for(int h=0;h<mpn;h++){
		cout<<MpN[h]<<"  ";
	}
	cout<<endl;
	return 0;
}
