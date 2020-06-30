#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll s,n;
int k;
vi a;
const int maxn=1e5+7;
int v[100];
bitset<maxn*2> f,g;
int solve()
{
    f.reset();
    f.set(0);
    while(n||s)
    {
        if(n&1)
        {
            g.reset();
            for(auto u:a)
                g^=f<<u;
            f=g;
        }
        g.reset();
        for(int i=0;i<maxn;i++)
            g[i]=f[i*2+(s&1)];
        f=g;
        n>>=1;
        s>>=1;
    }
    return f[0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>s>>k;
        a=vi(k);
        for(int i=0;i<k;i++) cin>>a[i];
        cout<<solve()<<'\n';
    }
}