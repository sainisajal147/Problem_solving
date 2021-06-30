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

void dfs(const vector<vector<int>> &v,int i,int j,int A,int B,string &ans,vector<vector<int>> &visi)
{
	visi[i][j]=1;
	cout<<i<<" "<<j<<endl;
	if(i==A and j==B)
	{
		ans="YES";
		return;
	}
	if(i-1>=0 and v[i-1][j]==1 and visi[i-1][j]==0)
		dfs(v,i-1,j,A,B,ans,visi);
	if(i-1>=0 and j+1<=B and v[i-1][j+1]==1 and visi[i-1][j+1]==0)
		dfs(v,i-1,j+1,A,B,ans,visi);
	if(j+1<=B and v[i][j+1]==1 and visi[i][j+1]==0)
		dfs(v,i,j+1,A,B,ans,visi);
	if(i+1<=A and j+1<=B and v[i+1][j+1]==1 and visi[i+1][j+1]==0)
		dfs(v,i+1,j+1,A,B,ans,visi);
	if(i+1<=A and v[i+1][j]==1 and visi[i+1][j]==0)
		dfs(v,i+1,j,A,B,ans,visi);
	if(i+1<=A and j-1>=0 and v[i+1][j-1]==1 and visi[i+1][j-1]==0)
		dfs(v,i+1,j-1,A,B,ans,visi);
	if(j-1>=0 and v[i][j-1]==1 and visi[i][j-1]==0)
		dfs(v,i,j-1,A,B,ans,visi);
	if(i-1>=0 and j-1>=0 and v[i-1][j-1]==1 and visi[i-1][j-1]==0)
		dfs(v,i-1,j-1,A,B,ans,visi);
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>> v(A+1, vector<int> (B+1,1));
    vector<vector<int>> visi(A+1, vector<int> (B+1,0));
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            int temp=0;
            for(int k=0;k<C;k++)
            {
                temp=(i-E[k])*(i-E[k])+(j-F[k])*(j-F[k])-D*D;
                if(temp<=0)
                    break;
            }
            if(temp>0)
                v[i][j]=1;
        }
    }
    string ans="NO";
    dfs(v,0,0,A,B,ans,visi);
    return ans;
}

int main(void) {
	vector<int> B={2},C={3};
	cout<<solve(2,3,1,1,B,C);
	return 0;
}