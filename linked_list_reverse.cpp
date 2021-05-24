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

struct node{
  int val;
  node * next;
};

node* getnew_node(int value)
{
	node * newn=new node();
	newn->val=value;
	newn->next=NULL;
	return newn;
}

node * head=NULL;

void make_list(vector<int> v)
{
	//cout<<"0";
	head=getnew_node(v[0]);
	node * temp=head;
	for(int i=1;i<v.size();i++)
	{
		temp->next=getnew_node(v[i]);
		temp=temp->next;
	}
}

void display()
{
	node * temp=head;
	while(temp)
	{
		cout<<temp->val<<" ";
		temp=temp->next;
	}
}

void reverse()
{
	stack<node *> s;
	node * temp=head;
	while(temp->next)
	{
		s.push(temp);
		temp=temp->next;
	}
	head =temp;
	while(!s.empty())
	{
		temp->next=s.top();
		temp=temp->next;
		s.pop();
	}
	temp->next=NULL;
	display();
}

void reverse_1()
{
	node * curr=head;
	node * prev=NULL;
	node * Next=NULL;
	while(curr)
	{
		Next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=Next;
	}
	head=prev;
	display();
}

void sol(vector<int> v)
{
	sort(v.begin(),v.end());
	for(int i=1;i<v.size()-1;i+=2)
		swap(v[i],v[i+1]);
	disp(v);
}

int main(void) {
	vector<int> v={1,2,3,4,5,6,7,8};
	make_list(v);
	display();
	cout<<endl;
	reverse_1();
	/*reverse();
	cout<<endl;
	sol(v);*/
	//display();
	return 0;
}