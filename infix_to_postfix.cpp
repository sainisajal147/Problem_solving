/*
AUTHOR : SAJAL SAINI
*/
#include <stdio.h>
#include <cmath>
#include <map>
#include <math.h>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
#include <math.h>
#include <set>

using namespace std;

typedef long long int ll;

template <class t>
void disp(vector<vector<t>> v)
{
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

template <class t>
void disp(vector<t> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

string solve(string s)
{
	map<char,int> m;
	m['*']=2,m['/']=2,m['+']=1,m['-']=1;
	stack<char> st;
	string ans="";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='+' and s[i]!='/' and s[i]!='-' and s[i]!='*')
		{
			ans+=s[i];
		}
		else
		{
			while(!s.empty() and m[st.top()]>=m[s[i]])
			{
				ans+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty())
	{
		ans+=st.top();
		st.pop();
	}
	return ans;
}

string solve_prefix(string s)
{
	reverse(s.begin(), s.end());
	s=solve(s);
	reverse(s.begin(), s.end());
	return s;
}

int main(void) {
	cout<<solve("a+b*c-d*e")<<endl;
	cout<<solve_prefix("a*b+c/d");
	return 0;
}