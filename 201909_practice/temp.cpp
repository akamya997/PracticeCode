#include<bits/stdc++.h>
using namespace std;
string s;
int ans=0;
void solve(int &pos)
{
	if(ans==-1) return;
	if(pos==s.length()) return;
	int cnt=0;
	bool hasc=0,hasop=0;
	while(pos<s.length())
	{
		if(s[pos]=='(') 
		{
			cnt++;
			if(hasc)
			{
				ans=-1;
				break;
			}
			if(hasop) 
			{
				hasop=0;
				hasc=1;
			}
			else hasc=1;
			pos++;
			solve(pos);
		}
		else if(s[pos]==')')
		{
			if(cnt==0) ans=-1;
			break;
		}
		else if(s[pos]>='a'&&s[pos]<='z')
		{
			cnt++;
			if(hasc)
			{
				ans=-1;
				break;
			}
			if(hasop) 
			{
				hasop=0;
				hasc=1;
			}
			else hasc=1;
		}
		else if(s[pos]!=' ')
		{
			if(!hasc)
			{
				ans=-1;
				break;
			}
			else {
				if(hasop)
				{
					ans=-1;
					break;
				}
				else 
				{
					hasc=0;
					hasop=1;
				}
			}
		}
//	cout<<pos<<":"<<cnt<<" "<<hasc<<" "<<hasop<<endl;
		pos++;
		if(ans==-1) return;
	}
	if(cnt!=2&&ans!=-1) ans=1;
	if(hasop) ans=-1;
}
int main()
{
	getline(cin,s);
	int cntl=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(') cntl++;
		else if(s[i]==')') cntl--;
		if(cntl<0) ans=-1;
	}
	if(cntl!=0) ans=-1;
	int p=0;
	solve(p);
	if(ans==-1)
		cout<<"error"<<endl;
	else if(ans==0) cout<<"proper"<<endl;
	else cout<<"improper"<<endl;

}
