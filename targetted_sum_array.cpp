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

void solve(vector<int> v,int s)
{
	int n=v.size();
	for(int i=0;i<n-1;i++)
	{
		int sum=v[i];
		for(int j=i+1;j<n;j++)
		{
			if(sum==s)
				cout<<"Found\n";
			if(sum>s)
				break;
			sum+=v[j];
		}
	}
}

void solve1(vector<int> v,int s)
{
	int n=v.size();
	int sum=v[0],st=0;
	for(int i=1;i<n;i++)
	{
		while(sum>s and i>st)
		{
			sum-=v[st];
			st++;
		}
		if(sum==s)
			cout<<"Found this time\n";
		sum+=v[i];
	}
}
int main() {
	vector<int> v={1, 4, 0, 0, 3, 10, 5};
	solve1(v,7);
	//cout<<"Hello World!";
	return 0;
}