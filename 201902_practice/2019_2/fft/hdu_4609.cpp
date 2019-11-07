#include<bits/stdc++.h>
using namespace std;
typedef double LD;
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
const int maxn=4e5+7;
int arr[maxn];
C A[maxn],B[maxn];
long long pre[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(pre,0,sizeof(pre));
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		int n;
		scanf("%d",&n);
		int len=1;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			A[arr[i]].r++;
			B[arr[i]].r++;
			while(len<=arr[i]*2) len<<=1;
		}
		conv(A,B,len);
		for(int i=0;i<n;i++)
			A[arr[i]*2].r--;
		for(int i=0;i<len;i++)
			A[i].r/=2;
		for(int i=1;i<=len;i++)
			pre[i]=pre[i-1]+round(A[i].r);
		long long ans=0;
		sort(arr,arr+n);
		long long cur=0;
		for(int i=0;i<n;i++)
		{
			ans+=pre[len]-pre[arr[i]];
			ans-=1LL*(n-1-i)*i;
			ans-=n-1;
			ans-=1LL*(n-1-i)*(n-i-2)/2;
		}
		printf("%.7f\n",(LD)ans*6/(1LL*n*(n-1)*(n-2)));
	}
}
