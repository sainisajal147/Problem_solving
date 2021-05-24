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

int main(void) {
	cout<<"Enter a Number :!\n";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int k=n-i-2;k>=0;k--)
		{
			cout<<" ";
		}
		for(int j=-1;j<i;j++)
		{
			cout<<"*";
		}
		for(int j=0;j<i;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2*n;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}