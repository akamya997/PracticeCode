#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxn=105;
bool ok[maxn];
void dfs(vi a)
{
    //for(auto u:a) cout<<u<<" ";
    //cout<<endl;
    if(a.size()==1)
    {
        ok[a[0]]=1;
        return;
    }
    for(int i=1;i<a.size()-1;i++)
    {
        vi nxt;
        for(int j=0;j<i-1;j++) nxt.push_back(a[j]);
        vi cur={a[i-1],a[i],a[i+1]};
        sort(cur.begin(),cur.end());
        nxt.push_back(cur[1]);
        for(int j=i+2;j<a.size();j++) nxt.push_back(a[j]);
        dfs(nxt);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    n=7;
    a={1,2,3,4,5,6,7};
    do{
        memset(ok,0,sizeof(ok));
        cout<<"cur permu:\n";
        vi pos(n);
        for(auto u:a) cout<<u<<" ";
        cout<<endl;
        dfs(a);
        vi ans(n);
        for(int i=1;i<=n;i++)
        {
            pos[a[i-1]]=i-1;
            if(ok[i]) cout<<i<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            if(ok[i])
                ans[pos[i]]=1;
        }
        for(auto u:ans) cout<<u;
        cout<<endl;
    }while(next_permutation(a.begin(),a.end()));
}