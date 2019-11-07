#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int ext[maxn*50];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int q;
	cin>>q;
	while(q--)
	{
		int m;
		cin>>m;
		int cur=0;
		int l=-1,r=-1;
		int upp=1;
		for(int i=s.length()-1;i>=0;i--)
		{
			cur=cur+(s[i]-'0')*upp%m;
			cur%=m;
			upp=upp*10%m;
			if(ext[cur])
			{
				r=ext[cur],l=i+1;
				break;
			}
			if(cur==0)
			{
				l=i+1,r=s.length();
				break;
			}
			ext[cur]=i;
		}
		if(l==-1||r==-1) cout<<"-1"<<endl;
		else cout<<l<<" "<<r<<endl;
		for(int i=0;i<=m;i++) ext[i]=0;
	}
}

