#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		if(n%2||m%2) cout<<"hasan\n";
		else cout<<"abdullah\n";
	}
}
