#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m;
char a[1000010];
char b[1010];
int nxt[1000010][27];
int dp[1010][1010];
void init(){
    for (int i=0;i<26;i++){
        nxt[n+1][i]=-1;
    }
    for (int i=n+1;i>=1;--i) {
        for (int j=0;j<26;++j){
            nxt[i-1][j]=nxt[i][j];
        }
        if (i!=n+1) nxt[i-1][a[i]-'a']=i;
    }
}
int main(){
    while(~scanf("%s%s",a+1,b+1))
	{
	n=strlen(a+1);
	m=strlen(b+1);
    init();
    memset(dp,0x3f,sizeof(dp));
    for (int i=0;i<=m;++i){
        dp[i][0]=0;
    }
    int ans=0;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=i;++j){
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if (dp[i-1][j-1]!=inf && nxt[dp[i-1][j-1]][b[i]-'a']!=-1){
                dp[i][j]=min(dp[i][j],nxt[dp[i-1][j-1]][b[i]-'a']);
            }
//            if (dp[i][j]!=inf) ans=max(ans,j);
        }
    }
    for (int i=0;i<=m;++i){
        for (int j=0;j<=m;++j){
            if (dp[i][j]!=inf) ans=max(ans,j);
        }
    }
    printf("%d\n",ans);
	}
    return 0;
}
