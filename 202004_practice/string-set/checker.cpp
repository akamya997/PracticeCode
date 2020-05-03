#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
void getfail(string &t,int *fail)
{
    memset(fail, 0, sizeof(fail));
    int len = t.length();
    int j = 0, k = fail[0] = -1;
    while (j < len)
    {
        while (k != -1 && t[j] != t[k])
            k = fail[k];
        fail[++j] = ++k;
    }
}

int kmp(string &s,string &t,int *fail)
{
    int n = s.length(), m = t.length();
    int i = 0, j = 0;
    int ret = 0;
    while (i < n)
    {
        while (j != -1 && s[i] != t[j])
            j = fail[j];
        i++, j++;
        if (j == m)
            ret++, j = fail[j];
    }
    return ret;
}
const int maxn=505;
int fail[maxn];
int checkAns(InStream &stream, int n) {
    int k = stream.readInt(1, n);
    map<int, int> len2id;
    string ptn = format("[01]{1, %d}", n);
    map<string,int> s2id;
    auto tokens = stream.readTokens(k, ptn);
    for(int i=0;i<k;i++)
    {
        int len=tokens[i].length();
        bool ok=len2id.count(len);
        if(ok)
        {
            stream.ensuref(!ok, "the %d%s token has the same length with %d%s",
                        i + 1, englishEnding(i + 1).c_str(), len2id[len],
                        englishEnding(len2id[len]).c_str());
        }
        len2id[len]=i+1;
        s2id[tokens[i]]=i+1;
    }
    sort(tokens.begin(),tokens.end(),[&](string &a,string &b){
        return a.length()<b.length();
    });
    for(int i=0;i<k;i++)
    {
        getfail(tokens[i],fail);
        for(int j=i+1;j<k;j++)
        {
            stream.ensuref(!kmp(tokens[j],tokens[i],fail),
                               "the %d%s token is a substring of %d%s", s2id[tokens[i]],
                               englishEnding(s2id[tokens[i]]).c_str(), s2id[tokens[j]],
                               englishEnding(s2id[tokens[j]]).c_str());
        }
    }
    return k;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    int pans = checkAns(ouf, n);
    int jans = checkAns(ans, n);
    if (jans > pans) {
        quitf(_wa, "jury found a better answer, %d vs %d", jans, pans);
    } else if (jans < pans) {
        quitf(_fail, "participant found a better answer, %d vs %d", jans, pans);
    }
    quitf(_ok, "the answer is %d", pans);
}