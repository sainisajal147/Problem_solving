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

string int_to_roman(int num)
{
	string ans="";
	int n=num;
	vector<int> st={1000,900,500,400,100,90,50,40,10,9,5,4,1};
	map<int,string> m;
	m[1]="I",m[5]="V",m[10]="X",m[50]="L",m[100]="C",m[500]="D",m[1000]="M";
	m[4]="IV",m[9]="IX",m[40]="XL",m[90]="XC",m[400]="CD",m[900]="CM"; 
	for(int i=0;i<st.size();i++)
	{
		while(n>=st[i])
		{
			n=n-st[i];
			ans+=m[st[i]];
		}
	}
	return ans;
}

int main(void) {
	cout<<int_to_roman(99);
	return 0;
}