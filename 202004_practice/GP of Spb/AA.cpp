#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin>>a>>b;
    vector<int> cnt(max(a.size(),b.size())*2+3);
    int mx=max(a.size(),b.size())-1;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<cnt.size()-3;i++)
    {
        int c1=0,c2=0;
        if(i<a.size()) c1=a[i]-'0';
        if(i<b.size()) c2=b[i]-'0';
        int cur=cnt[i]+c1+c2;
        if(cur/2) mx=i+3;
        cnt[i]=cur%2;
        cnt[i+2]+=cur/2;
        cnt[i+3]+=cur/2;
    }
    for(int i=mx;i>=0;i--) cout<<cnt[i];
    cout<<'\n';
}