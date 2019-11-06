#include <iostream>
#include <cstdio>
#include <cstring>
#define lson pos << 1     //左儿子坐标 当前节点坐标*2
#define rson pos << 1 | 1 //右儿子坐标 当前节点坐标*2+1
using namespace std;
typedef long long ll;
const int maxn = 100005;         //元素个数
ll sum[maxn * 4], add[maxn * 4]; //sum求和，add为延迟标记
ll a[maxn], n, q;                //a为原[1,n]数组
char Q;
int x, y, z;
//PushUp函数 更新线段树上每个节点的信息 当前是求区间和
void PushUp(int pos)
{
    sum[pos] = sum[lson] + sum[rson];
}
//PushDown函数 下推延迟标记
void PushDown(int pos, int ln, int rn)
//ln,rn为左右子树的数量
{
    if (add[pos])
    {
        //标记下推
        add[lson] += add[pos];
        add[rson] += add[pos];
        //修改子节点的sum值
        sum[lson] += add[pos] * ln;
        sum[rson] += add[pos] * rn;
        //清楚当前节点标记
        add[pos] = 0;
    }
}
//Build建树
void Build(int l, int r, int pos)
{
    if (l == r) //l == r抵达叶节点
    {
        sum[pos] = a[l]; //存储数组
        return;
    }
    int m = (l + r) >> 1;
    //向左右递归建树
    Build(l, m, lson);     //向左递归建树
    Build(m + 1, r, rson); //向右递归建树
    //向上更新节点信息
    PushUp(pos);
}
void UpdateInterval(int L, int R, int C, int l, int r, int pos)
//对a[L,R] += C
{
    if (L <= l && r <= R) //[l,r]区间完全包含在[L,R]区间内
    {
        sum[pos] += C * (r - l + 1);
        add[pos] += C;
        return;
    }
    int m = (l + r) >> 1;
    PushDown(pos, m - l + 1, r - m);
    if (L <= m)
    {
        UpdateInterval(L, R, C, l, m, lson);
    }
    if (R > m)
    {
        UpdateInterval(L, R, C, m + 1, r, rson);
    }
    PushUp(pos);
}
ll Query(int L, int R, int l, int r, int pos)
{
    if (L <= l && r <= R)
    {
        return sum[pos];
    }
    int m = (l + r) >> 1;
    //下推标记
    PushDown(pos, m - l + 1, r - m);
    //答案
    ll ans = 0;
    if (L <= m)
        ans += Query(L, R, l, m, lson);
    if (R > m)
        ans += Query(L, R, m + 1, r, rson);
    return ans;
}

int main()
{
    while (scanf("%d%d", &n, &q) != EOF)
    {
        memset(sum, 0, sizeof(sum));
        memset(add, 0, sizeof(add));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        Build(1, n, 1);
        for (int i = 0; i < q; i++)
        {
            cin >> Q;
            if (Q == 'Q')
            {
                scanf("%d%d", &x, &y);
                ll temp = Query(x, y, 1, n, 1);
                printf("%lld\n", temp);
            }
            else
            {
                scanf("%d%d%d", &x, &y, &z);
                UpdateInterval(x, y, z, 1, n, 1);
            }
        }
    }
}