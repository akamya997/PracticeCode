#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef pair<int,int> PII;
int ans[maxn];
bool dp[maxn][3][3];
PII pre[maxn][3][3];
int brr[maxn];
int n;
int cho[maxn][3];
template <typename T>
bool scan_d(T &num)
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
inline void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			static vector<int> cur;
			cur.clear();
			for(int k=0;k<3;k++)
			{
				if(i-k<1||i-k>n-2) continue;
				cur.push_back(brr[i-k]);
			}
			sort(cur.begin(),cur.end());
			cho[i][j]=cur[min((int)cur.size()-1,j)];
		}
	}
}
int main()
{
	int T;
	scan_d(T);
	while(T--)
	{
		scan_d(n);
		for(int i=0;i<=n;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					dp[i][j][k]=0;
		dp[0][2][2]=1;
		for(int i=1;i<=n-2;i++)
			scan_d(brr[i]);
		init();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					for(int t=0;t<3;t++)
					{
						static vector<int> tot;
						tot.clear();
						tot.push_back(cho[i+1][t]);
						if(i==0) tot.push_back(tot.back());
						else tot.push_back(cho[i][j]);
						if(i-1<=0) tot.push_back(tot.back());
						else tot.push_back(cho[i-1][k]);
						sort(tot.begin(),tot.end());
						if(i<=1||tot[1]==brr[i-1])
						{
							if(dp[i][j][k])
								pre[i+1][t][j]=make_pair(j,k);
							dp[i+1][t][j]|=dp[i][j][k];
						}
					}
				}
			}
		}
		bool ok=0;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(dp[n][i][j])
				{
					int p1=i,p2=j;
					for(int k=n;k>=1;k--)
					{
						static vector<int> cur;
						cur.clear();
						for(int kk=k;kk>=k-2&&kk>1;kk--)
							cur.push_back(brr[kk]);
						ans[k]=cho[k][p1];
						PII nxt=pre[k][p1][p2];
						p1=nxt.first;
						p2=nxt.second;
					}
					ok=1;
					break;
				}
			}
			if(ok) break;
		}
	//	ans[1]=brr[1];
		if(!ok) puts("-1");
		else{
			for(int i=1;i<=n;i++)
				printf("%d%c",ans[i],i==n?'\n':' ');
		}
	}
}
