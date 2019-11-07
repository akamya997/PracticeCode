#include<bits/stdc++.h>
using namespace std;
const long long top=2e9+7;
bool query(int cur,int type)
{
	if(type==1)
	{
		cout<<"0 "<<cur<<" 0 0"<<endl;
	}
	else if(type==2)
	{
		cout<<"0 0 "<<cur<<" 0"<<endl;
	}
	else cout<<"0 0 0 "<<cur<<endl;
	int ret;
	cin>>ret;
	return ret;
}
int solve(int type)
{
	int retl,retr;
	long long l=0,r=top;
	while(l<r)
	{
		long long mid=l+r>>1;
		if(query(mid,type)) l=mid+1,retr=mid;
		else r=mid;
	}
	l=-top,r=0;
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(query(mid,type)) r=mid-1,retl=mid;
		else l=mid;
	}
	return retr-(retr-retl)/2;
}
int main()
{
	int x,y,z;
	x=solve(1);
	y=solve(2);
	z=solve(3);
	cout<<"1 "<<x<<" "<<y<<" "<<z<<endl;
}
