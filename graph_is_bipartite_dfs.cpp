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



bool isBipartite(vector<vector<int>> v,int i,vector<bool> &visi,vector<int> &col)
{
	int n=v.size();
	for(int j=0;j<n;j++)
	{
		if(!visi[j] and v[i][j])
		{
			visi[j]=1;
			col[j]=!col[i];
			if(!isBipartite(v,j,visi,col))
				return true;
		}
		else if(col[i]==col[j] and v[i][j])
			return false;
	}
	return true;
}

int main(void) {
	vector<vector<int>> v = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0} }; 
	int n=v.size();
	vector<bool> visi(n,0);
	vector<int> col(n);
	visi[0]=1,col[0]=0;
    isBipartite(v, 0,visi,col) ? cout << "Yes" : cout << "No";
	return 0;
}