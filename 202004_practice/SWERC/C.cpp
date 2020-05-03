#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        int num=0;
        if(x.length()<=6)
        {
            for(int i=0;i<x.length();i++)
                num=num*10+x[i]-'0';
            s.insert(num);
        }
    }
    for(int i=0;;i++)
    {
        if(!s.count(i))
        {
            cout<<i<<'\n';
            return 0;
        }
    }
}