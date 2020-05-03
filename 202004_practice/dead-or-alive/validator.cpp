#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int fa[maxn];
int Find(int x)
{
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    fa[y]=x;
}
int main(int argc,char* argv[])
{
    registerValidation(argc,argv);
    int n=inf.readInt(1,100000,"n");
    inf.readEoln();
    for(int i=0;i<maxn;i++) fa[i]=i;
    for(int i=0;i<n;i++)
    {
        inf.readInt(0,1000000000,"a_i");
        if(i==n-1) inf.readEoln();
        else inf.readSpace();
    }
    for(int i=1,u,v;i<n;i++)
    {
        u=inf.readInt(1,n,"u");
        inf.readSpace();
        v=inf.readInt(1,n,"v");
        inf.readEoln();
        ensuref(u!=v,"self ring");
        Union(u,v);
    }
    map<int,int> ext;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!ext.count(Find(i)))
        {
            ext[Find(i)]=1;
            cnt++;
        }
    }
    ensuref(cnt==1,"not a tree");
    inf.readEof();
}