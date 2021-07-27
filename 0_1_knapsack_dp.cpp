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

int solve(vector<int> &A, vector<int> &B, int c) {
	int n=A.size();
	vector<vector<int>> v(n,vector<int> (c+1,0));
	for(int i=0;i<=c;i++)
	{
		if(B[0]<=i)
			v[0][i]=A[0];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(j<B[i])
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max(v[i-1][j],A[i]+v[i-1][j-B[i]]);
		}
	}
	disp(v);
	return v[n-1][c];
}

int main(void) {
	vector<int> A={60,100,120},B={10,20,30};
	cout<<solve(A,B,50);
	return 0;
}