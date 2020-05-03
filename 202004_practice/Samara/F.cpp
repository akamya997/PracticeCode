#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> ans;
    for(int i=1;i<=n;i+=2) ans.push_back(i);
    if(n%2==0) ans.push_back(n);
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i==ans.size()-1];
}