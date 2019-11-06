#include<bits/stdc++.h>
using namespace std;
const int N = 105;
typedef long long ll;
ll mod = 998244353;
char s[105];
int root = 0, sz = 0;
int ch[N][15];
int fail[N];
int ed[N];

void init()
{
	root = 0;
	sz = 0;
	for (int i = 0; i <= 9; i++)
		ch[root][i] = 0;
	fail[root] = 0;
	ed[root] = 0;
}

int new_node()
{
	sz++;
	for (int i = 0; i <= 9; i++)
		ch[sz][i] = 0;
	fail[sz] = 0;
	ed[sz] = 0;
	return sz;
}

void build(int id, char buf[])
{
	int len = strlen(buf);
	int cur = root;
	for (int i = 0; i < len; i++)
	{
		int c = buf[i] - '0';
		if (!ch[cur][c])
			ch[cur][c] = new_node();
		cur = ch[cur][c];
	}
	ed[cur] = 1 << id;
}

void get_fail()
{
	queue<int> q;
	for (int i = 0; i <= 9; i++)
	{
		int u = ch[root][i];
		if (!u)
		{
			ch[root][i] = root;
			continue;
		}
		q.push(u);
		fail[u] = root;
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int c = 0; c <= 9; c++)
		{
			int v = ch[u][c];
			if (!v)
			{
				ch[u][c] = ch[fail[u]][c];
				continue;
			}
			fail[v] = ch[fail[u]][c];
			ed[v] |= ed[fail[v]];
			q.push(v);
		}
	}
}

char l[105], r[105];
pair<ll, ll> dp[N][N][35];
int len;
ll wei[N];
int n;
//dp[i][j][k] 到第i位，自动机上j号点，含有子串k的结果

pair<ll, ll> solve(char num[], int pos, int cur, bool limit, int con)
{
	if (pos == -1)
		return make_pair(con == (1 << n) - 1, 0);
	if (!limit && dp[pos][cur][con].second != -1)
	{
		return dp[pos][cur][con];
	}
	int up = limit? num[pos] - '0' : 9;
	ll sum = 0;
	ll cnt = 0;
	for (int i = 0; i <= up; i++)
	{
		pair<ll, ll> ret = solve(num, pos - 1, ch[cur][i], limit && i == up, con | ed[ch[cur][i]]);
		cnt += ret.first;
		cnt %= mod;
		sum = (sum + ret.second + ret.first * wei[pos] % mod * i % mod) % mod;
		/*
		if (cnt > 0)
		{
			printf("dfs %lld %lld %d\n", cnt, sum, pos);
		}
		*/
	}
	if (!limit)
		return dp[pos][cur][con] = make_pair(cnt, sum);
	return make_pair(cnt, sum);
}

int main()
{
	scanf("%d", &n);
	init();
	scanf("%s", l);
	scanf("%s", r);
	len = strlen(l);
	for (int i = len - 1; i >= 0; i--)
	{
		if (l[i] > '0')
		{
			l[i]--;
			break;
		}
		l[i] = '9';
	}
	int len1 = len;
	if (l[0] == '0' && len > 1)
	{
		for (int i = 0; i < len - 1; i++)
		{
			s[i] = s[i + 1];
		}
		len1 = len - 1;
	}
	for (int i = 0; i < len1 / 2; i++)
	{
		swap(l[i], l[len1 - i - 1]);
	}
	/*
	//debug
	for (int i = 0; i < len1; i++)
		putchar(l[i]);
	putchar('\n');
	*/
	len = strlen(r);
	for (int i = 0; i < len / 2; i++)
		swap(r[i], r[len - 1 - i]);
	/*
	//debug
	for (int i = 0; i < len; i++)
		putchar(r[i]);
	putchar('\n');
	*/
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		// puts(s);
		build(i, s);
	}
	get_fail();
	wei[0] = 1;
	for (int i = 1; i <= 100; i++)
		wei[i] = wei[i - 1] * 10 % mod;

	pair<ll, ll> ini = make_pair(0, -1ll);
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			for (int k = 0; k <= 33; k++)
				dp[i][j][k] = ini;
	ll ret = solve(r, strlen(r) - 1, root, 1, 0).second - solve(l, len1 - 1, root, 1, 0).second;
	ret = (ret + mod) % mod;
	printf("%lld\n", ret);
	return 0;
}
