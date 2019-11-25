#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double ans=0;
	string s;
	getline(cin,s);
	while(n--)
	{
		getline(cin,s);
		int jpy;
		double btc;
		stringstream ss(s);
		if(s[s.length()-1]=='Y') ss>>jpy,ans+=jpy;
		else ss>>btc,ans+=btc*380000;
	}
	printf("%.8f\n",ans);
}
