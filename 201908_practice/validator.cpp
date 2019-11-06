#include "testlib.h"
using namespace std;
int main(int argc,char* argv[])
{
	registerValidation(argc,argv);
	int T=inf.readInt(1,100000,"T");
	inf.readEoln();
	while(T--)
	{
		int n,q;
		n=inf.readInt(0,10000,"n");
		inf.readSpace();
		q=inf.readInt(0,100,"q");
		inf.readEoln();
		for(int i=0;i<n;i++)
		{
			int x=inf.readInt(0,100);
			inf.readSpace();
			int y=inf.readInt(0,100);
			inf.readEoln();
		}
		for(int i=0;i<n;i++)
		{
			int x=inf.readInt(0,100);
			inf.readSpace();
			int y=inf.readInt(0,100);
			inf.readEoln();
		}
	}
}
