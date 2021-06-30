#include <iostream>
#include<math.h>
#include<map>
#include<set>
using namespace std;

void disp(int n,int **a)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void TSP(int n,int **a,int start)
{
    map<map<int,set<int>>,int> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

        }
    }
}
int main()
{
    int n=4;
    int **a{new int *[n]};
    a[0]= new int[n]{0,10,15,20};
    a[1]= new int[n]{5,0,9,10};
    a[2]= new int[n]{6,13,0,12};
    a[3]= new int[n]{8,8,9,0};
    disp(n,a);
    return 0;
}
