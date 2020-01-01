#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;

int main()
{
	string s;
	cin>>s;
	string d1="dream",d2="dreamer",e1="erase",e2="eraser";
	string t;
	for(int i=0;i<s.length();i++)
	{
	//	dbg(i);
		if(s[i]=='d') 
		{
			t+=d1;
			i+=5;
			if(i>=s.length())
				break;
			if(s[i]=='d')
			{
				i--;
				continue;
			}
			if(i+2>=s.length())
			{
				t+="er";
				break;
			}
			if(s[i+2]!='a')
			{
				t+="er";
				i+=2;
			}
			i--;
		}
		else if(s[i]=='e')
		{
			t+=e1;
			i+=5;
			if(i>=s.length()) break;
			if(s[i]=='r') {
				i++;
				t+='r';
			}
			i--;
		}
		else break;
	}
	if(s==t) cout<<"YES\n";
	else cout<<"NO\n";
}
