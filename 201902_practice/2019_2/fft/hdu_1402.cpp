#include<bits/stdc++.h>
using namespace std;
typedef double LD;
const LD PI=3.141592653589;
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
const int maxn=2e5+7;
C A[maxn],B[maxn];
int ans[maxn];
string a,b;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>a>>b)
	{
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(ans,0,sizeof(ans));
		int len=1;
		while(len<a.length()+b.length()) len<<=1;
		for(int i=a.length()-1;i>=0;i--)
			A[a.length()-i-1].r=a[i]-'0';
		for(int i=b.length()-1;i>=0;i--)
			B[b.length()-i-1].r=b[i]-'0';
		conv(A,B,len);
		int up=0;
		for(int i=0;i<len;i++)
		{
			ans[i]+=round(A[i].r);
			if(ans[i]) up=i;
			if(ans[i]>=10)
				ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		for(int i=up;i>=0;i--)
			cout<<ans[i];
		cout<<endl;
	}
}
