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
const int maxn=1e6+7;
C A[maxn],B[maxn];
int image[maxn/4],msg[maxn/4];
int match[maxn/4];
vector<int> ok;
int f[maxn/4];
void getfail(int b[],int len)
{
	int i,j;
	j=f[0]=-1;
	i=0;
	while(i<len)
	{
		while(j!=-1&&b[i]/2!=b[j]/2) j=f[j];
		f[++i]=++j;
	}
}
void kmp(int a[],int b[],int n,int m)
{
	getfail(b,m);
	int i,j;
	int ret=0;
	i=j=0;
	while(i<n)
	{
		while(j!=-1&&a[i]/2!=b[j]/2) j=f[j];
		i++,j++;
		if(j>=m)
		{
			ok.push_back(i-m);
			j=f[j];
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	string temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		for(int j=7;j>=0;j--)
			if(temp[7-j]=='1') image[i]+=(1<<j);
	}
	for(int i=0;i<m;i++)
	{
		cin>>temp;
		for(int j=7;j>=0;j--)
			if(temp[7-j]=='1') msg[i]+=(1<<j);
	}
	kmp(image,msg,n,m);
	reverse(msg,msg+m);
	int len=1;
	while(len<=(n+m)) len*=2;
	for(int i=0;i<n;i++)
		if(image[i]&1) A[i].r=1;
	for(int i=0;i<m;i++)
		if(msg[i]&1) B[i].r=1;
	conv(A,B,len);
	for(int i=0;i<n;i++)
		match[i]+=(int)(A[i+m-1].r+0.5);
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	for(int i=0;i<n;i++)
		if(!(image[i]&1)) A[i].r=1;
	for(int i=0;i<m;i++)
		if(!(msg[i]&1)) B[i].r=1;
	conv(A,B,len);
	for(int i=0;i<n;i++)
		match[i]+=(int)(A[i+m-1].r+0.5);
	if(!ok.size())
		cout<<"No"<<endl;
	else{
		cout<<"Yes"<<endl;
		int ans=0x3f3f3f3f;
		int index=0;
		for(int i=0;i<ok.size();i++)
		{
			if(ans>m-match[ok[i]])
			{
				ans=m-match[ok[i]];
				index=ok[i]+1;
			}
		}
		cout<<ans<<" "<<index<<endl;
	}

}
