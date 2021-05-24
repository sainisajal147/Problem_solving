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

vector<int> grey_code(int n)
{
	vector<int> ans;
	while(n>0)
	{
		ans.push_back(n%2);
		n/=2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

void grey(int n, vector<int> &v,int k)
{
	for(int i=0;i<pow(2,n);i++)
	{
		v.push_back(i^(i>>1));
	}
}
int main() {
	int n=2;
	vector<int> v;
	/*for(int i=0;i<pow(2,n);i++)
	{
		v.push_back(i);
	}*/
	grey(n,v,0);
	for(int j=0;j<v.size();j++)
	{
		cout<<v[j]<<" ";
	}
	cout<<endl;
	
	return 0;
}