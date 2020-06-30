#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    if(n==1)
        cout<<0<<'\n';
    else if(n==2)
        cout<<-1<<'\n';
    else if(n==3)
        cout<<"3\n1 3 2\n2 3 1\n3 1 2\n";
    else {
        vector<vi> ans;
        if(n%2==0)
        {
            if(n%4==0)
            {
                vi cur(n+1);
                for(int i=1;i<=n;i+=4)
                {
                    cur[i]=i+1;
                    cur[i+1]=i+3;
                    cur[i+2]=i;
                    cur[i+3]=i+2;
                }
                ans.push_back(cur);
            }
            else{
                vi cur(n+1);
                for(int i=1;i<=n;i+=4)
                {
                    if(i+3>n) break;
                    cur[i]=i+1;
                    cur[i+1]=i+3;
                    cur[i+2]=i;
                    cur[i+3]=i+2;
                }
                for(int i=n-4;i<=n;i++) if(cur[i]==0) cur[i]=i;
                ans.push_back(cur);
                cur=vi(n+1);
                for(int i=n-3;i>=1;i-=4)
                {
                    cur[i]=i+1;
                    cur[i+1]=i+3;
                    cur[i+2]=i;
                    cur[i+3]=i+2;
                }
                for(int i=1;i<=4;i++) if(cur[i]==0) cur[i]=i;
                ans.push_back(cur);
            }
        }
        int k=0;
        while((1<<k)<n) k++;
        if(n%2==0&&n%4!=0) k--;
        for(int i=0;i<k;i++)
        {
            vi cur(n+1);
            for(int j=1;j<=n;j++)
                cur[j]=(j-1+(1<<i))%n+1;
            ans.push_back(cur);
        }
        cout<<ans.size()<<'\n';
        for(auto u:ans)
        {
            for(int j=1;j<=n;j++) cout<<u[j]<<" \n"[j==n];
        }
    }
}