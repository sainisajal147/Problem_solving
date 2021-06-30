#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void disp(vector<int> x)
{
    for(int i=0;i<x.size();i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
struct node{
int profit,index;
};
void solve(vector<int> p,vector<int> d,int n)
{
    queue<node> q;
    for(int i=0;i<n;i++)
    {
        node temp;
        temp.profit=p[i];
        temp.index=i;
        q.push(temp);
    }
    vector<int> x,y;
    while(!q.empty())
    {
        node temp=q.front();
        //cout<<temp.index<<" "<<temp.profit<<"\n";
        if(temp.index==n-1)
        {
            cout<<temp.profit<<endl;
        }
        /*else
        {
            x.push_back(n-1);
            disp(x);
            x.clear();
        }*/
        for(int i=temp.index+1;i<n;i++)
        {
            node s;
            s.profit=p[i]+temp.profit;
            s.index=i;
            q.push(s);
        }
        q.pop();
    }
}
int main()
{
    int n=4;
    vector<int> v={10,5,8,3};
    vector<int> d={1,2,1,2};
    solve(v,d,n);
    return 0;
}
