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

int pivot(vector<int> v,int l, int h)
{
	int mid=(l+h)/2;
	if(v[mid]>v[l] and v[mid]>v[h])
		return pivot(v,mid,h);
	else if(v[mid]<v[l] and v[mid]<v[h])
		return pivot(v,l,mid);
	else
		return mid;
}

int bin_search(vector<int> v,int l, int h,int tar)
{
	while(l<=h)
	{
		int mid=ceil(((l+h)*1.0)/2);
		if(v[mid]<tar)
			l=mid+1;
		else if(v[mid]>tar)
			h=mid-1;
		else
			return mid;
	}
	return -1;
}

int search(vector<int>& nums, int target) {
        int h=nums.size()-1;
        int piv=pivot(nums,0,h);
       	int l=bin_search(nums,0,piv,target);
        int r=bin_search(nums,piv+1,h,target);
        cout<<l<<" "<<r<<" "<<endl;
        if(l!=-1)
            return l;
        if(r!=-1)
            return r;
        return -1;
}

int main(void) {
	vector<int> v={4,5,6,7,0,1,2};
	int h=v.size()-1;
	cout<<search(v,0);
	return 0;
}