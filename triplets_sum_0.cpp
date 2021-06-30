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

typedef long long int ll;
vector<vector<int> > threeSum(vector<int> &A) {
     vector<vector<int>> x;
    if(A.size()<3)
        return x;
    set<vector<int>> a;
    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-2;i++)
    {
        int j=i+1,k=A.size()-1;
        while(j<k)
        {
            long long x=(long long)A[j]+(long long )A[k]+(long long )A[i];
            if(x==0)
            {
                vector<int> temp(3);
                temp[0]=A[i],temp[1]=A[j],temp[2]=A[k];
                a.insert(temp);
                j++;
                k--;
            }
            else if(x<0)
            {
                j++;
            }
            else if(x>0)
            {
                k--;
            }
        }
    }
    set<vector<int>>::iterator p=a.begin();
    while(p!=a.end())
    {
    	vector<int> temp=*p;
    	if(accumulate(temp.begin(),temp.end(),0)==0)
        	x.push_back(temp);
        p++;
        cout<<accumulate(temp.begin(),temp.end(),0)<<endl;
    }
    return x;
}

void disp(vector<vector<int>> x)
{
	for(int i=0;i<x.size();i++)
	{
		for(int j=0;j<x[i].size();j++)
		{
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main() {
	vector<int> v={ 2147483647, -2147483648, -2147483648, 0, 1 };
	disp(threeSum(v));
	return 0;
}