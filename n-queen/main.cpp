#include <iostream>
#include<vector>
using namespace std;
void disp(vector<vector<int>> v,int n)
{
    vector<int> x;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]!=0)
                x.push_back(j+1);
        }
    }
    cout<<"[";
    for(int i=0;i<x.size()-1;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<x[x.size()-1]<<"] ";
}
bool F(int n, int i,int j, vector<vector<int>> &v)
{
    for(int row=0;row<n;row++)
    {
        if(v[row][j]==1)
            return false;
    }
    int x=i,y=j;
    while(x>=0 and y>=0)
    {
        if(v[x][y]==1)
            return false;
        x--;
        y--;
    }
    x=i,y=j;
    while(x>=0 and y<n)
    {
        if(v[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;
}
void n_queen(int n,int i,vector<vector<int>> &v,vector<int> &x)
{
    if(i==n)
    {
        disp(v,n);
    }
    else
    {
        for(int j=0;j<n;j++)
        {
            if(F(n,i,j,v))
            {
                v[i][j]=1;
                n_queen(n,i+1,v,x);
                x.push_back(j);
                v[i][j]=0;
            }
        }
    }
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (n,0));
    vector<int > x;
    n_queen(n,0,v,x);
    cout<<endl;
    }
    return 0;
}
