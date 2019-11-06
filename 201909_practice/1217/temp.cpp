#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    // 逆时针旋转
    point turn(db k1) { return (point){x * cos(k1) - y * sin(k1), x * sin(k1) + y * cos(k1)}; }
    point turn90() { return (point){-y, x}; }
    bool operator<(const point k1) const    //x 为第一关键词 y 为第二关键词
    {
        int a = cmp(x, k1.x);
        if (a == -1)
            return 1;
        else if (a == 1)
            return 0;
        else
            return cmp(y, k1.y) == -1;
    }
    db abs() { return sqrt(x * x + y * y); }
    db abs2() { return x * x + y * y; }
    db dis(point k1) { return ((*this) - k1).abs(); }
    point unit()
    {
        db w = abs();
        return (point){x / w, y / w};
    }
    void scan()
    {
        double k1, k2;
        scanf("%lf%lf", &k1, &k2);
        x = k1;
        y = k2;
    }
    void print() { printf("%.11lf %.11lf\n", x, y); }
    db getw() { return atan2(y, x); }
    point getdel()
    {
        if (sign(x) == -1 || (sign(x) == 0 && sign(y) == -1))
            return (*this) * (-1);
        else
            return (*this);
    }
    int getP() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) == -1); }
};
int inmid(point k1, point k2, point k3) { return inmid(k1.x, k2.x, k3.x) && inmid(k1.y, k2.y, k3.y); }
db cross(point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
db dot(point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
db rad(point k1, point k2) { return atan2(cross(k1, k2), dot(k1, k2)); }
// -pi -> pi
int compareangle(point k1, point k2)
{
    return k1.getP() < k2.getP() || (k1.getP() == k2.getP() && sign(cross(k1, k2)) > 0);
}
point proj(point k1, point k2, point q)
{ // q 到直线 k1,k2 的投影
    point k = k2 - k1;
    return k1 + k * (dot(q - k1, k) / k.abs2());
}
point reflect(point k1, point k2, point q) { return proj(k1, k2, q) * 2 - q; }  q 对于直线 k1,k2 的对称点
int clockwise(point k1, point k2, point k3)
{ // k1 k2 k3 逆时针 1 顺时针 -1 否则 0
    return sign(cross(k2 - k1, k3 - k1));
}
int checkLL(point k1, point k2, point k3, point k4)
{ // 求直线 (L) 线段 (S)k1,k2 和 k3,k4 的交点
    return cmp(cross(k3 - k1, k4 - k1), cross(k3 - k2, k4 - k2)) != 0;
}
point getLL(point k1, point k2, point k3, point k4)
{
    db w1 = cross(k1 - k3, k4 - k3), w2 = cross(k4 - k3, k2 - k3);
    return (k1 * w2 + k2 * w1) / (w1 + w2);
}
int intersect(db l1, db r1, db l2, db r2)
{
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return cmp(r1, l2) != -1 && cmp(r2, l1) != -1;
}
int checkSS(point k1, point k2, point k3, point k4)
{ // 非规范相交 <= 0 ; 规范相交 < 0
    return intersect(k1.x, k2.x, k3.x, k4.x) && intersect(k1.y, k2.y, k3.y, k4.y) &&
           sign(cross(k3 - k1, k4 - k1)) * sign(cross(k3 - k2, k4 - k2)) <= 0 &&
           sign(cross(k1 - k3, k2 - k3)) * sign(cross(k1 - k4, k2 - k4)) <= 0;
}
db disSP(point k1, point k2, point q)
{ // 点 ( q ) 到线段 ( k1 , k2 ) 距离
    point k3 = proj(k1, k2, q);
    if (inmid(k1, k2, k3))
        return q.dis(k3);
    else
        return min(q.dis(k1), q.dis(k2));
}
db disSS(point k1, point k2, point k3, point k4)
{
    if (checkSS(k1, k2, k3, k4))
        return 0;
    else
        return min(min(disSP(k1, k2, k3), disSP(k1, k2, k4)), min(disSP(k3, k4, k1), disSP(k3, k4, k2)));
}
int onS(point k1, point k2, point q) //点q在点k1,k2之间
{
    return inmid(k1, k2, q) && sign(cross(k1 - q, k2 - k1)) == 0;
}

//---------------------------------------------------------------------
//
//
//
//
vector<point> db;

int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};
void work(int d,int r)
{
    for(int s=1;s*s<=r/d;++s)
    {
        int t=sqrt(r/d-s*s);
        if(__gcd(s,t)==1&&s*s+t*t==r/d)
        {
            int x=(s*s-t*t)/2*d;
            int y=d*s*t;
            if(x>0&&y>0&&x*x+y*y==(r/2)*(r/2)) 
			{
				// cout<<x<<" "<<y<<endl;
				for (int i = 0; i < 4; i++) {
					int nx = x * dx[i];
					int ny = y * dy[i];
					db.push_back((point){nx,ny});
					db.push_back((point){ny,nx});
				}
			}
        }
    }
}


void gao(int r)
{
	db.push_back((point){0,r});
	db.push_back((point){r,0});
	db.push_back((point){0,-r});
	db.push_back((point){-r,0});
	r*=2;
	for(int i=1;i*i<=r;++i)
    {
        if(r%i==0)
        {
            work(i,r);
            if(i*i!=r) work(r/i,r);
        }
    }
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		gao(n);
		for(auto x: db)
			x.print();
	}
}
