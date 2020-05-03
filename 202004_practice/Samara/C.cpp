#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef vector<int> vi;
typedef pair<int,int> pi;
vi all;
typedef long long ll;
inline int getid(int x)
{
    return lower_bound(all.begin(),all.end(),x)-all.begin();
}
int n;
vector<pi> pt;
struct Bit{
    vector<ll> a;
    int sz;
    Bit(int n)
    {
        sz=n+1;
        a=vector<ll>(sz);
    }
    void add(int x,ll v)
    {
        x++;
        while(x<sz)
        {
            a[x]+=v;
            x+=x&-x;
        }
    }
    ll query(int x)
    {
        x++;
        ll ret=0;
        while(x)
        {
            ret+=a[x];
            x-=x&-x;
        }
        return ret;
    }
    ll qsum(int l,int r)
    {
        return query(r)-query(l-1);
    }

};
ll check(int x)
{
    Bit T(all.size()+1);
    int l=0;
    ll ret=0;
    for(int i=0;i<n;i++)
    {
        while(l<i&&pt[i].first-pt[l].first>x)
        {
            T.add(pt[l].second,-1);
            l++;
        }
        int L=getid(all[pt[i].second]-x),R=upper_bound(all.begin(),all.end(),all[pt[i].second]+x)-all.begin()-1;
        //printf("L:%d R:%d cnt:%lld\n",all[L],all[R],T.query(L,R));
        ret+=T.qsum(L,R);
        T.add(pt[i].second,1);
    }
    //printf("cur:%d ret:%d\n",x,ret);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k;
    cin>>n>>k;
    pt=vector<pi>(n);
    for(int i=0,x,y;i<n;i++)
    {
        cin>>x>>y;
        pt[i].first=x+y,pt[i].second=x-y;
        //cout<<pt[i].first<<" "<<pt[i].second<<'\n';
        all.push_back(pt[i].second);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(int i=0;i<n;i++)
        pt[i].second=getid(pt[i].second);
    sort(pt.begin(),pt.end());
    int L=0,R=5e8,ans=-1;
    while(L<=R)
    {
        int mid=L+R>>1;
        if(check(mid)>=k)
        {
            ans=mid;
            R=mid-1;
        }
        else L=mid+1;
    }
    cout<<ans<<'\n';
}