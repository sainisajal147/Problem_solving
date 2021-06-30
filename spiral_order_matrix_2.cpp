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

vector<vector<int> > generateMatrix(int A) {
	vector<vector<int>> v(A,vector<int> (A,0));
	int x=1;
	for(int i=0;i<A/2;i++)
	{
		int j=i,k=i+1,l=A-i-2,m=A-i-2;
		for(;j<A-i;j++)
		{
			v[i][j]=x++;
		}
		j--;
		for(;k<A-i;k++)
		{
			v[k][j]=x++;
		}
		k--;
		for(;l>=i;l--)
		{
			v[k][l]=x++;
		}
		l++;
		for(;m>=i+1;m--)
		{
			v[m][l]=x++;
		}
	}
	if(A%2)
	v[A/2][A/2]=A*A;
	return v;
}

int main(void) {
	disp(generateMatrix(5));
	return 0;
}