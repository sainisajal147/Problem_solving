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

void subsets(vector<int> v,int k)
{
	static int h[1000]={0};
	for(int i=k;i<v.size();i++)
	{
			h[i]=1;
			for(int j=0;j<v.size();j++)
			{
				if(h[j]==1)
					cout<<v[j]<<" ";
			}
			cout<<endl;
			//h[i]=1;
			subsets(v,i+1);
			h[i]=0;
	}
}

int main() {
	vector<int> v={1,2,3};
	subsets(v,0);
	return 0;
}