#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        string z,x,y;
        cin>>z>>x>>y;
        vi last(y.length());
        vi cur(26,-1);
        vector<vi> pre(z.length(),vi(26));
        for(int i=0;i<z.length();i++)
        {
            for(int j=0;j<26;j++)
                pre[i][j]=cur[j];
            cur[z[i]-'a']=i;
        }
        bool ok=1;
        last[y.length()-1]=cur[y.back()-'a'];
        for(int i=y.length()-2;i>=0;i--)
        {
            if(last[i+1]==-1)
                ok=0;
            if(!ok) break;
            last[i]=pre[last[i+1]][y[i]-'a'];
        }
        if(!ok||last[0]==-1)
        {
            cout<<"NO\n";
            continue;
        }
        x+='$';
        y+='$';
        int a=0,b=0;
        for(int i=0;i<z.length();i++)
        {
            if(z[i]==x[a]&&z[i]==y[b])
            {
                if(last[b]>i)
                    a++;
                else b++;
            }
            else if(z[i]==x[a])
                a++;
            else if(z[i]==y[b])
                b++;
            printf("i:%d a:%d b:%d\n",i,a,b);
        }
        if(x[a]=='$'&&y[b]=='$') cout<<"YES\n";
        else cout<<"NO\n";


    }
}