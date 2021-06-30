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

bool tot = 0;
bool subsetSums(int arr[], int l, int r, int sum,int res) 
{ 
    // Print current subset 
    if(sum==res){
    	tot = 1;
    	return 1;
    }
    if(l==r){
    	return 0;
    }
  
    // Subset including arr[l] 
    //bool tot = 0;
    tot= tot or subsetSums(arr, l+1, r, sum+arr[l],res); 
  
    // Subset excluding arr[l] 
    tot= tot or subsetSums(arr, l+1, r, sum,res); 
    return tot;
} 


int main(void) {
	int v[]={4,6,23,10,1,3};
	int sum=0;
	int p = sizeof(v)/sizeof(v[0]);
	sort(v,v+ p);
	bool result = subsetSums(v,0,p - 1,sum,v[p - 1]);
	cout<<::tot;
	return 0;
}