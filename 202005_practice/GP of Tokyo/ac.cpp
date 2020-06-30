#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
#define int ll
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifndef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
 
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
 
using pi=pair<int,int>;
using vi=vc<int>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif
 
using uint=unsigned;
using ull=unsigned long long;
 
template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}
 
template<int i,class T>
void print_tuple(ostream&,const T&){
}
 
template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}
 
template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}
 
template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}
 
ll read(){
	ll i;
	cin>>i;
	return i;
}
 
vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}
 
template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}
 
string readString(){
	string s;
	cin>>s;
	return s;
}
 
template<class T>
T sq(const T& t){
	return t*t;
}
 
//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
}
 
constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}
 
const ll infLL=LLONG_MAX/3;
 
#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif
 
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
int mask(int i){
	return (int(1)<<i)-1;
}
 
bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}
 
template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}
 
ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}
 
template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}
 
using uint=unsigned;
using ull=unsigned long long;
 
struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};
 
extern constexpr modinfo base{998244353,3};
//extern constexpr modinfo base{1000000007,0};
using mint=modular<base>;
 
//左c列をsweepしする
//aの先頭rank行に要素が入っている感じ
//掃き出しに使った列の番号が返る
vi sweep(vvc<mint>&a,int c=-1){
	if(a.empty())return {};
	if(c==-1)c=a[0].size();
	int h=a.size(),w=a[0].size(),r=0;
	vi res;
	rep(i,c){
		if(r==h)break;
		rng(j,r,h)if(a[j][i].v){
			swap(a[r],a[j]);
			break;
		}
		if(a[r][i].v==0)continue;
		rep(j,h)if(j!=r){
			mint z=-a[j][i]/a[r][i];
			rng(k,i,w)
				a[j][k]+=a[r][k]*z;
		}
		res.pb(i);
		r++;
	}
	return res;
}
 
//解を一つ見つける
//解空間？kernelでも使っとけ
//aが空のときに備えてaの列の個数wを与える
//解が見つからないときは {} を返す
vc<mint> lineareq(vvc<mint> a,int w,vc<mint> b){
	int h=a.size();
	rep(i,h)a[i].pb(b[i]);
	vi idx=sweep(a,w);
	rng(i,idx.size(),h)
		if(a[i][w].v)return {};
	vc<mint> res(w);
	rep(i,idx.size())
		res[idx[i]]=a[i][w]/a[i][idx[i]];
	
	assert(si(idx)==h);
	
	return res;
}
 
vc<mint> mult_mod_f(const vc<mint>&x,const vc<mint>&y,const vc<mint>&f){
	int n=si(x),m=si(y);
	vc<mint> res(n+m-1);
	rep(i,n)rep(j,m)res[i+j]+=x[i]*y[j];
	int k=si(f);
	gnr(i,k-1,n+m-1){
		mint w=res[i]/f[k-1];
		rep(p,k-1)res[i-(k-1)+p]-=w*f[p];
	}
	res.resize(k-1);
	return res;
}
 
vc<mint> add_vec(const vc<mint>&x,const vc<mint>&y){
	assert(si(x)==si(y));
	vc<mint> res=x;
	rep(i,si(x))res[i]+=y[i];
	return res;
}
 
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m,k;cin>>n>>m>>k;
	assert(inc(1,n,m-1));
	assert(inc(1,k,m-1));
	
	vi raw=readvi(n);
	int sum=accumulate(all(raw),int(0));
	vc<mint> p(n);
	rep(i,n)p[i]=mint(raw[i])/sum;
	
	vc<mint> f(n+1);
	f[n]=1;
	rep(i,n)f[n-1-i]=-p[i];
	
	auto getweight=[&](int q){
		vc<mint> x(n),y(n);
		x[0]=1;
		vc<mint> z{0,1},w(n);
		w[0]=1;
		while(q){
			if(q%2){
				x=mult_mod_f(x,z,f);
				y=add_vec(mult_mod_f(y,z,f),w);
			}
			w=add_vec(mult_mod_f(z,w,f),w);
			z=mult_mod_f(z,z,f);
			q>>=1;
		}
		return mp(x,y);
	};
	vvc<mint> tail(n-1);
	vc<mint> con(n-1);
	{
		vc<mint> x,y;
		tie(x,y)=getweight(m-n);
		rep(i,n-1){
			tail[i]=x;
			con[i]=y[n-1];
			x=mult_mod_f(x,{0,1},f);
			y=mult_mod_f(y,{0,1},f);
			y[0]+=1;
		}
	}

	vvc<mint> a(n,vc<mint>(n));
	rep(i,n)a[i][i]=1;
	vc<mint> b(n,1);
	rep(i,n){
		rep(j,n){
			int x=i-j;
			if(x==0)continue;
			else if(0<x){
				a[i][x-1]-=p[j];
			}else{
				x=n-1+x;
				rep(t,n)
					a[i][t]-=tail[x][t]*p[j];
				b[i]+=p[j]*con[x];
			}
		}
	}
	vc<mint> c=lineareq(a,n,b);
	vc<mint> x,y;tie(x,y)=getweight(k-1);
	mint ans=y[n-1];
	rep(i,n)ans+=x[i]*c[i];
	cout<<ans<<endl;
}