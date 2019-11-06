#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;

using board = vector<string>;

const int N = 1e6+6;



char winner(board &a){
	static string str = "XO";
	for(char c : str)
	for(int dx=-1;dx<2;++dx)
	for(int dy=-1;dy<2;++dy) if(dx || dy)
	for(int i=0;i<3;++i)
	for(int j=0;j<3;++j){
		int cnt = 0;
		for(int k=0;k<3;++k){
			int x = i+dx*k, y = j+dy*k;
			if(0<=x && x<=2 && 0<=y && y<=2 && a[x][y]==c) ++cnt;
		}
		if(cnt==3) return c;
	}
	return '.';
}

int states = 0;

map<char,map<board,int>> mem;
map<char,map<board,vector<pair<int,int>>>> how;
int who(board a, char player, char enemy){
	char w = winner(a);
	if(w==player) return 1;
	if(w==enemy) return -1;
	if(!mem[player].count(a)){
		++states;
		auto &res = mem[player][a];
		res = -1;
		bool can = false;
		for(int i=0;i<3;++i)
		for(int j=0;j<3;++j) if(a[i][j]=='.'){
			can = true;
			board t = a;
			t[i][j] = player;
			int call = -who(t, enemy, player);
			if(call > res){
				res = call;
				how[player][a].clear();
			}
			if(call == res) how[player][a].push_back({i,j});
		}
		if(!can) res = 0;
	}
	return mem[player][a];
}

int main(){
	board a = {"...","...","..."};
	
	string s;
	cin>>s;
	char now = s[0];
	
	for(;;){
		bool can = false;
		for(int i=0;i<3;++i) for(int j=0;j<3;++j) if(a[i][j]=='.') can = true;
		if(!can) break;
		if(now=='O'){
			cin>>s;
			if(s=="WIN" || s=="LOSE" || s=="DRAW") break;
			int i = atoi(s.c_str()), j;
			cin>>j;
			--i; --j;
			a[i][j] = 'O';
		}else{
			who(a, 'X', 'O');
			int i = how['X'][a][0].first;
			int j = how['X'][a][0].second;
			a[i][j] = 'X';
			cout<<i+1<<' '<<j+1<<endl;
		}
		now^='X'^'O';
	}
	
	return 0;
}
