#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db eps = 1e-6;
const db pi = acos(-1.0);
int sign(db k)
{
    if (k > eps)
        return 1;
    else if (k < -eps)
        return -1;
    return 0;
}
int cmp(db k1, db k2) { return sign(k1 - k2); }
int inmid(db k1, db k2, db k3) { return sign(k1 - k3) * sign(k2 - k3) <= 0; } // k3 在 [k1,k2] 内
struct point
{
    db x, y;
    point operator+(const point &k1) const { return (point){k1.x + x, k1.y + y}; }
    point operator-(const point &k1) const { return (point){x - k1.x, y - k1.y}; }
    point operator*(db k1) const { return (point){x * k1, y * k1}; }
    point operator/(db k1) const { return (point){x / k1, y / k1}; }
    int operator==(const point &k1) const { return cmp(x, k1.x) == 0 && cmp(y, k1.y) == 0; }
    bool operator<(const point k1) const
    {
        int a = cmp(x, k1.x);
        if (a == -1)
            return 1;
        else if (a == 1)
            return 0;
        else
            return cmp(y, k1.y) == -1;
    }
    void scan()
    {
        double k1, k2;
        scanf("%lf%lf", &k1, &k2);
        x = k1;
        y = k2;
    }
};
int inmid(point k1, point k2, point k3) { return inmid(k1.x, k2.x, k3.x) && inmid(k1.y, k2.y, k3.y); }
db cross(point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
db dot(point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }

int onS(point k1, point k2, point q)
{
    return inmid(k1, k2, q) && sign(cross(k1 - q, k2 - k1)) == 0;
}

int contain(vector<point> A, point q)
{
    int pd = 0;
    A.push_back(A[0]);
    for (int i = 1; i < A.size(); i++)
    {
        point u = A[i - 1], v = A[i];
        if (onS(u, v, q))
            return 1;
        if (cmp(u.y, v.y) > 0)
            swap(u, v);
        if (cmp(u.y, q.y) >= 0 || cmp(v.y, q.y) < 0)
            continue;
        if (sign(cross(u - v, q - v)) < 0)
            pd ^= 1;
    }
    return pd << 1;
}
vector<point> ConvexHull(vector<point> A, int flag = 1)
{
    int n = A.size();
    vector<point> ans(n * 2);
    sort(A.begin(), A.end());
    int now = -1;
    for (int i = 0; i < A.size(); i++)
    {
        while (now > 0 && sign(cross(ans[now] - ans[now - 1], A[i] - ans[now - 1])) <= flag)
            now--;
        ans[++now] = A[i];
    }
    int pre = now;
    for (int i = n - 2; i >= 0; i--)
    {
        while (now > pre && sign(cross(ans[now] - ans[now - 1], A[i] - ans[now - 1])) <= flag)
            now--;
        ans[++now] = A[i];
    }
    ans.resize(now);
    return ans;
}

vector<point> v;

int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //clock_t st = clock();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        v.clear();
        int n, q;
        scanf("%d%d", &n, &q);

        point t;
        for (int i = 0; i < n; i++)
        {
            t.scan();
            v.push_back(t);
        }
        if (n == 1)
        {
            while (q--)
            {
                t.scan();
                if (t == v[0])
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            continue;
        }
        if (n == 2)
        {
            while (q--)
            {
                t.scan();
                if (onS(v[0], v[1], t))
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            continue;
        }
        v = ConvexHull(v, 0);
        while (q--)
        {
            t.scan();
            if (contain(v, t))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    //cout << clock() - st << endl;
}

/*
4
1 1
1 1
1 1
2 3
20 20
50 50
20 20
30 30
30 35
3 4
0 0
100 0
50 100
50 100
50 0
50 50
0 100
4 2
3 3
5 5
10 10
15 15
1 1
12 12
*/
