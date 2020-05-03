#include<bits/stdc++.h>
using namespace std;
map<string,int> id;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int maxn=205;
int ok[maxn][maxn];
vi G[100005];
int deg[100005];
vector<int> a;
int S,L,N;
void solve()
{
    priority_queue<pi,vector<pi>,greater<pi>> q;
    vi pre(S,-1);
    vi pos;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<S;j++)
        {
            if(pre[j]!=-1&&!ok[a[i]][j])
            {
                G[pre[j]].push_back(i);
                deg[i]++;
            }
        }
        pre[a[i]]=i;
    }
    vi ans;
    for(int i=0;i<a.size();i++)
    {
        if(!deg[i])
            q.emplace(a[i],i);
    }
    while(!q.empty())
    {
        auto u=q.top();q.pop();
        ans.push_back(u.first);
        for(auto v:G[u.second])
        {
            deg[v]--;
            if(!deg[v])
                q.emplace(a[v],v);
        }
    }
    a=ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>S>>L>>N;
    vector<string> all(S);
    for(int i=0;i<S;i++) cin>>all[i];
    sort(all.begin(),all.end());
    for(int i=0;i<S;i++) id[all[i]]=i;
    a=vector<int>(N);
    for(int i=0;i<L;i++)
    {
        string a,b;
        cin>>a>>b;
        int ida=id[a],idb=id[b];
        ok[ida][idb]=ok[idb][ida]=1;
    }
    for(int i=0;i<N;i++)
    {
        string x;
        cin>>x;
        int j=id[x];
        a[i]=j;
    }
    solve();
    for(int i=0;i<N;i++)
        cout<<all[a[i]]<<" \n"[i==N-1];
}