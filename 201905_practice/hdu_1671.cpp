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
struct Trie{
	Trie *ch[10];
	bool isw;
	Trie ():isw(0){memset(ch,0,sizeof(ch));}
};
Trie *rt;
void del(Trie *cur)
{
	if(!cur) return;
	for(int i=0;i<10;i++)
		del(cur->ch[i]);
	delete cur;
}
bool ok=0;
void Insert(char *str)
{
	int len=strlen(str);
	Trie* cur=rt;
	for(int i=0;i<len;i++)
	{
		int c=str[i]-'0';
		if(i==len-1&&cur->ch[c]) ok=0;
		if(!cur->ch[c])
			cur->ch[c]=new Trie();
		cur=cur->ch[c];
		if(cur->isw) ok=0;
	}
	cur->isw=1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ok=1;
		rt=new Trie();
		int n;
		scanf("%d",&n);
		char str[20];
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			Insert(str);
		}
		del(rt);
		if(ok) puts("YES");
		else puts("NO");
	}
}
