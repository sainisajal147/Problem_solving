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

int uniquePathsWithObstacles(vector<vector<int> > &A) {
    vector<vector<int>> v(A.size(),vector<int> (A[0].size(),0));
    v[0][0]=1;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j])
                v[i][j]=-1;
        }
    }
    int m=A.size(),n=A[0].size(),ans=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(i==0 and j==0)
            {
                v[i][j]=1;
                continue;
            }
            else if(v[i][j]==-1)
                continue;
            if(i-1>=0 and j-1<0 and v[i-1][j]!=-1)
            {
                v[i][j]+=v[i-1][j];
            }
            else if(j-1>=0 and i-1<0 and v[i][j-1]!=-1)
            {
                v[i][j]+=v[i][j-1];
            }
            else if(i-1>=0 and j-1>=0)
            {
                if(v[i-1][j]!=-1 and v[i][j-1]!=-1)
                    v[i][j]+=v[i-1][j]+v[i][j-1];
                else if(v[i-1][j]!=-1 and v[i][j-1]==-1)
                    v[i][j]+=v[i-1][j];
                else if(v[i-1][j]==-1 and v[i][j-1]!=-1)
                    v[i][j]+=v[i][j-1];
            }
        }
    }
    disp(v);
    return v[m-1][n-1];
}


int main() {
	vector<vector<int>> v={{0,0,0},{0,0,0},{0,0,0}};
	//disp(v);
	cout<<uniquePathsWithObstacles(v);
	return 0;
}