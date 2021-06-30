#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int s(vector<int> a)
{
    int s=0;
    for(int i=0;i<a.size();i++)
        s+=a[i];
    return s;
}
void subset_sum(vector<int> a,int n,int sum,int sum_r,int i,vector<int> x,int in,int m,set<vector<int>> &see)
{
    if(i==n or sum==m)
    {
        if(sum==m)
        {
            vector<int> ans;
            int k=0;
            for(;k<x.size();k++)
                {
                    if(x[k]==1)
                    {
                        ans.push_back(a[k]);
                    }
                }
                sort(ans.begin(),ans.end());
                if(!ans.empty())
                    see.insert(ans);
                /*if(ans.empty())
                    cout<<"Empty\n";
                else
                {
                    cout<<"(";
                    for(int z=0;z<ans.size()-1;z++)
                        cout<<ans[z]<<" ";
                    cout<<ans[ans.size()-1]<<")";
                }*/
        }
        x.clear();
        return;
    }
    //if(sum+a[i]<=m)// and sum+sum_r>m)
    //{
        sum+=a[i];
       // sum_r-=a[i];
        x.push_back(1);
        subset_sum(a,n,sum,sum_r,i+1,x,1,m,see);
    //}
   // if(sum+a[i]<=m)// and sum+sum_r>m)
    //{
        sum-=a[i];
        //sum_r-=a[i];
        x.pop_back();
        x.push_back(0);
        subset_sum(a,n,sum,sum_r,i+1,x,0,m,see);
    //}
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
           {
                cin>>a[i];
           }
        cin>>m;
        vector<int> x;
        set<vector<int>> see;
        subset_sum(a,n,0,s(a),0,x,0,m,see);
        if(see.empty())
            cout<<"Empty\n";
        else
        {
            set<vector<int>>::iterator p=see.begin();
            while(p!=see.end())
            {
                        cout<<"(";
                        for(int z=0;z<(*p).size()-1;z++)
                            cout<<(*p)[z]<<" ";
                        cout<<(*p)[(*p).size()-1]<<")";
                        p++;
            }
            cout<<endl;
        }
    }
    return 0;
}
