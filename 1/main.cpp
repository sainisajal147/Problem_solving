
#include <iostream>
struct node{
int data;
node * next;
};
int INSERT(node * head, int data)
{
    node* newn=new node();
    newn->data=data;
    newn->next=NULL;
    if(head==NULL)
        head=newn;
    while(head!=NULL)
        head=head->next;
    head->next=newn;
    return head;
}

int main()
{
    int n;
    cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    node *list;
    for(int i=0;i<5;i++)
    {
        int item;
        cin>>item;
        INSERT(list,item);
    }
    return 0;
}
