#include <bits/stdc++.h>
using namespace std;

struct node
{
    int l,r,w;
    node(){}
    node(int _l,int _r,int _w):l(_l),r(_r),w(_w){}
    friend bool operator<(node a,node b)
    {
        return a.w>b.w;
    }
};


const int maxn=5e5+10;

int d[maxn],arr[maxn],l[maxn];
int n,m;
priority_queue<node> pq;
map<pair<int,int>,int> mp;

bool judge(node k)
{
    if(k.l<1||k.r>n||mp[make_pair(k.l,k.r)]>0)  return false;
    return true;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>arr[i];
    for(int i=1;i<=m;i++)   cin>>l[i];
    sort(l+1,l+1+m);
    for(int i=1;i<=n;i++)   d[i]=arr[i]-arr[i-1];
    for(int i=2;i<=n;i++)   {pq.push((node){i-1,i,d[i]});mp[make_pair(i-1,i)]++;}
    bool flag=true;

    if(m>n*(n-1)/2)
    {
        cout<<"no"<<endl;
        return 0;
    }

    for(int i=1;i<=m;i++)
    {
        node now=pq.top();  pq.pop();
//        printf("i: %d w: %d l: %d\n",i,now.w,l[i]);
        if(now.w>l[i]){flag=false;  break;}

        node nxt(now.l-1,now.r,now.w+d[now.l]);
        if(judge(nxt))
        {
            pq.push(nxt);
            mp[make_pair(nxt.l,nxt.r)]++;
        }
        nxt=(node){now.l,now.r+1,now.w+d[now.r+1]};
        if(judge(nxt))
        {
            pq.push(nxt);
            mp[make_pair(nxt.l,nxt.r)]++;
        }
    }
    if(flag)    cout<<"yes"<<endl;
    else    cout<<"no"<<endl;
}

