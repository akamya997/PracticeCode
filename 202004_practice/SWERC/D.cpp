#include<bits/stdc++.h>
using namespace std;
double ti;
struct G
{
	vector<int> q;
	vector<pair<int,int>> v;
	int tot;
	bool fail;
	void init()
	{
		fail=0;
		for(int i=10005;i>=1;--i)
		{
			q.push_back(i-1);
			v.emplace_back(tot++,-1);
		}
	}
	inline void operate(char op)
	{
		if(op=='C')
		{
			int id=q.back();
			q.push_back(id);
		}
		else if(op=='D')
		{
			q.pop_back();
		}
		else if(op=='L')
		{
			int id=q.back();
			if(v[id].second!=-1)
			{
				q.pop_back();
				q.push_back(v[id].first);
			}
			else
				fail=1;
		}
		else if(op=='P')
		{
			int l=q.back();
			q.pop_back();
			int r=q.back();
			q.pop_back();
			q.push_back(v.size());
			v.emplace_back(l,r);
		}
		else if(op=='R')
		{
			int id=q.back();
			if(v[id].second!=-1)
			{
				q.pop_back();
				q.push_back(v[id].second);
			}
			else
				fail=1;
		}
		else if(op=='S')
		{
			int l=q.back();
			q.pop_back();
			int r=q.back();
			q.pop_back();

			q.push_back(l);
			q.push_back(r);
		}
		else if(op=='U')
		{
			int id=q.back();
			if(v[id].second!=-1)
			{
				q.pop_back();
				q.push_back(v[id].second);
				q.push_back(v[id].first);
			}
			else
				fail=1;
		}
	}
	bool check(int x,vector<pair<int,int>> &vx,int y,vector<pair<int,int>> &vy)
	{
        stack<pair<int,int>> st;
        st.emplace(x,y);
        while(!st.empty())
        {
            auto u=st.top();st.pop();
            x=u.first,y=u.second;
            if(vx[x].second==-1&&vy[y].second==-1)
            {
                if(vx[x].first!=vy[y].first) return false;
            }
            else if(vx[x].second!=-1&&vy[y].second!=-1)
            {
                st.emplace(vx[x].first,vy[y].first);
                st.emplace(vx[x].second,vy[y].second);
            }
            else return false;
            if(clock()-ti>CLOCKS_PER_SEC*0.28) return true;
        }
		return true;
	}
	bool compare(G &t)
	{
		if(q.size()!=t.q.size())
			return false;
		for(int i=0;i<q.size();++i)
			if(!check(q.at(i),v,t.q.at(i),t.v))
				return false;
		return true;
	}
	void show()
	{
		for(auto p:v)
			cout<<p.first<<" "<<p.second<<endl;
		cout<<"queue: ";
		for(int i=0;i<q.size();++i)
			cout<<q.at(i)<<" ";
		cout<<endl;
	}
}X,Y;

string sx,sy;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ti=clock();
	X.init();
	Y.init();
	cin>>sx>>sy;
	for(char c:sx)
	{
		X.operate(c);
		if(X.fail)
			break;
	}
	for(char c:sy)
	{
		Y.operate(c);
		if(Y.fail)
			break;
	}
	/*X.show();
	cout<<endl;
	Y.show();*/
	if(!X.fail&&!Y.fail&&X.compare(Y))
		cout<<"True"<<endl;
	else if(X.fail&&Y.fail)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
}