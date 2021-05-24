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

bool val(int i, int j, int radius)
{
	int x=sqrt(abs(i-radius)*abs(i-radius)+abs(j-radius)*abs(j-radius));
	if(x<=radius)
		return true;
	else
		return false;
}

int main() {
	int n=40;
	int radius=n/2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(val(i,j,radius))
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}