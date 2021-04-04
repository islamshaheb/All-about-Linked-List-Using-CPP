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


int main()
{
    Node* head=NULL;

    //Inset int he beginning
    insertstart(head,0);
    insertstart(head,1);
    insertstart(head,2);
    insertstart(head,3);
    insertstart(head,-1);
    insertstart(head,-2);

    //Print
    cout<<"Print"<<": ";
    printlinkedlist(head);


}

