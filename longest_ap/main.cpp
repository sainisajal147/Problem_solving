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
#include <set>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int solve(const vector<int> &A) {
    map<int,set<int>> m;
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            int d=A[j]-A[i];
            set<int> s;
            s.insert(A[j]);
            s.insert(A[i]);
            m[d]=s;
        }
    }
    map<int,set<int>> ::iterator p=m.begin();
    while(p!=m.end())
    {
    	if(ans<(p->second).size())
    		ans=(p->second).size();
    	p++;
    }
    return ans;
}

int main() {
	vector<int> v={9,4,7,2,10};
	cout<<solve(v);
	return 0;
}
