#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> col(200001);
    for(int i=0;i<n;i++)
    {
        int a,c;
        cin>>a>>c;
        col[c].push_back(a);
    }
    bool ok=1;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<col[i].size();j++)
        {
            if(col[i][j]<col[i][j-1]) ok=0;
        }
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}