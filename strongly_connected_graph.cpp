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

stack<int> S;
int component[5];
vector<int> components[5];
vector<bool> visited(5,0);
int numComponents;

void dfs_1(int x,vector<vector<int>> v)
{
	int n=v.size();
    visited[x] = true;
    for (int i=0;i<n;i++)
    {
        if (!visited[i] and v[x][i]==1) 
        	dfs_1(i,v);
    }
    S.push(x);
}

void dfs_2(int x,vector<vector<int>> v)
{
	int n=v.size();
    cout<<x<<" ";
    component[x] = numComponents;
    components[numComponents].push_back(x);
    visited[x] = true;
    for (int i=0;i<n;i++)
    {
        if (!visited[i] and v[x][i]==1)
        	dfs_2(i,v);
    }
}

void Kosaraju(vector<vector<int>> v, vector<vector<int>> v_rev)
{
	int n=v.size();
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        	dfs_1(i,v);
    }
    
    for (int i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    
    while (!S.empty())
    {
        int x = S.top(); S.pop();
        if (!visited[x])
        {
            cout<<"Component number "<<numComponents<<" :";
            dfs_2(x,v_rev);
            numComponents++;
            cout<<endl;
        }
    }
}

int main(void) {
	vector<vector<int>> v={{0,0,1,0,0},{1,0,0,0,0},{0,1,0,1,0},{0,0,0,0,1},{0,0,0,0,0}};
	int n=v.size();
	vector<vector<int>> v_rev(n,vector<int> (n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			v_rev[j][i]=v[i][j];
		}
	}
	Kosaraju(v,v_rev);
	//cout<<dia_bfs(v,0);
	return 0;
}