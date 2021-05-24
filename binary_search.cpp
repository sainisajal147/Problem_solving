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

int binary_search(vector<int> a, int l, int h, int key)
{
	if (l < h)
	{
		int mid = (l + h) / 2;
		if (a[mid] == key)
			return 1;
		else if (a[mid] > key)
			return binary_search(a, l, mid, key);
		else
			return binary_search(a, mid + 1, h, key);
	}
	return 0;
}

int itr_binary_search(vector<int> a, int key)
{
	int l = 0, h = a.size();
	while (l < h)
	{
		int mid = (l + h) / 2;
		if (a[mid] == key)
			return 1;
		else if (a[mid] > key)
			h = mid;
		else
			l = mid + 1;
	}
	return 0;
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5, 6, 9, 10, 12, 17};
	//cout << binary_search(v, 0, v.size(), 18);
	cout << itr_binary_search(v, 6);
	return 0;
}