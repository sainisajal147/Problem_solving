#include <iostream>
using namespace std;

void disp(int **a,int n)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m1,m2;
        cin>>n;
        int **a{new int *[4]};
        a[0]=new int[n];//{1,15,51,45,33,100,12,18,9};
        a[1]=new int[n];//{1,15,51,45,33,100,12,18,9};
        a[2]=new int[n];//{9,18,12,100,33,45,51,15,1};
        a[3]=new int[n];//{9,18,12,100,33,45,51,15,1};
        for(int i=0;i<n;i++)
        {
            int q;
            cin>>q;
            a[0][i]=a[1][i]=q;
            a[2][n-i-1]=a[3][n-i-1]=q;
        }
        m1=a[1][0],m2=a[2][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[0][j]<a[0][i] && a[1][j]+a[0][i]>a[1][i])
                {
                    a[1][i]=a[1][j]+a[0][i];
                }
            }
            if(m1<a[1][i])
                m1=a[1][i];
        }
        int k=0,m=a[1][0];
        for(int i=1;i<n;i++)
        {
            if(m<a[1][i])
            {
                m=a[1][i];
                k=i;
            }
        }
        for(int i=1;i<n-k-1;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[3][j]<a[3][i] && a[2][j]+a[3][i]>a[2][i])
                {
                    a[2][i]=a[2][j]+a[3][i];
                }
            }
            if(m2<a[2][i])
                m2=a[2][i];
        }
        //disp(a,n);
        //cout<<m1<<" "<<m2<<endl;
        cout<<m1+m2<<endl;
    }
    return 0;
}
