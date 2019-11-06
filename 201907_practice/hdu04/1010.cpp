#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e3;

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
            r = mul(r, v, m);
        v = mul(v, v, m);
        p >>= 1;
    }

    return r;
}

bool witness(ll a, ll p)
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
        v = mul(v, v, p);
        if (v == p - 1)
            return false;
    }

    return true; // composite number
}

bool miller_rabin(ll p)
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

int prime[maxn];
bool vis[maxn];
int tot = 0;

void init()
{
    vis[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[tot++] = i;
        for (int j = 0; j < tot && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    init();
    //cout << tot << endl;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        //cout << n << endl;
        if (miller_rabin(n))
        {
            printf("1\n");
            continue;
        }

        int ans = 0x3f3f3f3f;

        for (int i = 0; i < tot && prime[i] * prime[i] <= n; i++)
        {
            if (n % prime[i] != 0)
                continue;
            int t = 0;
            while (n % prime[i] == 0)
            {
                t++;
                n /= prime[i];
            }
            ans = min(ans, t);
        }

        //cout << n << endl;
        if (n >= maxn)
        {

            ll p1 = pow(n, 1.0 / 3.0) + 0.5;
            if (p1 * p1 * p1 == n)
            {
                ans = min(ans, 3);
                printf("%d\n", ans);
            }
            else
            {
                ll p2 = sqrt(n) + 0.5;
                if (p2 * p2 == n)
                {
                    ll p3 = sqrt(p2) + 0.5;
                    if (p3 * p3 == p2)
                    {
                        printf("%d\n", min(4, ans));
                    }
                    else
                        printf("%d\n", min(2, ans));
                }
                else
                {
                    printf("1\n");
                }
            }
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}

