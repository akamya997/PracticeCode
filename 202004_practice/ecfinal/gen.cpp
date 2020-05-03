#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int n;
    n=100000;
    cout<<n<<' '<<(n-2)*2<<endl;
    for(int i=2;i<n;i++)
    {
        cout<<1<<" "<<i<<" "<<rand()<<endl;
        cout<<i<<" "<<n<<" "<<rand()<<endl;
    }
}