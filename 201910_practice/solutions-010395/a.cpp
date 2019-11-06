// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<deque>
#include<stack>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

struct Stream
{
	deque<char> buffer;
	Stream()
	{
		buffer.clear();
	}
	char nxtChar()
	{
		if (buffer.size() == 0)
			buffer.push_back(getchar());
		return buffer.front();
	}
	char getChar()
	{
		char ret = nxtChar();
		buffer.pop_front();
		return ret;
	}
};

struct Cursor
{
	Stream mystream;
	deque<string> buffer;
	Cursor()
	{
		buffer.clear();
	}
	string nxtLexeme()
	{
		if (buffer.size()) return buffer.front();
		while ((mystream.nxtChar() == ' ') || (mystream.nxtChar() == '\n'))
			mystream.getChar();
		string ret = "";
		switch (mystream.nxtChar())
		{
			case '[': case ']':
			case '(': case ')':
			case '{': case '}':
			case ',': case ';':
				ret += mystream.getChar();
			break;
			case '>': case '=':
				while ((mystream.nxtChar() == '=') || (mystream.nxtChar() == '>'))
					ret += mystream.getChar();
			break;
			default:
				if ((mystream.nxtChar() >= '0') && (mystream.nxtChar() <= '9'))
					while ((mystream.nxtChar() >= '0') && (mystream.nxtChar() <= '9'))
						ret += mystream.getChar();
				else
					while ((mystream.nxtChar() >= 'a') && (mystream.nxtChar() <= 'z'))
						ret += mystream.getChar();
			break;
		}
		buffer.push_back(ret);
		return buffer.front();
	}
	string getLexeme()
	{
		string ret = nxtLexeme();
		buffer.pop_front();
		return ret;
	}
	int getInt()
	{
		string lex = getLexeme();
		int ret = 0;
		int i;
		fortodo(i, 0, lex.size() - 1)
			ret = ret * 10 + (lex[i] - '0');
		return ret;
	}
};

const int MAXN = 100010;
const int INF = int(1e+9);

struct SEG
{
	SEG* s[2];
	i64 lsum, rsum, sum;
	bool thru;
	SEG()
	{
		s[0] = s[1] = NULL;
		lsum = rsum = sum = 0;
		thru = false;
	}
};

SEG* emp(int L, int R)
{
	SEG* cur = new SEG;
	if (L == R) return cur;
	int Mid = (L + R) / 2;
	cur->s[0] = emp(L, Mid);
	cur->s[1] = emp(Mid + 1, R);
	return cur;
}

void modify(SEG* cur, int L, int R, int b, int v)
{
	if (L == R)
		{
			cur->sum = cur->lsum = cur->rsum = v;
			cur->thru = (v != 0);
			return;
		}
	int Mid = (L + R) / 2;
	if (b <= Mid)
		modify(cur->s[0], L, Mid, b, v);
	else
		modify(cur->s[1], Mid + 1, R, b, v);
	cur->thru = cur->s[0]->thru && cur->s[1]->thru;
	cur->sum = max(max(cur->s[0]->sum, cur->s[1]->sum), cur->s[0]->rsum + cur->s[1]->lsum);
	cur->lsum = cur->s[0]->lsum + ((cur->s[0]->thru) ? cur->s[1]->lsum : 0);
	cur->rsum = cur->s[1]->rsum + ((cur->s[1]->thru) ? cur->s[0]->rsum : 0);
}

struct Modification
{
	int A, T, OV, NV;
	Modification() {};
	Modification(int a, int t, int ov, int nv)
	{
		A = a; T = t;
		OV = ov; NV = nv;
	}
};

struct Restriction
{
	int N, K;
	int L[MAXN], R[MAXN], Conflict;
	SEG* root;
	void init(int n, int k)
	{
		N = n; K = k;
		int i;
		fortodo(i, 1, N)
			{
				L[i] = 0;
				R[i] = INF + 1;
			}
		Conflict = 0;
		root = emp(1, N);
	}
	pair<Modification,Modification> toModify(int x, int v)
	{
		Modification caseThen, caseElse;
		caseThen = Modification(x, 0, L[x], max(L[x], v));
		caseElse = Modification(x, 1, R[x], min(R[x], v - 1));
		return make_pair(caseThen, caseElse);
	}
	void Attach(Modification x)
	{
		if (x.OV == x.NV) return;
		Conflict -= ((L[x.A] > R[x.A]) ? 1 : 0);
		if (x.T == 0)
			{
				L[x.A] = x.NV;
				modify(root, 1, N, x.A, x.NV);
			}
		else
			R[x.A] = x.NV;
		Conflict += ((L[x.A] > R[x.A]) ? 1 : 0);
	}
	void Deattach(Modification x)
	{
		swap(x.OV, x.NV);
		Attach(x);
	}
	bool Satisfiable()
	{
		return ((Conflict == 0) && (root->sum <= K));
	}
};

Cursor fin;
Restriction rez;

int main()
{
	fin.getLexeme(); // game
	fin.getLexeme(); // (
	int N = fin.getInt();
	fin.getLexeme(); // , 
	int K = fin.getInt();
	fin.getLexeme(); // )
	rez.init(N, K);
	static bool cg[1<<20];
	static stack<char> P;
	static stack<Modification> Q;
	P.push('B');
	fin.getLexeme(); // {
	string lex;
	while (P.size())
		switch (P.top())
		{
			case 'B':
				if (fin.nxtLexeme() == "}")
					{
						fin.getLexeme();
						P.pop();
					}
				else
					P.push('S');
			break;
			case 'S':
				P.pop();
				lex = fin.nxtLexeme();
				if (lex == "{")
					{
						fin.getLexeme();
						P.push('B');
					}
				if (lex == "art")
					{
						fin.getLexeme(); // cg
						fin.getLexeme(); // (
						cg[fin.getInt()] |= rez.Satisfiable();
						fin.getLexeme(); // )
						fin.getLexeme(); // ;
					}
				if (lex == "if")
					{
						fin.getLexeme(); // if
						fin.getLexeme(); // (
						fin.getLexeme(); // a
						fin.getLexeme(); // [
						int x = fin.getInt();
						fin.getLexeme(); // ]
						fin.getLexeme(); // >=
						int v = fin.getInt();
						fin.getLexeme(); // )
						P.push('I');
						P.push('T');
						P.push('S');
						pair<Modification,Modification> pmm = rez.toModify(x, v);
						Q.push(pmm.second);
						Q.push(pmm.first);
						rez.Attach(pmm.first);
					}
			break;
			case 'T':
				P.pop();
				rez.Deattach(Q.top());
				Q.pop();
				if (fin.nxtLexeme() == "else")
					{
						fin.getLexeme();
						rez.Attach(Q.top());
						P.push('S');
					}
				else
					{
						P.pop();
						Q.pop();
					}
			break;
			case 'I':
				P.pop();
				rez.Deattach(Q.top());
				Q.pop();
			break;
			default:
			break;
		}
	int sum = 0;
	int i;
	fortodo(i, 0, 0xFFFFF)
		if (cg[i])
			sum++;
	printf("%d\n", sum);
}

