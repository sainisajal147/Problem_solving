#include <iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    double profit;
    double weight;
    double pwratio;
    double included=0;
    node(int p, int w)
    {
        this->profit=p;
        this->weight=w;
        this->pwratio=(p*1.0)/(w);
    }
};
bool comp(node a1, node a2)
{
    return a1.pwratio>a2.pwratio;
}
void disp(vector<node> v)
{
    double profit=0;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].profit<<" "<<v[i].weight<<" "<<v[i].pwratio<<" "<<v[i].included<<endl;
        profit+=v[i].included*v[i].profit;
    }
    cout<<endl;
    if(profit>0)
        cout<<"Maximum profit is:"<<profit<<endl;
}
int main()
{
    double n=7,m=15;
    vector<node> v;
    node a1(10,2);
    v.push_back(a1);
    node a2(5,3);
    v.push_back(a2);
    node a3(15,5);
    v.push_back(a3);
    node a4(7,7);
    v.push_back(a4);
    node a5(6,1);
    v.push_back(a5);
    node a6(18,4);
    v.push_back(a6);
    node a7(3,1);
    v.push_back(a7);
    disp(v);
    sort(v.begin(),v.end(),comp);
    cout<<"After Sorting the knapsack be like:\n";
    disp(v);
    int i=0;
    while(m>0)
    {
        if(m>=v[i].weight)
        {
            v[i].included=1;
            m-=v[i].weight;
        }
        else
        {
            v[i].included=(m*1.0)/v[i].weight;
            m=0;
        }
        i++;
    }
    disp(v);
    return 0;
}
