#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
map<ll,int> cnt;
struct Card{
	int c[4];
	void modify()
	{
		vector<vi> a(4);
		for(int i=0;i<4;i++)
		{
			for(int j=i;j<4;j++) a[i].push_back(c[j]);
			for(int j=0;j<i;j++) a[i].push_back(c[j]);
		}
		sort(a.begin(),a.end());
		for(int i=0;i<4;i++) c[i]=a[0][i];
	}
	inline int factor()
	{
		if(c[0]==c[1]&&c[1]==c[2]&&c[2]==c[3]) return 4;
		if(c[0]==c[2]&&c[1]==c[3]) return 2;
		return 1;
	}
}card[500];
inline ll Hash(Card a)
{
	ll ret=0;
	ll step=1000000000;
	for(int i=0;i<4;i++)
	{
		ret+=1LL*a.c[i]*step;
		step/=1000;
	}
	return ret;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Card &cc=card[i];
		cin>>cc.c[0]>>cc.c[1]>>cc.c[2]>>cc.c[3];
		cc.modify();
		cnt[Hash(cc)]++;
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cnt[Hash(card[i])]--;
			cnt[Hash(card[j])]--;
			for(int k=0;k<4;k++)
			{
				Card up;
				int p=0;
				for(int kk=k;kk<4;kk++)
					up.c[p++]=card[i].c[kk];
				for(int kk=0;kk<k;kk++)
					up.c[p++]=card[i].c[kk];
				Card down=card[j];
				Card Back={up.c[0],down.c[1],down.c[0],up.c[1]};
				Card Front={up.c[3],up.c[2],down.c[3],down.c[2]};
				Card Left={up.c[0],up.c[3],down.c[2],down.c[1]};
				Card Right={up.c[2],up.c[1],down.c[0],down.c[3]};
				Back.modify();
				Front.modify();
				Left.modify();
				Right.modify();
				ll cur=1;
				ll bn=Hash(Back),fn=Hash(Front),ln=Hash(Left),rn=Hash(Right);
				//dbg(i,j,k,bn,fn,ln,rn);
				bool ok=1;
				if(!cnt[bn]) ok=0;
				cur*=cnt[bn];
				cnt[bn]--;
				if(!cnt[fn]) ok=0;
				cur*=cnt[fn];
				cnt[fn]--;
				if(!cnt[ln]) ok=0;
				cur*=cnt[ln];
				cnt[ln]--;
				if(!cnt[rn]) ok=0;
				cur*=cnt[rn];
				cnt[rn]--;
				cur*=Back.factor()*Front.factor()*Left.factor()*Right.factor();
				cnt[bn]++;
				cnt[fn]++;
				cnt[ln]++;
				cnt[rn]++;
				if(ok)
					ans+=cur;
			}
			cnt[Hash(card[i])]++;
			cnt[Hash(card[j])]++;
			//dbg(i,j,ans);
		}
	}
	cout<<ans/3<<endl;

}
