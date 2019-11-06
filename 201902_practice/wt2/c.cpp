#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,s;
	string str;
	cin>>n>>s;
	getline(cin,str);
	while(n--)
	{
		getline(cin,str);
		string ans;
		for(int i=0;i<str.length();i++)
		{
			if(!((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))) ans+=str[i];
			else 
			{
				if(str[i]>='a'&&str[i]<='z')
					ans+=((str[i]-'a'-s)%26+26)%26+'a';
				else 
					ans+=((str[i]-'A'-s)%26+26)%26+'A';
			}
		}
		cout<<ans<<endl;
	}
}
