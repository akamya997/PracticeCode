#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1e5+7;
int trie[maxn][10];
bool isw[maxn];
string ss[maxn];
int tot=0;
void Insert(string &s)
{
	int rt=0;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		int id=s[i]-'0';
		if(!trie[rt][id]) trie[rt][id]=++tot;
		rt=trie[rt][id];
	}
	isw[rt]=true;
}
bool Find(string &s)
{
	int rt=0;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(isw[rt]) return false;
		int id=s[i]-'0';
		rt=trie[rt][id];
	}
	return true;
}
void init()
{
	for(int i=0;i<=tot;i++)
	{
		isw[i]=0;
		for(int j=0;j<10;j++)
			trie[i][j]=0;
	}
	tot=0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		int n;
		scanf("%d",&n);
		char temp[15];
		for(int i=0;i<n;i++)
		{
			scanf("%s",temp);
			ss[i]=temp;
			Insert(ss[i]);
		}
		bool ok=1;
		for(int i=0;i<n;i++)
		{
			ok=Find(ss[i]);
			if(!ok) break;
		}
		if(ok) puts("YES"); 
		else puts("NO"); 
	}
}
