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

string countAndSay(int n) {
        vector<string> v(n);
        v[0]="1",v[1]="11";
        for(int i=2;i<n;i++)
        {
            string s=v[i-1],ans="";
            int c=1;
            for(int j=1;j<s.size();j++)
            {
                if(s[j]!=s[j-1])
                {
                    ans+=to_string(c)+s[j-1];
                    c=1;
                }
                else
                {
                    c++;
                }
            }
            if(c)
                ans+=to_string(c)+s.back();
            v[i]=ans;
        }
        disp(v);
        return v[n-1];
    }

int main(void) {
	cout<<countAndSay(5);
	return 0;
}