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

void search(vector<string> A,string B,int i,int j,int &ans,int index)
{
    if(index==B.size()-1)
    {
        ans=1;
        return;
    }
    if(i-1>=0 and A[i-1][j]==B[index+1])
    {
    	cout<<"i-1\n";
        search(A,B,i-1,j,ans,index+1);
    }
    if(i+1<A.size() and A[i+1][j]==B[index+1])
    {
    	cout<<"i+1\n";
        search(A,B,i+1,j,ans,index+1);
    }
    if(j-1>=0 and A[i][j-1]==B[index+1])
    {
        cout<<"j-1\n";
        search(A,B,i,j-1,ans,index+1);
    }
    if(j+1<A[0].size() and A[i][j+1]==B[index+1])
    {
    	cout<<"j+1\n";
        search(A,B,i,j+1,ans,index+1);
    }
}
int exist(vector<string> &A, string B) {
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]==B[0])
            {
            	cout<<i<<""<<j<<"B[0] found\n";
                search(A,B,i,j,ans,0);
                if(ans)
                    return 1;
            }
        }
    }
    return 0;
}


int main(void) {
	vector<string> v={"BCD"};
	string B="BCD";
	cout<<exist(v,B);
	return 0;
}