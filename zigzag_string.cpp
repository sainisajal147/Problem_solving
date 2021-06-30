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

void disp(vector<string> ans)
{
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}
void disp(vector<int> ans)
{
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] <<" ";
	}
	cout<<endl;
}
string convert(string A, int B) {
    vector<string> x(B);
    vector<int> v;
    for(int i=0;i<B;i++)
    {
    	v.push_back(i);
    }
    for(int i=B-2;i>0;i--)
    {
    	v.push_back(i);
    }
    //disp(v);
    int i=0,j=0;
    while(i<A.size())
    {
    	j=j%(v.size());
        x[v[j]]+=A[i];
        i++;
        j++;
    }
    string ans;
    for(int i=0;i<x.size();i++)
    {
        ans+=x[i];
    }
    //disp(x);
    return ans;
}

class Outer {
public:
  static int outer_x=100;
  class Inner {
  public:
    void display() {
      cout<<outer_x;
    }
  };
  void test() {
    Inner inner = new Inner();
    inner.display();
  }
};

int main() {
	Outer o=new Outer();
    o.test();
    //int a=1;
    //printf("%d%d%d",++a,a,a++);
    //cout<<convert("ABCD",2);
	return 0;
}