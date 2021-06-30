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

int max_sum_subarray(vector<int> v)
{
	int ans=v[0],res=INT_MIN;
	for(int i=1;i<v.size();i++)
	{
		ans=max(ans+v[i],v[i]);
		if(res<ans)
			res=ans;
		//cout<<res<<endl;
	}
	return res;
}

int solve(vector<int> v,int money)
{
	int start=0,end=0,n=v.size(),sum=v[0],sol=0;
	while(start<n and end<n)
	{
		if(sum<=money)
		{
			sol=max(end-start+1,sol);
			end++;
			if(end<n)
				sum+=v[end];
		}
		else
		{
			sum-=v[start];
			start++;
		}
	}
	return sol;
}

int main() {
	vector<int> v={2,5,6};
	//cout<<max_sum_subarray(v);
	cout<<solve(v,10);
	return 0;
}