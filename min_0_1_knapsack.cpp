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

struct p{
	int b,c;
};
bool comp(p a1, p a2)
{
	return a1.b<a2.b;
}
int solve(const vector<int> &A, const vector<int> &b, const vector<int> &C) {
    vector<p> arr(b.size());
    for(int i=0;i<b.size();i++)
    {
    	p temp;
    	temp.b=b[i],temp.c=C[i];
    	arr[i]=temp;
    }
    sort(arr.begin(),arr.end(),comp);
    vector<int> c(C.size()),B(b.size());
    for(int i=0;i<arr.size();i++)
    {
        B[i]=arr[i].b,c[i]=-arr[i].c;
    }
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        int m=A[i];
        int x=B.size(),y=c.size();
        vector<vector<int>> v(x+1,vector<int> (m+1,0));
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==1 and B[i-1]<=j)
                    v[i][j]=ceil(j/B[i-1])*c[i-1];
                else if(j<B[i-1])
                    v[i][j]=v[i-1][j];
                else
                    v[i][j]=max(v[i-1][j],v[i][j-B[i-1]]+c[i-1]);
            }
        }
        disp(v);
        ans+=v[x][m];
    }
    return -ans;
}


int main() {
	vector<int> a={4,6},b={1,3},c={5,3};
	cout<<solve(a,b,c);
	return 0;
}