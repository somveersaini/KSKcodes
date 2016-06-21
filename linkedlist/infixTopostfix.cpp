#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cout<<"Enter the length  of expression "<<endl;
	cin>>n;
	char exp[n+1];
	for(int i=0;i<n;i++){
		cin>>exp[i];
	}
	infix_to_postfix(exp);

	return 0;
}

