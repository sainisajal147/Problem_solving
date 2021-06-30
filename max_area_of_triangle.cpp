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
	int len,j;
	char c1,c2;
};

int solve(vector<string> &A) {
	int n=A.size(),m=A[0].size();
	vector<node> v;
	vector<int> r_min(m,-1),g_min(m,-1),b_min(m,-1),r_max(m,-1),g_max(m,-1),b_max(m,-1);
	for(int j=0;j<m;j++)
	{
		bool r_flag=false,g_flag=false,b_flag=false;
		for(int i=0;i<n;i++)
		{
			if(A[i][j]=='r')
			{
				if(!r_flag)
				{
					r_min[j]=i;
					r_flag=true;
				}
				r_max[j]=i;
			}
			if(A[i][j]=='g')
			{
				if(!g_flag)
				{
					g_min[j]=i;
					g_flag=true;
				}
				g_max[j]=i;
			}
			if(A[i][j]=='b')
			{
				if(!b_flag)
				{
					b_min[j]=i;
					b_flag=true;
				}
				b_max[j]=i;
			}
		}
	}
	cout<<"r_min ";
	disp(r_min);
	cout<<"r_max ";
	disp(r_max);
	cout<<"g_min ";
	disp(g_min);
	cout<<"g_max ";
	disp(g_max);
	cout<<"b_min ";
	disp(b_min);
	cout<<"b_max ";
	disp(b_max);
	return 0;
}

int main(void) {
	vector<string> A = {"rrrrr", "rrrrg", "rrrrr", "bbbbb"};
	cout<<solve(A);
	return 0;
}