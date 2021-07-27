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

int trap(const vector<int> &a) {
    queue<int> left,right;
    int n=a.size(),ans=0,max_ele=*max_element(a.begin(), a.end());
    for(int i=0;i<n;i++)
    {
        if((left.empty() and a[i]!=0) or (!left.empty() and a[i]>=a[left.back()]))
        	left.push(i);
        if(a[i]==max_ele)
        	break;
    }
    for(int i=n-1;i>=0;i--)
    {
        if((right.empty() and a[i]!=0) or (!right.empty() and a[i]>=a[right.back()]))
        	right.push(i);
    }
    while(left.size()>1)
    {
        int i=left.front();
        left.pop();
        int j=left.front();
        int temp=(j-i-1)*(a[i]);
        //cout<<temp<<endl;
        for(int p=i+1;p<j;p++)
        {
            temp=temp-(a[p]);
        }
        ans+=temp;
    }
    //cout<<ans<<" left ended\n";
    while(right.size()>1)
    {
    	/*cout<<right.front()<<" ";
    	right.pop();*/
        int i=right.front();
        right.pop();
        int j=right.front();
        int temp=(i-j-1)*(a[i]);
        for(int p=j+1;p<i;p++)
        {
            temp=temp-(a[p]);
        }
        //cout<<temp<<endl;
        ans+=temp;
    }
    //cout<<ans<<" Fun ended\n";
    return ans;
}


int main(void) {
	vector<int> v={5,0,0,0,5};
	cout<<trap(v);
	return 0;
}