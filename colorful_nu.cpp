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

#define a 100000
int x[a]={0};
int colorful(int A) {
    int n=A;
    vector<int> v;
    while(n>0)
    {
        v.insert(v.begin(),n%10);
        n/=10;
    }
    int N=v.size();
    vector<vector<int>> m(N,vector<int> (N,1));
    for(int i=0;i<N;i++)
    {
        m[i][i]=v[i];
        x[v[i]]++;
        if(x[v[i]]>1)
            return 0;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            m[i][j]=v[j]*m[i][j-1];
            x[m[i][j]]++;
            if(x[m[i][j]]>1)
                return 0;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
           cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return 1;
}
int main() {
	cout<<colorful(234);
	return 0;
}