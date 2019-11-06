#include<bits/stdc++.h>
using namespace std;
int cnt[26];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		string a,b;
		cin>>a>>b;
		for(int i=0;i<b.length();i++)
		{
			cnt[b[i]-'a']++;
		}
		int ans=0;
		for(int i=0;i<a.length();i++)
		{
			if(cnt[a[i]-'a'])
			{
				ans++;
				cnt[a[i]-'a']--;
			}
			else break;
		}
		cout<<ans<<endl;
	}
}
