#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
int main(int argc,char* argv[])
{
    registerGen(argc,argv,1);
    int mx=atoi(argv[1]);
    int t=atoi(argv[2]);
    int mxval=atoi(argv[3]);
    int n=rnd.next(1,mx);
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        if(t==0)
            a[i]=rnd.next(-mxval,mxval);
        else if(t==1)
            a[i]=rnd.next(-mxval,0);
        else if(t==2) a[i]=rnd.next(0,mxval);
        else a[i]=0;
    }
    cout<<n<<'\n';
    for(int i=0;i<n;i++) cout<<a[i]<<(i==n-1?'\n':' ');
}