#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5;
int dp[1005];
int nxt[maxn][26];
char s[maxn], t[1005];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", s + 1, t + 1);
    int cur[26];
    memset(cur, -1, sizeof(cur));
    for (int i = n; i >= 0; --i)
    {
        for (int j = 0; j < 26; ++j)
            nxt[i][j] = cur[j];
        cur[s[i] - 'a'] = i;
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (dp[j - 1] == -1)
                continue;
            int cur = nxt[dp[j - 1]][t[i] - 'a'];
            if (cur == -1)
                continue;
            if (dp[j] == -1)
                dp[j] = cur;
            else
                dp[j] = min(dp[j], cur);
            ans = max(ans, j);
        }
    }
    printf("%d\n", ans);
}
