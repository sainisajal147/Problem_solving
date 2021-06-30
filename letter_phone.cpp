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


void letter(string s,int k,map<char, string> m,vector<string> &a)
{
	static string ans;
	if(k==s.size())
	{
		a.push_back(ans);
		return;
	}
	for(int i=0;i<m[s[k]].size();i++)
	{
		char ch=m[s[k]][i];
		ans.push_back(ch);
		letter(s,k+1,m,a);
		ans.pop_back();
	}
}

int main() {
	vector<string> a;
	map<char,string> m;
	m['0']="0";
	m['1']="1";
	m['2']="abc";
	m['3']="def";
	m['4']="ghi";
	m['5']="jkl";
	m['6']="mno";
	m['7']="pqrs";
	m['8']="tuv";
	m['9']="wxyz";
	string s="2";
	letter(s,0,m,a);
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}