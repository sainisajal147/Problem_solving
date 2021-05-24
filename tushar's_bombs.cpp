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

vector<int> solve(int A, vector<int> &B) {
    int n=B.size();
    
    vector<int> dp(A+1,0),index(A+1);
    
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=B[j])
            {
                if(dp[i-B[j]]+1 > dp[i])
                {
                    dp[i]=dp[i-B[j]]+1;
                    index[i]=j;
                }
            }
        }
    }
    //disp(dp);
    //disp(index);
    vector<int> ans;
    int v=A;
    while(v>0 and v>=B[index[v]])
    {
    	ans.push_back(index[v]);
    	v=v-B[index[v]];
    }
    return ans;
    /*map<int,int> m;
    for(int i=0;i<B.size();i++)
    {
        m[B[i]]=i;
    }
    vector<int> ans;
    int p=*min_element(B.begin(),B.end());
 	int size=A/p,k=A/p;
    while(k--)
    {
    	ans.push_back(m[p]);
    }
    if(A%p==0)
    	return ans;
    else
    {
    	ans.pop_back();
    	if(m[A%p+p])
    		ans.push_back(m[A%p+p]);
    	sort(ans.begin(),ans.end());
    	return ans;
    }*/
}

int main() {
	vector<int> v={3,4};
	vector<int> ans=solve(12,v);
	disp(ans);
	return 0;
}