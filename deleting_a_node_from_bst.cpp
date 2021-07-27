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
	node * left;
	node * right;
	node(int val):val(val),left(NULL),right(NULL){}
};

void inorder(node * root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}

int findmin(node * root)
{
	int ans=root->val;
	while(root)
	{
		ans=root->val;
		root=root->left;
	}
	return ans;
}

node * Delete(node * root,int val)
{
	if(root==NULL)
		return root;
	else if(root->val>val)
	{
		root->left=Delete(root->left,val);
	}
	else if(root->val<val)
	{
		root->right= Delete(root->right,val);
	}
	else
	{
		if(root->left==NULL and root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		else if(root->left==NULL and root->right!=NULL)
		{
			node *temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->left!=NULL and root->right==NULL)
		{
			node *temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		else
		{
			int min_in_right=findmin(root->right);
			root->val=min_in_right;
			root->right=Delete(root->right,min_in_right);
		}
	}
	return root;
}

int main(void) {
	node * root=new node(6);
	root->left=new node(4);
	root->right=new node(8);
	root->left->left=new node(1);
	root->left->right=new node(5);
	root->right->left=new node(7);
	root->right->right=new node(10);
	inorder(root);
	cout<<endl;
	root=Delete(root,1);
	inorder(root);
	cout<<endl;
	root=Delete(root,4);
	inorder(root);
	cout<<endl;
	root=Delete(root,8);
	inorder(root);	
	return 0;
}