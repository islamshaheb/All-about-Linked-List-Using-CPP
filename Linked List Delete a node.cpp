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


//Delete a Node
int deletenode(Node* &head,int value)
{
    int found = 0;

    Node* temp=head;
    Node* temp1=head;

    while(temp1!=NULL)
    {
        if(temp1->data==value)
        {
            found=1;
            break;
        }
        temp1=temp1->next;
    }
    if(!found)return 0;

    //Delete in the head
    if(head->data==value)
    {
        head=head->next;
        delete temp;
        return 1;
    }

    while(temp->next->data!=value)temp = temp->next;

    Node* deleteit=temp->next;
    temp->next = deleteit->next;
    delete deleteit;
    return 1;
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



    //Inset int he beginning
    insertstart(head,0);
    insertstart(head,-1);
    insertstart(head,-2);

    //Print
    cout<<"Print"<<" ";
    printlinkedlist(head);


    //delete node
    cout<<"Deleting 5\n";
    int temp=deletenode(head,5);
    string s=temp==0?"Not Found\n":"Deleted\n";
    cout<<s;
    cout<<"Deleting -2\n";
    temp=deletenode(head,-2);
    s=temp==0?"Not Found\n":"Deleted\n";
    cout<<s;
    cout<<"Deleting 7\n";
    temp=deletenode(head,7);
    s=temp==0?"Not Found\n":"Deleted\n";
    cout<<s;
    cout<<"Deleting 9\n";
    temp=deletenode(head,9);
    s=temp==0?"Not Found\n":"Deleted\n";
    cout<<s;

    //Print
    cout<<"\nAfter deletion : ";
    printlinkedlist(head);


}

