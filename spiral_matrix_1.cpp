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

vector<int> spiralOrder(const vector<vector<int> > &A) {
    vector<int> ans;
    int row=A.size(),col=A[0].size();
    int st_i=0,st_j=0,en_i=row-1,en_j=col-1;
    int dir=0;
    while(st_i<=en_i and st_j<=en_j)
    {
        //cout<<"st i = "<<st_i<<" st j = "<<st_j<<" en i = "<<en_i<<" en j = "<<en_j<<endl;
	    if(dir==0)
	    {
	        for(int i=st_j;i<=en_j;i++)
	            ans.push_back(A[st_i][i]);
	        dir=1;
	        st_i++;
	    }
	    else if(dir==1)
        {
        	for(int i=st_i;i<=en_i;i++)
        	    ans.push_back(A[i][en_j]);
        	en_j--;
        	dir=2;
        }
        else if(dir==2)
	    {
	        for(int i=en_j;i>=st_j;i--)
	            ans.push_back(A[en_i][i]);
	        en_i--;
	        dir=3;
	    }
	    else if(dir==3)
        {
        	for(int i=en_i;i>st_i;i--)
            	ans.push_back(A[i][st_j]);
            st_j++;
            dir=0;
        }
    }
    return ans;
}


int main(void) {
	vector<vector<int>> v={{1,2,3,12},{4,5,6,13},{7,8,9,14}};//{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	disp(spiralOrder(v));
	return 0;
}