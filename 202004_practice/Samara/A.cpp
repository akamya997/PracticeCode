#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> sgn(n);
    int c=1;
    long long tot=0;
    for(int i=n-1;i>=0;i--)
    {
        sgn[i]=c;
        tot+=c*a[i];
        c*=-1;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r,v;
        cin>>l>>r>>v;
        if((r-l+1)%2==0) ;
        else tot+=(sgn[l-1])*v;
        cout<<tot<<'\n';
    }
}