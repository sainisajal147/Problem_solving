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

map<int,int> m;

void subsetSums(int arr[], int l, int r, int sum=0) 
{ 
    // Print current subset 
    if (l > r) 
    { 
        cout << sum << " "; 
        m[sum]++;
        return; 
    } 
  
    // Subset including arr[l] 
    subsetSums(arr, l+1, r, sum+arr[l]); 
  
    // Subset excluding arr[l] 
    subsetSums(arr, l+1, r, sum); 
} 

int main(void) {
	int v[]={5,7,16,1,2};
	int ma=INT_MIN;
	int p = sizeof(v)/sizeof(v[0]);
	for(int i=0;i<p;i++)
	{
		ma=max(ma,v[i]);
	}
	int sum=0;
	subsetSums(v,0,p-2,sum);
	if(m[ma]!=0)
		cout<<1;
	return 0;
}