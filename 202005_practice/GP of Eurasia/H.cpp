#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
void solve()
{
    int n,l;
    cin>>n>>l;
    vector<pi> ext(n);
    for(int i=0;i<n;i++) cin>>ext[i].first>>ext[i].second;
    sort(ext.begin(),ext.end(),greater<pi>());
    double cv=0,cs=0,ans=0;
    for(int i=0;i<n;i++)
    {
        double a=ext[i].first/1000.0;
        double t=ext[i].second/1000000.0;
        double curs=0.5*a*t*t+cv*t;
        //cout<<i<<":"<<t<<":"<<curs<<endl;
        if(cs+curs>l)
        {
            double L=0,R=t,ct=0;
            while(R-L>1e-9)
            {
                double mid=(L+R)/2;
                double ccs=0.5*a*mid*mid+cv*mid;
                if(ccs+cs>l)
                {
                    ct=mid;
                    R=mid;
                }
                else L=mid;
            }
            ans+=ct;
            cout<<ans<<'\n';
            return;
        }
        else{
            ans+=t;
            cv+=a*t;
            cs+=curs;
        }
    }
    ans+=(l-cs)/cv;
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(10);
    int m;
    cin>>m;
    while(m--)
        solve();
}