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

int removeDuplicates(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();)
        {
            if(nums[i]!=nums[i-1])
                i++;
            else
                nums.erase(nums.begin()+i);
        }
        disp(nums);
        return nums.size();
    }

int main(void) {
	vector<int> v={0,0,1,1,1,2,2,3,3,4};
	cout<<removeDuplicates(v);
	return 0;
}