#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int num=15;
int all[]={2,4,6,7,9,9,10,11,11,13,14,17,19,26,30};
vector<vi> ans;
bool check(int cur)
{
	int sum=0;
	for(int i=0;i<num;i++)
		if(cur&(1<<i)) sum+=all[i];
	return sum==29;
}
void output(int cur)
{
	vector<int> tot;
	for(int i=0;i<num;i++)
		if(cur&(1<<i)) tot.push_back(all[i]);
	ans.push_back(tot);
}
int main()
{
	for(int i=0;i<(1<<num);i++)
		if(check(i))
			output(i);
	sort(ans.begin(),ans.end());
	for(auto u:ans)
	{
		for(int i=0;i<u.size();i++)
			printf("%d%c",u[i],i==u.size()-1?'\n':'+');
	}
}
