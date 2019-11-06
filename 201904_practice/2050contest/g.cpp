#include <bits/stdc++.h>
using namespace std;
#define nxt(i) ((i + 1) % s.size())
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
vector<int> all;
const int maxn=1e3+7;
const int mod=1e9+7;
vector<int> row,col;
int maze[maxn*2][maxn*2];
int w,h,n,m;
typedef double LD;
const LD PI = 3.14159265358979323846;
const LD eps = 1E-10;
int sgn(LD x) { return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1); }
struct L;
struct P;
typedef P V;
struct P {
    LD x, y;
    explicit P(LD x = 0, LD y = 0): x(x), y(y) {}
    explicit P(const L& l);
};
struct L {
    P s, t;
    L() {}
    L(P s, P t): s(s), t(t) {}
};

P operator + (const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }
P operator - (const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
P operator * (const P& a, LD k) { return P(a.x * k, a.y * k); }
P operator / (const P& a, LD k) { return P(a.x / k, a.y / k); }
inline bool operator < (const P& a, const P& b) {
    return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}
bool operator == (const P& a, const P& b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y); }
P::P(const L& l) { *this = l.t - l.s; }
ostream &operator << (ostream &os, const P &p) {
    return (os << "(" << p.x << "," << p.y << ")");
}
istream &operator >> (istream &is, P &p) {
    return (is >> p.x >> p.y);
}

LD dist(const P& p) { return sqrt(p.x * p.x + p.y * p.y); }
LD dot(const V& a, const V& b) { return a.x * b.x + a.y * b.y; }
LD det(const V& a, const V& b) { return a.x * b.y - a.y * b.x; }
LD cross(const P& s, const P& t, const P& o = P()) { return det(s - o, t - o); }
typedef vector<P> S;
bool p_on_seg(const P& p, const L& seg) {
    P a = seg.s, b = seg.t;
    return !sgn(det(p - a, b - a)) && sgn(dot(p - a, p - b)) <= 0;
}
P l_intersection(const L& a, const L& b) {
    LD s1 = det(P(a), b.s - a.s), s2 = det(P(a), b.t - a.s);
    return (b.s * s2 - b.t * s1) / (s2 - s1);
}
// 点是否在多边形中 0 = 在外部 1 = 在内部 -1 = 在边界上
int inside(const S& s, const P& p) {
    int cnt = 0;
	for(int i=0;i<s.size();i++)
    {
        P a = s[i], b = s[nxt(i)];
        if (p_on_seg(p, L(a, b))) return -1;
        if (sgn(a.y - b.y) <= 0) swap(a, b);
        if (sgn(p.y - a.y) > 0) continue;
        if (sgn(p.y - b.y) <= 0) continue;
        cnt += sgn(cross(b, a, p)) > 0;
    }
    return bool(cnt & 1);
}
S rec;
bool inrec(LD x,LD y)
{
	P cur=P((x-y)*sqrt(2.0)/2.0,(x+y)*sqrt(2.0)/2.0);
	return inside(rec,cur);
}
P seg_int(int a,int b)
{
	return l_intersection(L(P(a,0),P(0,a)),L(P(-b,0),P(0,b)));
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		all.clear();
		rec.clear();
		cin>>w>>h>>n>>m;
		rec.push_back(P{0,0});
		rec.push_back(P{sqrt(2.0)*w/2.0,sqrt(2.0)*w/2.0});
		rec.push_back(P{sqrt(2.0)*w/2.0-sqrt(2.0)/2.0*h,sqrt(2.0)/2.0*(h+w)});
		rec.push_back(P{-sqrt(2.0)*h/2.0,sqrt(2.0)*h/2.0});
		for(int i=0;i<n;i++)
		{
			int tmp;
			cin>>tmp;
			row.push_back(tmp);
		}
		for(int i=0;i<m;i++)
		{
			int tmp;
			cin>>tmp;
			col.push_back(tmp);
		}
		sort(row.begin(),row.end());
		sort(col.begin(),col.end());
		for(int i=1;i<row.size();i++)
		{
			for(int j=1;j<col.size();j++)
			{
				P c1=seg_int(row[i],col[j]),c2=seg_int(row[i-1],col[j]),c3=seg_int(row[i-1],col[j-1]),c4=seg_int(row[i],col[j-1]);
				maze[i][j]=(inrec(c1.x,c1.y)&&inrec(c2.x,c2.y)&&inrec(c3.x,c3.y)&&inrec(c4.x,c4.y));
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<m;j++)
				cout<<maze[i][j]<<" ";
			cout<<endl;
		}
	}
}
