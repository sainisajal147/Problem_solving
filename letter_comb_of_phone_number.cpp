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

vector<string> letterCombinations(string digits) {
     map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        int n=digits.size();
        vector<string> ans;
        if(n==0)
            return ans;
        else if(n==1)
        {
            string t1=m[digits[0]];
            for(int i=0;i<t1.size();i++)
            {
                string x="";
                x+=t1[i];
                ans.push_back(x);
            }
        }
        else if(n==2)
        {
            string t1=m[digits[0]],t2=m[digits[1]];
            for(int i=0;i<t1.size();i++)
            {
                for(int j=0;j<t2.size();j++)
                {
                    string x="";
                    x+=t1[i];
                    x+=t2[j];
                    ans.push_back(x);
                }
            }
        }
        else if(n==3)
        {
            string t1=m[digits[0]],t2=m[digits[1]],t3=m[digits[2]];
            for(int i=0;i<t1.size();i++)
            {
                for(int j=0;j<t2.size();j++)
                {
                    for(int k=0;k<t3.size();k++)
                    {
                        string x="";
                        x+=t1[i];
                        x+=t2[j];
                        x+=t3[k];
                        ans.push_back(x);
                    }
                }
            }
        }
        else if(n==4)
        {
            string t1=m[digits[0]],t2=m[digits[1]],t3=m[digits[2]],t4=m[digits[3]];
            for(int i=0;i<t1.size();i++)
            {
                for(int j=0;j<t2.size();j++)
                {
                    for(int k=0;k<t3.size();k++)
                    {
                        for(int l=0;l<t4.size();l++)
                        {
                            string x="";
                            x+=t1[i];
                            x+=t2[j];
                            x+=t3[k];
                            x+=t4[l];
                            ans.push_back(x);
                        }
                    }
                }
            }
        }
        return ans;
    }

int main(void) {
	int a[10]={1,2,3,4,5};
	char st1[]="abcd";
	char st2[]="abcd";
	if(st1==st2)
		cout<<"sd";
	else
		cout<<"dsa";
	int c=2.8;
	cout<<c<<endl;
	//disp(letterCombinations("234"));
	return 0;
}