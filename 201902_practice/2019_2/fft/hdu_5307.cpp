#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
const LD PI=3.14159265358979;
struct C{
	LD r,i;
	C(LD r=0,LD i=0):r(r),i(i){}
	C operator +(const C& a)const{
		return C(r + a.r, i + a.i);
	}
	C operator -(const C& a)const{
		return C(r - a.r, i - a.i);
	}
	C operator *(const C& a)const{
		return C(r * a.r - i * a.i,r * a.i + i * a.r);
	}
};
void FFT(C x[],int n,int p)
{
	for(int i = 0, t = 0; i < n; ++i)
	{
		if(i > t) swap(x[i], x[t]);
		for(int j = n >> 1;(t ^= j) < j; j >>= 1);
	}
	for(int h = 2;h <= n;h <<= 1)
	{
		C wn(cos(p * 2 * PI / h),sin(p * 2 * PI / h));
		for(int i = 0; i < n; i += h)
		{
			C w(1,0),u;
			for(int j = i, k = h >> 1;j < i + k; ++j)
			{
				u = x[j + k] * w;
				x[j + k] = x[j] - u;
				x[j] = x[j] + u;
				w = w * wn;
			}
		}
	}
	if (p == -1)
		for(int i=0;i<n;++i)
			x[i].r /= n;
}
void conv(C a[],C b[],int n)
{
	FFT(a,n,1);
	FFT(b,n,1);
	for(int i=0;i<n;++i)
		a[i]=a[i]*b[i];
	FFT(a,n,-1);
}
const int maxn=5e5+7;
C A[maxn],B[maxn];
int arr[maxn/5];
LD ans[maxn];
long long pre[maxn/5];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int tot=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			tot+=arr[i];
			if(i>0) pre[i]=pre[i-1]+arr[i];
			else pre[0]=arr[0];
		}
		const int var=tot+1;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		int len=1;
		while(len<3*var) len*=2;
		for(int i=0;i<n;i++)
			A[pre[i]+var].r+=i+1;
		for(int i=1;i<n;i++)
			B[var-pre[i-1]].r+=1;
		B[var].r+=1;
		conv(A,B,len);
		for(int i=0;i<len;i++) ans[i]=A[i].r;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		for(int i=1;i<n;i++)
			A[var-pre[i-1]].r+=i;
		for(int i=0;i<n;i++)
			B[var+pre[i]].r+=1;
		conv(A,B,len);
		for(int i=0;i<len;i++) ans[i]-=A[i].r;
		ans[2*var]=0;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(!arr[i])
				cnt++,ans[2*var]+=cnt*(cnt+1)/2;
			else cnt=0;
		}
		for(int i=0;i<=tot;i++)
			printf("%lld\n",(long long)(ans[i+2*var]+0.5));
	}
}
