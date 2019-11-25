#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
const int maxn=1e6+7;
C A[maxn],B[maxn];
char str[maxn];
void conv(int a[],int b[],int n)
{
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	for(int i=0;i<n;i++)
	{
		A[i].r=a[i];
		B[i].r=b[i];
	}
	FFT(A,n,1);
	FFT(B,n,1);
	for(int i=0;i<n;++i)
		A[i]=A[i]*B[i];
	FFT(A,n,-1);
	for(int i=0;i<n;i++)
		a[i]=A[i].r+0.5;
}
struct num{
	int a[maxn],mm;
	inline void zero(){memset(a,0,sizeof(a));mm=1;}
	inline void input()
	{
		memset(a,0,sizeof(a));
		scanf("%s",str);
		mm=strlen(str);
		for(int i=mm-1;i>=0;i--)
			a[mm-i-1]=str[i]-'0';
	}
	bool operator <=(const num &b)const{
		if(mm==b.mm)
		{
			for(int i=mm-1;i>=0;i--)
			{
				if(a[i]>b.a[i])
					return false;
				else if(a[i]<b.a[i]) return true;
			}
			return true;
		}
		return mm<b.mm;
	}
	num operator +(num& b)
	{
		num ret;
		ret.zero();
		for(int i=0;i<max(mm,b.mm);i++)
		{
			ret.a[i]+=a[i]+b.a[i];
			if(ret.a[i]>=10)
			{
				ret.a[i+1]+=ret.a[i]/10;
				ret.a[i]%=10;
			}
		}
		ret.mm=max(mm,b.mm);
		if(ret.a[ret.mm]) ret.mm++;
		return ret;
	}
	num operator -(const int & t)
	{
		for(int i=0;i<mm;i++)
		{
			if(a[i])
			{
				a[i]-=t;
				break;
			}
			else{
				a[i]=9;
			}
		}
		if(!a[mm-1]) mm--;
		return *this;
	}
	num operator *(num &b){
		int len=1;
		while(len<(b.mm+mm)) len*=2;
		conv(a,b.a,len);
		for(int i=0;i<len;i++)
		{
			if(a[i]) mm=i+1;
			if(a[i]>=10)
			{
				a[i+1]+=a[i]/10;
				a[i]=a[i]%10;
			}
		}
		return *this;
	}
	num plusone()
	{
		for(int i=0;i<mm;i++)
		{
			if(a[i]!=9)
			{
				a[i]++;
				break;
			}
			else{
				a[i]=0;
			}
		}
		if(a[mm]) mm++;
		return *this;
	}
	num operator/(const int &b)const{
		num ret;
		int cur=0;
		for(int i=mm-1;i>=0;i--)
		{
			ret.a[i]=(cur*10+a[i])/b;
			cur=(cur*10+a[i])%b;
		}
		ret.mm=1;
		for(int i=mm-1;i>=0;i--)
			if(ret.a[i])
			{
				ret.mm=i+1;
				break;
			}
		return ret;
	}
	num (){}
	num (const num& T):mm(T.mm)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<mm;i++)
			a[i]=T.a[i];
	}
	num & operator=(const num &b)
	{
		mm=b.mm;
		memset(a,0,sizeof(a));
		for(int i=0;i<mm;i++)
			a[i]=b.a[i];
		return *this;
	}
	inline void output()
	{	
	//	cout<<"len:"<<mm<<endl;
		for(int i=mm-1;i>=0;i--)
			printf("%d",a[i]);
		puts("");
	}
};
num up;
num one;
num two;
num l,r,mid,cur,ret;
num ans;
int b;
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	one.a[0]=1;one.mm=1;two.mm=1;
	int n;
	scanf("%d",&n);
	up.input();
	l.zero();
	two.a[0]=8;
	if(n<10)
	{
		b=10-n;
		ret=two;
		two=one;
		while(b)
		{
			if(b&1) two=two*ret;
			ret=ret*ret;
			b>>=1;
		}
	}
	//two=up/(n*n*n*n*n);
	r=one;
	cur=one;
	ans=l;
	while(cur<=up)
	{
		l=r;
		r=r*two;
		cur=r;
		ret=cur;
		cur=one;
		b=n;
		while(b)
		{
			if(b&1) cur=cur*ret;
			ret=ret*ret;
			b>>=1;
		}
	}
	while(l<=r)
	{
		mid=(l+r)/2;
		ret=mid;
		cur=one;
		b=n;
		while(b)
		{
			if(b&1) cur=cur*ret;
			ret=ret*ret;
			b>>=1;
		}
	//	cur.output();
	//	up.output();
		if(cur<=up) ans=mid,l=mid.plusone();
		else r=mid-1;
	//	l.output(),r.output();
	//	cout<<"sum:";
	//	sum.output();
	//	cout<<"mid:";
	//	mid.output();
	}
	ans.output();
}

