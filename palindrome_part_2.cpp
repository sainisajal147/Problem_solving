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

int minCut(string A) {
	int n=A.size();
	vector<vector<int>> v(n,vector<int> (n,0));
	for(int i=0;i<n;i++)
		v[i][i]=1;
	for(int i=0;i<n-1;i++)
		if(A[i]==A[i+1])
			v[i][i+1]=1;
	for(int i=2;i<n;i++)
	{
		for(int j=0;j+i<n;j++)
		{
			int r=j,c=j+i;
			if(A[r]==A[c] and v[r+1][c-1]==1)
				v[r][c]=1;
		}
	}
	disp(v);
	/*int ans=0,j=n-1;
	while(j>=0)
	{
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			if(i==0 and v[i][j]==1)
			{
				return ans;
			}
			else if(i!=0 and v[i][j]==1)
			{
				ans++;
				j=i-1;
				flag=true;
				break;
			}
		}
		if(!flag)
			j--;
	}*/
	vector<vector<int>> dp(n,vector<int> (n,0));
	for(int i=0;i<n-1;i++)
		if(A[i]!=A[i+1])
			dp[i][i+1]=1;
	for(int i=2;i<n;i++)
	{
		for(int j=0;j+i<n;j++)
		{
			int r=j,c=j+i;
			if(v[r][c]==1)
				dp[r][c]=0;
			else
				{
					dp[r][c]=INT_MAX;
					for(int k=r;k<c;k++)
					{
						dp[r][c]=min(dp[r][c],1+dp[r][k]+dp[k+1][c]);
					}
				}
		}
	}
	disp(dp);
	return dp[0][n-1];
}

int main(void) {
	cout<<minCut("ababb");
	return 0;
}