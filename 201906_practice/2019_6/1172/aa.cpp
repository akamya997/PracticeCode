#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int a[maxn],b[maxn];

int main(){
    int n,x,p=-1,ans,nn;
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&x);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        if (a[i]==1) p=i;
    }
    if (p!=-1){
        bool flag=true;
        for (int i=p;i<n;++i){
            if (a[i]!=i-p+1){
                flag=false;
                break;
            }
        }
        if (flag){
            int bk=a[n-1];
            for (int i=0;i<p;++i){
                if (a[i]==0) continue;
                if (a[i]-bk<=i+1){
                    flag=false;
                    break;
                }
            }
            if (flag){
//                cout<<"SP!"<<endl;
                printf("%d\n",p);
                return 0;
            }
        }
    }
    nn=n;
    ans=0;
    if (p!=-1){
        nn=0;
        for (int i=p+1;i<n;++i){
            b[nn++]=a[i];
        }
    }
//    cout<<"b: ";
//    for (int i=0;i<nn;++i){
//        cout<<b[i]<<' ';
//    }
//    cout<<endl;
    for (int i=0;i<nn;++i){
        if (b[i]==0) continue;
        if (b[i]-i<=1){
        ans=max(ans,2-(b[i]-i));
        }
    }
//    cout<<ans<<'+'<<p+1<<'+'<<n<<endl;
    if (p!=-1){
        ans+=p+1;
    }
    ans+=n;
    printf("%d\n",ans);
    return 0;
}

/*
3
0 2 0
0 3 1
*/
