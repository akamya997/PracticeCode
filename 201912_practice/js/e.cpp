#include <bits/stdc++.h>
const int maxn=105;
int a[maxn];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        std::sort(a, a+n);
        printf("%d %d\n", a[n - 2], a[1]);
    }
}
