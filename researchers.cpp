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

int solve(int l, int h, vector<int> v)
{
	int mid=(l+h)/2;
	if(l<h)
	{
		if(v[mid]>mid)
		{
			while(v[mid]>mid)
				mid++;
			return mid;
		}
		else 
			return solve(0,mid,v);
	}
	return -1;
}

int solve1(int l, int h, vector<int> v)
{
	int mid=(l+h)/2;
	if(l<h)
	{
		if(v[mid]>=mid)
		{
			int p=solve1(mid+1,h,v);
			if(p==-1)
				return mid;
			else
				return p;
		}
		else 
			return solve1(l,mid-1,v);
	}
	return -1;
}
int solve3(int l, int h, vector<int> v)
{
	int mid=(l+h)/2;
	if(l<h)
	{
		if(v[mid]>mid)
			return solve3(mid+1,h,v);
		else if(v[mid]==mid)
			return mid;
		else 
			return solve3(l,mid-1,v);
	}
	else
		return l;
}
int main() {
	vector<int> v={8,8,8,8,1};
	cout<<solve1(0,v.size()-1,v)+1;
	return 0;
}