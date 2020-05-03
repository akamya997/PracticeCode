#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    vector<ll> a(1000000);
    int k=1;
    a[0]=0;
    a[1]=1;
    for(int i=2;i<100;i++)
    {
        a[i]=a[i-1]*k+a[i-2];
        bool pp=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0) pp=0;
        }
        if(pp)
        cout<<i<<":"<<a[i]%i<<" "<<bitset<5>(i)<<endl;
    }
}