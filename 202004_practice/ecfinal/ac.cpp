#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;
#define int long long
const int N = (int) 1e5 + 5, mod = (int) 0;
vector<int> adj[N];
int a[N], k, sz[N], dp0[N], dp1[N], pre[N], suf[N], val[N];
int cmp(int x, int y) {
	return min(dp0[x], dp0[y] - 1 - sz[x]*2) > min(dp0[y], dp0[x] - 1 - sz[y]*2);	
}
void dfs(int v, int p = -1) {
	sz[v] = 1;
	for (int u : adj[v]) if (u != p) {
		dfs(u, v);
		sz[v] += sz[u];
	}
	dp0[v] = min(a[v], a[v] + k - (sz[v] - 1) * 2);
	dp1[v] = -1e18;
	vector<int> sr;
	for (int u : adj[v]) if (u != p) sr.pb(u);
	dp0[N-1] = a[v]+k-1;
	sort(ALL(sr), cmp);
	sr.pb(N-1);
	sz[N-1] = 0;
	int sum_t = 0;
	int m = (int) sr.size();
	for (int j = 0; j <= m; ++j) pre[j] = suf[j] = 1e18;
	for (int j = 0; j < m; ++j) {
		int u = sr[j];
		val[j] = dp0[u] - sum_t - 1;
		
		pre[j + 1] = min(pre[j], val[j]);
		sum_t += sz[u]*2;
	}
	for (int j = m - 1; j >= 0; --j) {
		suf[j] = min(suf[j+1], val[j]);
	}
	dp0[v] = min(dp0[v], pre[m]);
	for (int j = 0; j < m - 1; ++j) {
		int u = sr[j];
		int wait = sum_t - sz[u]*2 + 1;
		int best = min(pre[j], suf[j+1] + 2*sz[u]);
		best = min(best, dp1[u] - wait);
		best = min(best, a[v]);
		dp1[v] = max(dp1[v], best);
        cout<<u<<"!!"<<best<<endl;
	}
	if (m == 1) dp1[v] = a[v];
    cout<<v<<":"<<dp0[v]<<","<<dp1[v]<<endl;
}
int32_t main() {
	int n;
	cin >> n >> k;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int j = 0; j < n; ++j) cin >> a[j];
	dfs(0);
	if (dp1[0] < 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << dp1[0] << endl;
}
