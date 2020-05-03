#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi a,pre;
int main()
{
    ll M=1LL<<40;
    int T=364258418;
    /*{
        ll scnt=0,fcnt=0;
        ll slow=1611516670,fast=slow;
        for(int i=0;;i++)
        {
            scnt++;
            fcnt+=2;
            slow=(slow+(slow>>20)+12345)%M;
            fast=(fast+(fast>>20)+12345)%M;
            fast=(fast+(fast>>20)+12345)%M;
            if(slow==fast)
            {
                cout<<fcnt-scnt<<endl;
                break;
            }
        }
    }*/
    ll cur=1611516670;
    int cnt=0;
    int var=300000;
    int n;
    cin>>n;
    vi pos;
    for(int i=var;i<T*2;i+=var)
        pos.push_back(i);
    int cc=0;
    ll cntt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=(cur%2==0);
        if(i==T)
            cntt=cnt;
        if(i==pos[cc])
        {
            a.push_back(cur);
            pre.push_back(cnt);
            //if(i==728100000)
            //{
              //  cout<<cnt<<" "<<cur<<endl;
            //}
            cc++;
        }
        cur=(cur+(cur>>20)+12345)%M;
    }
    //cout<<cntt<<endl;
    //cout<<"ed"<<":"<<cur<<endl;
    //cout<<cnt-cntt<<endl;
    cout<<cnt<<endl;
}