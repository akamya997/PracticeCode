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

#define x1 xxx
#define x2 xxxx
#define y1 yyy
#define y2 yyyy
#define x first
#define y second

bool check(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    if (p1.x >= p2.x && p1.x <= p3.x && p1.y >= p2.y && p1.y <= p3.y)
        return true;
    return false;
}

void solve()
{
    pair<int, int> x1, x2, y1, y2;
    cin >> x1.first >> x1.second >> x2.first >> x2.second >> y1.first >> y1.second >> y2.first >> y2.second;
    pair<int, int> x3(x1.first, x2.second), x4(x2.first, x1.second), y3(y1.first, y2.second), y4(y2.first, y1.second);
    if (check(x1, y1, y2) && check(x2, y1, y2))
        cout << "A in B" << '\n';
    else if (check(y1, x1, x2) && check(y2, x1, x2))
        cout << "B in A" << '\n';
    else if (check(x1, y1, y2) || check(x2, y1, y2) || check(y1, x1, x2) || check(y2, x1, x2) ||
             check(x3, y1, y2) || check(x4, y1, y2) || check(y3, x1, x2) || check(y4, x1, x2))
        cout << "Intersect" << '\n';
    else     
        cout << "Separate" << '\n';
}

int main()
{
    IO();
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}