#include <bits/stdc++.h>

using namespace std;

pair<int ,int> g;//use for storing point minimum point
pair<int ,int> k;//according to second point which have minimum distance

// sort according to second parameter
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}

//finding minimum value 
double min(double x,double y)
{
	if(x>y){
		return y;
	}
	else {
		return x;
	}
}
// distance between two point 
double distance(int vfirst,int vsecond,int pfirst,int psecond)
{
	//calculate distance between two points 
	int dd = (vfirst - pfirst)*(vfirst-pfirst) + (vsecond-psecond)*(vsecond-psecond);
	double ans = (double)sqrt(dd);
//	cout<<ans<<endl;
	return ans;
}	
double bruteforce(vector<pair<int , int > > &pre ,int start ,int n,double mn)
{
	for(int i=start;i<n;i++){
		for(int j=start;j<n;j++){
			if(i!=j){
				double pp = distance(pre[i].first,pre[i].second,pre[j].first,pre[j].second);
				if(pp<mn){
				mn=pp;
				g.first=(pre[i].first);
				g.second=(pre[i].second);
				k.first=(pre[j].first);
				k.second=(pre[j].second);
				}
			}
		}
	}
	return mn;
}

double strip_close(vector<pair<int ,int > > &pre ,int size ,double dis)
{
	//for(int i=0;i<pre.size();i++) cout<<pre[i].first<<" "<<pre[i].second<<"\n";	
	double min  =  dis;
	//cout<<"dis: "<<min<<"\n";
	sort(pre.begin(),pre.end(),myComparison);//sort according to second parameter y 
	
	for(int i =0;i<size;i++){
		pair<int ,int > ff = pre[i];
		pair<int ,int > kk = pre[i+1];
		
		for(int j = i+1;(j<size);j++){
			if((kk.second - ff.second)<min) {
			//cout<<"yes";
			if((distance(ff.first,ff.second,kk.first,kk.second))<min){
				g.first=(ff.first);
				g.second=(ff.second);
				k.first=(kk.first);
				k.second=(kk.second);
				min = (distance(ff.first,ff.second,kk.first,kk.second));
			}
			//cout<<"min: "<<min<<"\n";
			kk = pre[j+1];
			}
		}
	}

	return min;
}
// finding closest distance points 
double closest(vector<pair<int ,int > > &v,int start,int n)
{
	//base case 
	if(n<=3){
		return bruteforce(v,start,n,FLT_MAX);
	}
	int mid=n/2;
	pair<int ,int > pmid = v[mid];
	//cout<<v[mid].first<<" "<<v[mid].second<<"\n";
	// divide and conqure calculate the minimum distance among both side 
	double dl  = closest(v,start,mid);//minimum distance of left side 
	double dr = closest(v,start+mid+1,n-mid-1);// minimum distance of right 
	// minimum of both distance dl and dr is equal to dis
	double dis=dr;
	
	// find out those points which have less distance than dis ...........suppose one point is left side another is on  right side and having distance less than minimum distance dis
	vector<pair<int ,int > > strip; //strip vector
	for(int i=0;i<n;i++){
		if((abs(v[i].first - pmid.first))<dis){//having distance less than dis
			strip.push_back(make_pair(v[i].first,v[i].second));
		}	
	}

	return min(dis,strip_close(strip,strip.size(),dis));
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
	double distance = closest(v,0,n);
	cout<<"minimum distance :"<<distance<<endl;
	cout<<g.first<<" "<<g.second<<"\t"<<k.first<<" "<<k.second<<"\n";
	return 0;
}
