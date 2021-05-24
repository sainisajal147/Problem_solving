#include <iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
#include<set>
#include<map>
#include<math.h>
#include<string>
using namespace std;
typedef long long int ll;
void solve(ll a,ll b,ll c)
{
    if(c<a)
    {
        cout<<"-1 1\n";
        return;
    }
    else if(a<=c/b)
    {
        cout<<"1 -1\n";
        return;
    }
    else if(c==a)
    {
        cout<<"-1 "<<b<<endl;
        return;
    }
    else
    {
        cout<<"1 "<<b<<endl;
    }
}
int main()
{
    ll t;
    cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--)
    {
        string s;
        getline(cin,s);
        ll cur=0,res=s.size(),mn=0;
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='+')
                cur+=1;
            else
                cur+=-1;
            if(cur<mn)
            {
                mn=cur;
                res+=i+1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
