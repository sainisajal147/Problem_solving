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

int cnttrue(string A) {
	string exp="",op="";
	for(int i=0;i<A.size();i++)
	{
		if(A[i]=='&' or A[i]=='|' or A[i]=='^')
			op+=A[i];
		else
			exp+=A[i];
	}
	cout<<op<<" "<<exp<<endl;
    vector<vector<int>> vt(exp.size(),vector<int> (exp.size(),0)),vf(exp.size(),vector<int> (exp.size(),0));
    /*map<char,bool> m;
    m['T']=true,m['F']=false;*/
    for(int i=0;i<exp.size();i++)
    {
    	if(exp[i]=='T')
    		vt[i][i]=1;
    	else
    		vf[i][i]=1;
    }
    /*for(int i=0;i<exp.size()-1;i++)
    {
    	if(op[i]=='&')
    	{
    		vt[i][i+1]=m[exp[i]]&m[exp[i+1]];
    		vf[i][i+1]=!vt[i][i+1];
    	}
    	else if(op[i]=='|')
    	{
    		vt[i][i+1]=m[exp[i]]|m[exp[i+1]];
    		vf[i][i+1]=!vt[i][i+1];
    	}
    	else if(op[i]=='^')
    	{
    		vt[i][i+1]=m[exp[i]]^m[exp[i+1]];
    		vf[i][i+1]=!vt[i][i+1];
    	}
    }*/
    for(int i=1;i<exp.size();i++)
    {
    	for(int j=0;j+i<exp.size();j++)
    	{
    		int r=j,c=i+j;
    		for(int k=r;k<c;k++)
    		{
    			int ltc=vt[r][k],rtc=vt[k+1][c],lfc=vf[r][k],rfc=vf[k+1][c];
    			cout<<"for i= "<<i<<" ltc = "<<ltc<<" rtc= "<<rtc<<" lfc= "<<lfc<<" rfc= "<<rfc<<endl;
    			if(op[k]=='&')
    			{
    				vt[r][c]+=ltc*rtc;
    				vf[r][c]+=ltc*rfc+lfc*rtc+lfc*rfc;
    			}
    			else if(op[k]=='^')
    			{
    				vt[r][c]+=ltc*rfc+lfc*rtc;
    				vf[r][c]+=ltc*rtc+lfc*rfc;	
    			}
    			else if(op[k]=='|')
    			{
    				vt[r][c]+=ltc*rtc+lfc*rtc+ltc*rfc;
    				vf[r][c]+=lfc*rfc;
    			}
    		}
    	}
    }
    disp(vt);
    cout<<endl;
    disp(vf);
    return vt[0].back();
}


int main(void) {
	//cout<<cnttrue("F|T^T&F");
	cout<<cnttrue("T^T^T^F|F&F^F|T^F^T");
	return 0;
}