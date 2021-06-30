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

void disp(vector<vector<int>> v)
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

void disp(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int long_sub(string s)
{
	vector<int> v(s.size(),1);
	int ans=1;
	for(int i=1;i<v.size();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(s[j]<s[i] and v[i]<v[j]+1)
			{
				v[i]=v[j]+1;
			}
		}
		ans=max(ans,v[i]);
	}
	disp(v);
	return ans;
}
int main() {
	string s="34678912";
	cout<<long_sub(s);
	return 0;
}