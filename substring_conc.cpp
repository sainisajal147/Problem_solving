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

void disp(vector<int> x)
{
	for(int i=0;i<x.size();i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
bool c(string a,string b)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>b[i])
			return false;
	}
	return true;
}
bool comp(string a,string b)
{
	return c(a,b);
}
vector<int> findSubstring(string A,vector<string> &B) {
    sort(B.begin(),B.end());
    /*for(int i=0;i<B.size();i++)
    {
    	cout<<B[i]<<" ";
    }
    cout<<endl;*/
    unordered_map<string,int> m;
    vector<int> ans;
    int start=0,count=0,maxi=0,z=0;
    int N=B[0].size();
    z=N*B.size();
    if(z>A.size())
    	return ans;
    for(int i=0;i<B.size();i++)
    {
        m[B[i]]=-1;
    }
    unordered_map<string,int> :: iterator p=m.begin();
    while(p!=m.end())
	{
		if(p->second==-1)
			maxi++;
		p++;
	}
    for(int i=0;i<=A.size()-z;i++)
    {
    	string t;
    	for(int j=i;j<i+z;j++)
    	{
    		t+=A[j];
    	}
    	//cout<<t<<endl;
    	vector<string> temp_1;
    	for(int j=0;j<t.size();j++)
    	{
    		string sub;
    		int k=N;
    		while(k--)
    		{
    			sub+=t[j];
    			j++;
    		}
    		j--;
    	//	cout<<sub<<" ";
    		temp_1.push_back(sub);
    	}
    	//cout<<endl;
    	sort(temp_1.begin(),temp_1.end());
    	/*for(int i=0;i<temp_1.size();i++)
	    {
	    	cout<<temp_1[i]<<" ";
	    }
	    cout<<endl;*/
    	bool y=true;
    	for(int j=0;j<B.size();j++)
    	{
    		if(temp_1[j]!=B[j])
    		{
    			y=false;
    			break;
    		}
    	}
    	if(y)
    		ans.push_back(i);
    }
    
    return ans;
}


int main() {
	string a="abbaccaaabcabbbccbabbccabbacabcacbbaabbbbbaaabaccaacbccabcbababbbabccabacbbcabbaacaccccbaabcabaabaaaabcaabcacabaa";
	vector<string> b={ "cac", "aaa", "aba", "aab", "abc" };
	vector<int> x=findSubstring(a,b);
	disp(x);
	return 0;
}