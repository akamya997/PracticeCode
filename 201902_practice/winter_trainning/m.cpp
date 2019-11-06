#include<bits/stdc++.h>
using namespace std;
struct Seg{
	long long l,r;
}seg[2];
int main()
{
	long long h;
	cin>>seg[0].l>>seg[0].r>>seg[1].l>>seg[1].r>>h;
	if(seg[0].l>seg[1].l) swap(seg[0],seg[1]);
	long long ans=0;
	if(seg[1].l>=seg[0].r) ans=0;
	else{
		ans=(seg[1].r-seg[1].l)*h;
		if(seg[1].r>seg[0].r) ans-=(seg[1].r-seg[0].r)*h;
	}
	cout<<ans<<endl;

}
