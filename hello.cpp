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

void disp(vector<int> s)
{
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i]<<" ";
	}
	cout<<endl;
}

int solve(string A) {
    string s = A;
    int ans = 0;
    reverse(s.begin(), s.end());
    s=A+'#'+s;
    vector<int> v(s.size(),0);
    int x=-1;
	for(int i=1;i<s.size();i++)
	{
		if(v[i-1]!=0 and x!=-1)
		{
			if(s[i]==s[i-x])
				v[i]=v[i-1]+1;
			else if(s[i]==s[0])
				{
					x=i;
					v[i]=1;
				}
		}
		else if(s[i]==s[0])
		{
			x=i;
			v[i]=1;
		}
	}
	cout<<s<<endl;
	disp(v);
    return A.size()-v[s.size()-1];
}
int main() {
	cout<<solve("ABC");
	return 0;
}