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

void merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    int i=0,j=0;
    while(i<A.size() and j<B.size())
    {
        if(A[i]<B[j])
        {
            ans.push_back(A[i]);
            i++;
        }
        else
        {
            ans.push_back(B[j]);
            j++;
        }
    }
    while(i<A.size())
    {
        ans.push_back(A[i]);
        i++;
    }
    while(j<B.size())
    {
        ans.push_back(B[j]);
        j++;
    }
    A.clear();
    for(int i=0;i<ans.size();i++)
    {
        A.push_back(ans[i]);
    }
    for(int i=0;i<A.size();i++)
    {
    	cout<<A[i]<<" ";
    }

}


int main() {
	vector<int> a={-4,-3,0}, b={2};
	merge(a,b);
	return 0;
}