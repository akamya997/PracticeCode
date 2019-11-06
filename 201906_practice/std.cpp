#include <bits/stdc++.h>
using namespace std;
const int mod = 119 << 23 | 1;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<mat> Mat;

Mat mul(Mat& A, Mat& B)
{
    Mat C(A.size(), mat(A[0].size(), vec(A[0].size())));
    int n = A.size();
    int m = A[0].size();
    for (int u = 0; u < n; u++)
        for (int i = 0; i < m; i++)
            for (int k = 0; k < m; k++)
                if (A[u][i][k])
                    for (int j = 0; j < m; j++)
                        (C[u][i][j] += A[u][i][k] * B[u][k][j]) %= mod;
    return C;
}

Mat Pow(Mat& A, ll n)
{
    Mat B(A.size(), mat(A[0].size(), vec(A[0].size())));
    B = A;
    int sz = A[0].size();
    --n;
    for (; n; n >>= 1, A = mul(A, A))
        if (n & 1) B = mul(B, A);
    return B;
}

mat& operator+=(mat& A, const mat& B)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = (A[i][j] + B[i][j]) % mod;
    return A;
}

mat& operator-=(mat& A, const mat& B)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = (A[i][j] - B[i][j] + mod) % mod;
    return A;
}

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

const int maxn = 50;
struct Trie
{
    int ch[maxn][26], f[maxn], val[maxn];
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'a'; };
    void insert(const char* s, const int& id)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] |= (1 << id);
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 26; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            val[u] |= val[f[u]];
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    void solve(int l, int n)
    {
        if (l == 0)
        {
            puts("0");
            return;
        }
        Mat G((1 << n), mat(sz, vec(sz)));
        for (int u = 0; u < sz; u++)
            for (int c = 0; c < 26; c++)
                G[val[ch[u][c]]][u][ch[u][c]]++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < (1 << n); j++)
                if (j & (1 << i))
                    G[j] += G[j ^ (1 << i)];
        G = Pow(G, l);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < (1 << n); j++)
                if (j & (1 << i))
                    G[j] -= G[j ^ (1 << i)];
        ll ans = 0;
        for (int i = 0; i < sz; i++)
            (ans += G[(1 << n) - 1][rt][i]) %= mod;
        printf("%lld\n", ans);
    }
} ac;

char buf[10];

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int l, n;
    scanf("%d%d", &l, &n);
    ac.init();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        ac.insert(buf, i);
    }
    ac.build();
    ac.solve(l, n);
    return 0;
}
