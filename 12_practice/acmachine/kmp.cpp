#include<bits/stdc++.h>
using namespace std;
int f[100];
void getfail(char *t)
{
	memset(f,0,sizeof(f));
	f[0]=-1;
	int len=strlen(t);
	for(int i=1;i<len;i++)
	{
		int j=f[i-1];
		while(t[j+1]!=t[i]&&j>=0)
			j=f[j];
		if(t[j+1]==t[i]) f[i]=j+1;
		else f[i]=-1;
		cout<<i<<":"<<f[i]<<endl;
	}
}
bool kmp(char *s,char *t)
{
	getfail(t);
	int n=strlen(s),m=strlen(t);
	bool ret=0;
	int i=0,j=0;
	while(i<n&&j<m&&m-j<=n-i)
	{
		if(s[i]==t[j])
			i++,j++;
		else {
			if(j==0) i++;
			else
				j=f[j-1]+1;
		}
		if(j==m) return puts("ok!!!");
	}
	return puts("NO!!!");
}
int main()
{
	char s[100],t[100];
	scanf("%s%s",s,t);
	kmp(s,t);
}
