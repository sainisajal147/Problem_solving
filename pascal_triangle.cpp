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

vector<vector<int> > solve(int A) {
	vector<vector<int>> v;
	vector<int> temp={1},temp2={1,1};
	v.push_back(temp),v.push_back(temp2);
	for(int i=2;i<A;i++)
	{
		vector<int> z;
		for(int j=0;j<v[i-1].size()-1;j++)
		{
			z.push_back(v[i-1][j]+v[i-1][j+1]);
		}
		z.push_back(1);
		z.insert(z.begin(),1);
		v.push_back(z);
	}
	return v;
}

int main(void) {
	//disp(solve(5));
	float a = 1.2;
	float b = 0.3;
	while (abs(a-b)<1e-9)
    {
    	cout<<"good\n";
    	b += 0.1;
    	cout<<b<<endl;
    }
	return 0;
}