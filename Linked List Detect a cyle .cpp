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

//Make cycle
void makecircle(Node* &head,int num)
{
    int cnt = 1;

    Node* startptr;
    Node* temp=head;

    while(temp->next!=NULL)
    {
        if(num==cnt)startptr=temp->next;
        cnt++;
        temp=temp->next;
    }

    temp->next = startptr;
}

int detectcycle(Node* &head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast->next->next!=NULL and fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)return 1;
    }

    return 0;
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
    insertend(head,6);

    //Inset int he beginning
    insertstart(head,0);
    insertstart(head,-1);
    insertstart(head,-2);

    //Print
    cout<<"Print"<<" ";
    printlinkedlist(head);


     //Detect cycle using hear and tortoise/Floyed's Algorithms
    int c = detectcycle(head);
    string s = c==0?"No Cycle !\n":"Cycle Detected!\n";
    cout<<s<<endl<<"Making cycle in 2nd Position"<<endl;

    //Make cycle in linked list
    //First inert a position number where you want to make circle
    makecircle(head,2);

    c = detectcycle(head);
    s = c==0?"No Cycle !\n":"Cycle Detected!\n";
    cout<<s<<endl;
    //if we remove comment in last line it will running in infinite time as it has cycle
    //printlinkedlist(head);

}










