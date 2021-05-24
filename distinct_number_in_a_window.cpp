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

vector<int> dNums(vector<int> &A, int B) {
    vector<int> ans;
    if(B>A.size())
        return ans;
    /*if(B==1)
    {
    	vector<int> a(A.size(),1);
    	return a;
    }*/
    map<int,int> m;//,m1;
    //multiset<int> s;
    for(int i=0;i<B;i++)
    {
        //s.insert()
        m[A[i]]++;
        //m1[A[i]]++;
    }
    ans.push_back(m.size());
    int count=0;
    map<int,int> ::iterator p=m.begin();
	    while(p!=m.end())
	    {
	    	//cout<<p->first<<" "<<p->second<<endl;
	    	if(p->second!=0)
	    		count++;
	    	p++;
	    }
	    /*cout<<count<<endl;
	    cout<<endl;*/
    for(int i=B;i<A.size();i++)
    {
    	//int count=0;
        int z=m[A[i]];
        m[A[i-B]]--;
        m[A[i]]++;
        //m1[A[i]]++;
        if(z==0)
        	count++;
        if(m[A[i-B]]==0)
            count--;
        ans.push_back(count);
        /*map<int,int> ::iterator p=m.begin();
	    while(p!=m.end())
	    {
	    	cout<<p->first<<" "<<p->second<<endl;
	    	p++;
	    }
	    cout<<count<<endl;
	    cout<<endl;*/
    }
    /*p=m.begin();
    while(p!=m.end())
    {
    	cout<<p->first<<" "<<p->second<<endl;
    	p++;
    }*/
    return ans;
}

int main() {
	vector<int> a={31, 51, 31, 51, 31, 31, 31, 31, 31, 31, 51, 31, 31};
	vector<int> b=dNums(a,1);
	disp(b);
	return 0;
}