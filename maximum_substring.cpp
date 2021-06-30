
// Sample code to perform I/O:

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
#include<stdio.h>
#include<conio.h>
using namespace std;

/*int a[106][106]={0};

int num(string txt,int l, int r)
{
	string pat;
	for(int i=l;i<=r;i++)
	{
		pat+=txt[i];
	}
	int M = pat.length(); 
    int N = txt.length(); 
    int res = 0; 
    
     A loop to slide pat[] one by one 
    for (int i = 0; i <= N - M; i++) 
    {  
        /* For current index i, check for  
           pattern match 
        int j; 
        for (j = 0; j < M; j++) 
            if (txt[i+j] != pat[j]) 
                break; 
   
        // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
        if (j == M)   
        { 
           res++; 
           j = 0; 
        } 
    } 
    return res; 
	//cout<<strstr(s1,s2);
	//int ans=0;
	//cout<<sub;
	/*while(ptr!=NULL)
	{
		ans++;
		ptr=strstr(ptr+1,sub);
	}
	/*cout<<sub<<endl;
	for(int i=0;i<s.size();i++)
	{
		int j=0,k=i;
		while(sub[j]==s[k])
		{
			j++;
			k++;
		}
		if(j==sub.size())
		{
			ans++;
		}
	}
	//return ans;
}*/
int main() {
	string s;
	getline(cin,s);
	//cout<<num(s,0,0);
	int n=s.size();
	vector<int> v(26,0);
	for(int i=0;i<n;i++)
	{
		v[s[i]-'a']++;
	}
	int m=0;
	string sub;
	for(int i=0;i<n;i++)
	{
		if(m<v[s[i]-'a'])
		{
			m=v[s[i]-'a'];
			//sub+=s[i];
		}
	}
	//cout<<sub;
	string same;
	for(int i=0;i<n;i++)
	{
		int x=same.find(s[i]);
		if(v[s[i]-'a']==m and x==string::npos)
			same+=s[i];
	}
	//cout<<same<<endl;
	//vector<int> x;
	sub+=same[0];
	for(int i=1;i<same.size();i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
		{
			if(same[i]==s[j] and s[j-1]==sub[sub.size()-1])
			{
				count++;
			}
		}
		if(count==m)
		{
			sub+=same[i];
		}
		else
			break;
	}
	cout<<sub;
	/*for(int i=0;i<x.size();i++)
	{
		cout<<char(i+'a');
	}
	cout<<endl;*/
	//int a[n][n]={0};
	/*int nu=0,si=0,l=0,r=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			a[i][j]=num(s,i,j);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(nu<a[i][j])
			{
				nu=a[i][j];
				l=i,r=j;
				si=j-i;
			}
			else if(nu==a[i][j] and si<j-i)
			{
				nu=a[i][j];
				l=i,r=j;
				si=j-i;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	string sub;
	for(int i=l;i<=r;i++)
	{
		sub+=s[i];
	}
	cout<<sub<<endl;*/
	return 0;
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
