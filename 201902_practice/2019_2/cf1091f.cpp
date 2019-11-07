#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long arr[maxn];
string s;
long long lim[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>s;
	long long allneed=0;fast=0;
	vector<int> path;
	vector<pair<int,long long> > block;
	long long pre=n;
	long long tot=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='L')
		{
			allneed+=arr[i];
			if(lim[i+1]<0)
			{
				long long use=-lim[i+1];
				use/=2;
				lim[i+1]=0;
				long long st=0;
				for(int j=path.size()-1;j>=0;j--)
				{
					int cur=path[j];
					int pos=i+j-path.size()+2;
					st+=arr[pos];
					if(cur==5)
					{
						if(st>=use*2)
						{
							fast+=use*4;
							use=0;
						}
						else{
							fast+=st/2*4;
							use-=st/2;
							st-=st/2;
						}
					}
				}
				if(use) fast+=use*2;
			}
			else if(lim[i+1]>0) block.push_back(make_pair(pre,lim[i+1]));
			lim[i]=arr[i];
			pre=i;
			tot=0;
			path.clear();
		}
		else if(s[i]=='W')
		{
			allneed+=arr[i]*3;
			tot+=arr[i];
			lim[i]=lim[i+1]-arr[i];
			path.push_back(3);
		}
		else{
			allneed+=arr[i]*5;
			tot+=arr[i];
			lim[i]=lim[i+1]-arr[i];
			path.push_back(5);
		}
	}
	int fiw=0x3f3f3f3f;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='W')
		{
			fiw=i;break;
		}
	}
	allneed-=fast;
	for(int i=block.size()-1;i>=0;i--)
	{
		auto cur=block[i];
		if(cur.first<fiw)
		{
			
		}
	}

}
