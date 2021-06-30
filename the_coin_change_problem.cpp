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

int coin_change( vector<int> v, int m, int n ) 
{ 
    int i, j, x, y; 
    vector<vector<int>> dp(n + 1,vector<int> (m,0)); 
    for (i = 0; i < m; i++) 
        dp[0][i] = 1; 
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            if(i-v[j]>=0)
            	x=dp[i-v[j]][j];
            else
            	x=0;
            if(j>=1)
            	y=dp[i][j-1];
            else
            	y=0;
            dp[i][j] = x + y; 
        } 
    } 
    return dp[n][m - 1]; 
} 



int main(void) {
	vector<int > s={1,5};
	int n=11,m=s.size();
	cout<<coin_change(s,m,n);
	return 0;
}