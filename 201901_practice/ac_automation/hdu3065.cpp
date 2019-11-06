#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<queue>
using namespace std;
const int kind=27;
const int maxn=2e6+7;
struct node{
	node* fail;
	node* next[kind];
	int code;
	node():fail(NULL),code(-1){memset(next,0,sizeof(next));}
};
int vis[1005];
map<int,string> mp;
string word;
string source;
typedef node* pn;
pn root=new node();
void init(pn cur)
{
	for(int i=0;i<kind;i++)
	{
		if(cur->next[i]) init(cur->next[i]);
	}
	delete cur;
}
void insert(string str,int code)
{
	int len=str.length();
	pn cur=root;
	for(int i=0;i<len;i++)
	{
		int index=str[i]-'A';
		if(!cur->next[index]) cur->next[index]=new node();
		cur=cur->next[index];
	}
	cur->code=code;
}
void build()
{
	queue<pn> q;
	q.push(root);
	while(!q.empty())
	{
		pn cur=q.front();q.pop();
		for(int i=0;i<kind;i++)
		{
			pn &v=cur->next[i];
			if(!v) continue;
			pn temp=cur->fail;
			while(temp)
			{
				if(temp->next[i])
				{
					v->fail=temp->next[i];
					break;
				}
				temp=temp->fail;
			}
			if(!temp) v->fail=root;
			q.push(v);
		}
	}
}
void query()
{
	int len=source.length();
	pn cur=root;
	for(int i=0;i<len;i++)
	{
		int index;
		if(source[i]>='A'&&source[i]<='Z') index=source[i]-'A';
		else index=26;
		while(!cur->next[index]&&cur!=root) cur=cur->fail;
		cur=cur->next[index];
		cur=cur?cur:root;
		pn temp=cur;
		while(temp!=root)
		{
			if(temp->code!=-1)
				vis[temp->code]++;
			temp=temp->fail;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n)
	{
		init(root);
		root=new node();
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			cin>>word;
			mp[i+1]=word;
			insert(word,i+1);
		}
		build();
		cin>>source;
		query();
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
				cout<<mp[i]<<": "<<vis[i]<<endl;
		}
	}
}
