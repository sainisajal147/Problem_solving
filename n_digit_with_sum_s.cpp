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

using namespace std;

typedef long long int ll;

void disp(vector<vector<ll>> v)
{
	for(int i=1;i<v.size();i++)
	{
		for(int j=01;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

#define m 1000000007
//typedef long long unsigned int ll;
int solve(int a, int b) {
    ll A=a,B=b;
    vector<vector<ll>> v(A+1,vector<ll> (B+1,0));
    for(int i=1;i<=A;i++)
    {
        for(int j=1;j<=B;j++)
        {
        	if(i==1 and j>=1 and j<=9)
            {
                    v[i][j]=1;
            }
            else if(i>1 and j>=1)
            {
            	ll sol=0;
            	ll in;
            	if(j<9) in=0;
            	else in=j-9;
            	for(int k=in;k<=j;k++)
            	{
            		sol=sol%m+v[i-1][k]%m;
            	}
            	v[i][j]=sol%m;
            }
        }
    }
    disp(v);
    return v[A][B];
}


int main() {
	cout<<solve(75,22);
	return 0;
}