#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main()
{
    string b;
    int s;
    cin>>b>>s;
    int n=b.length();
    b=b+b;
    vi pos;
    for(int i=0;i<b.length();i++)
        if(b[i]=='E') pos.push_back(i);
    ll ans=0;
    if(!pos.size())
    {
        cout<<0<<'\n';
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int r=lower_bound(pos.begin(),pos.end(),i)-pos.begin();
        r=pos[r];
        //printf("%d %d\n",i,r);
        int len=r-i+1;
        ans+=max(0,s-len+1);
    }
    cout<<ans<<'\n';
}