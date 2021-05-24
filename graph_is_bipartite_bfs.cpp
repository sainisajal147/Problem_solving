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

bool isBipartite(vector<vector<int>> v, int initial) 
{ 
    int n=v.size();
    vector<int> col(n,-1);
    col[initial] = 1; 
    queue <int> q; 
    q.push(initial); 
    while (!q.empty()) 
    { 
        int x = q.front(); 
        q.pop();
        for (int y = 0; y < n; y++) 
        { 
            if (v[x][y] && col[y] == -1) 
            {
                col[y] = 1 - col[x]; 
                q.push(y); 
            }
            else if (v[x][y] && col[y] == col[x]) 
                return false; 
        } 
    }
    disp(col);
    return true;
}

int main(void) {
	vector<vector<int>> G = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
  
    isBipartite(G, 0) ? cout << "Yes" : cout << "No";
	return 0;
}