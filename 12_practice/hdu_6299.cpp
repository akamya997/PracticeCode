#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct Point{
    int l,r;
    bool operator <(const Point &a) const{
        if(r==0||a.l==0) return true;
        if(l==0||a.r==0) return false;
        return r+a.l>l+a.r;
    }
}pt[maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        memset(pt,0,sizeof(pt));
        int n;
        cin>>n;
        string str;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            for(int j=0;j<str.length();j++)
            {
                if(str[j]=='(')
                    pt[i].l++;
                else{
                    if(pt[i].l)
                        pt[i].l--,ans++;
                    else pt[i].r++;
                }
            }
        }
        sort(pt,pt+n);
        int ansl=0,ansr=0;
        for(int i=0;i<n;i++)
        {
            if(ansl)
            {
                ans+=min(ansl,pt[i].r);
                ansl-=pt[i].r;
                if(ansl<0) ansl=0;
            }
            ansl+=pt[i].l;
        }
        cout<<ans*2<<endl;
    }
}
