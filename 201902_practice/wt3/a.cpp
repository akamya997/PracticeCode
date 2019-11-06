#include<bits/stdc++.h>
using namespace std;
map<int,int> app;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		app.clear();
		int n;
		cin>>n;
		string s;
		int f;
		int ans=0;
		int mx=0;
		for(int i=0;i<n;i++)
		{
			cin>>s>>f;
			app[f]++;
			if(mx<=app[f])
			{
				if(mx==app[f]) ans=min(ans,f);
				else ans=f;
				mx=app[f];
			}
		}
		cout<<ans<<endl;
	}
}
