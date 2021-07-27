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

int minDistance(string A, string B) {
    int bn=B.size(),an=A.size();
    vector<vector<int>> v(an+1,vector<int> (bn+1,0));
    for(int i=1;i<=an;i++)
    {
        for(int j=1;j<=bn;j++)
        {
            if(A[i-1]==B[j-1])
                v[i][j]=1+v[i-1][j-1];
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    disp(v);
    if(B.size()>A.size())
        return B.size()-v[an][bn];
    else
        return A.size()-v[an][bn];
}

int main(void) {
	//cout<<minDistance("bbbaabaa","aababbabb");
	cout<<((true)^(false));
	return 0;
}