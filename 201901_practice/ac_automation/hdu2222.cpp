#include<bits/stdc++.h>
using namespace std;
const int maxn=26;
struct node{
	node *fail;
	node *next[maxn];
	int cnt;
	node():fail(NULL),cnt(0){memset(next,0,sizeof(next));}
};
node* root;
char keyword[51];
char stc[1000001];
void build_ac_automation(node *root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* cur=q.front();q.pop();
		for(int i=0;i<maxn;i++)
		{
			node* &v=cur->next[i];
			if(v)
			{
				node *temp=cur->fail;
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
}
void insert(char *str,node *root)
{
	node* cur=root;
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		int index=str[i]-'a';
		if(!cur->next[index])cur->next[index]=new node();
		cur=cur->next[index];
	}
	cur->cnt++;
}
int query(node *root)
{
	int len=strlen(stc);
	node *cur=root;
	int ans=0;
	for(int i=0;i<len;i++)
	{
		int index=stc[i]-'a';
		while(!cur->next[index]&&cur!=root)cur=cur->fail;
		cur=cur->next[index];
		cur=cur?cur:root;
		node* temp=cur;
		while(temp!=root&&temp->cnt!=-1) 
		{
			ans+=temp->cnt;
			temp->cnt=-1;
			temp=temp->fail;
		}
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		root=new node();
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",keyword);
			insert(keyword,root);
		}
		build_ac_automation(root);
		scanf("%s",stc);
		printf("%d\n",query(root));
	}
}
