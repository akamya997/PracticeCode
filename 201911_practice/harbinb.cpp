#include<bits/stdc++.h>
using namespace std;
#define reads(n) FastIO::read(n)
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    template<typename T>
    bool read(T& x) {
        int n = read(str), bf;
        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};
typedef long long ll;
const int mod=1e8+7;
const int maxn=(1<<17)+5;
int dp[maxn][18][18];//j: lcp(a[i],l[i]+1), k :lcp(a[i],r[i])
int l[maxn],r[maxn];
int n,m;
inline int lcp(int x,int y)
{
    if(x==-1||y==-1) return 0;
    int cc=0;
    for(int i=m-1;i>=0;i--)
    {
        if((x>>i&1)==(y>>i&1)) cc++;
        else break;
    }
    return cc;
}
int main()
{
    int T;
    reads(T);
    while(T--)
    {
		reads(m);
        reads(n);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=m;k++)
                    dp[i][j][k]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            reads(l[i]);reads(r[i]);
        }
        dp[0][0][m]=1;
        l[0]=r[0]=-1;
        for(int i=1;i<=n;i++)
        {
            for(int x=l[i];x<=r[i];x++)
            {
                int l1=lcp(x,l[i]-1),l2=lcp(x,l[i]),r1=lcp(x,r[i]),r2=lcp(x,r[i]+1);
                for(int j=0;j<=l2;j++)
                {
                    for(int k=l1;k<=m;k++)
                    {
                        dp[i][r2][r1]=(dp[i][r2][r1]+1LL*x*dp[i-1][j][k]%mod)%mod;
                    }
                }
            }
        }
        int ans=0;
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=m;k++)
                ans=(ans+dp[n][j][k])%mod;
        }
        printf("%d\n",ans);
    }
}
