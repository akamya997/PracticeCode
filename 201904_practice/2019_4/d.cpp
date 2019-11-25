#include<bits/stdc++.h>
using namespace std;
int arr[1200];
int ans[1200];
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<1050;i++) arr[i]=i;
	while(T--)
	{
		memset(ans,0,sizeof(ans));
		int n,b,f;
		cin>>n>>b>>f;
		for(int i=0;i<10;i++)
		{
			string op="";
			for(int j=0;j<n;j++)
			{
				op+=((j>>i)&1)+'0';
			}
			cout<<op<<endl;
			string ret;
			cin>>ret;
			for(int j=0;j<n-b;j++)
			{
				ans[j]+=((ret[j]-'0')<<i);
			}
		}
		sort(ans,ans+n-b);
		vector<int> all;
		int cur=0;
		for(int i=0;i<n;i++)
		{
			if(ans[cur]>i||cur>=n-b) all.push_back(i);
			else cur++;
		}
		for(int i=0;i<all.size();i++) cout<<all[i]<<" ";
		cout<<endl;
		int vedict;
		cin>>vedict;
		if(vedict==-1) break;
	}
}
