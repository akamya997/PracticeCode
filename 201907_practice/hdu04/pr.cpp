#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline LL mul(LL u, LL v, LL p) { // 卡常
    LL t = u * v - LL((long double) u * v / p) * p;
    return t < 0 ? t + p : t;
}
inline LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x=(mul(x,x,MOD)))
        if (n & 1) ret = mul(ret,x,MOD);
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline bool checkQ(LL a, LL n) {
    if (n == 2 || a >= n) return 1;
    if (n == 1 || !(n & 1)) return 0;
    LL d = n - 1;
    while (!(d & 1)) d >>= 1;
    LL t = bin(a, d, n);  // 不一定需要快速乘
    while (d != n - 1 && t != 1 && t != n - 1) {
        t = mul(t, t, n);
        d <<= 1;
    }
    return t == n - 1 || d & 1;
}

inline bool primeQ(LL n) {
    static vector<LL> t = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if (n <= 1) return false;
    for (LL k: t) if (!checkQ(k, n)) return false;
    return true;
}
LL var=1e6;
mt19937 mt(time(0));
inline LL pollard_rho(LL n, LL c) {
    LL x = uniform_int_distribution<LL>(1, n-1)(mt), y = x;
    auto f = [&](LL v) { LL t = mul(v, v, n) + c; return t < n ? t : t -n; };
    while (1) {
        x = f(x); y = f(f(y));
        if (x == y) return n;
        LL d = __gcd(abs(x - y), n);
        if (d != 1) 
		{
			cout<<cnt<<endl;
			return d;
		}
    }
}
unordered_map<LL,int> tot;
inline void get_fac(LL n, LL cc = 999983) {
    if (n == 4) { tot[2]+=2; return; }
    if (primeQ(n)) 
	{
		tot[n]++;
		return; 
	}
    LL p = n;
    while (p == n) p = pollard_rho(n, --cc);
    get_fac(p); get_fac(n / p);
}
int main()
{
	LL n;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		tot.clear();
		get_fac(n);
		int ans=0x3f3f3f3f;
		for(auto &u:tot)
			ans=min(ans,u.second);
		printf("%d\n",ans);
	}
}
