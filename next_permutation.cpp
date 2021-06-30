/*
AUTHOR : SAJAL SAINI
*/
#include <bits/stdc++.h>

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

void nextPermutation(vector<int> &nums)
{
	//vector<int> v=nums;
	bool flag=true;
	for(int i=0;i<nums.size()-1;i++)
	{
		if(nums[i]<nums[i+1])
		{
			flag=false;
			break;
		}
	}
	if(flag==true)
	{
		sort(nums.begin(),nums.end());
		disp(nums);
	}
	else
	{
		int curr=nums.size()-2,mini=nums.size()-1;
		for(;curr>=0;curr--)
		{
			if(nums[curr]<nums[curr+1])
			{
				break;
			}
		}
		int minval=INT_MAX,minans=-1;
		for(;mini>curr;mini--)
		{
			if(nums[mini]>nums[curr] and nums[mini]<minval)
			{
				minval=nums[mini];
				minans=mini;
			}
		}
		swap(nums[curr],nums[minans]);
		sort(nums.begin()+curr+1,nums.end());
		disp(nums);
	}
}

int main(void) {
	vector<int> v={1,1,5};
	nextPermutation(v);
	return 0;
}