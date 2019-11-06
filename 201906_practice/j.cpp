#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=2e5+7;
char s[maxn];
char tmp[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], rk[maxn], height[maxn];

void build_sa(int m, int n)
{ //n为字符串的长度,字符集的值为0~m-1
    n++;
    int *x = t, *y = t2;
    //基数排序
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; ~i; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    { //直接利用sa数组排序第二关键字
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k) y[p++] = sa[i] - k;
        //基数排序第一关键字
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--) sa[--c[x[y[i]]]] = y[i];
        //根据sa和y数组计算新的x数组
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n) break; //以后即使继续倍增，sa也不会改变，推出
        m = p;             //下次基数排序的最大值
    }
    n--;
    int k = 0;
    for (int i = 0; i <= n; i++) rk[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
}
int dp[maxn][30];
void initrmq(int n)
{
    for (int i = 1; i <= n; i++)
        dp[i][0] = height[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
int rmq(int l, int r)
{
	int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int len;
int lcp(int a, int b)
{ // 求两个后缀的最长公共前缀
	if(a==b) return len-a;
    a = rk[a], b = rk[b];
    if (a > b) swap(a, b);
    return rmq(a + 1, b);
}
int f[maxn];
int lson[maxn*32],rson[maxn*32];
int sum[maxn*32];
int tot;
#define Lson lson[o],L,mid
#define Rson rson[o],mid+1,R
struct sgt{
	int rt;
	sgt(){rt=0;}
	void add(int p,int val,int& o,int L=0,int R=len-1)
	{
		assert(tot<maxn*32);
		if(!o)
			o=++tot,sum[o]=0,lson[o]=0,rson[o]=0;
		sum[o]+=val;
		if(L==R)
			return;
		int mid=L+R>>1;
		if(p<=mid) add(p,val,Lson);
		else add(p,val,Rson);
	}
	int query(int l,int r,int &o,int L=0,int R=len-1)
	{
		if(!o) return 0;
		if(l<=L&&r>=R)
			return sum[o];
		int mid=L+R>>1;
		int ret=0;
		if(l<=mid) ret+=query(l,r,Lson);
		if(r>mid) ret+=query(l,r,Rson);
		//dbg(ret,L,R);
		return ret;
	}
};
sgt tree[maxn];
void add(int x,int pos,int val)
{
	while(x<=len)
	{
		tree[x].add(pos,val,tree[x].rt);
		x+=x&-x;
	}
}
int query(int x,int l,int r)
{
	int ret=0;
	while(x)
	{
		//dbg(x);
		ret+=tree[x].query(l,r,tree[x].rt);
		x-=x&-x;
	}
	return ret;
}
void upd(int x,int val)
{
	add(x,sa[x],val);
}
int ry(int l,int r,int l1,int r1)
{
	return query(r,l1,r1)-query(l-1,l1,r1);
}
int main()
{
	int T;
	scanf("%d",&T);
	int ans=0;
	while(T--)
	{
		//memset(sum,0,sizeof(sum));
		//memset(lson,0,sizeof(lson));
		//memset(rson,0,sizeof(rson));
		//memset(tree,0,sizeof(tree));
		ans=0;
		tot=0;
		scanf("%s",s);
		int pos=strlen(s);
		reverse(s,s+pos);
		s[pos]='$';
		scanf("%s",tmp);
		int tlen=strlen(tmp);
		reverse(tmp,tmp+tlen);
		for(int i=0;i<=tlen;i++)
			s[pos+i+1]=tmp[i];
		len=strlen(s);
		for(int i=0;i<=len;i++) tree[i].rt=0;
		build_sa(128,len);
		initrmq(len);
		for(int i=pos-1;i>=0;i--)
		{
			scanf("%d",&f[i]);
			upd(rk[i],f[i]);
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int op;
			scanf("%d",&op);
			if(op==1)
			{
				int xx,val;
				scanf("%d%d",&xx,&val);
				xx^=ans;
				val^=ans;
				xx=pos-1-xx;
				upd(rk[xx],val-f[xx]);
				f[xx]=val;
			}
			else{
				int a,b,c,d;
				scanf("%d%d%d%d",&a,&b,&c,&d);
				a^=ans,b^=ans,c^=ans,d^=ans;
				a=pos+1+tlen-1-a;
				b=pos+1+tlen-1-b;
				c=pos-1-c;
				d=pos-1-d;
				swap(a,b);swap(c,d);
				cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
				assert(a<=b);
	//			dbg(a,b,c,d);
				assert(c<=d);
				int qlen=b-a+1;
				int l=1,r=rk[a],lpos=rk[a];
				while(l<=r)
				{
					int mid=l+r>>1;
					if(lcp(sa[mid],a)>=qlen) r=mid-1,lpos=mid;
					else l=mid+1;
				}
				l=rk[a],r=len;
				int rpos=rk[a];
				while(l<=r)
				{
					int mid=l+r>>1;
					if(lcp(sa[mid],a)>=qlen) l=mid+1,rpos=mid;
					else r=mid-1;
				}
	//			assert(lpos<=rpos);
				//dbg(c,d-qlen+1);
				//assert(c<=d-qlen+1);
	//			dbg(lpos,rpos,c,d-qlen+1);
				assert(lpos<=rpos);
				cout<<c<<"<="<<d-qlen+1<<endl;
				if(c>d-qlen+1) ans=0;
				else ans=ry(lpos,rpos,c,d-qlen+1);
				printf("%d\n",ans);
				fflush(stdout);
			}
		}
		//dbg(tot);

	}
}
