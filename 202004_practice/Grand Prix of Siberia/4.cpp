#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int,int> pi;
typedef long long ll;
const int maxn=505;
pi p[maxn];
int dp[maxn][maxn];
int pre[maxn][maxn];
struct D{
    int X,Y,L,R;
};
vector<D> op;
inline void add(int X,int Y,int L,int R)
{
    if(X==L&&Y==R) return;
    if(X<L||Y<R) swap(X,L),swap(Y,R);
    op.push_back(D{X,Y,L,R});
}
void getans(int l,int r)
{
    if(l==r) return;
    int t=pre[l][r];
    add(p[t].x,p[t].y,p[l].x,p[t].y);
    add(p[t+1].x,p[t+1].y,p[t+1].x,p[r].y);
    getans(l,t);
    getans(t+1,r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>(p[i].x)>>(p[i].y);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(int len=2;len<=n;len++)
    {
        for(int l=1,r=l+len-1;r<=n;l++,r++)
        {
            for(int t=l;t<r;t++)
            {
                int L=p[t].x-p[l].x;
                int R=p[t+1].y-p[r].y;
                if(dp[l][r]>dp[l][t]+dp[t+1][r]+L+R)
                {
                    dp[l][r]=dp[l][t]+dp[t+1][r]+L+R;
                    pre[l][r]=t;
                }
            }
        }
    }
    ll ans=dp[1][n];
    add(0,0,p[1].x,0);
    add(p[1].x,0,p[1].x,p[n].y);
    add(p[1].x,p[n].y,p[1].x,p[1].y);
    add(p[1].x,p[n].y,p[n].x,p[n].y);
    ans+=p[1].y+p[n].x;
    getans(1,n);
    cout<<op.size()<<" "<<ans<<'\n';
    for(auto u:op) cout<<u.X<<" "<<u.Y<<" "<<u.L<<" "<<u.R<<'\n';
}