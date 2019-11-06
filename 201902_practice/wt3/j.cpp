#include<bits/stdc++.h>
using namespace std;
string str,cur;
const int maxn=1e5+7;
int arr[maxn];
int tot=0;
int all=0;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	getline(cin,str);
	while(T--)
	{
		tot=0;all=0;
		getline(cin,str);
		stringstream s(str);
		while(s>>cur) arr[tot++]=cur.length()+1,all+=arr[tot-1];
		vector<int> fac;
		bool ok=0;
		for(int i=1;i*i<=all;i++)
		{
			if(all%i==0) fac.push_back(i);
			if(i*i!=all&&i!=1) fac.push_back(all/i);
		}
		for(auto &p:fac)
		{
			int cur=0;
			for(int i=0;i<tot;i++)
			{
				cur+=arr[i];
				if(cur>p)
					break;
				if(cur==p)
				{
					cur=0;
					if(i==tot-1) ok=1;
				}
			}
			if(ok) break;
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
