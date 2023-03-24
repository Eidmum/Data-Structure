#include<bits/stdc++.h>
using namespace std;
typedef struct Node node;
node* create_node(int v);
void print_node(node *n);
void print_node_address(node *n);
void print_list(node *head);
bool is_Empty(node *n);
int list_size(node *head);
int first(node *head);
node* Begin(node *head);
int last_node(node *head);
node* End(node *head);
node* address_of(node *head,int key);
void update(node *head, int key, int newValue);
node* Delete(node *head,int key);
node* insert_back(node *head,int key);
node* insert_front(node *head,int key);
node* insert_before(node* head,int key,int newValue);
node* insert_after(node* head,int key,int newValue);
struct Node
{
    int value;
    node *next;
};
int main()
{
    node *head=NULL,*a=NULL,*b=NULL,*c=NULL,*d=NULL;
    a=create_node(1);
    b=create_node(2);
    c=create_node(3);
    d=create_node(4);
    d->next=c;
    c->next=b;
    b->next=a;
    //head=d;
    print_list(head);
    head=insert_after(head,100,65);
    print_list(head);

    return 0;
}
node* create_node(int v)
{
    node* new_node=NULL;
    new_node=(node*)malloc(sizeof(node));
    new_node->value=v;
    new_node->next=NULL;
    return new_node;

}
void print_node(node *n){
    cout<<n->value<<endl;

}
void print_node_address(node *n){
    cout<<n->value<<" "<<n->next<<endl;

}
void print_list(node *head)
{
    node* temp=head;
    if(is_Empty(temp))
    {
        cout<<"List is Empty."<<endl;
        return;
    }
    while(temp)
    {
        cout<<temp->value<<endl;
        temp=temp->next;

    }

}
bool is_Empty(node *n)
{
    if(n==NULL)
        return true;
    else
        return false;
}
int list_size(node *head)
{
    node *temp;
    temp=head;
    if(is_Empty(temp))
    {
        return 0;
    }
    int cnt=0;
    while(temp)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
int first(node *head)
{
    if(is_Empty(head))
    {
        return -1;
    }
    return head->value;
}
node* Begin(node *head)
{
    if(is_Empty(head))
    {
        return NULL;
    }
    return head;
}
int last_node(node *head)
{
    if(is_Empty(head))
        return -1;
    node *temp=head;
    node *previous=head;
    while(temp)
    {
        previous=temp;
        temp=temp->next;
    }
    return previous->value;
}
node* End(node *head)
{
    if(is_Empty(head))
        return NULL;
    node *temp=head;
    node *previous=head;
    while(temp)
    {
        previous=temp;
        temp=temp->next;
    }
    return previous;
}
node* address_of(node *head,int key)
{
    node *temp=head;
    while(temp)
    {
        if(temp->value==key)
        {
            return temp;
        }

        temp=temp->next;
    }
    return NULL;
}
void update(node *head, int key, int newValue)
{
    node *temp=head;
    while(temp)
    {
        if(temp->value==key)
            temp->value=newValue;
        temp=temp->next;
    }
}
node* Delete(node *head,int key)
{
    node* temp=head;
    node* prev=head;
    if(is_Empty(temp))
        return NULL;
    if(temp->value==key)
    {
        head=head->next;
        free(temp);
        return head;
    }
    while(temp)
    {   if(temp->value==key)
            {
                prev->next=temp->next;
                free(temp);
                return head;
            }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
node* insert_back(node *head,int key)
{
    node* temp=head;
    node* newNode=head;
    node* last=head;
    if(is_Empty(temp))
     {
        newNode=create_node(key);
        return newNode;
     }
     newNode=create_node(key);
     last=End(temp);
     last->next=newNode;
     return temp;
}
node* insert_front(node *head,int key)
{
   node* temp=head;
   node* newNode=head;
   if(is_Empty(temp))
   {
       newNode=create_node(key);
       return newNode;
   }
   newNode=create_node(key);
   newNode->next=temp;
   return newNode;

}
node* insert_before(node* head,int key,int newValue)
{
    node* temp=head;
    node* prev=head;
    node* newNode=head;
    if(is_Empty(temp))
        return NULL;
    if(temp->value==key)
    {
        newNode=create_node(newValue);
        newNode->next=temp;
        return newNode;
    }
    while(temp)
    {
        if(temp->value==key)
        {
            newNode=create_node(newValue);
            newNode->next=prev->next;
            prev->next=newNode;
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;

}
node* insert_after(node* head,int key,int newValue)
{
    node* temp=head;
    node* newNode=head;
    while(temp)
    {
        if(temp->value==key)
        {
            newNode=create_node(newValue);
            newNode->next=temp->next;
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
