#include <iostream>
#include<vector>
using namespace std;
#define I 32786
struct Node
{
    int data;
    Node * left;
    Node *right;
} ;
Node * getnode(int data)
{
    Node * newn =new Node();
    newn->data=data;
    newn->left=newn->right=NULL;
    return newn;
}
void ino(Node * h)
{
    if(h)
    {
        ino(h->left);
        cout<<h->data<<" ";
        ino(h->right);
    }
}
struct node
{
    int cost, root;
};
int W(int * freq,int n,int s, int f)
{
    int sum=0;
    for(int i=s;i<f;i++)
    {
        sum+=freq[i];
    }
    return sum;
}
Node * head=NULL;
Node * optimal(vector<vector<node>> v,int s,int e)
{
    if(v[s][e].cost!=0)
    {
        head=getnode(v[s][e].root);
        cout<<v[s][e].root<<" \n";
        head->left=optimal(v,s,v[s][e].root-1);
        head->right=optimal(v,v[s][e].root,e);
    }
    return head;
}
void optimal_bst(int n, int * keys, int * freq)
{
    vector<vector<node>> v(n+1,vector<node> (n+1,{0,0}));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {

            if(i==j)
                v[i][j].cost=0;
            else
                v[i][j].cost=I;
        }
    }
    for(int l=0;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++)
        {
            int j=i+l;
            for(int k=i+1;k<=j;k++)
            {
                if(v[i][j].cost>v[i][k-1].cost+v[k][j].cost+W(freq,n,i,j))
                {
                    v[i][j].cost=v[i][k-1].cost+v[k][j].cost+W(freq,n,i,j);
                    v[i][j].root=k;
                }
            }
        }
    }
    Node * h=optimal(v,0,n);
    //ino(h);
    cout<<h->data<<" \n";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<v[i][j].cost<<v[i][j].root<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n=4;
    int *keys{new int[n]{10,20,30,40}}, *freq={new int[n]{4,2,6,3}};
    optimal_bst(n,keys,freq);
    return 0;
}
