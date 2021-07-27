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

struct node{
    int val;
    int idx;
    node(int val,int idx):val(val),idx(idx){}
};
bool comp(node a, node b)
{
    if(a.val==b.val)
    	return a.idx<b.idx;
    else
    	return a.val<b.val;
}
/*struct comp{
  bool operator()(node a, node b){
      return a.val<b.val;
  }  
};*/
vector<int> twoSum(const vector<int> &A, int b) {
    vector<int> ans(2);
    int n=A.size();
    vector<node> a;
    bool flag=false;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        node temp(A[i],i+1);
        a.push_back(temp);
        if(m[A[i]]==0)
        	m[A[i]]=i+1;
    }
    sort(a.begin(),a.end(),comp);
    int i=0,j=a.size()-1;
    while(i<j)
    {
        if(a[i].val+a[j].val<b)
            i++;
        else if(a[i].val+a[j].val>b)
            j--;
        else
        {
            if(flag==false or max(a[i].idx,a[j].idx)<ans[1])
            {
                ans[0]=a[i].idx,ans[1]=a[j].idx;
                sort(ans.begin(),ans.end());
                if(a[i].val!=a[j].val)
                	ans[0]=m[A[ans[0]-1]];
                flag=true;
            }
            //i++;
            j--;
        }
    }
    cout<<endl;
    for(int i=0;i<a.size();i++)
    {
    	cout<<a[i].val<<" to "<<a[i].idx<<endl;
    }
    cout<<endl;
    return ans;
}


int main(void) {
	vector<int> v={10, -3, 5, -7, -4, 5, 6, -7, 8, -5, 8, 0, 8, -5, -10, -1, 1, -6, 4, -1, -2, -2, 10, -2, -4, -7, 5, 1, 7, -10, 0, 5, 8, 6, -8, 8, -8, -8, 3, -9, -10, -5, -5, -10, 10, -4, 8, 0, -6, -2, 3, 7, -5, 5, 1, -7, 0, -5, 1, -3, 10, -4, -3, 3, 3, 5, 1, -2, -6, 3, -4, 10, -10, -3, -8, 2, -2, -3, 0, 10, -6, -8, -10, 6, 7, 0, 3, 9, -10, -7, 8, -7, -7};
	disp(twoSum(v,-2));
	return 0;
}