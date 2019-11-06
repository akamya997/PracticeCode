#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", __func__, ##__VA_ARGS__)
#else
#define debug(...)
#endif
int main()
{
    std::string s;
    cin >> s;
    int n = s.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(110));
    if (s[0] != '0') dp[0][s[0] - '0'] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 110; j++)
        {
            int k = (j * 10 + s[i] - '0') % 110;
            dp[i][k] += dp[i - 1][j];
        }
        if (s[i] != '0') dp[i][s[i] - '0']++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += dp[i][0];
    cout << ans << endl;
}
