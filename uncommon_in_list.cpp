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

bool comp(int a, int b)
{
	return a>b;
}

int main(void) {
	vector<int> v1={1,2,3,4,4,4},v2={4,5,6,7},a;
	//cout<<"Hello World!";
	int ans=0;
	map<int,int> m1,m2;
	for(int i=0;i<v1.size();i++)
	{
		m1[v1[i]]++;
	}
	for(int i=0;i<v2.size();i++)
	{
		m2[v2[i]]++;
	}
	for(int i=0;i<v1.size();i++)
	{
		if(m2[v1[i]]==0)
			ans++;
	}
	for(int i=0;i<v1.size();i++)
	{
		if(m2[v1[i]]==0)
			a.push_back(v1[i]);
			//ans++;
	}
	for(int i=0;i<v2.size();i++)
	{
		if(m1[v2[i]]==0)
			a.push_back(v2[i]);
			//ans++;
	}
	disp(a);
	cout<<"the ans is: "<<a.size()<<endl;
	vector<int> z={2,343,21,54,28,5,50};
	int k=4;
	sort(z.begin(),z.begin()+k);
	sort(z.begin()+k,z.end(),comp);
	disp(z);
	return 0;
}