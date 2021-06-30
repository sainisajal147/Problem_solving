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

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void disp(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
TreeNode * Insert(vector<int> A,TreeNode * root)
{
	if(A.empty())
		return NULL;
	if(A.size()==1)
	{
		TreeNode * temp=new TreeNode(A[0]);
        return temp;
	}
    int m=*max_element(A.begin(),A.end());
    vector<int> t1,t2;
    bool f=false;
    for(int i=0;i<A.size();i++)
    {
    	if(A[i]==m)
    	{
    		f=true;
			continue;
		}
		if(f)
		{
			t2.push_back(A[i]);
		}
		else
		{
			t1.push_back(A[i]);
		}
    }
    root=new TreeNode(m);
    root->left=Insert(t1,root->left);
    root->right=Insert(t2,root->right);
    return root;
}
TreeNode* buildTree(vector<int> &A) {
    TreeNode * root=NULL;
    return root;
}
void ino(TreeNode * A)
{
	if(A)
	{
		ino(A->left);
		cout<<A->val;
		ino(A->right);
	}
}
int main() {
	vector<int> v={1,2,5,3};
	TreeNode * root=NULL;
	root=Insert(v,root);
	ino(root);
	return 0;
}