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

int solve(vector<int> &A) {
    int n=A.size();
    vector<int> r(n,A[n-1]),l(n,A[0]);
    for(int i=n-2;i>=0;i--)
    {
        r[i]=max(r[i+1],A[i]);
    }
    for(int i=1;i<n;i++)
    {
        l[i]=max(l[i-1],A[i]);
    }
    int ans=0;
    for(int i=1;i<n-1;i++)
    {
        if(l[i-1]<A[i] and A[i]<r[i+1])
            ans=max(ans,l[i-1]+A[i]+r[i+1]);
    }
    disp(l),disp(r);
    return ans;
}

int main(void) {
	vector<int> v={2,5,3,1,4,9};//{18468, 6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605};
	cout<<solve(v);
	return 0;
}