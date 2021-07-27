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

void subset(const vector<int> &A,int n,int sum,vector<int> &temp,vector<int> &ans,int start,bool &first,int &fixed_size)
{
	if(accumulate(temp.begin(), temp.end(),0)==sum and first==false and temp.size()==fixed_size)
	{
		ans=temp;
		first=true;
		return;
	}
	for(int i=start;i<n;i++)
	{
		temp.push_back(A[i]);
		subset(A,n,sum,temp,ans,i+1,first,fixed_size);
		temp.pop_back();
	}
}

vector<vector<int> > avgset(vector<int> &A) {
	sort(A.begin(), A.end());
	int n=A.size(),sum=accumulate(A.begin(), A.end(),0),possible_sum=0,fixed_size=0;
	map<int,int> m;
	for(int i=0;i<n;i++)
		m[A[i]]++;
	for(int i=1;i<n;i++)
	{
		if((sum*i)%n==0)
		{
			possible_sum=(sum*i)/n;
			cout<<"the i value is: "<<i<<endl;
			if(i==1 and m[possible_sum]==1)
			{
				fixed_size=1;
				break;
			}
			else if(i==1)
				continue;
			fixed_size=i;
			break;
		}
	}
	cout<<"the possible sum is: "<<possible_sum<<" other sum is: "<<sum-possible_sum<<endl;
	vector<vector<int>> ans(2);
	vector<int> temp;
	bool first=false;
	subset(A,n,possible_sum,temp,ans[0],0,first,fixed_size);
	for(int i=0;i<ans[0].size();i++)
		m[ans[0][i]]--;
	map<int,int>::iterator p=m.begin();
	while(p!=m.end())
	{
		int x=p->second;
		while(x--)
		{
			ans[1].push_back(p->first);
		}
		p++;
	}
	cout<<" fun ended\n";
	return ans;
}

int main(void) {
	vector<int> v={9, 2, 8, 13, 27, 43, 1, 15, 6, 23, 19, 49, 9, 2, 4, 22, 36, 5, 46, 5, 44, 46, 13, 46, 17};//{1, 7, 15, 29, 11, 9};
	disp(avgset(v));
	/*vector<int> v={1,2,3,4,5,6},temp,ans;
	int sum=7,n=v.size(),fixed_size=2;
	bool first=false;
	subset(v,n,sum,temp,ans,0,first,fixed_size);
	disp(ans);*/
	return 0;
}