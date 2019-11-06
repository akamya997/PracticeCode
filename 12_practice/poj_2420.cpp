#include<algorithm>
#include<cmath>
#include<cstdio>
#include<ctime>
using namespace std;
const double eps=0.01,delta=0.98;
struct point{
	double x,y;
	point(){};
	point(double _x,double _y):x(_x),y(_y){}
	double operator -(const point &a)const{
		return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
	}
}pt[105];
double getsum(double x,double y,int n)
{
	double ret=0;
	for(int i=0;i<n;i++)
	{
		ret+=sqrt((x-pt[i].x)*(x-pt[i].x)+(y-pt[i].y)*(y-pt[i].y));
	}
	return ret;
}
int main()
{
	srand(time(NULL));
	int n;
	while(~scanf("%d",&n))
	{
		double TT=100000;
		double ansx=0,ansy=0,ans=10000000;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&pt[i].x,&pt[i].y);
			ansx+=pt[i].x,ansy+=pt[i].y;
		}
		ansx/=n,ansy/=n;
		ans=getsum(ansx,ansy,n);
		while(TT>eps)
		{
			double nx=0,ny=0;
			for(int i=0;i<n;i++)
			{
				nx+=(pt[i].x-ansx)/(point(ansx,ansy)-pt[i]);
				ny+=(pt[i].y-ansy)/(point(ansx,ansy)-pt[i]);
			}
			double temp=getsum(ansx+nx*TT,ansy+ny*TT,n);
			if(temp<ans)
			{
				ans=temp;
				ansx+=nx*TT,ansy+=ny*TT;
			}
			else if(log((temp-ans)/TT)<(rand()%10000)/10000.0)
			{
				ans=temp;ansx+=nx*TT,ansy+=ny*TT;
			}
			TT*=delta;
		}
		printf("%.0f\n",ans);
	}
}
