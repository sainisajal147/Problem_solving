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

int solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    map<int,int> ma;
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<m;b++)
        {
            for(int i=0;i<n-a;i++)
            {
                for(int j=0;j<m-b;j++)
                {
                    int sum=0;
                    for(int k=i;k<=i+a;k++)
                    {
                        for(int l=j;l<=j+b;l++)
                        {
                            sum+=A[k][l];
                        }
                    }
                    ma[sum]++;
                }
            }
        }
    }
    return ma[0];
}

int main() {
	vector<vector<int>> v={{0,0},{0,0}};
	cout<<solve(v);
	return 0;
}