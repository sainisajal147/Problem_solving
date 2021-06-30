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

vector<int> findpairn2(vector<int> a,vector<int> b)
{
	vector<int> ans(2);
	int x=INT_MAX;
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			if(abs(a[i]-b[j])<x)
				x=abs(a[i]-b[j]),ans[0]=a[i],ans[1]=b[j];
		}
	}
	return ans;
}

vector<int> findpairn1(vector<int> a,vector<int> b)
{
	vector<int> ans(2);
	int x=INT_MAX;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int i,j;
	j=i=0;
	while(i<a.size() and j<b.size())
	{
			if(a[i]<b[j])
			{
				if(abs(a[i]-b[j])<x)
					x=abs(a[i]-b[j]),ans[0]=a[i],ans[1]=b[j];
				i++;
			}
			else
			{
				if(abs(a[i]-b[j])<x)
					x=abs(a[i]-b[j]),ans[0]=a[i],ans[1]=b[j];
				j++;
			}
	}
	/*i=i==a.size()?i--:i;
	j=j==b.size()?j--:j;
	while(i<a.size())
	{
		if(abs(a[i]-b[j])<x)
			x=abs(a[i]-b[j]),ans[0]=a[i],ans[1]=b[j];
		i++;
	}
	i=i==a.size()?i--:i;
	j=j==b.size()?j--:j;
	while(j<b.size())
	{
		if(abs(a[i]-b[j])<x)
			x=abs(a[i]-b[j]),ans[0]=a[i],ans[1]=b[j];
		j++;
	}*/
	return ans;
}

int main() {
	vector<int> a={4,4, 1, 8, 7},b={5, 3, 6, 5,5,6};
	disp(findpairn2(a,b));
	return 0;
}