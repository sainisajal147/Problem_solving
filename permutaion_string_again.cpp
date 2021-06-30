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

//string ans="";
void permutaion(string s,int i,vector<int> &h)
{
	static string ans(s.size(),'0');
	if(i==s.size())
	{
		cout<<ans<<endl;
		//ans.clear();
		return;
	}
	for(int k=0;k<s.size();k++)
	{
		if(h[k]==0)
		{
			h[k]=1;
			ans[i]=s[k];
			permutaion(s,i+1,h);
			//ans.erase(s.begin()+k);
			h[k]=0;
		}
	}
}

/*void itr_pre(node t)
{
	stack<node> s;
	s.push(t)
	while(t and !s.empty())
	{
		if(t)
		{
			cout<<t->data<<" ";
			s.push(t);
			t=t->left;
		}
		else
		{
			s.pop();
			t=t->right;
		}
	} 
}*/

int po(int x,int n)
{
	if(n==0)
		return 1;
	int half=po(x,n/2);
	if(n%2)
		return half*half*x;
	else
		return half*half;
}

string sol1(string s)
{
	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]>s[i+1])
		{
			s.erase(s.begin()+i);
			return s;
		}
	}
	s.pop_back();
	return s;
}

int dig_sum(int n)
{
	int ans=0;
	while(n>0)
	{
		ans+=n%10;
		n/=10;
	}
	return ans;
}

int sol2(vector<int> v)
{
	map<int,vector<int>> m;
	for(int i=0;i<v.size();i++)
	{
		m[dig_sum(v[i])].push_back(v[i]);
	}
	map<int,vector<int>>::iterator p=m.begin();
	int sum=-1;
	while(p!=m.end())
	{
		vector<int> temp=p->second;
		int temp_n=temp.size();
		if(temp.size()>=2)
		{
			sort(temp.begin(),temp.end());
			sum=max(temp[temp_n-1]+temp[temp_n-2],sum);
		}
		p++;
	}
	return sum;
}

int sol3(vector<int> v,int m)
{
	vector<int> freq(m,0);
	int ans=0;
	for(int i=0;i<v.size();i++)
	{
		int p=v[i]%m;
		while(p<0)
			p+=m;
		freq[p]++;
		ans=max(ans,freq[p]);
	}
	return ans;
}

int main(void) {
	//cout<<sol1("aaaaaaay");
	vector<int> v={7,1,11,8,4,10};
	//cout<<sol2(v);
	cout<<sol3(v,8);
	//vector<int> v(3,0);
	//permutaion("abc",0,v);
	return 0;
}