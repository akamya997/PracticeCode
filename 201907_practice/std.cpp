#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
const int N = 10005;
int h[N];
ll s[N], p[N];

ll dp[55][N];

inline ll getup(int i, int j, int k) { return (dp[i][j] + p[j]) - (dp[i][k] + p[k]); }
inline ll getdown(int i, int j, int k) { return s[j] - s[k]; }

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k, m;
        scanf("%d%d%d", &n, &k, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + h[i], p[i] = p[i - 1] + i * h[i];
        vector<int> v;
        for (int i = 1; i <= n; i++)
            v.push_back((n - i + 1) * h[i]);
        sort(v.begin(), v.end(), greater<int>());
        long long ans = 0;
        for (int i = 0; i < m; i++)
            ans += v[i];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            static int dq[N];
            static int head, tail;
            head = tail = 0;
            dq[tail++] = 0;
            for (int j = 1; j <= n; j++)
            {
                while (tail - head >= 2 && getup(i - 1, dq[head + 1], dq[head]) <= (j + 1) * getdown(i - 1, dq[head + 1], dq[head]))
                    ++head;
                int tt = dq[head];
                // debug(">>> tt = %d\n", tt);
                dp[i][j] = dp[i - 1][tt] + (j + 1) * (s[j] - s[tt]) - (p[j] - p[tt]);
                // debug(">>> dp[%d][%d]: %d\n", i, j, dp[i][j]);
                while (tail - head >= 2 && getup(i - 1, j, dq[tail - 1]) * getdown(i - 1, dq[tail - 1], dq[tail - 2]) <= getdown(i - 1, j, dq[tail - 1]) * getup(i - 1, dq[tail - 1], dq[tail - 2]))
                    --tail;
                dq[tail++] = j;
            }
        }
        ans -= dp[k + 1][n];

        printf("%lld\n", ans);
    }
}