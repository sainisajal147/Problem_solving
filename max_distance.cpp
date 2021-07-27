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

struct node{
    int val;
    int idx;
    node(int val,int idx):val(val),idx(idx){}
};

bool comp(node a, node b)
{
    return a.val<b.val;
}
int maximumGap(const vector<int> &A) {
    int n=A.size();
    vector<node> sorted;
    for(int i=0;i<n;i++)
    {
        node temp(A[i],i);
        /*temp.val=A[i];
        temp.idx=i;//*/
        sorted.push_back(temp);
    }
    sort(sorted.begin(),sorted.end(),comp);
    for(int i=0;i<n;i++)
    {
    	cout<<sorted[i].val<<" "<<sorted[i].idx<<endl;
    }
    int ans=-1,max_idx=sorted[n-1].idx;
    for(int i=n-2;i>=0;i--)
    {
        if(sorted[i].idx>max_idx)
            max_idx=sorted[i].idx;
        else
            ans=max(ans,max_idx-sorted[i].idx);
    }
    return ans;
}

int main(void) {
	//vector<int> v={3,5,4,2};
	//cout<<maximumGap(v);
    string s="aab";
    int i=2;
	string subleft(s.begin(),s.begin());//,subright(s.begin()+i,s.end());
    cout<<subleft;//<<" "<<subright;
    return 0;
}