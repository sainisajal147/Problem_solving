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

void disp(vector<vector<int>> v)
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

void disp(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int solve(vector<int> &A, int B) {
    int ans=0;
    B=min(B,(int)A.size());
    vector<vector<int>> v(B+1,vector<int> (A.size(),0));
    for(int i=1;i<=B;i++)
    {
    	int m=-A[0];
        for(int j=1;j<A.size();j++)
        {
        	v[i][j]=max(v[i][j-1],A[j]+m);
       		m=max(v[i-1][j]-A[j],m);
        }
    }
    //disp(v);
    return v[B][A.size()-1];
}

int main() {
	vector<int> v={19230, 13765, 6863, 3840, 8367, 15603, 16327, 15140, 5582, 12937, 9472, 14190, 9541, 4126, 2757, 400, 19685, 15908, 4929, 18136, 16050, 6622, 13439, 265, 5846, 3188, 8756, 4960, 18781, 11139, 5152, 12314};//{11, 7, 11, 17, 12, 12, 16, 10, 11};
	cout<<solve(v,100000089);
	return 0;
}