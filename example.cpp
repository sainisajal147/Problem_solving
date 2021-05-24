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
#include <math.h>
#include <set>

using namespace std;

typedef long long int ll;

void disp(vector<vector<int>> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

void disp(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

class rectangle
{
public:
	static int z;
	int get()
	{
		return z;
	}
};
int rectangle::z = 0;
int main() {
	rectangle r, r1;
	r.z++;
	r1.z++;
	cout << r1.get();
	return 0;
}