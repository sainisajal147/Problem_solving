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

int perfectPeak(vector<int> &A) {
    int n=A.size();
    vector<int> f_max(n),b_min(n);
    f_max[0]=A[0],b_min[n-1]=A[n-1];
    for(int i=1;i<n;i++)
    {
        f_max[i]=max(f_max[i-1],A[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        b_min[i]=min(b_min[i+1],A[i]);
    }
    disp(f_max),disp(b_min);
    //bool ans=false;
    for(int i=0;i<n;i++)
    {
        if(f_max[i]==b_min[i])
            return 1;
    }
    return 0;
}


int main(void) {
	vector<int> v={9488, 25784, 5652, 9861, 31311, 8611, 1671, 7129, 28183, 2743, 11059, 4473, 7927, 21287, 2259, 7214, 32529};
	cout<<perfectPeak(v);
	return 0;
}