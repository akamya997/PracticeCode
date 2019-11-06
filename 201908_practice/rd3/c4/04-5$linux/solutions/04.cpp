#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s1[maxn],s2[maxn];
int a[maxn][26],b[maxn][26];
int f[maxn],bac[maxn];
int main()
{
 scanf("%s%s",s1+1,s2+1);
 int len1=strlen(s1+1);
 int len2=strlen(s2+1);
 for(int i=0;i<26;i++)
    a[len1][i]=0;
 for(int i=len1;i>0;i--)
 {
     for(int j=0;j<26;j++)
        a[i-1][j]=a[i][j];
     a[i-1][s1[i]-'a']=i;
 }
 for(int i=0;i<26;i++)
    b[1][i]=0;
 for(int i=1;i<=len1;i++)
 {
      for(int j=0;j<26;j++)
        b[i+1][j]=b[i][j];
     b[i+1][s1[i]-'a']=i;
 }
 int temp=0;
 for(int i=1;i<=len2;i++)
 {

     temp=a[temp][s2[i]-'a'];
     f[i]=temp;
 }
 f[0]=0;
 f[len2+1]=len1+1;
 temp=len1+1;
 for(int i=len2;i>=1;i--)
 {
     temp=b[temp][s2[i]-'a'];
     bac[i]=temp;
 }
 bac[0]=0;
 bac[len2+1]=len1+1;
 int ans=0;

 for(int i=1;i<=len2+1;i++)
 {
     ans=max(ans,f[i]-f[i-1]-1);
     ans=max(ans,bac[i]-bac[i-1]-1);
 }
 for(int i=1;i<len2;i++)
 {
     ans=max(ans,bac[i+1]-f[i]-1);
 }
 cout<<ans<<endl;
 return 0;
}
