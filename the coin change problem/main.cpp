#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long int ll;

ll getWays(int n, vector<ll> c) {
sort(c.begin(),c.end());
map<ll,ll *> m;
for(ll i=0;i<c.size();i++)
{
    m[c[i]]=new ll [n+1];
    for(int j=0;j<=n;j++)
    {
        m[c[i]][j]=0;
    }
}
for(ll i=0;i<c.size();i++)
{
    for(ll j=0;j<=n;j++)
    {
        if(j==0)
        {
            m[c[i]][j]=1;
        }
        else if(i==0)
        {
            if(j%c[i])
            m[c[i]][j]=0;
            else
            m[c[i]][j]=1;
        }
        else if(c[i]>j)
        {
            m[c[i]][j]=m[c[i-1]][j];
        }
        else
        {
            m[c[i]][j]=m[c[i-1]][j]+m[c[i]][j-c[i]];
        }
    }
}
/*for(ll i=0;i<c.size();i++)
{
    cout<<c[i]<<" ";
    for(ll j=0;j<=n;j++)
    {
        cout<<m[c[i]][j]<<" ";
    }
    cout<<endl;
}*/
return m[c[c.size()-1]][n];
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
    }
    cout<<getWays(n,v)<<endl;
    return 0;
}
