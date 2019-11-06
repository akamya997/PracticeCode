#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int T=10;
	cout<<T<<endl;
	while(T--)
	{
		int n=rand()%100+1;
		cout<<n<<endl;
		for(int i=0;i<n;i++)
		{
			int len=rand()%100+1;
			for(int j=0;j<len;j++)
			{
				if(rand()%2) cout<<"(";
				else cout<<")";
			}
			cout<<endl;
		}
	}
}
