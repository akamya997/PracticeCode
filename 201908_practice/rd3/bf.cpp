#include <bits/stdc++.h>
using namespace std;
int tol; //节点个数
const int maxn = 1e5 + 100;
int th(int x,int y)
{
    int ret=0;
    for(int i=0;i<31;i++)
    {
        if((1<<i)>x&&(1<<i)>y) break;
        if((x>>i&1)&&(y>>i&1))
            ret|=(1<<i);
        else if(!(x>>i&1)&&!(y>>i&1))
            ret|=(1<<i);
    }
    return ret;
}
int ch[31*maxn][2];
int val[31*maxn];
int sz;
void init()
{
    sz=1;
    memset(ch,0,sizeof(ch));
    memset(val,0,sizeof(val));
}
void _insert(int x)
{
    int u=0;
    for(int i=30;i>=0;i--)
        {
        int c=(x>>i)&1;
        if(!ch[u][c]){
            ch[u][c]=sz++;
        }
        u=ch[u][c];
        val[u]++;
    }
}
void _delete(int x)
{
    int u=0;
    for(int i=30;i>=0;i--){
        int c=(x>>i)&1;
        u=ch[u][c];
        --val[u];
    }
}
int query(int x)
{
    int minn=0;
    int u=0;
    for(int i=30;i>=0;i--){
        int c=(x>>i)&1;
        if(ch[u][c]&&val[ch[u][c]]){
            minn+=((c)<<i);
            u=ch[u][c];
        }
        else{
            u=ch[u][c^1];
            minn+=((c^1)<<i);
        }
    }
    return max(x,th(minn,x));
}
int main()
{
    //init();
    int n,x;
   // cout << th(4,5) <<endl;
    scanf("%d",&n);
    set<int>st;
    for(int i = 1;i <= n; ++i)
    {
        scanf("%d",&x);
        st.insert(x);
        //_insert(x);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int c,v;
        scanf("%d%d",&c,&v);
        if(c == 0)
        {
            int ans = v;
           // int res = 0;
            for(auto it :st)
            {
                ans = max(ans,th(it,v));
            }
			for(auto it:st)
			{
				if(th(it,v)==ans)
					cout<<it<<":";
			}
            printf("%d\n",ans);
        }
        else if(c == 1)
        {
            st.insert(v);
           // _insert(v);
        }
        else
        {
            auto t = st.find(v);
            if(t != st.end())
            {
                st.erase(t);
                //_delete(v);
            }
        }
    }
    return 0;
}
