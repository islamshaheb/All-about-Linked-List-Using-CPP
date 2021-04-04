#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next = NULL;
    }

};
int i =0;

//Insert in the end
void insertend(Node* &head,int value)
{
    Node* new_node = new Node(value);
    if(head==NULL)
    {
        head=new_node;
        return;
    }
    Node* temp = head;
    //cout<<temp->next<<" "<<i++<<endl;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = new_node;

}


// Insert in the beginning
void insertstart(Node* &head,int value)
{
    Node* new_node = new Node(value);
    if(head==NULL)
    {
        head=new_node;
        return;
    }

    new_node->next=head;
    head=new_node;

}


//display the linked list
void printlinkedlist(Node* &head)
{

    Node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}



//Revers linked list using recursion

Node* reverserec(Node* &head)
{
    if(head==NULL or head->next==NULL) return head;
    Node* curhead = reverserec(head->next);
    head->next->next=head;
    head->next=NULL;
    return curhead;
}

int main()
{
    Node* head=NULL;
    //Insert in the End
    insertend(head,1);
    insertend(head,2);
    insertend(head,3);
    insertend(head,4);
    insertend(head,5);
    insertend(head,6);
    insertend(head,6+1);

    //Insert int he beginning
    insertstart(head,0);
    insertstart(head,-1);
    insertstart(head,-2);

    //Print
    cout<<"Linked list before reversing"<<" ";
    printlinkedlist(head);


    // Reverse Linked List using recursion
    Node* new_head = reverserec(head);


     //Print
    cout<<"Print after reverse "<<" ";
    printlinkedlist(new_head);
}

