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

string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> v(n,vector<int> (n,0));
        int l=0,h=0,size=1;
        for(int i=0;i<n;i++)
        {
            v[i][i]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                v[i][i+1]=2;
                size=2;
                l=i,h=i+1;
            }
            else
                v[i][i+1]=1;
        }
        for(int i=2;i<n;i++)
        {
            for(int j=0;j+i<n;j++)
            {
                if(s[j]==s[j+i] and v[j+1][j+i-1]==i-1)
                {
                	if(size<i+1)
                    	l=j,h=j+i;
                    size=i+1;
                    v[j][j+i]=2+v[j+1][i+j-1];
                }
            }
        }
        disp(v);
        string ans="";
        for(int i=l;i<=h;i++)
        {
            ans+=s[i];
        }
        return ans;
    }

int main(void) {
	string s="aaaaa";
	cout<<longestPalindrome(s);
	return 0;
}