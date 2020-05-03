#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        vector<int> all;
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        all.push_back(l1);
        all.push_back(l2);
        all.push_back(r1);
        all.push_back(r2);
        int l3,r3,l4,r4;
        cin>>l3>>r3>>l4>>r4;
        all.push_back(l3);
        all.push_back(l4);
        all.push_back(r3);
        all.push_back(r4);
        sort(all.begin(),all.end());
        all.erase(unique(all.begin(),all.end()),all.end());
        int maze[20][20];
        auto getid=[&](int x)
        {
            return lower_bound(all.begin(),all.end(),x)-all.begin();
        };
        l1=getid(l1);
        l2=getid(l2);
        l3=getid(l3);
        l4=getid(l4);
        r1=getid(r1);
        r2=getid(r2);
        r3=getid(r3);
        r4=getid(r4);
        int cnt1=(r2-r1+1)*(l2-l1+1),cnt2=(r4-r3+1)*(l4-l3+1);
        memset(maze,0,sizeof(maze));
        for(int i=l1;i<=l2;i++)
        {
            for(int j=r1;j<=r2;j++)
                maze[i][j]=1;
        }
        for(int i=l3;i<=l4;i++)
        {
            for(int j=r3;j<=r4;j++)
                maze[i][j]=2;
        }
        int c1=0,c2=0;
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                if(maze[i][j]==1) c1++;
                else if(maze[i][j]==2) c2++;
            }
        }
        if(c1==cnt1&&c2==cnt2)
            cout<<"Separate\n";
        else if(c1==0)
            cout<<"A in B\n";
        else if(c1+c2==cnt1)
            cout<<"B in A\n";
        else cout<<"Intersect\n";
    }
}