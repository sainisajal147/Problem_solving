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

node * get_new_node(int val)
{
	node * newn=new node();
	newn->val=val;
	newn->next=NULL;
	return newn;
}

void disp(node * root)
{
	/*node * temp=root;
	while(temp)
	{
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl;*/
	if(!root)
		return;
	cout<<root->val<<" ";
	disp(root->next);
}

node * insert_in_linked_list(node * root,int val)
{
	if(root==NULL)
	{
		return get_new_node(val);
	}
	node * temp=root;
	while(temp->next)
	{
		temp=temp->next;
	}
	temp->next=get_new_node(val);
	return root;
}

node * reverse_linked_list(node * root)
{
	node * curr, * nex, * prev;
	nex=NULL;
	curr=root;
	while(curr)
	{
		nex=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nex;
	}
	root=prev;
	return root;
}

node * reverse_rec(node * root)
{
	if(root==NULL or root->next==NULL)
	{
		return root;
	}
	node * temp=reverse_rec(root->next);
	root->next->next=root;
	root->next=NULL;
	return temp;
}

int main(void) {
	cout<<"Hello linked list World!\n";
	node * root=NULL;//=get_new_node(0);
	for(int i=23;i<30;i++)
	{
		root=insert_in_linked_list(root,i);
	}
	cout<<"the formed linked list is: \n";
	disp(root);
	cout<<endl;
	root=reverse_rec(root);
	disp(root);
	/*cout<<"\nthe reversed print linked list is: \n";
	for(int i=7;i>=1;i--)
	{
		node * temp=root;
		for(int j=0;j<i-1;j++)
		{
			temp=temp->next;
		}
		cout<<temp->val<<" ";
	}
	cout<<endl;
	root=reverse_linked_list(root);
	disp(root);*/
	return 0;
}