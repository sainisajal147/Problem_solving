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

struct node
{
	int v1,v2;
};

bool comp(pair<int,int> p,pair<int,int> m)
{
	return p.first<m.first;
}

void question(vector<int> v)
{
	int n=v.size();
	/*int min_abs_diff=INT_MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(min_abs_diff>abs(v[i]-v[j]))
				min_abs_diff=abs(v[i]-v[j]);
		}
	}
	cout<<min_abs_diff<<" \n";
	vector<pair<int,int>> vec;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(abs(v[i]-v[j])==min_abs_diff)
			{
				pair<int,int> temp(v[i],v[j]);
				if(v[i]>v[j])
					swap(temp.first,temp.second);
				vec.push_back(temp);
			}
		}
	}
	sort(vec.begin(),vec.end(),comp);
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
	}
*/
	sort(v.begin(), v.end());
	int min_a_diff=INT_MAX;
	vector<pair<int,int>> ans;
	for(int i=0;i<n-1;i++)
	{
		if(abs(v[i]-v[i+1])<min_a_diff)
		{
			ans.clear();
			min_a_diff=abs(v[i]-v[i+1]);
		}
		if(min_a_diff==abs(v[i]-v[i+1]))
			ans.push_back(pair<int,int> (v[i],v[i+1]));
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}
int main(void) {
	vector<int> v={4,6,2,10};
	question(v);
	return 0;
}