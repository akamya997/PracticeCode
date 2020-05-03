#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
typedef pair<int,int> pi;
string m[maxn];
bool vis[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++) cin>>m[i];
    queue<pi> q;
    for(int i=0;i<w;i++)
    {
        if(m[0][i]=='.')
            q.emplace(0,i);
    }
    while(!q.empty())
    {
        auto u=q.front();q.pop();
        if(vis[u.first][u.second]) continue;
        vis[u.first][u.second]=1;
        if(m[u.first+1][u.second]=='.')
            q.emplace(u.first+1,u.second);
        else if(m[u.first+1][u.second]=='#')
        {
            if(u.second&&m[u.first][u.second-1]=='.')
                q.emplace(u.first,u.second-1);
            if(u.second+1<w&&m[u.first][u.second+1]=='.')
                q.emplace(u.first,u.second+1);
        }
    }
    bool suc=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(m[i][j]=='.'&&!vis[i][j])
            {
                m[i][j]='X';
                suc=1;
                break;
            }
        }
        if(suc) break;
    }
    if(!suc) cout<<"No\n";
    else{
        cout<<"Yes\n";
        for(int i=0;i<h;i++) cout<<m[i]<<'\n';
    }
}