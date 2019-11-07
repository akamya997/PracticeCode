#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef pair<int,int> PII;
int nxt[maxn];
int arr[maxn];
map<int,int> pre;
map<int,int> cur;
struct cmp{
	bool operator()(const PII &a,const PII &b)const{
		return a.second<b.second;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		pre.clear();
		cur.clear();
		memset(nxt,0x3f,sizeof(nxt));
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) 
		{
			cin>>arr[i];
			if(pre[arr[i]]!=0) nxt[pre[arr[i]]]=i;
			pre[arr[i]]=i;
		}
		set<PII,cmp> table;
		int ans=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cur[arr[i]]!=0)
			{
				PII del=make_pair(arr[i],i);
				table.erase(del);
				table.insert(make_pair(arr[i],nxt[i]));
				continue;
			}
			ans++;
			cnt++;
			if(cnt>k)
			{
				cnt--;
				auto del=*(--table.end());
				cur[del.first]=0;
				table.erase(del);
			}
			table.insert(make_pair(arr[i],nxt[i]));
			cur[arr[i]]=nxt[i];
		}
		cout<<ans<<endl;
	}
}
