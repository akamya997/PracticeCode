#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;

const int A = 26, N = 100;

int cntl[A][A][N + 1];
int cntr[A][A][N + 1];

int main(){
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
    
    vector<string> s(4);
    for(string &t : s) cin>>t;
    
    ll ans = 0;
    
    sort(ALL(s));
    do{
	string p = s[0], t = s[1], l = s[2], r = s[3];
	
	memset(cntl, 0, sizeof cntl);
	memset(cntr, 0, sizeof cntr);
	
	for(int i=0;i<l.size();++i)
	for(int j=i+2;j<l.size();++j) cntl[l[i]-'a'][l[j]-'a'][j-i+1]++;
	
	for(int i=0;i<r.size();++i)
	for(int j=i+2;j<r.size();++j) cntr[r[i]-'a'][r[j]-'a'][j-i+1]++;
	
	int m = min(l.size(), r.size());
	for(int i=0;i<p.size();++i)
	for(int j=i+2;j<p.size();++j){
	    int w = j-i+1;
	    int a = p[i]-'a', b = p[j]-'a';
	    for(int k=0;k+w<=t.size();++k){
		int c = t[k]-'a', d = t[k+w-1]-'a';
		for(int h=3;h<=m;++h) ans+=1LL*cntl[a][c][h]*cntr[b][d][h];
	    }
	}
    }while(next_permutation(s.begin(), s.end()));
    
    cout<<ans<<endl;
    
    return 0;
}