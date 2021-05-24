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

struct node
{
	char ch;
	node * child[26];
	bool end;
};

node * getnew(char ch)
{
	node * newn=new node();
	newn->ch=ch;
	newn->end=false;
	for(int i=0;i<26;i++)
	{
		(newn->child)[i]=NULL;
	}
	return newn;
}

node * insert_node(node * root, string s)
{
	node * temp=root;
	for(int i=0;i<s.size();i++)
	{
		int x=s[i]-'a';
		if(!temp->child[x])
		{
			temp->child[x]=getnew(s[i]);
			temp=temp->child[x];
		}
	}
	temp->end=true;
	return root;
}


int main(void) {
	vector<string> v={"abc","abgl","cdf","abcd","lmn"};
	//disp(v);
	node * root = new node();
	root->end=false;
	root=insert_node(root,"abc");
	root=insert_node(root,"cdf");
	for(int i=0;i<26;i++)
	{
		if(root->child[i])
			cout<<root->child[i]->ch;
	}
	return 0;
}