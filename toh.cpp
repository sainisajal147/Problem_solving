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

void solve(int n, char A, char B, char C)
{
	if(n>0)
	{
		solve(n-1,A,C,B);
		cout<<"move a disk from "<<A<<" to "<<C<<endl;
		solve(n-1,B,A,C);
	}
}

void subset(string s,int i)
{
	static vector<int> hash(1000,0);
	for(int j=i;j<s.size();j++)
	{
		hash[s[i]-'a']=1;
		for(int k=0;k<s.size();k++)
		{
			if(hash[s[k]-'a']==1)
			{
				cout<<s[k]<<" ";
			}
		}
		cout<<endl;
		subset(s,j+1);
		hash[s[i]-'a']=0;
	}
}

void permu(string s,int l, int h)
{
	if(l==h)
	{
		cout<<s<<endl;
		return;
	}
	for(int i=l;i<h;i++)
	{
		swap(s[l],s[i]);
		permu(s,l+1,h);
		swap(s[l],s[i]);
	}
}

void permu1(string s,int k)
{
	static vector<int> v(1000);
	static string res="";
	if(k==s.size())
	{
		cout<<res<<" ";
		return;
	}
	for(int i=0;i<s.size();i++)
	{
		if(v[i]==0)
		{
			res+=s[i];
			v[i]=1;
			permu1(s,k+1);
			v[i]=0;
			res.erase(res.begin()+res.size()-1);
		}
	}
}

int main(void) {
	//subset("abc",0);
	//permu1("abc",0);
	//cout<<stoi("1232");
	//solve(3,'A','B','C');
	int n;
	cin>>n;
	cout<<n;
	return 0;
}