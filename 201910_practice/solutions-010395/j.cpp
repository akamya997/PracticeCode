#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Weighted Job Scheduling problem
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// A job has start time, finish time and profit.
struct Job
{
    int start, finish, profit;
    Job(int s, int f, int p) {
        start = s;
        finish = f;
        profit = p;
    }
};

bool mycomp(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int time2int(string s)
{
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 3600 +
           ((s[3] - '0') * 10 + (s[4] - '0')) * 60 +
            (s[6] - '0') * 10 + (s[7] - '0');
}

int binsearch(vector<Job> const& jobs, int index)
{
    int l = 0;
    int r = index - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (jobs[mid].finish <= jobs[index].start) {
            if (jobs[mid + 1].finish <= jobs[index].start) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }
        else {
            r = mid - 1;
        }
    }

    return -1;
}

long long solve(vector<Job>& jobs)
{
    if (jobs.size() == 0) {
        return 0LL;
    }
    // sort jobs by finish time
    sort(jobs.begin(), jobs.end(), mycomp);

    int n = jobs.size();
    vector<long long> dp(n);
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; ++i) {
        long long profit = jobs[i].profit;
        int l = binsearch(jobs, i);
        if (l != -1) {
            profit += dp[l];
        }
        dp[i] = max(profit, dp[i - 1]);
    }

    return dp[n - 1];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int i, n, c, p, start, finish, profit;
    string s, f;
    vector<Job> jobs;
    cin >> n >> c;
    for (i = 0; i < n; ++i) {
        cin >> s >> f >> p;
        start = time2int(s);
        finish = time2int(f);
        profit = p - c * (finish - start);
        if (profit > 0L) {
            jobs.push_back(Job(start, finish, profit));
        }
    }

    cout << solve(jobs) << endl;
    return 0;
}
