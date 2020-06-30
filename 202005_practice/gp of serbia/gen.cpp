#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
int main()
{
    srand(time(NULL));
    int m=21521;
    cout<<rand_int(0,m-1)<<" "<<m<<" "<<rand_int(1,1000)<<endl;
}