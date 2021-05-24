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

int ato(string A) {
    string s;
    int i=0;
    while(A[i]!=' ' and i<A.size())
    {
        s+=A[i];
        i++;
    }
    int ans=0;
    if(s[0]=='+' or s[0]=='-')
    {
    	int k=0;
    	for(;k<s.size();k++)
    	{
    		if(s[k]=='-' or s[k]=='+')
    			continue;
    		else
    			break;
    	}
    	char sym=s[0];
    	string sub;
    	for(int j=k;j<s.size();j++)
    	{
    		//cout<<s[j];
    		if(s[j]>='0' and s[j]<='9')
    			sub+=s[j];
    		else
    			break;
    	}
    	//cout<<sub<<endl;
        for(int j=sub.size()-1;j>=0;j--)
        {
            if(ans+pow(10,sub.size()-j-1)*(sub[j]-'0')>INT_MAX)
            {
            	if(sym=='+')	
                	return INT_MAX;
                else
                	return INT_MIN;
            }
            else
                ans+=pow(10,sub.size()-j-1)*(sub[j]-'0');
        }
        if(sym=='+')
        return ans;
        else
        return -ans;
    }
    else
    {
    	string sub;
    	for(int j=0;j<s.size();j++)
    	{
    		//cout<<s[j];
    		if(s[j]>='0' and s[j]<='9')
    			sub+=s[j];
    		else
    			break;
    	}
    	//cout<<sub<<endl;
        for(int j=sub.size()-1;j>=0;j--)
        {
            if(ans+pow(10,sub.size()-j-1)*(sub[j]-'0')>INT_MAX)
            {
                return INT_MAX;
            }
            else
                ans+=pow(10,sub.size()-j-1)*(sub[j]-'0');
        }
        return ans;
    }
}


int main() {
	cout<<ato("-A26626 445569J260714W5 9 2 59 11 52C401");
	return 0;
}