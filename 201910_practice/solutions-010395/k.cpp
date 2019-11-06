#include <stdlib.h>
#include <string.h>
#include <algorithm>
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#include<stdio.h>
#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 5e4 + 4;
const int M = 3e5 + 5;
const ll inf = 1e18;
int D;

int a[N][3], ra[N][3];
vector<ll> f[N];

ll cnt, cnt2;

vector<pair<int,int>> q[N];
ll ans[M];

void go(int L, int R){
	int m = (L+R) / 2;
	
	f[m+1].assign(D, -inf);
	f[m+1][0] = 0;
	for(int i=m; i>=L; --i){
		vector<ll> &t = f[i], fr = f[i+1];
		t.resize(D);
		for(int r=0;r<D;++r){
			int r0 = r-ra[i][0]; if(r0<0) r0+=D;
			int r1 = r-ra[i][1]; if(r1<0) r1+=D;
			int r2 = r-ra[i][2]; if(r2<0) r2+=D;
			t[r] = max(max(fr[r0]+a[i][0], fr[r1]+a[i][1]), fr[r2]+a[i][2]);
			++cnt;
		}
	}
	vector<ll> dr(D, -inf), t(D);
	dr[0] = 0;
	for(int i=m+1; i<=R; ++i){
		for(int r=0;r<D;++r){
			int r0 = r-ra[i][0]; if(r0<0) r0+=D;
			int r1 = r-ra[i][1]; if(r1<0) r1+=D;
			int r2 = r-ra[i][2]; if(r2<0) r2+=D;
			t[r] = max(max(dr[r0]+a[i][0], dr[r1]+a[i][1]), dr[r2]+a[i][2]);
			++cnt;
		}
		t.swap(dr);
		for(int it = int(q[i].size())-1; it>=0; --it){
		    ++cnt2;
			int j = q[i][it].first;
			if(j<=m){
				auto &dl = f[j];
				ll res = -inf;
				for(int r=0;r<D;++r){
					int rr = r ? D-r : 0;
					res = max(res, dl[r] + dr[rr]);
				}
				if(res<0) res = -1;
				ans[q[i][it].second] = res;
				q[i][it] = q[i].back();
				q[i].pop_back();
			}
		}
	}
	
	if(L==R) return ;
	go(L,m);
	go(m+1,R);
}

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	
	int n;
	scanf("%d%d",&n,&D);
	
	for(int i=0;i<n;++i) 
	for(int k=0;k<3;++k){
		scanf("%d",&a[i][k]);
		ra[i][k] = a[i][k]%D;
	}
	
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		int l, r;
		scanf("%d%d",&l,&r);
		if(l>r) swap(l,r);
		--l; --r;
		ans[i] = -1;
		if(l==r){
			for(int k=0;k<3;++k) if(a[l][k]%D==0) ans[i] = max(ans[i], 1LL*a[l][k]);
			continue;
		}
		q[r].push_back({l,i});
	}
	
	go(0,n-1);
	
	
	for(int i=0;i<n;++i) assert(q[i].empty());
	
	for(int i=0;i<m;++i) printf(INT64 "\n", ans[i]);
	
	cerr<<"cnt: "<<cnt<<' '<<cnt2<<endl;
	
	return 0;
}
