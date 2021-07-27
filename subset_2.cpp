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

map<vector<int>,int> m;
void subset(vector<int> &a,int start,vector<int> &temp,vector<vector<int>> &ans)
{
	if(start>a.size())
		return;
	if(!temp.empty())
	{
		if(m[temp]==0)
		{
			ans.push_back(temp);
			m[temp]=1;
		}
	}
	for(int i=start;i<a.size();i++)
	{
		temp.push_back(a[i]);
		subset(a,i+1,temp,ans);
		temp.pop_back();
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &A) {
	vector<vector<int>> ans;
	vector<int> temp;
	ans.push_back(temp);
	sort(A.begin(), A.end());
	subset(A,0,temp,ans);
	return ans;
}

int main(void) {
	vector<int> v={5,4};
	disp(subsetsWithDup(v));
	return 0;
}