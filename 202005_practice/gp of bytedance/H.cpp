#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int mod=1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        string s,t;
        cin>>s>>t;
        ll cur=0;
        int mx=max(s.length(),t.length())+3;
        vi cs(mx),ct(mx);
        ll evens=0,event=0;
        vi ps(mx),pt(mx);
        ll tots,tott;
        for(int i=0;i<s.length();i++)
        {
            int len=s.length()-1-i;
            if(s[i]=='1')
                cs[i]=(cur+1)%mod;
            else{
                cs[i]=cur;
            }
            cur=(cur*2+s[i]-'0')%mod;
            ps[len]=(ps[len+1]+cs[i])%mod;
            if(len%2==0)
                evens=(evens+cs[i])%mod;
        }
        tots=cur;
        cur=0;
        for(int i=0;i<t.length();i++)
        {
            int len=t.length()-1-i;
            if(t[i]=='1')
                ct[i]=(cur+1)%mod;
            else ct[i]=cur;
            cur=(cur*2+t[i]-'0')%mod;
            pt[len]=(pt[len+1]+ct[i])%mod;
            if(len%2==0)
                event=(event+ct[i])%mod;
        }
        tott=cur;
        ll ansf=0,anss=0;
        for(int i=0;i<s.length()-1;i++)
        {
            int len=s.length()-1-i;
            if(len&1)
                ansf=(ansf+(ll)cs[i]*pt[len+1]%mod)%mod;
        }
        for(int i=0;i<t.length()-1;i++)
        {
            int len=t.length()-1-i;
            if(len&1) ansf=(ansf+(ll)ct[i]*ps[len+1]%mod)%mod;
        }
        for(int i=1;i<mx-1;i+=2) ansf=(ansf+(ll)(pt[i]-pt[i+1]+mod)%mod*(ps[i]-ps[i+1]+mod)%mod)%mod;
        for(int i=0;i<mx-1;i+=2) anss=(anss+(ll)(pt[i]-pt[i+1]+mod)%mod*(ps[i]-ps[i+1]+mod)%mod)%mod;
        cout<<ansf<<" "<<(tots*tott%mod-ansf-anss+2*mod)%mod<<" "<<anss<<'\n';
    }

}