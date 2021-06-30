#include <stdio.h>
#include <cmath>
#include <map>
#include <math.h>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define m 1000000007
struct trip{
  int x,y,z;  
};
vector<trip> tr;
void filltr()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(i!=j and j!=k)
                    tr.push_back({i,j,k});
            }
        }
    }
}
bool comp(trip a, trip b)
{
    if(a.x==b.x or a.y==b.y or a.z==b.z)
        return 0;
    return 1;
}
int dp[4][4][4][100000]={0};
int solve(int A) {
    filltr();
    for(int i=1;i<=A;i++)
    {
        for(int j=0;j<36;j++)
        {
            if(i==1)
                dp[tr[j].x][tr[j].y][tr[j].z][i]=1;
            else
            {
                ll temp=0;
                for(int k=0;k<36;k++)
                {
                    if(comp(tr[j],tr[k]))
                    {
                        temp+=dp[tr[k].x][tr[k].y][tr[k].z][i-1];
                        temp%=m;
                    }
                }
                dp[tr[j].x][tr[j].y][tr[j].z][i]=temp;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<tr.size();i++)
    {
        ans=(ans+dp[tr[i].x][tr[i].y][tr[i].z][A])%m;
    }
    //if(A==1)
      //  return 36;
    return ans;
}

ll solve1(int A)
{
	ll c2=12,c3=24;
    //c2[0]=12,c3[0]=24;
    for(int i=1;i<A;i++)
    {
        ll temp1=(7*c2+5*c3)%m;
        ll temp2=(10*c2+11*c3)%m;
        c2=temp1;
        c3=temp2;
    }
    return (c2+c3)%m;
}
int main() {
	cout<<solve1(2);
	return 0;
}