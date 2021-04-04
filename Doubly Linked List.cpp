#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value)
    {
        data=value;
        prev=NULL;
        next=prev;
    }
};



void insertatthehead(Node* &head,int value)
{
    Node* new_node = new Node(value);
    if(head!=NULL)new_node->next=head;
    head=new_node;

}

void insertintheend(Node* &head,int value)
{
    if(head==NULL)
    {
        insertatthehead(head,value);
        return;
    }

    Node* new_node = new Node(value);
    Node* temp = head;
    while(temp->next!=NULL)
    {
         temp=temp->next;
    }
    temp->next = new_node;
    new_node->prev=temp;
}

void displaylist(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

main()
{

    Node* head=NULL;
    //Insert in the tail
    insertintheend(head,1);
    insertintheend(head,2);
    insertintheend(head,3);
    insertintheend(head,4);
    insertintheend(head,5);

    //Insert in the front
    insertatthehead(head,0);
    insertatthehead(head,-1);
    insertatthehead(head,-2);
    insertatthehead(head,-3);

    //Print all value
    cout<<"Linked list: ";
    displaylist(head);
    cout<<endl;
}
