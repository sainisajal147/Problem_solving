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

vector<int> slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    deque<int> element,idx;
    for(int i=0;i<B;i++)
    {
    	if(i==0)
    	{
    		element.push_back(A[0]);
    		idx.push_back(0);
    	}
    	else
    	{
	    	while(!element.empty() and A[i]>element.front())
	    	{
	    		idx.pop_front();
	    		element.pop_front();
	    	}
	    	while(!element.empty() and A[i]>element.back())
	    	{
	    		idx.pop_back();
	    		element.pop_back();
	    	}
    		if(A[i]>=element.front())
    		{
    			element.push_front(A[i]);
    			idx.push_front(i);
    		}
    		else
    		{
    			element.push_back(A[i]);
    			idx.push_back(i);
    		}
    	}
    }
    ans.push_back(element.front());
    for(int i=B;i<A.size();i++)
    {
    	while(!idx.empty() and i-B+1>idx.front())
    	{
    		idx.pop_front();
    		element.pop_front();
    	}
    	while(!element.empty() and A[i]>element.front())
    	{
    		idx.pop_front();
    		element.pop_front();
    	}
    	while(!element.empty() and A[i]>element.back())
	    {
	   		idx.pop_back();
	   		element.pop_back();
	   	}
    	if(A[i]>=element.front())
    	{
    		element.push_front(A[i]);
    		idx.push_front(i);
    	}
   		else
    	{
    		element.push_back(A[i]);
    		idx.push_back(i);
    	}
    	
    	ans.push_back(element.front());
    }
    return ans;
}

int main(void) {
	vector<int> v={648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368};//{1, 8, -1, -3, 5, 9, 6, 7};
	disp(slidingMaximum(v,9));
	return 0;
}