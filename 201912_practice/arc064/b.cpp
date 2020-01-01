#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
  	cin>>s;
  	if(s[0]==s[s.length()-1])
    {
      	if(s.length()&1)
      		cout<<"Second\n";
  		else cout<<"First\n";
    }
  	else{
    	if(s.length()&1) cout<<"First\n";
      	else cout<<"Second\n";
    }
}
