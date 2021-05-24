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
bool validate(vector<vector<int>> v,int i,int j,int n)
{
	for(int k=0;k<n;k++)
	{
		if(v[i][k]==1)
			return false;
		if(v[k][j]==1)
			return false;
	}
	for(int k=1;i-k>=0 and j-k>=0;k++)
	{
		if(v[i-k][j-k]==1)
			return false;
	}
	for(int k=1;i-k>=0 and j+k<n;k++)
	{
		if(v[i-k][j+k]==1)
			return false;
	}
	return true;
}
void n_queen(int n,vector<vector<int>> &v,int i)
{
	if(i==n)
	{
		disp(v);
		cout<<endl;
		return;
	}
	for(int j=0;j<n;j++)
	{
		if(v[i][j]==0 and validate(v,i,j,n))
		{
			v[i][j]=1;
			n_queen(n,v,i+1);
			v[i][j]=0;
		}
	}
}
int main() {
	int n=6;
	vector<vector<int>> v(n,vector<int> (n,0));
	n_queen(n,v,0);
	//disp(v);
	//disp(v);
	return 0;
}