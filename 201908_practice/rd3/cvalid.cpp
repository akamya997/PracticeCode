#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
int main(int argc,char* argv[])
{
	registerValidation(argc,argv);
	int n=inf.readInt(1,100000,"n");
	inf.readEoln();
	set<int> all;
	for(int i=0;i<n;i++)
	{
		int bi=inf.readInt(1,1<<30,"bi");
		all.insert(bi);
		if(i==n-1) inf.readEoln();
		else inf.readSpace();
	}
	int q;
	q=inf.readInt(1,100000,"q");
	inf.readEoln();
	while(q--)
	{
		int c,v;
		c=inf.readInt(0,2,"c");
		inf.readSpace();
		v=inf.readInt(1,1<<30,"v");
		inf.readEoln();
		if(c==1)
		{
			ensure(!all.count(v));
			all.insert(v);
		}
		else if(c==2)
		{
			ensure(all.count(v));
			all.erase(v);
		}
	}
	inf.readEof();
}
