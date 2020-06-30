#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<ll, ll> dp;
const ll INF = 1e12;
ll n, a, b, c, d;
ll gao(ll x) {
    if(x == 0) return 0;
    if(x == 1) return d;
    auto it = dp.find(x);
    if(it != dp.end()) return it->second;
    dp[x] = min({d>INF/x?INF:d*x, gao(x/2)+d*(x-x/2*2)+a, gao((x+1)/2)+d*((x+1)/2*2-x)+a,
                     gao(x/3)+d*(x-x/3*3)+b, gao((x+2)/3)+d*((x+2)/3*3-x)+b,
                     gao(x/5)+d*(x-x/5*5)+c, gao((x+4)/5)+d*((x+4)/5*5-x)+c});
    return dp[x];
}
void solve() {
    dp.clear();
    cin >> n >> a >> b >> c >> d;
    cout << gao(n) << '\n';
}
int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}
