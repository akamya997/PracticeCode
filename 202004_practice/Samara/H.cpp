#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxn=2e5+7;
vi G[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(G[i].size()==1) ans++;
    cout<<(ans+1)/2<<'\n';
}