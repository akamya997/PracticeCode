#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e7 + 10;

int prime[maxn];
bool vis[maxn];
int tot = 0;

ll mul(ll a, ll b, ll m)
{
    ll ret = 0;
    while (b)
    {
        if (b & 1)
        {
            ret += a;
            if (ret >= m)
                ret -= m;
        }
        a += a;
        if (a >= m)
            a -= m;
        b >>= 1;
    }
    return ret;
}
ll power(ll v, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = mul(r , v , m);
        v = mul(v , v , m);
        p >>= 1;
    }

    return r;
}
inline bool witness(ll a, ll p)
{
    int k = 0;
    ll q = p - 1;
    while ((q & 1) == 0)
        ++k, q >>= 1;
    ll v = power(a, q, p);
    if (v == 1 || v == p - 1)
        return false; // probably prime number
    while (k-- != 0)
    {
        v = mul(v , v , p);
        if (v == p - 1)
            return false;
    }

    return true; // composite number
}

inline bool isprime(ll p)
{
    if (p == 1)
        return false;
    if (p == 2)
        return true;
    if (p % 2 == 0)
        return false;

    for (int i = 0; i != 50; ++i)
    {
        ll a = std::rand() % (p - 1) + 1;
        if (witness(a, p))
            return false;
    }

    return true;

}


ll fp(ll a, ll n, ll mod)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        n >>= 1;
    }
    return ans;
}

ll inv(ll a, ll mod)
{
    return fp(a, mod - 2, mod);
}

int main()
{
	srand(time(NULL));
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll p;
        scanf("%lld", &p);
        ll ans = p - 1;

        ll now = p - 1;
        while (!isprime(now))
        {
            ans = mul(ans, inv(now, p), p);
            now--;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
