#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
int main(int argc,char* argv[])
{
	registerValidation(argc,argv);
	int n=inf.readInt(1,200000,"n");
	inf.readEoln();
	for(int i=0;i<n-1;i++)
	{
		inf.readInt(0,1000000000,"a");
		inf.readSpace();
	}
	inf.readInt(0,1000000000,"a");
	inf.readEoln();
	inf.readEof();
}

