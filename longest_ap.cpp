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
#include <set>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

/*bool val(set<int> s)
{
	vector<int> x;
	set<int> :: iterator p=s.begin();
	while(p!=s.end());
	{
		x.push_back(*p);
		p++;
	}
	for(int i=0;i<x.size()-1;i++)
	{

	}
}*/

void disp(vector<int> v)
{
		for(int j=0;j<v.size();j++)
		{
			cout<<v[j]<<" ";
		}
		cout<<endl;
}

int solve(const vector<int> &A) {
	vector<unordered_map<int,int>> m(A.size());
	int ans=0;
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<i;j++)
		{
			int diff=A[i]-A[j];
			if(m[j][diff])
			{
				m[i][diff]=m[j][diff]+1;
			}
			else
			{
				m[i][diff]=1;
			}
			if(ans<m[i][diff])
				ans=m[i][diff];
		}
	}
	/*for(int i=0;i<m.size();i++)
	{
		unordered_map<int,int> :: iterator p=m[i].begin();
		while(p!=m[i].end())
		{
			cout<<p->first<<"->"<<p->second;
			p++;
		}
		cout<<endl;
	}*/
	return ans+1;
    /*map<vector<int>,vector<int>> m;
    map<int,int> m1;
    int ans=0,ans1=0;
    for(int i=0;i<A.size();i++)
    {
    	m1[A[i]]++;
    }
    map<int,int>::iterator p1=m1.begin();
    while(p1!=m1.end())
    {
    	//cout<<"first="<<p1->first<<" sec="<<p1->second<<endl;
    	if(p1->second>ans1)
    		ans1=p1->second;
    	p1++;
    }
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
        	if(j==i or A[j]==A[i])
        		continue;
            vector<int> d;
            d.push_back(i);
            d.push_back(j);
            m[d].push_back(i);
            m[d].push_back(j);
        }
    }
    map<vector<int>,vector<int>> ::iterator p=m.begin();
    while(p!=m.end())
    {
    	int d=A[(p->first)[1]]-A[(p->first)[0]];
    	int next=A[(p->first)[1]]+d;
    	for(int i=(p->second).back();i<A.size();i++)
    	{
    		if(A[i]==next)
    		{
    			next=next+d;
    			(p->second).push_back(i);
    		}
    	}
    	//cout<<"p ka first ";
    	//disp(p->first);
    	//disp(p->second);
    	//cout<<endl;
    	//cout<<endl<<endl;
    	if(ans<(p->second).size())
    	{
    		//cout<<p->first<<endl;
			ans=(p->second).size();
		}
    	p++;
    }
    return max(ans,ans1);*/
}

int main() {
	vector<int> v={9,4,7,2,10};
	cout<<solve(v);
	return 0;
}