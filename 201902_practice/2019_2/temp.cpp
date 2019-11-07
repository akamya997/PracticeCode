#include<bits/stdc++.h>
using namespace std;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
typedef long long LL;
const int MOD=998244353;
const int N=2e5+7;
int G=3;
LL wn[N << 2], rev[N << 2];
long long bin(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ret;
}
long long get_inv(LL cur)
{
	return bin(cur,MOD-2);
}
int NTT_init(int n_) {
	int step = 0; int n = 1;
	for ( ; n < n_; n <<= 1) ++step;
	FOR (i, 1, n)
	rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (step - 1));
	int g = bin(G, (MOD - 1) / n);
	wn[0] = 1;
	for (int i = 1; i <= n; ++i)
	wn[i] = wn[i - 1] * g % MOD;
	return n;
}
void NTT(LL a[], int n, int f) {
	FOR (i, 0, n) if (i < rev[i])
	std::swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k <<= 1) {
		for (int i = 0; i < n; i += (k << 1)) {
			int t = n / (k << 1);
			FOR (j, 0, k) {
				LL w = f == 1 ? wn[t * j] : wn[n - t * j];
				LL x = a[i + j];
				LL y = a[i + j + k] * w % MOD;
				a[i + j] = (x + y) % MOD;
				a[i + j + k] = (x - y + MOD) % MOD;
			}
		}
	}
	if (f == -1) {
		LL ninv = get_inv(n);
	FOR (i, 0, n)
		a[i] = a[i] * ninv % MOD;
	}
}
int reval(int x,int r)  //蝴蝶操作
{
    int ans=0;
    for(int i=0; i<r; i++)
    {
        if(x&(1<<i))
        {
            ans+=1<<(r-i-1);
        }
    }
    return ans;
}
void ntt(LL A[],int n,int on) // 长度为N (2的次数)
{
    int r=0;
    for(;; r++)
    {
        if((1<<r)==n)
            break;
    }
    for(int i=0; i<n; i++)
    {
        int tmp=reval(i,r);
        if(i<tmp)
            swap(A[i],A[tmp]);
    }
    for(int s=1; s<=r; s++)
    {
        int m=1<<s;
        LL wn=bin(G,(MOD-1)/m);
        for(int k=0; k<n; k+=m)
        {
            LL  w=1;
            for(int j=0; j<m/2; j++)
            {
                LL t,u;
                t=w*(A[k+j+m/2]%MOD)%MOD;
                u=A[k+j]%MOD;
                A[k+j]=(u+t)%MOD;
                A[k+j+m/2]=((u-t)%MOD+MOD)%MOD;
                w=w*wn%MOD;
            }
        }
    }
    if(on==-1)
    {
        for(int i=1;i<n/2;i++)
            swap(A[i],A[n-i]);
        LL inv=bin(n,MOD-2);
        for(int i=0;i<n;i++)
            A[i]=A[i]%MOD*inv%MOD;
    }

}
void conv(LL a[],LL b[],int len)
{
	ntt(a,len,1);
	ntt(b,len,1);
	for(int i=0;i<len;i++)
		a[i]=a[i]*b[i]%MOD;
	ntt(a,len,-1);
}
int arr[N];
int brr[N];
long long A[N],B[N];
vector<int> all;
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
vector<long long> cnta[N],cntb[N];
long long ans[2*N];
int main()
{
	int n,m;
	int var=10000;
	scanf("%d%d",&n,&m);
	int len=1;
	while(len<max(n,m)) len*=2;
	len*=2;
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		all.push_back(arr[i]);
	}
	for(int i=0;i<=m;i++)
	{
		scanf("%d",&brr[i]);
		all.push_back(brr[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=0;i<=n;i++)
		cnta[getid(arr[i])].push_back(i);
	for(int i=0;i<=m;i++)
		cntb[getid(brr[i])].push_back(i);
	for(int i=0;i<all.size();i++)
	{
		if(cnta[i].size()+cntb[i].size()<var)
		{
			for(int j=0;j<cnta[i].size();j++)
			{
				for(int k=0;k<cntb[i].size();k++)
				{
					ans[cnta[i][j]+cntb[i][k]]=(ans[cnta[i][j]+cntb[i][k]]+cnta[i][j]*cntb[i][k]%MOD)%MOD;
				}
			}
		}
		else{
			memset(A,0,sizeof(A));
			memset(B,0,sizeof(B));
			for(int j=0;j<=n;j++)
				A[j]=(arr[j]==all[i]?j:0);
			for(int j=0;j<=m;j++)
				B[j]=(brr[j]==all[i]?j:0);
			conv(A,B,len);
			for(int j=0;j<=m+n;j++)
			{
				ans[j]=(ans[j]+A[j])%MOD;
			}
		}
	}
	printf("%lld",ans[0]);
	for(int i=1;i<=n+m;i++)
		printf(" %lld",ans[i]);
	puts("");
}
