#include <iostream>
#include<map>
#include<vector>
using namespace std;
bool Find(vector<int> v,int value)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==value)
            return true;
    }
    return false;
}
void knapsack(int n,int *p,int *w,int m)
{
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    for(int i=1;i<=m;i++)
    {
        if(i>=w[0])
        v[1][i]=p[0];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j>=w[i-1])
            v[i][j]=max(v[i-1][j],v[i-1][j-w[i-1]]+p[i-1]);
            else
            v[i][j]=v[i-1][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    int profit=v[n][m];
    cout<<"The maximum profit is : "<<profit<<endl;
    int *x{new int[n]{0}};
    for(int i=n;i>=0;i--)
    {
        if(!Find(v[i-1],profit))
        {
            profit-=p[i-1];
            x[i-1]=1;
        }
        else
            x[i-1]=0;
        if(profit<=0)
            break;
    }
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
}

int main()
{
    int n=4,m=8;
    int *p{new int[n]{1,2,5,6}};
    int *w{new int[n]{2,3,4,5}};
    knapsack(n,p,w,m);
    return 0;
}
