#include<bits/stdc++.h>
using namespace std;
#ifndef Online_Judge
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
int main()
{
	int year,month,day;
	char c;
	cin>>year>>c>>month>>c>>day;
	if(year<2019)
	{
		cout<<"Heisei"<<endl;
	}
	else if(year==2019){
		if(month<4) cout<<"Heisei"<<endl;
		else if(month==4)
		{
			if(day<=30) cout<<"Heisei"<<endl;
			else cout<<"TBD"<<endl;
		}
		else cout<<"TBD"<<endl;
	}
	else cout<<"TBD"<<endl;
}
