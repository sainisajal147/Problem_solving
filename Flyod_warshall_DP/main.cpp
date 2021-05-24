#include <iostream>

using namespace std;
#define m 32678
void disp(int n, int a[4][4])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==m)
                cout<<"- ";
            else
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void floyd(int n, int a[][4])
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && (i!=k || j!=k))
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
        cout<<"\nThe matrix for iteration no. "<<k<<" is:\n";
        disp(n,a);
    }
}
int main()
{
    int n=4;
    int a[4][4]={{0,3,m,7},{8,0,2,m},{5,m,0,1},{2,m,m,0}};
    disp(n,a);
    floyd(n,a);
    return 0;
}
