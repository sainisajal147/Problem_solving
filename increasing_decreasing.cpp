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

void disp(vector<int> v)
{
		for(int j=0;j<v.size();j++)
		{
			cout<<v[j]<<" ";
		}
		cout<<endl;
}

int longestSubsequenceLength(const vector<int> &A) {
    if(A.empty())
    return 0;
    int n=A.size();
    vector<int> v1(n,1),v2(n,1),b;
    for(int i=n-1;i>=0;i--)
    {
        b.push_back(A[i]);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i] and v1[i]<v1[j]+1)
                v1[i]=v1[j]+1;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(b[j]<b[i] and v2[i]<v2[j]+1)
                v2[i]=v2[j]+1;
        }
    }
    reverse(v2.begin(),v2.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(v1[i]+v2[i]-1>ans)
            ans=v1[i]+v2[i]-1;
    }
    disp(v1),disp(v2);
    return ans;
}


int main() {
	vector<int> v={35, 71, 52, 12, 82, 82, 75, 100, 83};
	cout<<longestSubsequenceLength(v);
	return 0;
}