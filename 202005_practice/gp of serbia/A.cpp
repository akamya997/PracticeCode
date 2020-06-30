#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,x;
    cin>>n>>k>>x;
    int rem=n*(n-1)/2-k;
    int len=0;
    for(int i=1;i<=n;i++)
    {
        if(rem<i)
        {
            len=i-1;
            break;
        }
        rem-=i;
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++) ans[i]=i*x+1;
    for(int i=0;i<len;i++) ans[i]=len*x+1;
    for(int i=len;i>=len-rem+1;i--)
        ans[i]=len*x+2;
    for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
}