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

void disp(vector<int> ans)
{
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] <<" ";
	}
	cout<<endl;
}

unsigned int reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> x;
    while(A>0)
    {
        x.push_back(A%2);
        A/=2;
    }
    int z=32-x.size();
    while(z--)
    {
    	x.push_back(0);
    }
    unsigned int a=0;
    for(int i=0;i<32;i++)
    {
        a+=pow(2,31-i)*x[i];
    }
    disp(x);
    return a;
}

int main() {
	cout<<reverse(2);
	return 0;
}