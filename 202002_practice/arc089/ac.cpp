#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define pdi pair<db,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define eps 1e-8
#define mo 974711
#define MAXN 1000005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
    if(c == '-') f = -1;
    c = getchar();
    }
    while(c >= '0' && c <= '9') {
    res = res * 10 + c - '0';
    c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
    out(x / 10);
    }
    putchar('0' + x % 10);
}
const int MOD = 1000000007;
int N,K,C[1005][1005],L[75],fac[1005],invfac[1005],cnt;
int sum[75],pos[75],tot,ans,matc[75];
char s[75];
bool vis[75];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void update(int &x,int y) {
    x = inc(x,y);
}
int fpow(int x,int c) {
    int res = 1,t = x;
    while(c) {
        if(c & 1) res = mul(res,t);
        t = mul(t,t);
        c >>= 1;
    }
    return res;
}
bool check() {
    if(tot < cnt) return false;
    memset(sum,0,sizeof(sum));
    int p = 1;
    for(int i = cnt ; i >= 1 ; --i) {
    sum[pos[i]]++;
    if(L[p] >= 2) {
        if(!matc[pos[i]]) return false;
        sum[matc[pos[i]]] += L[p] - 1;
    }
    ++p;
    }
    for(int i = K ; i >= 1 ; --i) {
    sum[i] += sum[i + 1];
    if(sum[i] > K - i + 1) return false;
    }
    return true;
}
bool dfs(int pre,int dep,int len) {
    cnt = dep;
    if(!check()) return false;
    int k = 1 + cnt;
    for(int i = 1 ; i <= cnt ; ++i) {
        if(L[i] == 1) ++k;
        else k += 2 * L[i] - 1;
    }
    int res = C[N - len + k - 1][k - 1];
    res = mul(res,fac[cnt]);
    int t = 0;
    for(int i = 1 ; i <= cnt ; ++i) {
        if(L[i] != L[i - 1]) {
            res = mul(res,invfac[t]);
            t = 0;
        }
        ++t;
    }
    res = mul(res,invfac[t]);
    //printf("L:");for(int i=1;i<=cnt;i++) printf("%d ",L[i]);
    //puts("");
    //printf("%d\n",res);
    update(ans,res);
    if(dep + 1 > tot) return true;
    for(int i = pre ; i <= 70 ; ++i) {
        int tl = len;
        if(dep != 0) ++tl;
        if(i == 1 || i == 2) tl += 1;
        else tl += i - 2 + i - 1;
        if(tl > N) break;
        L[dep + 1] = i;
        if(!dfs(i,dep + 1,tl)) break;
    }
    return true;
}
void Solve() {
    read(N);read(K);
    scanf("%s",s + 1);
    C[0][0] = 1;
    for(int i = 1 ; i <= 1000 ; ++i) {
        C[i][0] = 1;
        for(int j = 1 ; j <= i ; ++j) {
            C[i][j] = inc(C[i - 1][j - 1],C[i - 1][j]);
        }
    }
    fac[0] = 1;
    for(int i = 1 ; i <= 1000 ; ++i) fac[i] = mul(fac[i - 1],i);
    invfac[1000] = fpow(fac[1000],MOD - 2);
    for(int i = 999 ; i >= 0 ; --i) invfac[i] = mul(invfac[i + 1],i + 1);
    tot = 0;
    for(int i = 1 ; i <= K ; ++i) {
        if(s[i] == 'r') {
        pos[++tot] = i;
    
        for(int j = i + 1 ; j <= K ; ++j) {
        if(s[j] == 'b' && !vis[j]) {matc[i] = j;vis[j] = 1;break;}
        }
    }
    }
    dfs(1,0,0);
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}