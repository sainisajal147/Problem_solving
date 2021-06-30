/*
AUTHOR : SAJAL SAINI
*/
#include <bits/stdc++.h>

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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void ino(TreeNode * root,vector<int> &ans)
{
	if(root)
	{
		ino(root->left,ans);
		ans.push_back(root->val);
		ino(root->right,ans);
	}
}

void pre(TreeNode * root,vector<int> &ans)
{
	if(root)
	{
		ans.push_back(root->val);
		pre(root->left,ans);
		pre(root->right,ans);
	}
}

void post(TreeNode * root)
{
	if(root)
	{
		post(root->left);
		post(root->right);
		cout<<root->val<<" ";
	}
}

TreeNode * add_node(TreeNode* root,int val)
{
	if(root==NULL)
	{
		TreeNode * newn=new TreeNode(val);
		return newn;
	}
	if(root->val>val)
	{
		root->left=add_node(root->left,val);
	}
	else
		root->right=add_node(root->right,val);
	return root;
}
TreeNode * Make_tree(vector<int> v)
{
	TreeNode * root=NULL;
	for(int i=0;i<v.size();i++)
		root=add_node(root,v[i]);
	return root;
}
vector<TreeNode*> generateTrees(int A) {
    vector<int> v;
    vector<TreeNode *> ans;
    for(int i=1;i<=A;i++)
        v.push_back(i);
    map<vector<vector<int>>,int> m;
    do{
    	TreeNode * temp=Make_tree(v);
    	vector<vector<int>> temp_vec(2);
    	ino(temp,temp_vec[0]);
    	pre(temp,temp_vec[1]);
    	if(m[temp_vec]==0)
    	{
    		ans.push_back(temp);
    		m[temp_vec]=1;
    	}
    }while(next_permutation(v.begin(), v.end()));
    return ans;
}

int main(void) {
	vector<TreeNode *> A=generateTrees(3);
	return 0;
}