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

int Max_Sum_Non_Adjacent(vector<int> v) 
{
    int excl = 0;
    int incl = v[0];
    for (int i = 1; i < v.size(); i++) 
    {
    	int temp = incl;
        incl = max(excl + v[i], incl);
        excl = temp;
    }
    return incl;
}

int main(void) {
	vector<int > v={3, 5, 8, 4, 9, 16, 14, 6, 13};
	cout<<Max_Sum_Non_Adjacent(v);
	return 0;
}