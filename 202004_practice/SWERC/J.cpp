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

const int maxn = 2e6 + 10, mod = 1000000007;
int inv[maxn], f[maxn], finv[maxn];

void init() //
{
    inv[1] = 1;
    for (int i = 2; i < maxn; i++)
        inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod; //inv: 逆元
    f[0] = finv[0] = 1;                                    //f: 阶乘 	finv:阶乘逆元(1/f)
    for (int i = 1; i < maxn; i++)
    {
        f[i] = (ll)f[i - 1] * i % mod;
        finv[i] = (ll)finv[i - 1] * inv[i] % mod;
    }
}

int C(int n, int m) //C(n,m)
{
    if (m < 0 || m > n)
        return 0;
    return (ll)f[n] * finv[n - m] % mod * finv[m] % mod;
}

int Catalan(int n)
{
    return (ll)C(2 * n, n) * inv[n + 1] % mod;
}
//---------------------------
typedef pair<int,int> pi;
map<pi,int> cnt;
vector<int> v;
ll gao1(vector<int> &v)
{
    int mn = 1e6 + 10;
    for (auto &x : v)
        mn = min(mn, x);
    vector<int> id; //最小值的下标
    id.push_back(-1);
    for (int i = 0; i < v.size(); i++)
        if (v[i] == mn)
            id.push_back(i);
    id.push_back(v.size());
    ll ans = Catalan(id.size() - 2);

    for (int i = 1; i < id.size(); i++)
    {
        vector<int> vv;
        for (int j = id[i - 1] + 1; j <= id[i] - 1; j++)
            vv.push_back(j);
        if (vv.size() != 0)
            ans = ans * gao1(vv) % mod;
    }
    return ans;
}
ll gao(vector<int> &v)
{
    
    vector<int> L(v.size()),R(v.size());
    vector<int> st;
    for(int i=0;i<v.size();i++)
    {
        while(!st.empty()&&v[st.back()]>v[i])
        {
            R[st.back()]=i-1;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(!st.empty())
    {
        R[st.back()]=v.size()-1;
        st.pop_back();
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        while(!st.empty()&&v[st.back()]>v[i])
        {
            L[st.back()]=i+1;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(!st.empty())
    {
        L[st.back()]=0;
        st.pop_back();
    }
    for(int i=0;i<v.size();i++)
    {
        //printf("%d %d\n",L[i],R[i]);
        cnt[make_pair(L[i],R[i])]++;
    }
    ll ret=1;
    for(auto u:cnt)
        ret=ret*Catalan(u.second)%mod;
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll ans = gao(v);
    cout << ans % mod << '\n';
    //cout<<gao1(v)<<'\n';
}

int main()
{
    //freopen("data.in", "r", stdin);
    IO();
    init();
    int _ = 1;
    //cin >> _;
    while (_--)
        solve();
}
