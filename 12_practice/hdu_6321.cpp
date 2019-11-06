#include<bits/stdc++.h>
using namespace std;
const double eps=1e-10;
struct L;
struct P;
typedef P V;
int sgn(double x){return fabs(x)<eps?0:(x>0?1:-1);}
struct P{
	double x,y;
	explicit P(double x=0,double y=0):x(x),y(y){}
	explicit P(const L& l);
}pt[5];
struct L{
	P s,t;
	L() {}
	L(P s,P t):s(s),t(t){}
};
P operator + (const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }
P operator - (const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
P operator * (const P& a, double k) { return P(a.x * k, a.y * k); }
P operator / (const P& a, double k) { return P(a.x / k, a.y / k); }
double dot(const V& a,const V& b){return a.x*b.x+a.y*b.y;}
double det(const V& a,const V& b){return a.x*b.y-a.y*b.x;}
bool p_on_seg(const P& p,const L& seg){
	P a=seg.s,b=seg.t;
	return !sgn(det(p-a,b-a))&&sgn(dot(p-a,p-b))<=0;
}
double cross(const P& s,const P& t,const P& o=P()){return det(s-o,t-o);}
int inside(P& p)
{
	int cnt=0;
	for(int i=0;i<4;i++)
	{
		P a=pt[i],b=pt[(i+1)%4];
		if(p_on_seg(p,L(a,b))) return -1;
		if(sgn(a.y-b.y)<=0) swap(a,b);
		if(sgn(p.y-a.y)>0) continue;
		if(sgn(p.y-b.y)<=0) continue;
		cnt+=sgn(cross(b,a,p))>0;
	}
	return bool(cnt&1);
}
int main()
{
	int T;
	int kas=0;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<4;i++)
		{
			scanf("%lf%lf",&pt[i].x,&pt[i].y);
		}
		P p;
		scanf("%lf%lf",&p.x,&p.y);
		printf("Case %d:\n",++kas);
		if(inside(p)==1) puts("In");
		else puts("No");
	}
}
