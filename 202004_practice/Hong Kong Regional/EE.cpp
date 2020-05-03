#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
struct D{
    int one,zero,ok,oneone,zerozero;
};
const int maxn=5e3+7;
int st[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vi a(n);
        vi ans(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        auto solve=[&](vi& c)->D
        {
            D ret={0,0,0,0,0};
            int cnt0=0,cnt1=0;
            for(auto u:c)
            {
                if(u==1) cnt1++;
                else cnt0++;
            }
            if(cnt0==cnt1) ret.ok=1;
            {
                int top=0;
                int c0=cnt0,c1=cnt1;
                for(auto u:c)
                {
                    st[top++]=u;
                    if(top>=3)
                    {
                        if(st[top-1]&&st[top-2]&&st[top-3])
                        {
                            c1-=2;
                            top-=2;
                        }
                    }
                    while(top>=2&&!st[top-1]&&st[top-2])
                    {
                        c1--;
                        c0--;
                        top-=2;
                    }
                    if(c1==c0) ret.ok=1;
                }
                //cout<<c0<<" "<<c1<<endl;
                if(c0>c1)
                {
                    if((c0-c1)&1) ret.zero=1;
                    else ret.zerozero=1;
                }
            }
            {
                int top=0;
                int c0=cnt0,c1=cnt1;
                for(auto u:c)
                {
                    st[top++]=u;
                    if(top>=3)
                    {
                        if(!st[top-1]&&!st[top-2]&&!st[top-3])
                        {
                            c0-=2;
                            top-=2;
                        }
                    }
                    while(top>=2&&st[top-1]&&!st[top-2])
                    {
                        c0--;
                        c1--;
                        top-=2;
                    }
                    if(c1==c0) ret.ok=1;
                }
                //cout<<c0<<" "<<c1<<endl;
                if(c1>c0)
                {
                    if((c1-c0)&1) ret.one=1;
                    else ret.oneone=1;
                }
            }
            return ret;
        };
        for(int i=0;i<n;i++)
        {
            vi cur;
            for(int j=0;j<i;j++)
            {
                if(a[j]>a[i]) cur.push_back(1);
                else cur.push_back(0);
            }
            D left=solve(cur);
            cur.clear();
            for(int j=i+1;j<n;j++)
            {
                if(a[j]>a[i]) cur.push_back(1);
                else cur.push_back(0);
            }
            D right=solve(cur);
            //printf("i:%d left.one:%d left.zero:%d right.one:%d right.zero:%d left.ok:%d right.ok:%d\n",i,left.one,left.zero,right.one,right.zero,left.ok,right.ok);
            if(left.ok&&right.ok) ans[i]=1;
            else if(left.one&&right.zero) ans[i]=1;
            else if(left.zero&&right.one) ans[i]=1;
            else if(left.oneone&&right.zerozero) ans[i]=1;
            else if(left.zerozero&&right.oneone) ans[i]=1;
        }
        for(auto u:ans) cout<<u;
        cout<<'\n';
    }
}