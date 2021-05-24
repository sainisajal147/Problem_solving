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

void disp(vector<vector<int>> v)
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

void disp(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

bool comp(int a, int b)
{
	return abs(a)>abs(b);
}

int highest_product(vector<int> A)
{
	sort(A.begin(),A.end());
	int n=A.size();
	disp(A);
	int ans1=A[n-1]*A[n-2]*A[n-3],ans2=A[n-1]*A[0]*A[1];
	return max(ans1,ans2);
}

int main() {
	vector<int> v={ };
	cout<<highest_product(v);
	return 0;
}