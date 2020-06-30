#include<bits/stdc++.h>
using namespace std;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(a==0) return b;
    if(b==0) return a;
    int la=63-__builtin_clzll(a),lb=63-__builtin_clzll(b);
    if(lb>la) swap(a,b),swap(lb,la);
    a^=(b<<(la-lb));
    return gcd(a,b);
}
int n;
const int maxn=1e5+7;
ll a[maxn];
ll mi[maxn<<2];
void build(int L=1,int R=n,int o=1)
{
    if(L==R)
    {
        mi[o]=a[L];
        while(mi[o]%2==0) mi[o]/=2;
        return;
    }
    int mid=L+R>>1;
    build(Lson);
    build(Rson);
    mi[o]=gcd(mi[lson],mi[rson]);
    while(mi[o]%2==0) mi[o]/=2;
}
void update(int p,ll val,int L=1,int R=n,int o=1)
{
    if(L==R)
    {
        mi[o]=val;
        while(mi[o]%2==0) mi[o]/=2;
        return;
    }
    int mid=L+R>>1;
    if(p<=mid) update(p,val,Lson);
    else update(p,val,Rson);
    mi[o]=gcd(mi[lson],mi[rson]);
    while(mi[o]%2==0) mi[o]/=2;
}
ll query(int l,int r,int L=1,int R=n,int o=1)
{
    if(l<=L&&r>=R)
        return mi[o];
    ll ret=0;
    int mid=L+R>>1;
    if(l<=mid) ret=gcd(ret,query(l,r,Lson));
    if(r>mid) ret=gcd(ret,query(l,r,Rson));
    while(ret%2==0) ret/=2;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build();
    int q;
    cin>>q;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int p;
            ll v;
            cin>>p>>v;
            update(p,v);
        }
        else {
            int l,r;
            cin>>l>>r;
            cout<<query(l,r)<<'\n';
        }
    }
}