#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin>>a>>b;
    vector<int> cnt((a.size()+b.size())*4+500);
    int mx=max(a.size(),b.size())-1;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
        if(a[i]-'0') cnt[i]++;
    for(int i=0;i<b.size();i++)
        if(b[i]-'0') cnt[i]++;
    for(int i=0;i<cnt.size()-3;i++)
    {
        int cur=cnt[i];
        while(cnt[i]>=2&&cnt[i+1]>=2&&cnt[i+2]>=1)
        {
            cnt[i]-=2;
            cnt[i+1]-=2;
            cnt[i+2]--;
            cur-=2;
        }
        //cout<<i<<":"<<cnt[i]<<":"<<cur<<endl;
        if(cur/2) mx=max(i+3,mx);
        cnt[i]=cur%2;
        cnt[i+2]+=cur/2;
        cnt[i+3]+=cur/2;
    }
    //cout<<mx<<endl;
    while(!cnt[mx]&&mx>0) mx--;
    for(int i=mx;i>=0;i--) cout<<cnt[i];
    cout<<'\n';
}