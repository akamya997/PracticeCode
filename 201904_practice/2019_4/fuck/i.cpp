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
struct node{
	node *fail;
	node *next[10];
	int cnt;
	int id;
	bool ok;
	node():fail(NULL),cnt(0),id(countnode++),ok(0){memset(next,0,sizeof(next));}
};
node* root;
int n;
int a[105];
struct num{
	long long cnt,sum;
};
num dp[105][2][2][7][505];
void build_ac_automation(node *root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* cur=q.front();q.pop();
		for(int i=0;i<10;i++)
		{
			node* &v=cur->next[i];
			if(v)
			{
				node *temp=cur->fail;
				while(temp)
				{
					if(temp->next[i])
					{
						v->fail=temp->next[i];
						break;
					}
					temp=temp->fail;
				}
				if(!temp) v->fail=root;
				q.push(v);
			}
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
	cur->cnt++;
}
bool vis[105][2][2][7][505];
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
num dfs(int pos,bool limit,bool zero,int mark,node* cur=root)
{
	if(pos==-1)
	{
		if(mark==n)
			return {1,0};
		else return {0,0};
	}
	if(vis[pos][limit][zero][mark][cur->id]) return dp[pos][limit][zero][mark][cur->id];
	vis[pos][limit][zero][mark][cur->id]=1;
	int up=limit?a[pos]:9;
	num ret={0,0};
	for(int i=0;i<=up;i++)
	{
		node* nxt=cur;
		int nxtnum=mark;
		vector<node*> ins;
		if((!zero)||i)
		{
			while(!nxt->next[i]&&nxt!=root) nxt=nxt->fail;
			nxt=nxt->next[i];
			nxt=nxt?nxt:root;
			node *temp=nxt;
			while(temp!=root&&!temp->ok)
			{
				nxtnum+=temp->cnt;
				ins.push_back(temp);
				temp->ok=1;
				temp=temp->fail;
			}
		}
		num getting=dfs(pos-1,limit&&i==up,zero&&i==0,nxtnum,nxt);
		for(auto p:ins) p->ok=0;
		ret.sum=ret.sum+getting.cnt*i*quick(10,pos)%mod+getting.sum;
		ret.sum%=mod;
		ret.cnt=(ret.cnt+getting.cnt)%mod;
	}
	return dp[pos][limit][zero][mark][cur->id]=ret;
}
long long solve(string s)
{
	int pos=0;
	for(int i=s.length()-1;i>=0;i--)
	{
		a[pos++]=s[i]-'0';
	}
	return dfs(pos-1,1,1,0).sum;
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
	build_ac_automation(root);
	cout<<(solve(r)-solve(l)+mod)%mod<<endl;
}
