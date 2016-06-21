#include <bits/stdc++.h>

using namespace std;

void findclosest(int a[],int n,int x,int k)
{
	int q;
	for(int i=0;i<n;i++){
		if(a[i]==x){
			q=i;
		}
	}
	cout<<q<<endl;
	int b[k+1];
	int p=q-1;
	int r=q+1;
	int i=0;
	int h=k;
	while(k>0){
		if(((a[q]-a[p])<(a[r]-a[q]))&&(p>=0)&&(r<n)){
			b[i]=a[p];
			p--;
			i++;
		}
		else{
			b[i] = a[r];
			r++;
			i++;
		}
		k--;
	}
	for(int j=0;j<h;j++){
		cout<<b[j]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	cout<<"how many element do you want "<<endl;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x,k;
	cout<<"Enter the element for finding closest "<<endl;
	cin>>x;
	cout<<"how many closest element"<<endl;
	cin>>k;
	findclosest(a,n,x,k);

	return 0;
}
