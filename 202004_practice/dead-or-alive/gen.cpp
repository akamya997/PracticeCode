#include "testlib.h"
#include<bits/stdc++.h>

int main(int argc,char* argv[])
{
        registerGen(argc, argv, 1);
        int n = opt<int>(1);
        int t = opt<int>(2);
        int mx = opt<int>(3);
        int rt = rnd.next(1,n);
        std::vector<int> p(n);
        std::vector<int> v(n);
        for(int i = 0; i < n; i++) v[i] = rnd.next(0, mx);
        for(int i = 1; i < n; i++) p[i] = rnd.wnext(i, t);
        println(n,rt);
        for(int i=0;i<n;i++) printf("%d%c",v[i],i==n-1?'\n':' ');
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 0);
        shuffle(perm.begin() + 1, perm.end());

        std::vector<std::pair<int, int>> edges;
        for (int i = 1; i < n; i++)
            if (rnd.next(2))
                edges.push_back(std::make_pair(perm[i], perm[p[i]]));
            else
                edges.push_back(std::make_pair(perm[p[i]], perm[i]));

        shuffle(edges.begin(), edges.end());

        for (auto& [x, y]: edges) {
            println(x + 1, y + 1);
        }
    }
