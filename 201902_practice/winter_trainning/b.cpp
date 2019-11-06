#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int brr[maxn];
long long sub[maxn];
int pre[maxn];
int nxt[maxn];
int main()
{
	int n,m;
	ignore=scanf("%d%d",&n,&m);
	pre[0]=-1;
	nxt[n-1]=-1;
	for(int i=0;i<n;i++) 
	{
		ignore=scanf("%d",&arr[i]);
		if(i) pre[i]=i-1;
		if(i!=n-1) nxt[i]=i+1;
	}
	for(int i=0;i<n;i++) ignore=scanf("%d",&brr[i]);
	int cnt=0,tot=n;
	for(int i=0;i<n;i++)
	{
		if(i) sub[i]=arr[i]-arr[i-1];
		else {
			sub[i]=arr[i];
			continue;
		}
		if(sub[i]%m==0) cnt++;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(tot==1||cnt==tot-1) break;
		int cur=brr[i]-1;
		if(sub[cur]%m==0&&pre[cur]!=-1) cnt--;
		if(pre[cur]!=-1) nxt[pre[cur]]=nxt[cur];
		if(nxt[cur]!=-1)
		{
			pre[nxt[cur]]=pre[cur];
			if(sub[nxt[cur]]%m==0) cnt--;
			sub[nxt[cur]]+=sub[cur];
			if(sub[nxt[cur]]%m==0&&pre[nxt[cur]]!=-1) cnt++;
		}
		ans++;
		tot--;
	}
	printf("%d\n",ans);
}
