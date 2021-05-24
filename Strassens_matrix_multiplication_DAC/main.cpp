#include <iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
typedef long long int ll;
int **  matrix_mul( int n, int **a,int **b)
{
    int **c;
    c=new int *[n];
    for(int i=0;i<n;i++)
    {
        c[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return c;
}
void disp(int **c,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n=6,**a,**b;
    a=new int *[n];
    b=new int *[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
        b[i]=new int[n];
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=rand()%10+1;
            b[i][j]=rand()%10+1;
        }
    }
    disp(a,n);
    cout<<endl;
    disp(b,n);
    cout<<endl;
    //a[0][]={{1,2},{2,3}},b[][]={{4,2},{6,4}};
    disp(matrix_mul(n,a,b),n);
    return 0;
}
