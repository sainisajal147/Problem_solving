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

string solve(string A) {
    vector<string> ans;
    string s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=' ')
        {
            s+=A[i];
        }
        else if(A[i]==' ' and i-1>=0)
        {
        	if(A[i-1]!=' ')
            {	
            	ans.push_back(s);
            	s.clear();
            }
        }
    }
    ans.push_back(s);
    s.clear();
    for(int i=ans.size()-1;i>0;i--)
    {
        s+=ans[i]+' ';
    }
    s+=ans[0];
    while(s[0]==' ')
        s.erase(s.begin());
    while(s[s.size()-1]==' ')
        s.erase(s.begin()+s.size()-1);
    return s;
}

int main() {
	cout<<solve("       fwbpudnbrozzifml     osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq  ");
	return 0;
}