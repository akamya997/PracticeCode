#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+10;
char s1[maxn], s2[1005];
int dp[1005][1005];
int nxt[maxn][26], lst[27];
int main (){
	int n,m;
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	memset(lst,0x3f,sizeof(lst));
	for(int i=n;i>=0;--i){
		for(int j=0;j<26;++j){
			nxt[i][j] = lst[j];
		}
		if(i>0)	lst[s1[i]-'a'] = i;
	}
	memset(dp,0x3f,sizeof(dp)); 
	dp[0][0] = 0;
	int ans=0;
	for(int i=1;i<=m;++i){
		dp[i][0] = 0;
        for (int j=1;j<=i;++j){
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if (dp[i-1][j-1]!=INF && nxt[dp[i-1][j-1]][s2[i]-'a']!=INF){
                dp[i][j]=min(dp[i][j],nxt[dp[i-1][j-1]][s2[i]-'a']);
            }
			if(dp[i][j]!=INF)
				ans=max(ans,j);
//            if (dp[i][j]!=inf) ans=max(ans,j);
        }
    }
	printf("%d\n",ans);
	return 0;
} 
