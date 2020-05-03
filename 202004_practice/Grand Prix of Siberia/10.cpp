#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int a=0,b=0;
    for(int i=0;i<6;i++)
    {
        if(s[i]<t[i]) a++;
        else if(s[i]>t[i]) b++;
    }
    cout<<a<<'\n';
    cout<<b<<'\n';
}