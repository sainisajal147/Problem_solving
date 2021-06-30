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

void bin_search(vector<int> v,int l, int h,int target,int &ans)
{
	if(l<=h)
	{
		int mid=ceil(((l+h)*1.0)/2);
		if(v[mid]>target)
			bin_search(v,l,mid,target,ans);
		else if(v[mid]<target)
			bin_search(v,mid+1,h,target,ans);
		else
		{
			ans=mid;
			bin_search(v,mid+1,h,target,ans);
		}
	}
	else
		return;
}

int main(void) {
	vector<int> v={5,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,10};
	int h=v.size()-1;
	int ans=-1;
	bin_search(v,0,h,8,ans);
	cout<<ans<<endl;
	return 0;
}