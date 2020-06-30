#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll k;
        cin>>k;
        k--;
        int cc=__builtin_popcountll(k);
        cout<<(1LL<<cc)<<'\n';
    }
}