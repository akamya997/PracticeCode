#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long ans=0;
    int L=0,R=n,k=-1;
    while(L<=R)
    {
        int mid=L+R>>1;
        int cc=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>mid) cc++;
        }
        if(cc>=mid)
        {
            L=mid+1;
            k=mid;
        }
        else R=mid-1;
    }
    assert(k!=-1);
    //cout<<k<<endl;
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<k;i++) ans+=a[i]-i-1;
    cout<<ans<<'\n';
}