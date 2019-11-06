#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
const LD PI = acos(-1);
const LD eps = 1E-10;
struct P {
	LD x, y;
};
const int maxn=1e5+7;
P pt[maxn];
void rot(P &a,LD ang)
{
	ang=ang*PI/180;
	LD x=a.x,y=a.y;
	a.y=y*cos(ang)+x*sin(ang);
	a.x=x*cos(ang)-y*sin(ang);
}
int main()
{
	int A,W,H,N;
	scanf("%d%d%d%d",&A,&W,&H,&N);
	LD mxx=-1e9-7,mxy=-1e9-7,mix=1e9+7,miy=1e9+7;
	for(int i=0;i<N;i++) 
	{
		scanf("%Lf%Lf",&pt[i].x,&pt[i].y);
		rot(pt[i],A);
		mxx=max(mxx,pt[i].x);
		mix=min(mix,pt[i].x);
		mxy=max(mxy,pt[i].y);
		miy=min(miy,pt[i].y);
	}
	LD xr=W/(mxx-mix);
	LD yr=H/(mxy-miy);
	for(int i=0;i<N;i++)
	{
		printf("%.10Lf %.10Lf\n",(pt[i].x-mix)*xr,(pt[i].y-miy)*yr);
	}
}
