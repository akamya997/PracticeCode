#include <bits/stdc++.h>

const int maxn=2e6+7;
int a[maxn];
    int n, m;
inline bool ok(int m, int v) {
    long long sum = 0;
    for (int i=0;i<n;i++) {
        int t=a[i];
        sum += (t + v - 1) / v;
    }
    return sum <= m;
}

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int l = 1, r = 1e7, ans;
    while(l <= r) {
        int mid = l + r >> 1;
        if (ok(m, mid)) {
            ans = mid, r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
}
