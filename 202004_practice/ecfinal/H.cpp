#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
void IO()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n, p, mod;

int bin(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ll)ans * a % mod;
        a = (ll)a * a % mod;
        n >>= 1;
    }
    return ans;
}

int inv(int a)
{
    return bin(a, mod - 2);
}

vector<int> v;
map<int, int> cnt;
vector<pair<int, int>> vp;

mt19937 ran(time(0));

void solve()
{
    cin >> n >> p;
    mod = p;
    v.resize(n);
    cnt.clear();
    vp.clear();
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (n == 2)
    {
        cout << 2 << '\n';
        return;
    }

    /*
    if (p == 2)
    {
        cout << n << '\n';
        return;
    }
    */

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 3 && i + j < n; j++)
        {
            int tem = (ll)v[i + j] * inv(v[i]) % mod;
            cnt[tem]++;
        }
    }
    for (auto &x : cnt)
    {
        //printf("num: %d cnt: %d\n", x.first, x.second);
        vp.push_back(x);
    }
    sort(vp.begin(), vp.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) { return p1.second > p2.second; });

    int ans = -1;
    for (int ii = 0; ii <= 13 && ii < vp.size(); ii++)
    {
        int time = 30;
        int q = vp[ii].first;
        while (time--)
        {
            int id = ran() % n, nowans = 1;
            for (int i = id - 1; i >= 0; i--)
                if ((ll)v[i] * q % mod == v[id])
                    id = i;
            for (int i = id + 1; i < n; i++)
                if ((ll)v[id] * q % mod == v[i])
                {
                    nowans++;
                    id = i;
                }
            ans = max(ans, nowans);
        }
    }
    if (ans * 2 < n)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    IO();
    int _;
    cin >> _;
    while (_--)
        solve();
}