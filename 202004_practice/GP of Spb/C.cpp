#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<ll> dp(1<<n);
    dp[0]=1;
    for(int S=0;S<(1<<n)-1;S++)
    {
        int cc=__builtin_popcount(S);
        for(int j=0;j<n;j++)
        {
            if(S>>j&1||a[cc]>b[j]) continue;
            dp[S|(1<<j)]+=dp[S];
        }
    }
    cout<<dp[(1<<n)-1]<<'\n';
}