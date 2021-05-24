#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int j=0;j<A.size();j++)
    {
        int i=j;
        while(A[j]==A[i+1] and i+1<A.size())
            i++;
        if(A[j]==A.size()-i-1)
        return 1;
    }
    return -1;
}
int main()
{
    vector<int> a={ -4, -2, 0, -1, -6 };
    /*sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    cout<<solve(a);
    return 0;
}
