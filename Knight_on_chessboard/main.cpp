#include <iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long int ll;
struct node{
    ll x;
    ll y;
    ll dis;
    node(ll x,ll y,ll dis)
    {
        this->x=x;
        this->y=y;
        this->dis=dis;
    }
};
bool bound(ll row,ll col,ll n)
{
    if(row<0 or col<0)
        return false;
    if(row>=n or col>=n)
        return false;
    return true;
}
void disp(vector<vector<ll>> ans , ll n)
{
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=0;j<n-1;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void BFS(ll n,ll a,ll b,ll &ans)
{
    vector<vector<ll>> v(n,vector<ll>(n,0));
    queue<node> q;
    node x(0,0,0);
    q.push(x);
    while(!q.empty())
    {
        node temp=q.front();
        v[temp.x][temp.y]=1;
        if(temp.x==n-1 and temp.y==n-1)
        {
            ans=temp.dis;
            return;
        }
        if(bound(temp.x+a,temp.y+b,n) and v[temp.x+a][temp.y+b]!=1)
        {
            v[temp.x+a][temp.y+b]=1;
            node temp1(temp.x+a,temp.y+b,temp.dis+1);
            q.push(temp1);
        }
        if(bound(temp.x+a,temp.y-b,n) and v[temp.x+a][temp.y-b]!=1)
        {
            v[temp.x+a][temp.y-b]=1;
            node temp1(temp.x+a,temp.y-b,temp.dis+1);
            q.push(temp1);
        }
        if(bound(temp.x-a,temp.y+b,n) and v[temp.x-a][temp.y+b]!=1)
        {
            v[temp.x-a][temp.y+b]=1;
            node temp1(temp.x-a,temp.y+b,temp.dis+1);
            q.push(temp1);
        }
        if(bound(temp.x-a,temp.y-b,n) and v[temp.x-a][temp.y-b]!=1)
        {
            v[temp.x-a][temp.y-b]=1;
            node temp1(temp.x-a,temp.y-b,temp.dis+1);
            q.push(temp1);
        }
        if(bound(temp.x+b,temp.y+a,n) and v[temp.x+b][temp.y+a]!=1)
        {
            v[temp.x+b][temp.y+a]=1;
            node temp1(temp.x+b,temp.y+a,temp.dis+1);
            q.push(temp1);
        }
        if(bound(temp.x+b,temp.y-a,n) and v[temp.x+b][temp.y-a]!=1)
        {
            v[temp.x+b][temp.y-a]=1;
            node temp1(temp.x+b,temp.y-a,temp.dis+1);
            q.push(temp1);
        }
        if(bound(temp.x-b,temp.y+a,n) and v[temp.x-b][temp.y+a]!=1)
        {
            v[temp.x-b][temp.y+a]=1;
            node temp1(temp.x-b,temp.y+a,temp.dis+1);
            q.push(temp1);
        }
        if(bound(temp.x-b,temp.y-a,n) and v[temp.x-b][temp.y-a]!=1)
        {
            v[temp.x-b][temp.y-a]=1;
            node temp1(temp.x-b,temp.y-a,temp.dis+1);
            q.push(temp1);
        }
        q.pop();
    }
    ans=-1;
}
void knightlOnAChessboard(ll n) {
vector<vector<ll>> ans(n-1,vector<ll> (n-1,0));
for(ll i=0;i<n-1;i++)
{
    for(ll j=0;j<n-1;j++)
    {
        if(j>=i)
        {
            BFS(n,i+1,j+1,ans[j][i]);
            ans[i][j]=ans[j][i];
        }
    }
}
disp(ans,n);
}
int main()
{
    ll n;
    cin>>n;
    knightlOnAChessboard(n);
    return 0;
}
