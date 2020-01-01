#include <bits/stdc++.h>
 
int a[6];
 
int arr[100000][6];
int cnt = 0;
bool visited[13][13][13][13][13][13];
void dfs(int a, int b, int c, int d, int e, int f) {
    visited[a][b][c][d][e][f] = true;
    if (a + b + c + d + e + f == 12) {
        arr[cnt][0] = a;
        arr[cnt][1] = b;
        arr[cnt][2] = c;
        arr[cnt][3] = d;
        arr[cnt][4] = e;
        arr[cnt][5] = f;
        cnt++;
        return;
    }
    if (!visited[a + 1][b][c][d][e][f]) dfs(a + 1, b, c, d, e, f);
    if (!visited[a][b + 1][c][d][e][f]) dfs(a, b + 1, c, d, e, f);
    if (!visited[a][b][c + 1][d][e][f]) dfs(a, b, c + 1, d, e, f);
    if (!visited[a][b][c][d + 1][e][f]) dfs(a, b, c, d + 1, e, f);
    if (!visited[a][b][c][d][e + 1][f]) dfs(a, b, c, d, e + 1, f);
    if (!visited[a][b][c][d][e][f + 1]) dfs(a, b, c, d, e, f + 1);
}
 
std::set<int> ans;
 
void init() {
    for (int i = 0; i < cnt; i++) {
        int sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += arr[i][j] * a[j];
        }
        ans.insert(sum);
    }
}
 
int main() {
    dfs(0, 0, 0, 0, 0, 0);
    for (int i = 0; i < 3; i++) {
        scanf("%d", a + i);
    }
    for (int i = 3; i < 6; i++) a[i] = -a[i - 3];
    int q, o, p = 0;
    // printf("%d\n", cnt);
    init();
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &o);
        int d = std::abs(o - p);
        if (ans.count(d)) {
            p = d;
            puts("YES");
        } else {
            puts("NO");
            p = 0;
        }
    }
}
