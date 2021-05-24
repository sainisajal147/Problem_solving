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

vector<int> dia(100,0);

int dia_bfs(vector<vector<int>> v,int i)
{
	int n=v.size();
	vector<int> visi(n,0);
	for(int i=0;i<n;i++)
		dia[i]=0;
	visi[i]=1;
	queue<int> q;
	q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int y=0;y<n;y++)
		{
			if(v[x][y]==1 and visi[y]==0)
			{
				q.push(y);
				visi[y]=1;
				dia[y]+=dia[x]+1;
			}
		}
	}
	int z=*max_element(dia.begin(),dia.end()),index;
	for(int i=0;i<n;i++)
	{
		if(z==dia[i])
		{
			index=i;
			break;
		}
	}
	return index; 
}

int main(void) {
	vector<vector<int>> v={{0,1,1,0,0,0},{1,0,1,0,0,0},{1,1,0,1,0,0},{0,0,1,0,1,1},{0,0,0,1,0,1},{0,0,0,1,1,0}};
	int z=dia_bfs(v,0);
	int index=dia_bfs(v,z);
	cout<<"The Diameter is : "<<dia[index];
	return 0;
}