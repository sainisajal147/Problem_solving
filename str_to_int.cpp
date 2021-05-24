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

bool isvalid(char ch)
    {
        string sub="+-1234567890";
        for(int i=0;i<sub.size();i++)
        {
            if(sub[i]==ch)
                return true;
        }
        return false;
    }
    int myAtoi(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                continue;
            else if(isvalid(s[i]))
                break;
            else
                return 0;
        }
        map<char,int> m;
        m['+']=m['-']=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                continue;
            else if(s[i]=='+' or s[i]=='-')
                m[s[i]]++;
            else
                break;
        }
        if(m['+'] and m['-'])
            return 0;
        if(m['+']>1 or m['-']>1)
            return 0;
        bool sign=true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                continue;
            else if(isvalid(s[i]) and s[i]!='+' and s[i]!='-')
                break;
            else
            {
                if(s[i]=='-')
                {
                    sign=false;
                    if(i+1<s.size())
                    {
                        if(!isvalid(s[i+1]))
                            return 0;
                    }
                    break;
                }
                else if(s[i]=='+')
                {
                    if(i+1<s.size())
                    {
                        if(!isvalid(s[i+1]))
                            return 0;
                    }
                    break;
                }
            }
        }
        vector<char> v;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]==' ' or s[i]=='+' or s[i]=='-' ) and v.empty())
                continue;
            else if(isvalid(s[i]) and s[i]!='+' and s[i]!='-')
                v.insert(v.begin(),s[i]);
            else
                break;
        }
        long long int ans=0;
        long long int mul=1;
        vector<char> vi;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i]=='0' and vi.empty())
                continue;
            else
                vi.insert(vi.begin(),v[i]);
        }
        for(int i=0;i<vi.size();i++)
        {
            int temp=vi[i]-'0';
            ans+=temp*mul;
            if(mul>INT_MAX)
            {
                if(sign)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            mul=mul*10;
        }
        if(!sign)
            ans=-ans;
        if(ans<INT_MIN)
            return INT_MIN;
        if(ans>INT_MAX)
            return INT_MAX;
        return ans;
    }

int main(void) {
	cout<<myAtoi("00000-42a1234");
	return 0;
}