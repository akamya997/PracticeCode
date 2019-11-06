#include<bits/stdc++.h>
using namespace std;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
typedef long long LL;
const int MOD=998244353;
const int N=1<<18;
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
	while(len<=n+m) len*=2;
	NTT_init(len);
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
			for(int j=0;j<=n;j++)
				A[j]=(arr[j]==all[i]?j:0);
			for(int j=0;j<=m;j++)
				B[j]=(brr[j]==all[i]?j:0);
			for(int j=n+1;j<len;j++) A[j]=0;
			for(int j=m+1;j<len;j++) B[j]=0;
			NTT(A,len,1);
			NTT(B,len,1);
			for(int j=0;j<len;j++) A[j]=(A[j]*B[j])%MOD;
			NTT(A,len,-1);
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
