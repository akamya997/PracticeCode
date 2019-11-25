#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
vector<int> prime;
int pm[maxn];
void db()
{
	memset(pm,0,sizeof(pm));
	for(int i=2;i<maxn;i++)
	{
		if(!pm[i]) {pm[i]=i;prime.push_back(i);}
		for(auto &p:prime)
		{
			if(p*i>=maxn) break;
			if(i%p==0){
				pm[i*p]=p;
				break;
			}
			pm[i*p]=p;
		}
	}
	//cout<<prime[prime.size()-1]<<","<<prime[prime.size()-2]<<endl;
}
inline __int128 input()
{
	__int128 ret=0;
	char ch=0;
	while(!(ch<='9'&&ch>='0')) ch=getchar();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
void print(__int128 a)
{
	if(a==0) return;
	print(a/10);
	char cur=a%10+'0';
	putchar(cur);
}
/*__int128 sqrt(__int128 a)
{
	long long tt=(1LL<<62)+((1LL<<62)-1);
	__int128 l=0,r=a;
	while(l<r)
	{
		__int128 mid=(l+r)/2;
		if(mid>tt||mid*mid>=a) r=mid;
		else l=mid+1;
	}
	//print(r);puts("");
	return r;
}*/

bool issqr(__int128_t x)
{
    __int128_t y=(__int128_t)ceil(sqrt((long double)x));
    for(;y*y<=x;++y);
        for(--y;y*y>x;--y);
    return y*y==x;
}
bool iscub(__int128_t x)
{
    __int128_t y=(__int128_t)ceil(pow((long double)x,1.0/3));
    for(;y*y*y<=x;++y);
        for(--y;y*y*y>x;--y);
    return y*y*y==x;
}
void upd(vector<int> &ans,__int128_t L,__int128_t R)
{
    if(R==1)
        ans.push_back(L==1?1:(iscub(L)?3:(issqr(L)?2:1)));//(1,1) (p1^3,1) (p1^2,1) (p1,1)
    else if(issqr(R))
        ans.push_back(R%L?2:3);//(p1,p2^2) (p1,p1^2)
    else if(issqr(L))//r>1
        ans.push_back(L%R?2:3);//(p1%2,p2) (p1^2,p1)
    else if(R%L==0)
        ans.push_back(L==R?2:2);//(p1,p1) (p1,p1 p2)
}
__int128 lif(__int128 a)
{
	__int128 l=0,r=a;
	while(l<r)
	{
		__int128 mid=(l+r)/2;
		if(mid*mid*mid<a) l=mid+1;
		else r=mid;
	}
	return r;
}
vector<int> ans1,ans2;
int main()
{
	db();
	int T;
	scanf("%d",&T);
	__int128 k1,k2;
	while(T--)
	{
		k1=input(),k2=input();
		ans1.clear(),ans2.clear();
		for(auto &p:prime)
		{
			if(k1>=p&&k1%p==0)
			{
				int cnt=0;
				while(k1%p==0) k1/=p,cnt++;
				ans1.push_back(cnt);
			}
			if(k2>=p&&k2%p==0)
			{
				int cnt=0;
				while(k2%p==0) k2/=p,cnt++;
				ans2.push_back(cnt);
			}
		}
		auto gcd=__gcd(k1,k2);
		upd(ans1,gcd,k1/gcd);
        upd(ans2,gcd,k2/gcd);
		long long ans=1;
		for(auto &p:ans1) ans*=p;
		printf("%lld ",ans);
		ans=1;
		for(auto &p:ans2) ans*=p;
		printf("%lld\n",ans);
	}
}
