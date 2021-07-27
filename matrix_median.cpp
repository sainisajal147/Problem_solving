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

int count_of_less_nums(vector<vector<int>> A,int num)
{
	int n=A.size(),m=A[0].size(),ans=0;
	for(int i=0;i<n;i++)
	{
		int l=0,h=m-1,temp_ans=0;
		while(l<=h)
		{
			int mid=(l+h)/2;
			if(A[i][mid]<=num)
			{
				temp_ans=mid+1;
				l=mid+1;
			}
			else
				h=mid-1;
		}
		//cout<<temp_ans<<" ";
		ans+=temp_ans;
	}
	return ans;
}

int findMedian(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    int nums=(n*m)/2;
    int outer_l=A[0][0],outer_h=A[0][m-1];
    for(int i=1;i<n;i++)
    {
    	outer_l=min(outer_l,A[i][0]);
    	outer_h=max(outer_h,A[i][m-1]);
    }
    int k=(n*m+1)/2;
    while(outer_l<=outer_h)
    {
        int curr=(outer_l+outer_h)/2;
        int lessthan=count_of_less_nums(A,curr);
        if(lessthan<k)
        {
        	outer_l=curr+1;
        }
        else
        	outer_h=curr-1;
    }
    return outer_l;
}

int main(void) {
	vector<vector<int>> v={{1,3,5},{2,6,9},{3,6,9}};
	cout<<findMedian(v);
	return 0;
}