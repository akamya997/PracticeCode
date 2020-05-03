#include "testlib.h"

namespace KMP {
template <typename T>
std::vector<int> kmp_table(int n, const T &s) {
    std::vector<int> p(n, 0);
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k > 0 && !(s[i] == s[k])) {
            k = p[k - 1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        p[i] = k;
    }
    return p;
}
template <typename T>
std::vector<int> kmp_table(const T &s) {
    return kmp_table((int)s.size(), s);
}
template <typename T>
std::vector<int> kmp_search(int n, const T &s, int m, const T &w,
                            const std::vector<int> &p) {
    ensure(n >= 1 && (int)p.size() == n);
    std::vector<int> res;
    int k = 0;
    for (int i = 0; i < m; i++) {
        while (k > 0 && (k == n || !(w[i] == s[k]))) {
            k = p[k - 1];
        }
        if (w[i] == s[k]) {
            k++;
        }
        if (k == n) {
            res.push_back(i - n + 1);
        }
    }
    return res;
    // returns 0-indexed positions of occurrences of w in s
}
template <typename T>
std::vector<int> kmp_search(const T &s, const T &w, const std::vector<int> &p) {
    return kmp_search((int)s.size(), s, (int)w.size(), w, p);
}
}  // namespace KMP

int checkAns(InStream &stream, int n) {
    int k = stream.readInt(1, n);
    std::map<size_t, int> len2id;
    std::string ptn = format("[01]{1, %d}", n);
    auto tokens = stream.readTokens(k, ptn);
    for (int i = 0; i < k; i++) {
        size_t len = tokens[i].length();
        bool have = len2id.count(len);
        stream.ensuref(not have, "the %d%s token has the same length with %d%s",
                       i + 1, englishEnding(i + 1).c_str(), len2id[len],
                       englishEnding(len2id[len]).c_str());
        len2id[len] = i + 1;
    }
    for (int i = 0; i < k; i++) {
        auto p = KMP::kmp_table(tokens[i]);
        for (int j = 0; j < k; j++) {
            if (i != j) {
                stream.ensuref(KMP::kmp_search(tokens[i], tokens[j], p).empty(),
                               "the %d%s token is a substring of %d%s", i + 1,
                               englishEnding(i + 1).c_str(), j + 1,
                               englishEnding(j + 1).c_str());
            }
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
