#include <bits/stdc++.h>

using namespace std;

struct Point
{
	int x,y;
};
float closest(Point P[],int n)
{

int main()
{
	int n,p,r;
	Point P[100];
	cout<<"How many point "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p>>r;
		P[i]->x = p;
		P[i]->y = r;
	}
	float distance = closest(P,n);
	return 0;
}
