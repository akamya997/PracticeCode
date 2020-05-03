#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    for(int i=0,t,d;i<n;i++)
    {
        cin>>t>>d;
        if(t>=ans) ans=t+d;
        else ans+=d;
    }
    cout<<ans<<'\n';
}