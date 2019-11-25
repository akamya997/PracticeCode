#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a[100005], q, NUL=2e9;
ll b[100005], c[100005], st[1<<18], lz[1<<18];

void bld(int i=1, int l=0, int r=n-1) {
	lz[i]=NUL;
	if(l==r) {
		st[i]=a[l];
		return;
	}
	int m=(l+r)/2;
	bld(2*i, l, m);
	bld(2*i+1, m+1, r);
	st[i]=st[2*i]+st[2*i+1];
}

void app(int i, int l, int r, ll x) {
	if(x==NUL)
		return;
	st[i]=(r-l+1)*x+c[r+1]-c[l];
	lz[i]=x;
}

void psh(int i, int l, int r, int m) {
	app(2*i, l, m, lz[i]);
	app(2*i+1, m+1, r, lz[i]);
	lz[i]=NUL;
}

void upd(int l1, int r1, ll x, int i=1, int l2=0, int r2=n-1) {
	if(l1<=l2&&r2<=r1) {
		app(i, l2, r2, x);
		return;
	}
	int m2=(l2+r2)/2;
	psh(i, l2, r2, m2);
	if(l1<=m2)
		upd(l1, r1, x, 2*i, l2, m2);
	if(m2<r1)
		upd(l1, r1, x, 2*i+1, m2+1, r2);
	st[i]=st[2*i]+st[2*i+1];
}

ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
	if(l1<=l2&&r2<=r1) {
		return st[i];
	}
	int m2=(l2+r2)/2;
	psh(i, l2, r2, m2);
	return (l1<=m2?qry(l1, r1, 2*i, l2, m2):0)+(m2<r1?qry(l1, r1, 2*i+1, m2+1, r2):0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=1; i<n; ++i)
		cin >> b[i], b[i]+=b[i-1];
	for(int i=1; i<=n; ++i)
		c[i]=c[i-1]+b[i-1];
	bld();
	cin >> q;
	while(q--) {
		char qt;
		cin >> qt;
		if(qt=='+') {
			int i, x;
			cin >> i >> x, --i;
			ll d=qry(i, i);
			int l=i, r=n-1;
			while(l<r) {
				int m=(l+r+1)/2;
				if(d+x+b[m]-b[i]>qry(m, m))
					l=m;
				else
					r=m-1;
			}
			//cout << i << " " << r << " " << d+x-b[i] << endl;
			upd(i, r, d+x-b[i]);
		} else {
			int l, r;
			cin >> l >> r, --l, --r;
			cout << qry(l, r) << "\n";
		}
	}
	return 0;
}