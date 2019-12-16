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
const int MAXN = 1e5 + 10;
#define pa pair<int, int>
int A[MAXN], B[MAXN], C[MAXN], KK[MAXN], RY[MAXN];
vector<int> G[MAXN];
int inq[MAXN];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m >> KK[0];
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i];
	}
	int f = 1;
	for (int i = 0; i < n; i++) {
		if (KK[i] < A[i]) { f = 0; break; }
		KK[i + 1] = KK[i] + B[i];
	}
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		G[u-1].push_back(v-1);
	}

	if (!f) {
		cout << -1 << endl;
	}
	else {
		RY[n-1]=KK[n];
		for (int i = n - 2; i >= 0; i--) {
			RY[i] = min(RY[i + 1], KK[i+1] - A[i+1]);
		}
		
		for (int i = 0; i <= n; i++) {
			dbg(i,A[i],KK[i],RY[i]);
 		}
		
		

		priority_queue<pa, vector<pa>, greater<pa> > Q;

		for (int u = 0; u < n; u++) {
			Q.push({ C[u],u }); inq[u] = 1;
			for (auto v : G[u]) {
				if (!inq[v]) {
					inq[v] = 1;
					Q.push({ C[v], v });
				}
			}
			// for (int i = 0; i < n; i++) cout << inq[i] << " ";
			// cout << endl;

			// cout << " " << Q.size() << endl;
			while (Q.size() > RY[u]) {
				inq[Q.top().second] = 0;
				Q.pop();
			}
		}

		int ans = 0;
		while (!Q.empty()) {
			ans += Q.top().first;
			Q.pop();
		}
		cout << ans << endl;
	}
}

