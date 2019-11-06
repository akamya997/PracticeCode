#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int A=a+c,B=b+d;
		if(A>B)
		{
			cout<<1<<endl;
		}
		else if(B>A){
			cout<<2<<endl;
		}
		else{
			if(b>c)
			{
				cout<<2<<endl;
			}
			else if(b<c)
			{
				cout<<1<<endl;
			}
			else cout<<-1<<endl;
		}
	}
}
