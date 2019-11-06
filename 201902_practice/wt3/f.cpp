#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef pair<int,int> PII;
int arr[maxn];
vector<int> all;
int nxt[maxn];
int pre[maxn];
int inq[maxn];
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		all.clear();
		memset(inq,0,sizeof(inq));
		memset(pre,0x3f,sizeof(pre));
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			all.push_back(arr[i]);
		}
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		for(int i=0;i<n;i++)
			arr[i]=getid(arr[i]);
		for(int i=n-1;i>=0;i--)
		{
			nxt[i]=pre[arr[i]];
			pre[arr[i]]=i;
		}
		priority_queue<PII> q;
		int cnt=0;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(inq[arr[i]])
			{
				q.push(make_pair(nxt[i],arr[i]));
			}
			else{
				while(cnt==k)
				{
					inq[q.top().second]--;
					if(!inq[q.top().second]) cnt--;
					q.pop();
				}
				q.push(make_pair(nxt[i],arr[i]));
				if(!inq[arr[i]]) cnt++;
				inq[arr[i]]++;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
