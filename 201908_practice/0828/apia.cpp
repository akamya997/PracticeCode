#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
map<int, int> euler;
long long w[maxn];
int phi(int n)
{
	int now = n;
	int ret = n;
	if (euler.count(now))
		return euler[now];
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			ret = ret / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		ret = ret / n * (n - 1);
	euler[now] = ret;
	return ret;
}
long long MOD(long long n, int mod)
{
	return n < mod ? n : (n % mod + mod);
}
long long quick_mod(long long base, long long p, int mod)
{
	long long ret = 1;
	do
	{
		if (p & 1)
			ret = MOD(base * ret, mod);
		base = MOD(base * base, mod);
	} while (p >>= 1);
	return ret;
}
long long solve(int l, int r, int mod)
{
	if (l == r || mod == 1)
		return MOD(w[l], mod);
	return quick_mod(w[l], solve(l + 1, r, phi(mod)), mod);
}
int main()
{
	int n, mod;
	scanf("%d%d", &n, &mod);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &w[i]);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		long long ans = solve(l, r, mod) % mod;
		printf("%lld\n", ans);
	}
	//system("pause");
}