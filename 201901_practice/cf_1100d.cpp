#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
}p[1000];
int maze[1000][1000];
int curx,cury;
int cntx[1000],cnty[1000];
void solve()
{
    bool flag=0;
    int k=0,nx=0,ny=0;
    do
    {
        if(k==-1&&nx==-1&&ny==-1) return;
        Point &cur=p[k];
        maze[cur.x][cur.y]=0;
        maze[nx][ny]=1;
        cntx[cur.x]--,cnty[cur.y]--;
        cur.x=nx,cur.y=ny;
        cntx[cur.x]++,cnty[cur.y]++;
        if(!flag)
        {
            if(curx==1&&cury==1) flag=1;
            else{
                if(curx==1||maze[curx-1][cury-1])
                    nx=curx,ny=cury-1;
                else if(cury==1) ny=cury,nx=curx-1;
                else{
                    nx=curx-1,ny=cury-1;
                }
            }
        }
        if(flag)
        {
            nx=curx+1,ny=cury+1;
            if(maze[nx][ny]) nx--;
        }
        cout<<nx<<" "<<ny<<endl;
        cout.flush();
        curx=nx,cury=ny;
    }while(cin>>k>>nx>>ny&&k+nx+ny);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cntx,0,sizeof(cntx));
    memset(cnty,0,sizeof(cnty));
    cin>>curx>>cury;
    for(int i=1;i<=666;i++)
    {
        cin>>p[i].x>>p[i].y;
        maze[p[i].x][p[i].y]=1;
        cntx[p[i].x]++;
        cnty[p[i].y]++;
    }
    solve();
}
