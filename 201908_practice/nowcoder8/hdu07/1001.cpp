#pragma GCC optimize(3)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int Max = 4e4 + 6;
const int N = 20;
int n, m;
int fa[Max][N];
int deep[Max];
int cost[Max];
int head[Max];
int tot;
struct edge
{
    int to, w, nxt;
} edges[Max * 3];
void addedge(int u, int v, int w)
{
    edges[++tot] = {v, w, head[u]};
    head[u] = tot;
}
void init(int n)
{
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    tot = 0;
}
void dfs(int u, int pre, int dis)
{
    cost[u] = dis;
    for (int i = head[u]; i != -1; i = edges[i].nxt)
    {
        int v = edges[i].to;
        int w = edges[i].w;
        if (v == pre)
        {
            continue;
        }
        fa[v][0] = u;
        deep[v] = deep[u] + 1;
        dfs(v, u, dis + w);
    }
}
void bz()
{
    for (int j = 1; j < N; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
}
inline int lca(int u, int v)
{
    if (deep[u] < deep[v])
    {
        swap(u, v);
    }
    int dc = deep[u] - deep[v];
    for (int i = 0; i < N; i++)
    {
        if ((1 << i) & dc)
        {
            u = fa[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    u = fa[u][0];
    return u;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m)
    {
        init(n);
        int u, v, w;
        char c;
        while (m--)
        {
            cin >> u >> v >> w >> c;
            addedge(u, v, w);
            addedge(v, u, w);
        }
        dfs(1, 0, 0);
        bz();
        int q;
        cin >> q;
        while (q--)
        {
            cin >> u >> v;
            cout << cost[u] + cost[v] - 2 * cost[lca(u, v)] << "\n";
        }
    }
    return 0;
}