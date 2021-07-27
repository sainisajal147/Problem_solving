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

struct node{
  int val;
  pair<int,int> idx;
  node(int val,pair<int,int> idx):val(val),idx(idx){}
};

struct comp{
	bool operator()(node a, node b)
	{
	    return a.val<b.val;
	}
};

vector<int> solve(vector<int> &a, vector<int> &b, int c) {
    vector<int> ans;
   	priority_queue<node, vector<node>,comp> q;
   	map<pair<int,int>,int> m;
   	int n=a.size();
   	sort(a.begin(), a.end());
   	sort(b.begin(), b.end());
   	node temp(a[n-1]+b[n-1],make_pair(n-1,n-1));
   	m[make_pair(n-1,n-1)]=1;
   	q.push(temp);
   	while(!q.empty() and c>0)
   	{
   		node top=q.top();
   		ans.push_back(top.val);
   		pair<int,int> temp_pair=top.idx;
   		int i=temp_pair.first,j=temp_pair.second;
   		if(m[make_pair(i-1,j)]==0)
   		{
   			node left(a[i-1]+b[j],make_pair(i-1,j));
   			q.push(left);
   			m[make_pair(i-1,j)]=1;
   		}
   		if(m[make_pair(i,j-1)]==0)
   		{
   			node right(a[i]+b[j-1],make_pair(i,j-1));
   			q.push(right);
   			m[make_pair(i,j-1)]=1;
   		}
   		q.pop();
   		c--;
   	}
    return ans;
}

int main(void) {
	vector<int> a={59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83},b={59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83};
	disp(solve(a,b,10));
	return 0;
}