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

/*bool comp(int a, int b)
{
	string A=to_string(a),B=to_string(b);
	if(A+B>B+A)
		return A;
}

ll odd(vector<int> v)
{
	ll ans=1;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			ans*=(1+v[i]);
		}
		else
			ans*=(1+v[i]);
	}
}*/

bool comp(int a, int b)
{
	return a>b;
}

int solve(vector<int> v,int process)
{
	int ans=0;
	while(process>0)
	{
		ans++;
		sort(v.begin(),v.end(),comp);
		process-=v[0];
		v[0]=floor(v[0]/2);
		//cout<<process;
	}
	return ans;
	/*sort(v.begin(), v.end());
	if(v.size()<=2){
		return v;
	}
	vector <int> res;
	for(int i = 0;i<v.size();i++){
		res.push_back(0);
	}
	int n = v.size();
	int f;
	if(n%2==1){
		f = floor(n/2);
	}
	else{
		f = n/2 - 1;
	}
	int cnt = 0;
	res[0] = v[f];
	f++;
	for(int i = 1;i<v.size();i++){
		if(i%2==1){
			res[i] = v[f];
			f++;
		}
		else{
			res[i] = v[cnt];
			cnt++;
		}
	}
	return res;*/
}

int main(void) {
	vector<int> v={1,2,3,4,7};
	cout<<solve(v,15);
	return 0;
}