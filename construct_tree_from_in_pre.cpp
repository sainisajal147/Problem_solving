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

TreeNode* make_tree(vector<int> &A, vector<int> &B,int starta,int enda,int startb,int endb)
{
	if(startb>endb)
		return NULL;
    TreeNode * node=new TreeNode(A[starta]);
    cout<<node->val<<" ";
    int als,ale,bls,ble,ars,are,brs,bre;
    int rootin=-1;
    for(int i=startb;i<=endb;i++)
    {
      	if(B[i]==node->val)
       	{
       		rootin=i;
       		break;
       	}
    }
    als=starta+1;
    bls=startb;
    ble=rootin-1;
    ale=ble-bls+als;
    ars=ale+1;//
    are=enda;
    brs=rootin+1;
    bre=endb;
    //cout<<als<<ale<<bls<<ble<<ars<<are<<brs<<bre<<endl;
    node->left=make_tree(A,B,als,ale,bls,ble);
    node->right=make_tree(A,B,ars,are,brs,bre);
    return node;
}
TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    TreeNode * ans=make_tree(A,B,0,A.size()-1,0,B.size()-1);
    return ans;
}

int main(void) {
	vector<int> v1={4,7,9,6,3,2,5,8,1},v2={7,6,9,3,4,5,8,2,1};
	TreeNode * ans=buildTree(v1,v2);
	cout<<ans->val;
	return 0;
}