#include <iostream>
#include<vector>
using namespace std;

void disp(vector<vector<int>> a)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<a[i][j]<<" ";
        }
    }
}
bool B(vector<vector<int>> a,int k,int i,int j)
{
    for(int z=0;z<9;z++)
    {
        if(a[i][z]==k)
            return false;
        if(a[z][j]==k)
            return false;
    }
    int x=(i/3)*3,y=(j/3)*3;
    for(int n=x;n<x+3;n++)
    {
        for(int m=y;m<y+3;m++)
        {
            if(a[n][m]==k)
                return false;
        }
    }
    return true;
}
bool U(vector<vector<int>> a,int &row,int &col)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
void solve(vector<vector<int>> &a)
{
    int row,col;
    if(!(U(a,row,col)))
    {
        disp(a);
        return;
    }
    for(int k=1;k<=9;k++)
    {
        if(B(a,k,row,col))
        {
            a[row][col]=k;
            solve(a);
            a[row][col]=0;
        }
    }
}
int main()
{
    /*vector<vector<int>> a={{3, 0, 6, 5, 0, 8, 4, 0, 0},{5, 2, 0, 0, 0, 0, 0, 0, 0},{0 ,8 ,7 ,0 ,0 ,0 ,0 ,3 ,1},{0, 0, 3, 0, 1, 0, 0, 8, 0},{9, 0, 0, 8, 6, 3, 0, 0, 5},{0, 5, 0, 0, 9, 0, 6, 0, 0},{1 ,3 ,0 ,0 ,0 ,0 ,2 ,5 ,0},{0, 0, 0, 0, 0, 0, 0, 7, 4},{0 ,0 ,5 ,2 ,0 ,6 ,3 ,0 ,0}};
    solve(a);*/
    int t;
    cin>>t;
    while(t--)
    {
        vector<vector<int>> a(9,vector<int> (9));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cin>>a[i][j];
            }
        }
        solve(a);
    }
    return 0;
}
