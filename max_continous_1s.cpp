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

vector<int> maxone(vector<int> &A, int B) {
    vector<int> ans;
    int i=0,j=0,zero=0,ones=0;
    while(j<A.size())
    {
        if(A[j]==0)
            zero++;
        while(zero>B)
        {
            if(A[i]==0)
                zero--;
            i++;
        }
        j++;
        ones=max(ones,j-i);
    }
    cout<<ones<<endl;
    for(int x=0;x<A.size()-ones;x++)
    {
        int count=0,z=x;
        while(z<x+ones)
        {
            if(A[z]==0)
            {
                count++;
            }
            z++;
        }
        if(count==B)
        {
            i=x;
            break;
        }
    }
    j=ones+i;
    for(;i<j;i++)
    {
        ans.push_back(i);
    }
    return ans;
}

void disp(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main() {
	vector<int> v={ 1, 1, 0 };
	disp(maxone(v,2));
	return 0;
}