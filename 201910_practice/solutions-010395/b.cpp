#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

const int MAX_N = 1e6 + 3;
const int oo = 1e9;

int lf[MAX_N];
int rg[MAX_N];
int n;
string str;

int find_lf(int i)
{
    if (i < 0) return -1;
    else if (lf[i] == i) {
        lf[i] = (str[i] == '.') ? find_lf(i - 1) : lf[i];
        return lf[i];
    } else return lf[i] = find_lf(lf[i]);
}

int find_rg(int i)
{
    if (i >= n) return n;
    else if (rg[i] == i) {
        rg[i] = (str[i] == '.') ? find_rg(i + 1) : rg[i];
        return rg[i];
    } else return rg[i] = find_rg(rg[i]);
}

int main()
{
    //freopen("input.txt","r",stdin); 
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    n = str.length();

    for (int i = 0; i < n; ++i) {
        lf[i] = i;
        rg[i] = i;
    } 

    set<pair<int, int>> pos;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == '(' && str[i + 1] == ')') pos.insert({i, i + 1});
    }

    int m, l, r, ans, lp, rp;
    cin >> m;
    while (m-- > 0) {
        ans = 0;
        cin >> l >> r;
        --l;
        --r;
        auto it = pos.lower_bound({l, -oo});
        while (it != pos.end() && it->F <= r && it->S <= r) {
            ans += 2;
            str[it->F] = '.';
            str[it->S] = '.';
            
            lp = find_lf(it->F);
            rp = find_rg(it->S);
            pos.erase(*it);
            if (lp >= 0 && rp < n && str[lp] == '(' && str[rp] == ')') pos.insert({lp, rp});
            it = pos.lower_bound({l, -oo});
        } 
        cout << ans << '\n';
    }

    return 0;
}