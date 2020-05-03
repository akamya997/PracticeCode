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

int n;
vector<pair<int, int>> v;
vector<int> ans;

void solve()
{
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first, v[i].second = i + 1;
    sort(v.begin(), v.end());
    int mx = v.back().first, sum = 0;
    ans.assign(mx, -1);
    for (auto x : v)
        sum += mx / x.first;
    if (sum > mx)
    {
        cout << "NIE" << '\n';
        return;
    }
    cout << "TAK" << '\n';
    cout<<mx<<" ";
    int cur=0;
    for(int i=0;i<n;i++)
    {
        while(ans[cur]!=-1) cur++;
        for(int j=cur;j<mx;j+=v[i].first)
            ans[j]=v[i].second;
    }
    for(int i=0;i<mx;i++)
        cout<<(ans[i]==-1?1:ans[i])<<" \n"[i==mx-1];
}

int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    IO();
    int _;
    cin >> _;
    while (_--)
        solve();
}