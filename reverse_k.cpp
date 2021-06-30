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

void reverseList(vector<int> &a, int B) {
    for(int i=0;i+B<a.size()+1;)
    {
        reverse(a.begin()+i,a.begin()+i+B);
        i=i+B;
    }
    for(int i=0;i<a.size();i++)
    {
    	cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
	vector<int> v={ 6, 10, 0, 3, 4, 8 };
	reverseList(v,3);
	return 0;
}