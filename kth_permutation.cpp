/*
AUTHOR : SAJAL SAINI
*/
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

template <class t>
void disp(vector<vector<t>> v)
{
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

template <class t>
void disp(vector<t> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int temp=0;
void permut(string &s, int l,int k,string &ans)
{
    
    if(l==s.size())
    {
        temp++;
        ans.clear();
        if(temp==k)
            ans=s;
        cout<<temp<<" th value "<<s<<endl;
        return;  
    }
    /*if(temp>=k)
    	return;*/
    for(int i=l;i<s.size();i++)
    {
        swap(s[i],s[l]);
        permut(s,l+1,k,ans);
        swap(s[i],s[l]);
    }
}
string getPermutation(int A, int B) {
    string s="",ans="";
    for(char i='1';i<'1'+A;i++)
        s+=i;
    //cout<<s<<" ";
    temp=0;
    ans.clear();
    do{
        temp++;
        //cout<<s<<endl;
        if(temp==B)
            ans=s;
    }while(next_permutation(s.begin(), s.end()));
    //permut(s,0,B,ans);
    return ans;
}

int main(void) {
	cout<<getPermutation(3,5);
	return 0;
}