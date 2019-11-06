#include<bits/stdc++.h>
using namespace std;
const int N =2e5+5;
int ch[N][26],step[N],pre[N];
int to[N],topo[N];
int sz,last;
void ins(int x)
{
	int np=++sz,p=last;
	last=np;
	step[np]=step[p]+1;
	while(!ch[p][x]&&p)
		ch[p][x]=np,p=pre[p];
	if(!p)
		pre[np]=1;
	else
	{
		int q=ch[p][x];
		if(step[q]==step[p]+1)
			pre[np]=q;
		else
		{
			int nq=++sz;
			step[nq]=step[p]+1;
			for(int i=0;i<26;++i)
				ch[nq][i]=ch[q][i];
			pre[nq]=pre[q];
			pre[q]=pre[np]=nq;
			while(ch[p][x]==q&&p)
				ch[p][x]=nq,p=pre[p];
		}
	}
}

void toposort()
{
	for(int i=1;i<=sz;++i)
		++to[step[i]];
	for(int i=1;i<=sz;++i)
		to[i]+=to[i-1];
	for(int i=1;i<=sz;++i)
		topo[to[step[i]]--]=i;
}
int mx[N],mm[N];

string a;
int main()
{
	cin>>a;
	sz=last=1;
	for(int i=0;i<a.length();++i)
		ins(a[i]-'a');
	memset(mm,0x3f,sizeof(mm));
	while(cin>>a)
	{
		int cur=1,len=0;
		for(int i=0;i<=a.length();++i)
		{
			int nx=a[i]-'a';
			while(!ch[cur][nx]&&cur)
			{
				cur=pre[cur];
				len=step[cur];
			}
			if(!cur)
			{
				cur=1;
				continue;
			}
			cur=ch[cur][nx];
			len++;
			mx[cur]=max(mx[cur],len);
		}
		for(int i=sz;i>0;--i)
		{
			mx[pre[i]]=max(mx[pre[i]],min(step[pre[i]],mx[i]));
			mm[i]=min(mm[i],mx[i]);
			mx[i]=0;
		}
	}
	int ans=0;
	for(int i=sz;i>1;--i)
		ans=max(ans,mm[i]);
	if(ans==0x3f3f3f3f)
		ans=0;
	cout<<ans<<endl;
}
