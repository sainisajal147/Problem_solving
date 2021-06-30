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

int main(void) {
	int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int z=n*(n+1);
    	int a=z/2;
    	vector<int> p,q;
    	for(int i=1;i<=a;i++)
    	{
    	    p.push_back(i);
    	}
    	for(int j=z,i=0;j>a and i<a;i++,j--)
    	{
    	    q.push_back(j);
    	}
    	//cout<<n<<endl;
    	//disp(p),disp(q);
    	int l=0,m=0;
    	vector<vector<int>> ans;
    	for(int i=0;i<n;i++)
    	{
    		vector<int> temp;
    	    int x=n-i;
    	    while(x--)
    	    {
    	        temp.push_back(p[l]);
    	        l++;
    	    }
    	    x=n-i;
    	    while(x--)
    	    {
    	        temp.push_back(q[m]);
    	        m++;
    	    }
    	    ans.push_back(temp);
    	}
    	for(int i=0;i<n;i++)
    	{
    		reverse(ans[i].end()-n+i,ans[i].end());
    	}
    	for(int i=0;i<ans.size();i++)
		{
			int c=i*2;
			while(c--)
			{
				cout<<"_";
			}
			int j=0;
			for(;j<ans[i].size()-1;j++)
			{
				cout<<ans[i][j]<<"*";
			}
			cout<<ans[i][j];
			cout<<endl;
		}
    }
	return 0;
}