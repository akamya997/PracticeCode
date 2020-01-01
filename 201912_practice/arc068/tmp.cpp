#include <iostream>

using namespace std;

typedef long long LL;

const int maxn = 2005;
const int mod = 1000000007;

inline int pow(int a, int b)
{
    if (b < 0)
        return 1;
    int ans = 1;
    for (; b; b >>= 1, a = (LL) a * a % mod)
        if (b & 1)
            ans = (LL) ans * a % mod;
    return ans;
}

int dp[maxn];

int main()
{
    int n, k;
    cin >> n >> k;
    dp[n + 1] = 1;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = n; j; --j)
        {
            if (n - j + 1 < i)
                dp[j] = 0;
            else
            {
				cout<<j<<"->"<<dp[j+1]<<" "<<dp[j]<<endl;
                dp[j] = dp[j + 1] + dp[j];
                if (dp[j] >= mod)
                    dp[j] -= mod;
            }
			cout<<i<<" "<<j<<"->"<<dp[j]<<endl;
        }
    }
    cout << (LL) dp[1] * pow(2, n - k - 1) % mod;
    return 0;
}
