#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7, INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;

void getfail(string &t,int *fail)
{
    memset(fail, 0, sizeof(fail));
    int len = t.length();
    int j = 0, k = fail[0] = -1;
    while (j < len)
    {
        while (k != -1 && t[j] != t[k])
            k = fail[k];
        fail[++j] = ++k;
    }
}
int fail[1000];
string A;

struct Node
{
    int nx[26],f;
}node[N];
int tot,rt;
int newnode()
{
    memset(node[tot].nx,0,sizeof(node[tot].nx));
    node[tot].f=0;
    return tot++;
}
void insert(string &s)
{
    int cur=rt;
    for(char c:s)
    {
        int x=c-'a';
        if(!node[cur].nx[x])
            node[cur].nx[x]=newnode();
        cur=node[cur].nx[x];
    }
    node[cur].f=1;
}
int can[510][510];
int dp[510][510];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>A;
    getfail(A,fail);
    if(A.length()%(A.length()-fail[A.length()])==0)
        A=A.substr(0,A.length()-fail[A.length()]);
    int m,len=A.length();
    string buf;
    cin>>m;
    rt=newnode();
    while(m--)
    {
        cin>>buf;
        insert(buf);
    }
    //cout<<A<<endl;
    for(int i=0;i<len;i++)
        for(int j=0;j<len;++j)
        {
            int p=i,cur=rt,x;
            while(1)
            {
                x=A[p]-'a';
                if(!node[cur].nx[x])
                    break;
                cur=node[cur].nx[x];
                if(p==j&&node[cur].f)
                {
                    can[i][j]=1;
                    break;
                }
                p=(p+1)%len;
            }
        }
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<len;++i)
    {
        for(int j=0;j<len;++j)
        {
            if(can[i][j])
                dp[i][j]=can[i][j];
        }
    }
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<i+len;j++)
        {
            int l=i,r=j%len;
            for(int k=0;k<len;k++)
            {
                if(can[l][k])
                    dp[l][r]=min(dp[l][r],dp[(k+1)%len][r]+1);
                if(can[(k+1)%len][r])
                    dp[l][r]=min(dp[l][r],dp[l][k]+1);
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<len;i++)
        ans=min(ans,dp[(i+1)%len][i]);
    if(ans>1e7) ans=-1;
    cout<<ans<<'\n';
}