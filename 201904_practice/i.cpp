#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=998244353;
int countnode=0;
int idx=0;
struct node{
	node *fail;
	node *next[10];
	int cnt;
	int id;
	node():fail(NULL),cnt(0),id(countnode++){memset(next,0,sizeof(next));}
};
node* root;
int n;
int a[105];
struct num{
	long long cnt,sum;
};
void build_ac_automation(node *root)
{
	root->fail=root;
	queue<node*> q;
	for (int i = 0; i < 10; i++)
	{
		if (root->next[i])
		{
			root->next[i]->fail = root;
			q.push(root->next[i]);
		}
		else
			root->next[i] = root;
	}
	while(!q.empty())
	{
		node* u = q.front();
		q.pop();
		u->cnt |= u->fail->cnt;
		for (int c = 0; c < 10; c++)
		{
			if (u->next[c])
			{
				u->next[c]->fail = u->fail->next[c];
				q.push(u->next[c]);
			}
			else
				u->next[c] = u->fail->next[c];
		}
	}
}
void insert(string s,node* root)
{
	node* cur=root;
	for(int i=0;i<s.length();i++)
	{
		int index=s[i]-'0';
		if(!cur->next[index]) cur->next[index]=new node();
		cur=cur->next[index];
	}
	cur->cnt|=(1<<idx);
	idx++;
}
long long quick(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
num dp[105][105][505];
bool vis[105][105][505];
num dfs(int pos,bool limit,bool zero,int mark,node* cur=root)
{
	if(pos==-1)
	{
		if(mark==(1<<n)-1)
			return {1,0};
		return {0,0};
	}
	if (!limit && !zero && vis[pos][mark][cur->id]) return dp[pos][mark][cur->id];
	if(!limit&&!zero) vis[pos][mark][cur->id]=1;
	int up=limit?a[pos]:9;
	num ret={0,0};
	for(int i=0;i<=up;i++)
	{
		node* nxt=cur;
		int nxtnum=mark;
		if((!zero)||i)
		{
			nxt=nxt->next[i];
			assert(nxt);
			nxtnum|=nxt->cnt;
		}
		num getting=dfs(pos-1,limit&&i==up,zero&&i==0,nxtnum,nxt);
		ret.sum=ret.sum+getting.cnt*i%mod*quick(10,pos)%mod+getting.sum;
		ret.sum%=mod;
		ret.cnt=(ret.cnt+getting.cnt)%mod;
	}
	if(!limit&&!zero) dp[pos][mark][cur->id]=ret;
	return ret;
}
long long solve(string s)
{
	int pos=0;
	for(int i=s.length()-1;i>=0;i--)
	{
		a[pos++]=s[i]-'0';
	}
	int res=dfs(pos-1,1,1,0).sum;
	dbg(res);
	return res;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	root=new node();
	cin>>n;
	string s;
	string l,r;
	cin>>l>>r;
	for(int i=l.length()-1;i>=0;i--)
	{
		if(l[i]!='0')
		{
			l[i]--;
			if(i==0&&l[i]=='0')
			{
				string t;
				for(int i=1;i<l.length();i++) t+=l[i];
				l=t;
				if(!l.length()) l+='0';
			}
			break;
		}
		else{
			l[i]='9';
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>s;
		insert(s,root);
	}
	assert(countnode<505);
	build_ac_automation(root);
	cout<<(solve(r)-solve(l)+mod)%mod<<endl;
}
