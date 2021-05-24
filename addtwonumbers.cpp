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

struct ListNode
{
	int val;
	ListNode * next;
};

ListNode * getnew(int val)
{
	ListNode * newn= new ListNode;
	newn->val=val;
	newn->next=NULL;
	return newn;
}

void disp(ListNode * root)
{
	ListNode * temp=root;
	while(temp)
	{
		cout<<"FUCK ";
		cout<<temp->val;
		temp=temp->next;
	}
}

int main(void) {
	ListNode * ans=getnew(0);
	ListNode * p=ans;
	for(int i=0;i<9;i++)
	{
		p->next=getnew(i);
		p=p->next;
	}
	disp(ans);
	return 0;
}