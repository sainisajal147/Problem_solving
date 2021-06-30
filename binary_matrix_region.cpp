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

void dfs(const vector<vector<int>> &v,int i,int j,int &ans,vector<vector<int>> &visi)
{
	cout<<ans<<"called\n ";
    visi[i][j]=1;
    ans++;
    int A=v.size()-1,B=v[0].size()-1;
    if(i-1>=0 and v[i-1][j]==1 and visi[i-1][j]==0)
        dfs(v,i-1,j,ans,visi);
    if(i-1>=0 and j+1<=B and v[i-1][j+1]==1 and visi[i-1][j+1]==0)
        dfs(v,i-1,j+1,ans,visi);
    if(j+1<=B and v[i][j+1]==1 and visi[i][j+1]==0)
        dfs(v,i,j+1,ans,visi);
    if(i+1<=A and j+1<=B and v[i+1][j+1]==1 and visi[i+1][j+1]==0)
        dfs(v,i+1,j+1,ans,visi);
    if(i+1<=A and v[i+1][j]==1 and visi[i+1][j]==0)
        dfs(v,i+1,j,ans,visi);
    if(i+1<=A and j-1>=0 and v[i+1][j-1]==1 and visi[i+1][j-1]==0)
        dfs(v,i+1,j-1,ans,visi);
    if(j-1>=0 and v[i][j-1]==1 and visi[i][j-1]==0)
        dfs(v,i,j-1,ans,visi);
    if(i-1>=0 and j-1>=0 and v[i-1][j-1]==1 and visi[i-1][j-1]==0)
        dfs(v,i-1,j-1,ans,visi);
}
int solve(vector<vector<int> > &A) {
    vector<vector<int>> visi(A.size(),vector<int> (A[0].size(),0));
    int ans=INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j]==1 and visi[i][j]==0)
            {
                int temp=0;
                dfs(A,i,j,temp,visi);
                ans=max(ans,temp);
            }
        }
    }
    disp(visi);
    return ans;
}


int main(void) {
	vector<vector<int>> A={{0, 0, 1, 0, 0, 0, 0, 0},{1, 1, 1, 1, 1, 1, 1, 0}};
	cout<<solve(A);
	return 0;
}