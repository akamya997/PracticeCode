#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 100;
const int mod = 1e9 + 7;
ll fac[maxn];
ll inv[maxn];
ll quickpow(ll a, int b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void init()
{
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= maxn - 50; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[maxn - 50] = quickpow(fac[maxn - 50], mod - 2);
    for (int i = maxn - 50 - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
ll getf(int x, int y)
{
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
ll getans(int x, int y, int z)
{
    return getf(x + y + z, x) * getf(y + z, y) % mod;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int L, H, W;
    init();
    cin >> L >> W >> H;
    int X1, Y1, Z1, X2, Y2, Z2;
    cin >> X1 >> Y1 >> Z1 >> X2 >> Y2 >> Z2;
    ll ans = getans(L, W, H);
    ll sum1 = getans(X1, Y1, Z1);
    ll sum2 = getans(L - X1, W - Y1, H - Z1);
    ll sum3 = getans(X2, Y2, Z2);
    ll sum4 = getans(L - X2, W - Y2, H - Z2);
    ans = (ans - sum1 * sum2 % mod + mod) % mod;
    ans = (ans - sum3 * sum4 % mod + mod) % mod;
    if ((X1 <= X2 && Y1 <= Y2 && Z1 <= Z2) || (X1 >= X2 && Y1 >= Y2 && Z1 >= Z2))
    {
        ans = (ans + getans(abs(X2 - X1), abs(Y2 - Y1), abs(Z2 - Z1))) % mod;
    }
    cout << ans << endl;
}