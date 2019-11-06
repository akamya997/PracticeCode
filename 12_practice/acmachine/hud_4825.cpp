#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int trie[maxn][2];
int tot=0;
void init()
{
	for(int i=0;i<=tot;i++)
		trie[i][0]=trie[i][0]=0;
	tot=0;
}
void change(int n,int *ret)
{
	int cnt=1;
	while(n)
	{
		ret[32-cnt]=n%2;
		n/=2;
		cnt++;
	}
}
void Insert(int n)
{
	int rt=0;
	int now[35];
	memset(now,0,sizeof(now));
	change(n,now);
	for(int i=0;i<32;i++)
	{
		int id=now[i];
		if(!trie[rt][id]) trie[rt][id]=++tot;
		rt=trie[rt][id];
	}
}
int Find(int n)
{
	vector<int> ret;
	int now[35];
	memset(now,0,sizeof(now));
	change(n,now);
	int rt=0;
	for(int i=0;i<32;i++)
	{
		int id=now[i]^1;
		if(trie[rt][id]){
			ret.push_back(id);
			rt=trie[rt][id];
		}
		else{
			ret.push_back(id^1);
			rt=trie[rt][id^1];
		}
	}
	int ans=0;
	int base=1;
	for(int i=31;i>=0;i--)
	{
		ans+=base*ret[i];
		base*=2;
	}
	return ans;

}
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0,temp;i<n;i++)
		{
			scanf("%d",&temp);
			Insert(temp);
		}
		int temp;
		printf("Case #%d:\n",++kas);
		while(m--)
		{
			scanf("%d",&temp);
			int ans=Find(temp);
			printf("%d\n",ans);
		}
	}
}
