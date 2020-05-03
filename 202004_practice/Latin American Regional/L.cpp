#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxn=1e3+7;
int a[maxn][maxn];
string maze[maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int preG=-1,preB=-1;
        cin>>maze[i];
        for(int j=0;j<m;j++)
        {
            if(maze[i][j]=='B')
            {
                a[i][j]=j-preG;
                preB=j;
            }
            else {
                a[i][j]=j-preB;
                preG=j;
            }
        }
    }
    int ans=1;
    for(int i=0;i<m;i++)
    {
        vi R(n);
        vi L(n);
        {
            stack<int> st;
            a[n][i]=0;
            for(int j=0;j<=n;j++)
            {
                while(!st.empty()&&a[st.top()][i]>a[j][i])
                {
                    int u=st.top();
                    R[u]=j;
                    ans=max(ans,min(a[u][i],j-u));
                    //printf("%d %d %d\n",i,j,u);
                    st.pop();
                }
                st.push(j);
            }
        }
        {
            stack<int> st;
            for(int j=n-1;j>=0;j--)
            {
                while(!st.empty()&&a[st.top()][i]>a[j][i])
                {
                    int u=st.top();
                    L[u]=j;
                    //printf("%d %d %d\n",i,j,u);
                    st.pop();
                }
                st.push(j);
            }
            while(!st.empty())
            {
                L[st.top()]=-1;
                st.pop();
            }
        }
        for(int j=0;j<n;j++)
            ans=max(ans,min(a[j][i],R[j]-L[j]-1));
    }
    cout<<ans*ans<<'\n';
}