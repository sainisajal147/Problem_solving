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

struct node{
  int key;
  node * next;
  node * prev;
  node(int key):key(key),next(NULL),prev(NULL){}
};

void disp(node * root)
{
    node * temp=root;
    while(temp)
    {
        cout<<temp->key<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void disp_rev(node * root)
{
    node * temp=root;
    while(temp->next)
        temp=temp->next;
    while(temp)
    {
        cout<<temp->key<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}

int capacity_global=0,Size_global=0;
map<int,int> map_key;
node * Start; 
void LRUCache(int capacity) {
    capacity_global=capacity;
    Size_global=0;
    Start=NULL;
}

int Get(int key) {
    if(capacity_global==1)
    {
        if(Start->key==key)
            return map_key[key];
        else
            return -1;
    }
    node * tail=Start;
    while(tail->next)
        tail=tail->next;
    node * to_search=Start;
    if(Start->key==key)
    {
        node * to_move=Start;
        Start=Start->next;
        Start->prev=NULL;
        tail->next=to_move;
        to_move->prev=tail;
        to_move->next=NULL;
        return map_key[key];
    }
    while(to_search)
    {
        if(to_search->key==key)
        {
            //cout<<"yes found\n";
            if(to_search==tail)
                return map_key[key];
            to_search->prev->next=to_search->next;
            to_search->next->prev=to_search->prev;
            to_search->prev=tail;
            tail->next=to_search;
            to_search->next=NULL;
            return map_key[key];
        }
        to_search=to_search->next;
    }
    return -1;
}

void Set(int key, int value) {
    if(capacity_global==1)
    {
        map_key[key]=value;
        Start=NULL;
        Start=new node(key);
        return;
    }
    if(map_key.find(key)==map_key.end())
    {
        map_key[key]=value;
        Size_global++;
        //cout<<"Size_global= "<<Size_global<<endl;
        if(Size_global>capacity_global)
        {
            //cout<<"Size_global>capacity_global : \n";
            while(Size_global>capacity_global)
            {
                node * LeastUsed=Start;
                Start=Start->next;
                Start->prev=NULL;
                map_key.erase(LeastUsed->key);
                delete LeastUsed;
                Size_global--;
            }
        }
        if(Size_global<=capacity_global)
        {
            if(Start==NULL)
            {
                Start=new node(key);
                Size_global=1;
            }
            else
            {
                node * to_point=Start;
                while(to_point->next)
                    to_point=to_point->next;
                node * new_node=new node(key);
                to_point->next=new_node;
                new_node->prev=to_point;
                to_point=to_point->next;
            }
        }
    }
    else
    {
        map_key[key]=value;
        int temp=Get(key);
        return;
    }
}

int main(void) {
    LRUCache(1);
    Set(1,10);
    Set(5,12);
    cout<<Get(5)<<endl;
    cout<<Get(1)<<endl;
    cout<<Get(10)<<endl;
    Set(6,14);
    //disp(Start);
    cout<<Get(5)<<endl;
    return 0;
}