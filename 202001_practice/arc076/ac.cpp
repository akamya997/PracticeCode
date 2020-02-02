
#include<bits/stdc++.h>
#define ls(x) (x*2)
#define rs(x) (x*2+1)
using namespace std;
 
const int maxn=2e5+7,inf=1e9+7;
 
int n,m,ans=0;
struct Opt{int l,r;}p[maxn];
struct Node{int lazy,maxx;}node[maxn*4];
 
bool cmp(const Opt &A,const Opt &B){return A.l<B.l;}
void pushdown(int num,int nl,int nr){
  if(!node[num].lazy)return;
  int lz=node[num].lazy; node[num].lazy=0;
  node[ls(num)].maxx+=lz;node[ls(num)].lazy+=lz;
  node[rs(num)].maxx+=lz;node[rs(num)].lazy+=lz;    
}
void update(int num){node[num].maxx=max(node[ls(num)].maxx,node[rs(num)].maxx);}
void build(int num,int nl,int nr){
  node[num].lazy=0; if(nl==nr){node[num].maxx=nr-m-1;return;}
  int mid=(nl+nr)/2;
  build(ls(num),nl,mid);build(rs(num),mid+1,nr);
  update(num);
}
void add(int num,int nl,int nr,int ql,int qr,int ad){
  if(ql<=nl&&nr<=qr){node[num].maxx+=ad;node[num].lazy+=ad;return;}
  if(nr<ql||qr<nl)return;
  int mid=(nl+nr)/2;pushdown(num,nl,nr);
  add(ls(num),nl,mid,ql,qr,ad);add(rs(num),mid+1,nr,ql,qr,ad);
  update(num);return;
}
int quary(int num,int nl,int nr,int ql,int qr){
  if(ql<=nl&&nr<=qr)return node[num].maxx;
  if(nr<ql||qr<nl)return -inf;
  int mid=(nl+nr)/2;pushdown(num,nl,nr);
  return max(quary(ls(num),nl,mid,ql,qr),quary(rs(num),mid+1,nr,ql,qr));
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d%d",&p[i].l,&p[i].r);
  sort(p+1,p+n+1,cmp);p[n+1].l=inf;
  build(1,0,m+1);
  for(int i=1;i<=n;i++){
    add(1,0,m+1,0,p[i].r,1);
    if(p[i].l!=p[i+1].l&&p[i].l<=m-1)ans=max(ans,quary(1,0,m+1,p[i].l+2,m+1)-p[i].l);
  }ans=max(ans,n-m);printf("%d\n",ans);
  return 0;
}