#include <bits/stdc++.h>
using namespace std;

const int mod = 119 << 23 | 1;
const int inv2 = mod + 1 >> 1;
const int N = 1 << 20;

int a[N], b[N];
int cnt[N];
int A[20][N], B[20][N], C[20][N];

void fwt(int f[], int m)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
            {
                int l = f[j ^ (1 << i)], r = f[j];
                f[j ^ (1 << i)] = (l + r) % mod, f[j] = (l - r + mod) % mod;
            }
}
void ifwt(int f[], int m)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
            {
                int l = f[j ^ (1 << i)], r = f[j];
                f[j ^ (1 << i)] = 1LL * (l + r) * inv2 % mod, f[j] = (1LL * (l - r) * inv2 % mod + mod) %mod;
            }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < N; i++) cnt[i] = __builtin_popcount(i);
    for (int i = 0; i < (1 << n); i++) scanf("%d", a + i);
    for (int i = 0; i < (1 << n); i++) scanf("%d", b + i);
    for (int i = 0; i < (1 << n); i++) A[cnt[i]][i] = 1LL * a[i] * (1 << cnt[i]) % mod, B[cnt[i]][i] = b[i];
    for (int i = 0; i <= n; i++) fwt(A[i], 1 << n), fwt(B[i], 1 << n);
    for (int i = 0; i <= n; i++)
        for (int j = i; j <= n; j++)
            for (int k = 0; k < (1 << n); k++)
                (C[j - i][k] += 1LL * A[i][k] * B[j][k] % mod) %= mod;
    for (int i = 0; i <= n; i++) ifwt(C[i], 1 << n);
    int x = 1, ans = 0;
    for (int i = 0; i < (1 << n); i++) (ans += 1LL * C[cnt[i]][i] * x % mod) %= mod, x = 1526LL * x % mod;
    printf("%d\n", ans);
}
