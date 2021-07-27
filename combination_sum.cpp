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

map<vector<int>,int> m;
void combi(vector<int> &a,int b,int start,vector<int> &temp,vector<vector<int>> &ans)
{
    /*if(!temp.empty())//accumulate(temp.begin(),temp.end(),0)==b)
    {
        //ans.push_back(temp);
        //temp.clear();
        if(accumulate(temp.begin(),temp.end(),0)>b)
        	return;
        else if(accumulate(temp.begin(),temp.end(),0)==b)
        	{
        		sort(temp.begin(), temp.end());
        		if(m[temp]==0)
        		{
        			ans.push_back(temp);
        			m[temp]=1;
        		}
        	}
    }*/
	if(b<0)
		return;
	if(b==0)
	{
		ans.push_back(temp);
	}
    for(int i=start;i<a.size();i++)
    {
        temp.push_back(a[i]);
        combi(a,b-a[i],i,temp,ans);
        temp.pop_back();
    }
}
vector<vector<int> > combinationSum(vector<int> &A, int B) {
	vector<vector<int>> ans;
	vector<int> temp;
	int sum=B;
	sort(A.begin(), A.end());
	combi(A,B,0,temp,ans);
	return ans;
}

int main(void) {
	vector<int> v={8, 5, 12, 10, 20, 18, 13, 18, 16, 3};
	disp(combinationSum(v,28));
	return 0;
}