#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int cnt;
    int nxt[26];
}node[100000];
int rt,tot;



int newnode()
{
    int cur=tot++;
    node[cur].cnt=0;
    for(int i=0;i<26;++i)
        node[cur].nxt[i]=-1;
    return cur;
}

void init()
{
    tot=0;
    rt=newnode();
}
bool insert(string &s)
{
    int cur=rt;
    for(int i=0;i<s.length();++i)
    {
        int x=s[i]-'0';
        if(node[cur].nxt[x]==-1)
            node[cur].nxt[x]=newnode();
        cur=node[cur].nxt[x];
        if(node[cur].cnt!=0)
            return 0;
    }
    node[cur].cnt++;
    return 1;
    
}

string str[10000];
bool cmp(string a,string b)
{
    return a.length()<b.length();
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        init();
        for(int i=1;i<=n;++i)
            cin>>str[i];
        sort(str+1,str+1+n,cmp);
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            flag=insert(str[i]);
            if(flag==0)
                break;
        }
        if(flag)
            cout<< "YES" <<endl;
        else
            cout<< "NO" <<endl;
    }
}