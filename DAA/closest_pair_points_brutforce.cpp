#include <bits/stdc++.h>

using namespace std;

double calc(pair<int,int> v ,pair<int ,int>  p)
{
	//calculate distance between two points 
	int dd = (v.first - p.first)*(v.first-p.first) + (v.second-p.second)*(v.second-p.second);
	double ans = (double)sqrt(dd);
//	cout<<ans<<endl;
	return ans;
}	
double closest(vector<pair<int,int> > v,int n)
{
	//calculate minimum distance using brutforce // complexity o(n*2)
	pair<int ,int> g;
	pair<int ,int> k;
	double dis=FLT_MAX;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				double pp = calc(v[i],v[j]);
				if(pp<dis){
				dis=pp;
				g = v[i];
				k = v[j];
				}
			}
		}
	}
	//minimum distance point 
	cout<<"points are :"<<"("<<g.first<<","<<g.second<<")"<<" & "<<"("<<k.first<<","<<k.second<<")"<<endl;
	return dis;
}

int main()
{
	int n,p,r;
	cout<<"How many point "<<endl;
	cin>>n;
	vector<pair<int ,int> > v;
	cout<<"Enter points (X,Y) : "<<endl;
	for(int i=0;i<n;i++){
		cin>>p>>r;
		v.push_back(make_pair(p,r));
	}
	sort(v.begin(),v.end());//sort according to first argumrent of pair
		cout<<"\n";
/*	for(int i=0;i<n;i++){
		cout<<v[i].first<<" "<<v[i].second<<endl;
		}*/
	double distance = closest(v,n);
	cout<<"minimum distance :"<<distance<<endl;
	return 0;
}
