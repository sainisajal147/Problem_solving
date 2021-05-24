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

int naive_match(string s, string sub)
{
	int N=s.size()-sub.size();
	for(int i=0;i<=N;i++)
	{
		int k=i,j=0;
		while(s[k]==sub[j])
		{
			j++;
			k++;
		}
		if(j==sub.size())
			return i;
	}
	return -1;
}
void disp(vector<string> s)
{
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i]<<" ";
	}
	cout<<endl;
}
void disp(vector<int> s)
{
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i]<<" ";
	}
	cout<<endl;
}
vector<int> kmp(string s)
{
	int n=s.size();
	vector<int> v(n+1,0);
	vector<string> pre(n), suf(n);
	pre[0].push_back(s[0]);
	suf[0].push_back(s[n-1]);
	for(int i=1;i<n;i++)
	{
		pre[i]=pre[i-1]+s[i];
		suf[i]=s[n-i-1]+suf[i-1];
	}
	//disp(pre);
	//disp(suf);
	int x=-1;
	for(int i=2;i<s.size();i++)
	{
		if(v[i-1]!=0 and x!=-1)
		{
			if(s[i-1]==s[i-1-x])
				v[i]=v[i-1]+1;
			else if(s[i-1]==s[0])
				{
					x=i-1;
					v[i]=1;
				}
		}
		else if(s[i-1]==s[0])
		{
			x=i-1;
			v[i]=1;
		}
	}
	return v;
}
void pattern_match(string s, string sub)
{
	vector<int> v=kmp(sub);
	disp(v);
	sub='#'+sub;
	cout<<sub<<endl;
	int i=0,j=0;
	while(i<s.size() and j+1<sub.size())
	{
		if(s[i]==sub[j+1])
		{
			i++;
			j++;
		}
		else if(j==0)
		{
			i++;
		}
		else
		{
			j=v[j];
		}
	}
	cout<<i<<" "<<j<<endl;
	if(j==sub.size()-1)
		cout<<"pattern matched at : "<<i-j<<endl;
	else
		cout<<"did'nt match!\n";
}
int main() {
	string s="ababcabcabababd";
	string sub="ababd";
	//cout<<"The substring is at: "<<naive_match(s,sub);
	pattern_match(s,sub);
	return 0;
}