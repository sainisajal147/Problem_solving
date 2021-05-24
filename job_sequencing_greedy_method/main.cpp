#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    int profit;
    int deadline;
    node(int p, int d)
    {
        this->deadline=d;
        this->profit=p;
    }
};
bool comp(node a1, node a2)
{
    return a1.profit>a2.profit;
}
void disp(vector<node > v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<i+1<<" "<<v[i].profit<<" "<<v[i].deadline<<endl;
    }
}
int main()
{
    int n=5;
    vector<node> v;
    node j1(20,2);
    v.push_back(j1);
    node j2(15,2);
    v.push_back(j2);
    node j3(10,1);
    v.push_back(j3);
    node j4(5,3);
    v.push_back(j4);
    node j5(1,3);
    v.push_back(j5);
    sort(v.begin(),v.end(),comp);
    disp(v);
    int job_slot=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].deadline>job_slot)
            job_slot=v[i].deadline;
    }
    int job[job_slot];
    for(int i=0;i<job_slot;i++)
    {
        job[i]=-1;
    }
    for(int i=0;i<v.size();i++)
    {
        int j=v[i].deadline-1;
        if(job[j]==-1)
            {
                job[j]=i;
            }
        else
        {
            while(job[j]!=-1)
            j--;
            if(job[j]==-1 && j>=0)
                job[j]=i;
        }
    }
    int ans=0;
    for(int i=0;i<job_slot;i++)
    {
        ans+=v[job[i]].profit;
    }
    cout<<"Maximum profit is:"<<ans;
    return 0;
}
