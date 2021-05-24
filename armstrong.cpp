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

bool armstrong(int n)
{
	vector<int> v;
	int a=n;
	while(a)
	{
		v.insert(v.begin(),a%10);
		a/=10;
	}
	disp(v);
	int sum=pow(v[0],v.size());
	cout<<sum<<endl;
	for(int i=1;i<v.size();i++)
	{
		sum+=pow(v[i],v.size());
		cout<<sum<<" ";
	}
	cout<<endl<<sum<<endl;
	return sum==n;
}

int main(void) {
	cout<<armstrong(1634);
	int x=10,y=22;
	int *const p=&x;
	cout<<*p<<endl;
	return 0;
}