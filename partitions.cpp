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

int solve(int B, vector<int> &A) {
    int ans=0,temp_sum=0,sum=accumulate(A.begin(), A.end(),0);
    if(sum%3)
    	return 0;
    sum=sum/3;
    vector<int> p,s,pre(A.size());
    for(int i=0;i<A.size();i++)
    {
    	temp_sum+=A[i];
    	pre[i]=temp_sum;
    	if(temp_sum==sum)
    		p.push_back(i);
    }
    temp_sum=0;
    for(int i=A.size()-1;i>=0;i--)
    {
    	temp_sum+=A[i];
    	if(temp_sum==sum)
    		s.push_back(i);
    }
    cout<<sum<<endl;
    disp(p),disp(s),disp(pre);
    for(int i=0;i<p.size();i++)
    {
    	for(int j=0;j<s.size();j++)
    	{
    		if(p[i]+1<s[j])
    			ans++;
    	}
    }
    return ans;
}

int main(void) {
	vector<int> v={1,2,3,0,3};
	cout<<solve(v.size(),v);
	return 0;
}