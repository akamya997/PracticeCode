#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d;bool x=1;
	cin>>a>>b>>c>>d;
	if (a!=d) {x=0;}
	if (c&&(!a||!d)) {x=0;}
	cout<<x<<"\n";
	return 0;
}
