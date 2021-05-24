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

void perm(vector<int> s, int k, vector<vector<int>> &ans)
{
	static vector<int> h(1000,0);
	static vector<int> res(1000,0) ;
	if(k==s.size())
	{
		vector<int> v(s.size());
		for(int j=0;j<s.size();j++)
		{
			v[j]=res[j];
		}
		ans.push_back(v);
		return;
	}
	for(int i=0;i<s.size();i++)
	{
		if(h[i]==0)
		{
			res[k]=s[i];
			h[i]=1;
			perm(s,k+1,ans);
			h[i]=0;
		}
	}
}
void permute(vector<int> &A) {
    vector<vector<int>> ans;
    //vector<int> r(A.size());
    perm(A,0, ans);
    for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
	    cout<<endl;
	}
    //return x;
}
int main() {
	vector<int> v={1,2,3};
	permute(v);
	/*for(int i=0;i<x.size();i++)
	{
		for(int j=0;j<x[i].size();i++)
		{
			cout<<x[i][j]<<" ";
		}
	    cout<<endl;
	}*/
	return 0;
}