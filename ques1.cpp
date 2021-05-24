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
/*void disp(vector<vector<t>> v)
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
}*/

/*int fun(string s, char ch)
{
	for(int i=0;i<s.size();i++)
	{
		if(ch==s[i])
			return i;
	}
	return -1;
}*/

int main(void) {
	string s="sajal";
	char ch='a';
	for(int i=0;i<s.size();i++)
	{
		if(ch==s[i])
			cout<<i;
	}
	cout<<"-1";
	//cout<<fun(s,ch);
	return 0;
}