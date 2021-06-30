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
	node * left, * right;
};

node * getnew_node(int val)
{
	node * newn=new node();
	newn->val=val;
	newn->left=newn->right=NULL;
	return newn;
}

node * insert(node* root, int val)
{
	if(root==NULL)
		return getnew_node(val);
	if(val>root->val)
		root->right=insert(root->right,val);
	else
		root->left=insert(root->left,val);
	return root;
}

void disp_in(node * root)
{
	if(root)
	{
		disp_in(root->left);
		disp_in(root->right);
		cout<<root->val<<" ";
	}
}

int height_of_bst(node * root)
{
	if(root==NULL)
		return -1;
	return max(height_of_bst(root->left),height_of_bst(root->right))+1;
}

void level_traversal(node * root)
{
	queue<node * > q;
	q.push(root);
	//cout<<root->val<<" ";
	while(!q.empty())
	{
		int nodecount=q.size();
		while(nodecount>0)
		{
			node * curr =q.front();
			cout<<curr->val<<" ";
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
			q.pop();
			nodecount--;
		}
		cout<<endl;
	}
}

void itr_pre(node * root)
{
	stack<node * > s;
	while(root or !s.empty())
	{
		if(root)
		{
			cout<<root->val<<" ";
			s.push(root);
			root=root->left;
		}
		else
		{
			root=s.top();
			s.pop();
			root=root->right;
		}
	}
}

int main(void) {
	cout<<"Hello Tree World\n";
	node * root=NULL;
	vector<int> v={23,1,4,3,2,78};
	for(int i=0;i<v.size();i++)
	{
		root=insert(root,v[i]);
	}
	cout<<"the postorder traversal of the tree is:\n";
	disp_in(root);
	cout<<"\nthe height of the tree is: "<<height_of_bst(root)<<endl;
	cout<<"the level traversal of the tree is:\n";
	level_traversal(root);
	cout<<"\nthe iterative preorder traversal is:\n";
	itr_pre(root);
	return 0;
}