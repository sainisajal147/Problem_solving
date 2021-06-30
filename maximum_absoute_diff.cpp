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

int maxArr(vector<int> &A) {
    int max1=INT_MIN,min1=INT_MAX,max2=INT_MIN,min2=INT_MAX;
    for(int i=0;i<A.size();i++)
    {
        max1=max(max1,A[i]+i);
        min1=min(min1,A[i]+i);
        max2=max(max2,-A[i]+i);
        min2=min(min2,-A[i]+i);
    }
    cout<<max1<<" "<<max2<<" "<<min1<<" "<<min2<<endl;
    return max((max1-min1),(max2-min2));
}

int main(void) {
	vector<int> v={1,3,-1};
	cout<<maxArr(v);
	return 0;
}