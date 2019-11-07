#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int ans;
int len[10];
int cal(vector<int> A,vector<int> B,vector<int> C)
{
	if(!A.size()||!B.size()||!C.size()) return 0x3f3f3f3f;
	int cost=0;
	int cura=0;
	for(int i=0;i<A.size();i++) cura+=A[i];
	cost+=abs(cura-a)+(A.size()-1)*10;
	int curb=0;
	for(auto p:B) curb+=p;
	cost+=abs(curb-b)+(B.size()-1)*10;
	int curc=0;
	for(auto p:C) curc+=p;
	cost+=abs(curc-c)+(C.size()-1)*10;
	return cost;
}
int n;
void dfs(int cur,vector<int> A,vector<int> B,vector<int> C)
{
	if(cur==n+1)
	{
		ans=min(ans,cal(A,B,C));
		return;
	}
	for(int i=0;i<4;i++)
	{
		if(i==1) 
		{
			A.push_back(len[cur]);
			dfs(cur+1,A,B,C);
			A.pop_back();
		}
		else if(i==2)
		{
			B.push_back(len[cur]);
			dfs(cur+1,A,B,C);
			B.pop_back();
		}
		else if(i==3)
		{
			C.push_back(len[cur]);
			dfs(cur+1,A,B,C);
			C.pop_back();
		}
		else{
			dfs(cur+1,A,B,C);
		}
	}
}
int main()
{
	ans=0x3f3f3f3f;
	cin>>n;
	cin>>a>>b>>c;
	for(int i=1;i<=n;i++) cin>>len[i];
	vector<int> A,B,C;
	dfs(1,A,B,C);
	cout<<ans<<endl;
}
