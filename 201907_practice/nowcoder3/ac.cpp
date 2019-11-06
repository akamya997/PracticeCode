#include<iostream>
#include<vector>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define N 200000
#define ll long long
#define MOD 998244353
using namespace std;
ll c[100][100],f[100][100];
int T,op,x,y,i,j;
ll n,a,res,res_t;
void init_c()
{
    int i,j;
    fo(i,0,64)
    {
        c[i][0] = 1;
        fo(j,1,i) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
    }
}
void init()
{
    int  i,j,i1,j1;
    fo(i,0,64)
    fo(j,0,64)
    {
        fo(i1,0,i)
        fo(j1,0,j)
            if ((i1 + j1 * 2) % 3 == 0)
                f[i][j] = (f[i][j] + (c[i][i1] * c[j][j1]) % MOD) % MOD;
    }
}
ll qp(ll a,ll x)
{
    ll res = 1; ll e = a;
    while (x)
    {
        if (x&1) res = (res * e) % MOD;
        e = (e * e) % MOD;
        x >>= 1;
    }
    return res;
}
int main()
{
    init_c();
    init();
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld",&n,&a);
        op = x = y = 0;
        while (a)
        {
            if (a&1) if (op==0) x++; else y++;
            a >>= 1;
            op = 1 - op;
        }
		cout<<x<<" "<<y<<endl;
        res = 0;
        fo(i,0,x)
        fo(j,0,y)
        {
            res_t = 1;
            res_t = (c[x][i] * c[y][j]) % MOD;
            res_t = (res_t * qp(f[i][j],n)) % MOD;
            if ((i+j) % 2 == (x+y) % 2) res_t *= 1; else res_t *= -1;
            res = (res + res_t + MOD) % MOD;
        }
        cout<<res<<endl;
    }
    return 0;
}
