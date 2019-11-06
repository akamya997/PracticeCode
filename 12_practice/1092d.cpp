#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
stack<int> s;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0,temp;i<n;i++)
	{
		scanf("%d",&temp);
		if(!s.empty()&&temp==s.top())
			s.pop();
		else s.push(temp);
	}
	if(s.size()<=1) puts("YES");
	else puts("NO");
	
}
