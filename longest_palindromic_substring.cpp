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

void disp(vector<vector<int>> v,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
int v[1000][1000]={0};
string longestPalindrome(string A) 
{
	int n=A.size(),st=0,en=0;
	vector<vector<int>> v(n,vector<int> (n,0));
	/*v[n-1][n-1]=1;
	for(int i=0;i<n-1;i++)
	{
		v[i][i]=1;
		if(A[i]==A[i+1])
		{
			v[i][i+1]=1;
			if(st==0 and en==0)
			{
				st=i;
				en=i+1;
			}
		}
	}*/
	for(int i=0;i<n;i++)
    {
        v[i][i]=1;
    }
    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        {
            v[i][i+1]=2;
        }
        else
        {
            v[i][i+1]=1;
        }
    }
	/*for(int i=2;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j+i<n)
			{
				v[j][j+i]= A[j]==A[j+i] and v[j+1][j+i-1]==1;
				if(v[j][j+i]==1 and en-st<i)
				{
					st=j,en=j+i;
				}
			}
		}
	}*/
	for(int i=2;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int I=j,J=j+i;
            if(J<n)
            {
                if(A[I]==A[J])
                 {
                     v[I][J]=2+v[I+1][J-1];
                 }
                 else
                 {
                     v[I][J]=max(v[I+1][J],v[I][J-1]);
                 }
            }
        }
    }
	disp(v,n);
	string ans;
	for(int i=st;i<=en;i++)
	{
		ans.push_back(A[i]);
	}
	//cout<<st<<" "<<en<<endl;
	return ans;
}

int main() {
	cout<<longestPalindrome("bebeeed");//"bbacaccaabcbaccbcacacabcbcbbbcbbbccabcbccacbacbbaacbbbcbbaabbbcabcabccaacbcccaabaccacabaccabbcacbc");
	return 0;
}