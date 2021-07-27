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
	vector<node *> child;
	bool end;
	node()
	{
		this->end=false;
		for(int i=0;i<26;i++)
			(this->child).push_back(NULL);
	}
};

node * insert_node(node * root, string s)
{
	node * temp=root;
	for(int i=0;i<s.size();i++)
	{
		int x=s[i]-'a';
		if(temp->child[x]==NULL)
		{
			temp->child[x]=new node();
			temp=temp->child[x];
		}
	}
	temp->end=true;
	return root;
}

void search_trie(node * root,string s)
{
	node * temp=root;
	for(int i=0;i<s.size();i++)
	{
		int x=s[i]-'a';
		if(temp->child[x]!=NULL)
		{
			if(temp->child[x]->end==true)
			{
				cout<<"word found\n";
				return;
			}
			temp=temp->child[x];
		}
		else
		{
			cout<<"word not exist\n";
			return;
		}
	}
	cout<<"word not exist\n";
	return;
}

void bfs(node * root)
{
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node * curr=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(curr->child[i])
			{
				cout<<(char)('a'+i)<<" ";
				q.push(curr->child[i]);
			}
		}
	}
	cout<<endl;
}

int main(void) {
	/*vector<string> v={"abc","abgl","cdf","abcd","lmn"};
	node * root=new node();
	for(int i=0;i<v.size();i++)
	{
		root=insert_node(root,v[i]);
	}
	cout<<endl;
	bfs(root);
	search_trie(root,"lm");
	*/
	vector<string> v={"echo dot second generation","echo show", "kindle book"};
	sort(v.begin(), v.end());
	disp(v);
	return 0;
}