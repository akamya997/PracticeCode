#include <iostream>
#include <queue>

using namespace std;

using ll = long long;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

ll mypow(ll b, ll n) {
    return n == 0 ? 1 : b * mypow(b, n - 1);
}

// 桁和を求める
ll dsum(ll n) {
    ll ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

// n以上で最小のすぬけ数を求める
ll snuke(ll n) {
    GPQ<pair<double, ll>> val;
    // (g(m), m)

    ll dig = 0;
    // 9が連続する桁数

    while (mypow(10, dig) <= n) {
        for (ll i = 1; i <= 9; ++i) {
            ll v = n - n % mypow(10, dig + 1) + i * mypow(10, dig) - 1;
            // 下dig桁が9
            // 1つ上は1~9
            // それより上はnと一致

            if (v >= n) {
                val.push(make_pair(v * 1.0 / dsum(v), v));
            }
        }
        ++dig;
    }
    --dig;

    // 1桁もnと一致しないものを列挙
    for (ll i = 1; i <= 100; ++i) {
        ll v = i * mypow(10, dig) - 1;
        if (v >= n) {
            val.push(make_pair(v * 1.0 / dsum(v), v));
        }
    }

    auto ret = val.top();
    // g(m)とmが最小となる(g(m), m)の組

    return ret.second;
}


int main() {
    ll K;
    cin >> K;
    ll pre = 1;

    for (ll i = 0; i < K; ++i) {
        cout << pre << endl;
        pre = snuke(pre + 1);
    }

    return 0;
}