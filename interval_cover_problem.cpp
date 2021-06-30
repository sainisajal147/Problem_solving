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

int interval_cover(vector<float> v)
{
	float st = -1;
	int ans = 0;
	for(int i = 0; i<v.size(); i++)
	{
		if(v[i]>ans)
		{
			st = v[i]+1;
			ans++;
		}
	}
	return ans;
}

int main(void) {
	vector<float> v={1.66 , 2.33 , 2.66, 2.99, 3.00, 3.99};
	cout<<interval_cover(v);
	return 0;
}