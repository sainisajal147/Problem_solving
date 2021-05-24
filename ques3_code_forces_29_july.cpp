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

void disp(vector<ll> v)
{
	for(ll i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main() {
	ll t;
	cin>>t;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	while(t--)
	{
		string s;
		getline(cin,s);
		vector<ll> nor(10,0);
		for(ll i=0;i<s.size();i++)
		{
			nor[s[i]-'0']++;
		}
		int m=nor[0];
		for(ll i=1;i<10;i++)
		{
			if(nor[i]>m)
				m=nor[i];
		}
		for(int i=0;i<=9;i++)
		{
			for( int j=0;j<=9;j++)
			{
				if(j==i)
					continue;
				int num=0;
				for(int k=0;k<s.size();k++)
				{
					if(num%2==0 and s[k]-'0'==i)
						num++;
					if(num%2 and s[k]-'0'==j)
						num++;
				}
				m=max(m,(num/2)*2);
			}
		}
		cout<<s.size()-m<<endl;
	}
	return 0;
}