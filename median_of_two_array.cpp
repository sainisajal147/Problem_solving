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

double findMedianSortedArrays(const vector<int> &x, const vector<int> &y) {
	if(x.size()>y.size())
	{
		return findMedianSortedArrays(y,x);
	}
	int n=x.size(),m=y.size();
	int l=0,h=n;
	double ans=0.0;
	while(l<=h)
	{
		int mid_x=(l+h)/2;
		int mid_y=(n+m+1)/2-mid_x;
		int xleft=(mid_x==0)?INT_MIN:x[mid_x-1];
		int xright=(mid_x==n)?INT_MAX:x[mid_x];
		int yleft=(mid_y==0)?INT_MIN:y[mid_y-1];
		int yright=(mid_y==m)?INT_MIN:y[mid_y];
		if(xleft<=yright and yleft<=xright)
		{
			if((n+m)%2==0)
			{
				ans=(max(xleft,yleft)+min(xright,yright))/2.0;
			}
			else
				ans=max(xleft,yleft);
			break;
		}
		else if(xleft>yright)
			h=mid_x-1;
		else
			l=mid_x+1;
	}
	return ans;
}

int main(void) {
	vector<int> v1={1,3,8,9,15},v2={7,11,18,19,21,25};
	cout<<findMedianSortedArrays(v1,v2);
	return 0;
}