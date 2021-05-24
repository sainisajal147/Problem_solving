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
    vector<vector<int>> v(n,vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(i==0 and j==0)
    		{
    			v[i][j]=A[i][j];
    			continue;
    		}
    		else
    		{
    			v[i][j]=A[i][j] - (((i-1)>=0 and (j-1)>=0)?v[i-1][j-1]:0) + (((i-1)>=0)?v[i-1][j]:0) + (((j-1)>=0)?v[i][j-1]:0);
    		}
    	}
    }
    /*for(int i1=0;i1<n;i1++)
    {
    	for(int i2=0;i2<n;i2++)
    	{

    	}
    }*/
    disp(v);
    return 0;
}

int solve1(vector<vector<int>> v)
{
	if(v.empty())
	{
		cout<<"fuck\n";
		return 0;
	}
	int n=v.size(),m=v[0].size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j==0)
				continue;
			v[i][j]+=v[i][j-1];
		}
	}
	int ans=0;
	unordered_map<int,int> ma;
	for(int i=0;i<m;i++)
	{
		for(int j=i;j<m;j++)
		{
			ma.clear();
			ma[0]=1;
			int sum=0;
			for(int k=0;k<n;k++)
			{
				int curr=v[k][j];
				if(i-1>=0)
					curr-=v[k][i-1];
				sum+=curr;
				ans+=ma[-sum];
				ma[-sum]++;
				//cout<<sum<<endl;
			}
		}
	}
	//disp(v);
	return ans;
}
int main() {
	vector<vector<int>> v={{-8,5,7},{3,7,-8},{5,-8,9}};
	//disp(v);
	//cout<<endl<<solve(v);
	cout<<solve1(v);
	return 0;
}