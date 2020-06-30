#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main()
{
    srand(time(0));
    int n=200;
    ll m=1e18;
    ll k=1e16;
    cout<<n<<" "<<m<<" "<<k<<'\n';
    for(int i=0;i<n;i++) cout<<rand()%100+1<<" ";
    cout<<endl;
}