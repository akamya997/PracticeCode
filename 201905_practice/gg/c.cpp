#include<bits/stdc++.h>
using namespace std;
vector<int> all;
const int maxn=5e6+9;
bool vis[maxn];
bool isw[maxn];
bool check(int cur)
{
	if(isw[cur]) return true;
	if(vis[cur]) return false;
    if(cur==1) return true;
	vis[cur]=1;
    int nxt=0;
	int sv=cur;
    while(cur)
    {
        nxt+=(cur%10)*(cur%10);
        cur/=10;
    }
    return isw[sv]=check(nxt);
}
void db()
{
	memset(isw,0,sizeof(isw));
	memset(vis,0,sizeof(vis));
    int cur=1;
    while(all.size()<150000)
    {
        assert(cur<maxn);
        if(check(cur)) all.push_back(cur);
        cur++;
    }
}
int main()
{
    db();
    int q;
	scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",all[n-1]);
    }
}
