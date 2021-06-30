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

int solve1(vector<int> a, vector<int> b, int k)
{
	int n=a.size(),score=0;
	for(int i=0;i<k;i++)
	{
		int index=-1,temp=INT_MIN,temp_val=INT_MIN;
		for(int j=0;j<n;j++)
		{
			if(a[j]>temp_val)
			{
				temp_val=a[j];
				index=j;
				temp=a[j]/b[i];
			}
		}
		score+=a[index];
		a[index]=a[index]/b[index];
	}
	return score;
}

int solve2(vector<vector<int>> v,int n,vector<int> a,int k)
{
	int ans=INT_MIN;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(v[i][j])
				a[i]=max(a[i],a[i]^a[j]);
		}
	}
	disp(v);
	disp(a);
	ans=accumulate(a.begin(), a.end(),0);
	return ans;
}

int main(void) {
	//vector<int> a={12,4,2,3},b={5,1,2,2};
	//cout<<solve1(a,b,3);
	int n=3;
	vector<vector<int>> v(n,vector<int> (n,0));
	vector<int> a(n,0);
	v[0][1]=1,v[0][2]=1;
	a[0]=1,a[1]=1,a[2]=3;
	cout<<solve2(v,n,a,3);
	return 0;
}