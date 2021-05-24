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

void Solve(vector<int> A,int &ans, int sum,int i,int p,int &z)
{
    if(i==A.size())
    {
        if(ans>abs(sum))
        {
            ans=sum;
            z=p;
        }
        return;
    }
    Solve(A,ans,sum+A[i],i+1,p,z);
    Solve(A,ans,sum-A[i],i+1,p+1,z);
}
struct node
{
	int sum,f;
};
int solve(const vector<int> &A) {
    /*int ans=0,x=INT_MAX;
    Solve(A,x,0,0,0,ans);
    return ans;*/
    int s=accumulate(A.begin(),A.end(),0);
    //cout<<s<<endl;
    int m=s/2;
    vector<int> b=A;
    sort(b.begin(), b.end());
    node z;
    z.sum=z.f=0;
    vector<vector<node>> v(b.size()+1,vector<node> (m+1,z));
    /*for(int i=0;i<v.size();i++)
    {
    	for(int j=0;j<v[i].size();j++)
    	{
    		v[i][j].sum=v[i][j].f=0;
    	}
    }*/
    int ans=0;
    for(int i=1;i<=b.size();i++)
   	{
   		for(int j=1;j<=m;j++)
   		{
   			if(i==1)
   			{
   				v[i][j].sum=b[i-1];
   				v[i][j].f=1;
   			}
   			else if(j<b[i-1])
   			{
   				v[i][j].sum=v[i-1][j].sum;
   				v[i][j].f=v[i-1][j].f;
   			}
   			else if(max(v[i-1][j].sum,v[i-1][j-b[i-1]].sum+b[i-1])<=m)
   			{
				v[i][j].sum=max(v[i-1][j].sum,v[i-1][j-b[i-1]].sum+b[i-1]);
				v[i][j].f=max(v[i-1][j].f,v[i-1][j-b[i-1]].f+1);
			}
   			else
   			{
				v[i][j].f=v[i-1][j].f;
				v[i][j].f=v[i-1][j].f;
			}
   		}
   	}
   	//disp(v);
    return A.size()-v[b.size()][m].f;
}

int solve1(const vector<int> &A) {
    int s=accumulate(A.begin(),A.end(),0);
    int m=s/2;
    vector<int> b=A;
    sort(b.begin(), b.end());
    vector<int> v(m+1,INT_MAX);
    v[0]=0;
    for(int i=0;i<A.size();i++)
   	{
   		for(int j=m;j>=A[i];j--)
   		{
   			if(v[j-A[i]]!=INT_MAX)
   				v[j]=min(v[j],v[j-A[i]]+1);
   		}
   	}
   	disp(v);
   	for(int j=m;j>=0;j--)
   	{
   		if(v[j]!=INT_MAX)
   			return v[j];
   	}
}

int main() {
	vector<int> v={8, 4, 5, 7, 6, 2};//{3, 3, 7, 10, 2, 1, 5, 3, 8, 5, 1, 4, 3, 9, 1, 4, 8, 1, 1, 4, 5, 10, 3, 8, 5, 3, 6, 3, 5, 5, 4, 9, 7, 1, 9, 10, 3, 3, 4, 2, 9, 4, 5, 3, 3, 5, 6, 2, 8, 6, 8, 2, 7, 10, 9, 2, 4, 4, 4, 8, 10, 9, 7, 8, 1, 5, 9, 5, 9, 2, 7, 9, 6, 3, 2, 10, 10, 7, 1, 7, 5, 10, 10, 1, 9, 10, 4, 2, 5, 9, 10};//{11, 10, 8, 6, 8, 11, 1, 10, 2, 3, 8, 3, 8, 12, 11, 1, 7, 5, 5, 12, 9, 4, 10, 3, 3, 3, 8, 8, 8, 6, 7, 7, 7, 6, 4, 2, 5, 8, 11, 10, 10, 10, 12, 9, 2, 3, 9, 12, 7, 6, 11, 8, 9, 9, 10, 3, 3, 5, 2, 10, 10, 9, 4, 9, 6, 11, 10, 2, 6, 1, 4, 7, 10, 3, 4, 3, 9, 4, 3, 8, 1, 1, 3};
	cout<<solve(v);
	return 0;
}