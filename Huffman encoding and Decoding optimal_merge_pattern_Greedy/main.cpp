//Huffman coding means the tree formation and decoding means to decode the tree
#include <iostream>
#include<map>
#include<string>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
    char ch;
    int freq;
    node * right;
    node * left;
};
bool comp(node * a, node * b)
{
    return a->freq<b->freq;
}
node * getnew(int freq)
{
    node * newn=new node();
    newn->freq=freq;
    newn->ch='\0';
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}
node * getnew(int freq,char ch)
{
    node * newn=new node();
    newn->freq=freq;
    newn->ch=ch;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}
void Merge(node * &head, node *a,node *b)
{
    head->left=a;
    head->right=b;
    head->freq=a->freq+b->freq;
    head->ch='\0';
}
void disp(vector<node*> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]->ch<<" "<<v[i]->freq<<endl;
    }
    cout<<endl;
}
void huffman(vector<node *> &v)
{
    while(v.size()>1)
    {
        sort(v.begin(),v.end(),comp);
        //disp(v);
        node * temp=getnew(0);
        Merge(temp,v[0],v[1]);
        v.push_back(temp);
        v.erase(v.begin());
        v.erase(v.begin());
    }
}
void inorder(node * head)
{
    if(head)
    {
        inorder(head->left);
        cout<<head->ch<<" "<<head->freq<<endl;
        inorder(head->right);
    }
}
int main()
{
    string s="ABBCDBCCDAABBEEEBEAB";
    map<char,int> m;
    int n=s.size();
    vector<node *> v;
    for(int i=0;i<n;i++)
    {
        m[s[i]]++;
    }
    map<char,int> ::iterator p=m.begin();
    while(p!=m.end())
    {
        v.push_back(getnew(p->second,p->first));
        p++;
    }
    huffman(v);
    inorder(v[0]);
    cout<<endl;
    disp(v);
    return 0;
}
